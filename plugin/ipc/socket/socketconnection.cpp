/****************************************************************************
 *   Copyright (C) 2006-2010 by Jason Ansel, Kapil Arya, and Gene Cooperman *
 *   jansel@csail.mit.edu, kapil@ccs.neu.edu, gene@ccs.neu.edu              *
 *                                                                          *
 *   This file is part of the dmtcp/src module of DMTCP (DMTCP:dmtcp/src).  *
 *                                                                          *
 *  DMTCP:dmtcp/src is free software: you can redistribute it and/or        *
 *  modify it under the terms of the GNU Lesser General Public License as   *
 *  published by the Free Software Foundation, either version 3 of the      *
 *  License, or (at your option) any later version.                         *
 *                                                                          *
 *  DMTCP:dmtcp/src is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *  GNU Lesser General Public License for more details.                     *
 *                                                                          *
 *  You should have received a copy of the GNU Lesser General Public        *
 *  License along with DMTCP:dmtcp/src.  If not, see                        *
 *  <http://www.gnu.org/licenses/>.                                         *
 ****************************************************************************/

#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <arpa/inet.h>

#include "dmtcpplugin.h"
#include "shareddata.h"
#include "util.h"
#include "jsocket.h"
#include "jassert.h"
#include "jfilesystem.h"
#include "jconvert.h"

#include "socketconnection.h"
#include "socketwrappers.h"
#include "kernelbufferdrainer.h"
#include "connectionrewirer.h"
#include "socketconnlist.h"

#ifdef REALLY_VERBOSE_CONNECTION_CPP
static bool really_verbose = true;
#else
static bool really_verbose = false;
#endif

using namespace dmtcp;

//this function creates a socket that is in an error state
static int _makeDeadSocket()
{
  //it does it by creating a socket pair and closing one side
  int sp[2] = {-1,-1};
  JASSERT(_real_socketpair(AF_UNIX, SOCK_STREAM, 0, sp) == 0) (JASSERT_ERRNO)
    .Text("socketpair() failed");
  JASSERT(sp[0]>=0 && sp[1]>=0) (sp[0]) (sp[1])
    .Text("socketpair() failed");
  _real_close(sp[1]);
  if (really_verbose) {
    JTRACE("Created dead socket.") (sp[0]);
  }
  return sp[0];
}

static bool _isBlacklistedTcp(int sockfd,
                              const sockaddr* saddr, socklen_t len)
{
  JASSERT(saddr != NULL);
  if (len >= sizeof(saddr->sa_family) && saddr->sa_family == AF_INET) {
    struct sockaddr_in* addr =(sockaddr_in*)saddr;
    // Ports 389 and 636 are the well-known ports in /etc/services that
    // are reserved for LDAP.  Bash continues to maintain a connection to
    // LDAP, leading to problems at restart time.  So, we discover the LDAP
    // remote addresses, and turn them into dead sockets at restart time.
    //However, libc.so:getpwuid() can call libnss_ldap.so which calls
    // libldap-2.4.so to create the LDAP socket while evading our connect
    // wrapper.
    int blacklistedRemotePorts[] = {53,                 // DNS Server
      389, 636,           // LDAP
      -1};
    int i;
    for (i = 0; blacklistedRemotePorts[i] != -1; i++) {
      if (ntohs(addr->sin_port) == blacklistedRemotePorts[i]) {
        JTRACE("LDAP port found") (ntohs(addr->sin_port))
          (blacklistedRemotePorts[0]) (blacklistedRemotePorts[1]);
        return true;
      }
    }
  }
  // FIXME:  Consider adding configure or dmtcp_checkpoint option to disable
  //   all remote connections.  Handy as quick test for special cases.
  return false;
}

dmtcp::SocketConnection::SocketConnection(int domain, int type, int protocol)
  : _sockDomain(domain)
  , _sockType(type)
  , _sockProtocol(protocol)
  , _peerType(PEER_UNKNOWN)
  , _socketPairRestored(false)
{ }

void dmtcp::SocketConnection::addSetsockopt(int level, int option,
                                            const char* value, int len)
{
  _sockOptions[level][option] = jalib::JBuffer(value, len);
}

void dmtcp::SocketConnection::restoreSocketOptions(dmtcp::vector<int>& fds)
{
  typedef map<int, map< int, jalib::JBuffer> >::iterator levelIterator;
  typedef map<int, jalib::JBuffer>::iterator optionIterator;

  for (levelIterator lvl = _sockOptions.begin();
       lvl!=_sockOptions.end(); ++lvl) {
    for (optionIterator opt = lvl->second.begin();
         opt!=lvl->second.end(); ++opt) {
      JTRACE("Restoring socket option.")
        (fds[0]) (opt->first) (opt->second.size());
      int ret = _real_setsockopt(fds[0], lvl->first, opt->first,
                                 opt->second.buffer(),
                                 opt->second.size());
      JASSERT(ret == 0) (JASSERT_ERRNO) (fds[0])
        (lvl->first) (opt->first) (opt->second.size())
        .Text("Restoring setsockopt failed.");
    }
  }
}

void dmtcp::SocketConnection::serialize(jalib::JBinarySerializer& o)
{
  JSERIALIZE_ASSERT_POINT("dmtcp::SocketConnection");
  o & _sockDomain  & _sockType & _sockProtocol
    & _peerType & _socketPairRestored;

  JSERIALIZE_ASSERT_POINT("SocketOptions:");
  size_t numSockOpts = _sockOptions.size();
  o & numSockOpts;
  if (o.isWriter()) {
    //JTRACE("TCP Serialize ") (_type) (_id.conId());
    typedef map< int, map< int, jalib::JBuffer > >::iterator levelIterator;
    typedef map< int, jalib::JBuffer >::iterator optionIterator;

    size_t numLvl = _sockOptions.size();
    o & numLvl;

    for (levelIterator lvl = _sockOptions.begin();
         lvl!=_sockOptions.end(); ++lvl) {
      int lvlVal = lvl->first;
      size_t numOpts = lvl->second.size();

      JSERIALIZE_ASSERT_POINT("Lvl");

      o & lvlVal & numOpts;

      for (optionIterator opt = lvl->second.begin();
           opt!=lvl->second.end(); ++opt) {
        int optType = opt->first;
        jalib::JBuffer& buffer = opt->second;
        int bufLen = buffer.size();

        JSERIALIZE_ASSERT_POINT("Opt");

        o & optType & bufLen;
        o.readOrWrite(buffer.buffer(), bufLen);
      }
    }
  } else {
    size_t numLvl = 0;
    o & numLvl;

    while (numLvl-- > 0) {
      int lvlVal = -1;
      size_t numOpts = 0;

      JSERIALIZE_ASSERT_POINT("Lvl");

      o & lvlVal & numOpts;

      while (numOpts-- > 0) {
        int optType = -1;
        int bufLen = -1;

        JSERIALIZE_ASSERT_POINT("Opt");

        o & optType & bufLen;

        jalib::JBuffer buffer(bufLen);
        o.readOrWrite(buffer.buffer(), bufLen);

        _sockOptions[lvlVal][optType]=buffer;
      }
    }
  }

  JSERIALIZE_ASSERT_POINT("EndSockOpts");
}

/*****************************************************************************
 * TCP Connection
 *****************************************************************************/

/*onSocket*/
  dmtcp::TcpConnection::TcpConnection(int domain, int type, int protocol)
  : Connection(TCP_CREATED)
  , SocketConnection(domain, type, protocol)
  , _listenBacklog(-1)
  , _bindAddrlen(0)
  , _remotePeerId(ConnectionIdentifier::Null())
{
  if (domain != -1) {
    JTRACE("Creating TcpConnection.") (id()) (domain) (type) (protocol);
  }
  memset(&_bindAddr, 0, sizeof _bindAddr);
}

dmtcp::TcpConnection& dmtcp::TcpConnection::asTcp()
{
  return *this;
}

void dmtcp::TcpConnection::onBind(int sockfd, const struct sockaddr* addr,
                                  socklen_t len)
{
  if (really_verbose) {
    JTRACE("Binding.") (id()) (len);
  }

  JASSERT(_type == TCP_CREATED) (_type) (id())
    .Text("Binding a socket in use????");
  JASSERT(len <= sizeof _bindAddr) (len) (sizeof _bindAddr)
    .Text("That is one huge sockaddr buddy.");

  if (_sockDomain == AF_UNIX) {
    _bindAddrlen = len;
    memcpy(&_bindAddr, addr, len);
  } else {
    _bindAddrlen = sizeof(_bindAddr);
    // Do not rely on the address passed on to bind as it may contain port 0
    // which allows the OS to give any unused port. Thus we look ourselves up
    // using getsockname.
    JASSERT(getsockname(sockfd, (struct sockaddr *)&_bindAddr, &_bindAddrlen) == 0)
      (JASSERT_ERRNO);
  }
  _type = TCP_BIND;
}

void dmtcp::TcpConnection::onListen(int backlog)
{
  if (really_verbose) {
    JTRACE("Listening.") (id()) (backlog);
  }
  JASSERT(_type == TCP_BIND) (_type) (id())
    .Text("Listening on a non-bind()ed socket????");
  // A -1 backlog is not an error.
  //JASSERT(backlog > 0) (backlog)
  //.Text("That is an odd backlog????");

  _type = TCP_LISTEN;
  _listenBacklog = backlog;
}

void dmtcp::TcpConnection::onConnect(int sockfd,
                                     const struct sockaddr *addr,
                                     socklen_t len)
{
  if (really_verbose) {
    JTRACE("Connecting.") (id());
  }
  JASSERT(_type == TCP_CREATED || _type == TCP_BIND) (_type) (id())
    .Text("Connecting with an in-use socket????");

  /* socketpair wrapper calls onConnect with sockfd == -1 and addr == NULL */
  if (addr != NULL && _isBlacklistedTcp(sockfd, addr, len)) {
    _type = TCP_EXTERNAL_CONNECT;
    _connectAddrlen = len;
    memcpy(&_connectAddr, addr, len);
  } else {
    _type = TCP_CONNECT;
  }
}

/*onAccept*/
dmtcp::TcpConnection::TcpConnection(const TcpConnection& parent,
                                    const ConnectionIdentifier& remote)
  : Connection(TCP_ACCEPT)
  , SocketConnection(parent._sockDomain, parent._sockType, parent._sockProtocol)
  , _listenBacklog(-1)
  , _bindAddrlen(0)
  , _remotePeerId(remote)
{
  if (really_verbose) {
    JTRACE("Accepting.") (id()) (parent.id()) (remote);
  }

  //     JASSERT(parent._type == TCP_LISTEN) (parent._type) (parent.id())
  //             .Text("Accepting from a non listening socket????");
  memset(&_bindAddr, 0, sizeof _bindAddr);
}

void dmtcp::TcpConnection::onError()
{
  JTRACE("Error.") (id());
  _type = TCP_ERROR;
  JTRACE("Creating dead socket.") (_fds[0]) (_fds.size());
  Util::dupFds(_makeDeadSocket(), _fds);
}

void dmtcp::TcpConnection::drain()
{
  JASSERT(_fds.size() > 0) (id());

  if ((_fcntlFlags & O_ASYNC) != 0) {
    if (really_verbose) {
      JTRACE("Removing O_ASYNC flag during checkpoint.") (_fds[0]) (id());
    }
    errno = 0;
    JASSERT(fcntl(_fds[0],F_SETFL,_fcntlFlags & ~O_ASYNC) == 0)
      (JASSERT_ERRNO) (_fds[0]) (id());
  }

  if (dmtcp_no_coordinator()) {
    markExternalConnect();
  }

  switch (_type) {
    case TCP_CONNECT:
    case TCP_ACCEPT:
      JTRACE("Will drain socket") (_hasLock) (_fds[0]) (_id) (_remotePeerId);
      KernelBufferDrainer::instance().beginDrainOf(_fds[0], _id);
      break;
    case TCP_LISTEN:
      KernelBufferDrainer::instance().addListenSocket(_fds[0]);
      break;
    case TCP_BIND:
      JWARNING(_type != TCP_BIND) (_fds[0])
        .Text("If there are pending connections on this socket,\n"
              " they won't be checkpointed because"
              " it is not yet in a listen state.");
      break;
    case TCP_EXTERNAL_CONNECT:
      JTRACE("Socket to External Process, won't be drained") (_fds[0]);
      break;
  }
}

void dmtcp::TcpConnection::doSendHandshakes(const ConnectionIdentifier& coordId)
{
  switch (_type) {
    case TCP_CONNECT:
    case TCP_ACCEPT:
      JTRACE("Sending handshake ...") (id()) (_fds[0]);
      sendHandshake(_fds[0], coordId);
      break;
    case TCP_EXTERNAL_CONNECT:
      JTRACE("Socket to External Process, skipping handshake send") (_fds[0]);
      break;
  }
}

void dmtcp::TcpConnection::doRecvHandshakes(const ConnectionIdentifier& coordId)
{
  switch (_type) {
    case TCP_CONNECT:
    case TCP_ACCEPT:
      recvHandshake(_fds[0], coordId);
      JTRACE("Received handshake.") (id()) (getRemoteId()) (_fds[0]);
      break;
    case TCP_EXTERNAL_CONNECT:
      JTRACE("Socket to External Process, skipping handshake recv") (_fds[0]);
      break;
  }
}

void dmtcp::TcpConnection::refill(bool isRestart)
{
  if ((_fcntlFlags & O_ASYNC) != 0) {
    JTRACE("Re-adding O_ASYNC flag.") (_fds[0]) (id());
    restoreSocketOptions(_fds);
  } else if (isRestart && _sockDomain != AF_INET6 &&
             _type != TCP_EXTERNAL_CONNECT) {
    restoreSocketOptions(_fds);
  }
}

void dmtcp::TcpConnection::restoreSocketPair(dmtcp::TcpConnection *peer)
{
  int sv[2];
  JASSERT(_peerType == PEER_SOCKETPAIR && _socketpairPeerId == peer->id())
   (_peerType) (_socketpairPeerId) (peer->id());
  JASSERT(_fds.size() > 0);
  JASSERT(peer->numFds() > 0);

  if (_socketPairRestored) {
    _socketPairRestored = false;
    return;
  }
  JASSERT(_real_socketpair(_sockDomain,_sockType,_sockProtocol, sv) == 0)
   (JASSERT_ERRNO);

  Util::dupFds(sv[0], _fds);
  Util::dupFds(sv[1], peer->_fds);
  peer->_socketPairRestored = true;
  JTRACE("Restored Socketpair") (id()) (peer->id()) (_fds[0]) (peer->_fds[0]);
}

void dmtcp::TcpConnection::postRestart()
{
  JASSERT(_fds.size() > 0);
  switch (_type) {
    case TCP_PREEXISTING:
    case TCP_ERROR: //not a valid socket
    case TCP_INVALID:
    case TCP_EXTERNAL_CONNECT:
      JTRACE("Creating dead socket.") (_fds[0]) (_fds.size());
      Util::dupFds(_makeDeadSocket(), _fds);
      break;
    case TCP_CREATED:
    case TCP_BIND:
    case TCP_LISTEN:
      {
        JWARNING((_sockDomain == AF_INET || _sockDomain == AF_UNIX ||
                  _sockDomain == AF_INET6) && _sockType == SOCK_STREAM)
          (id()) (_sockDomain) (_sockType) (_sockProtocol)
          .Text("Socket type not yet [fully] supported.");

        if (really_verbose) {
          JTRACE("Restoring socket.") (id()) (_fds[0]);
        }

        jalib::JSocket sock(_real_socket(_sockDomain, _sockType,
                                         _sockProtocol));
        JASSERT(sock.isValid());
        sock.changeFd(_fds[0]);

        Util::dupFds(_fds[0], _fds);

        if (_type == TCP_CREATED) break;

        if (_sockDomain == AF_UNIX) {
          const char* un_path =((sockaddr_un*) &_bindAddr)->sun_path;
          JTRACE("Unlinking stale unix domain socket.") (un_path);
          JWARNING(unlink(un_path) == 0) (un_path);
        }
        /*
         * During restart, some socket options must be restored(using
         * setsockopt) before the socket is used(bind etc.), otherwise we might
         * not be able to restore them at all. One such option is set in the
         * following way for IPV6 family:
         * setsockopt(sd, IPPROTO_IPV6, IPV6_V6ONLY,...)
         * This fix works for now. A better approach would be to restore the
         * socket options in the order in which they are set by the user
         * program.  This fix solves a bug that caused OpenMPI to fail to
         * restart under DMTCP.
         *                               --Kapil
         */

        if (_sockDomain == AF_INET6) {
          JTRACE("Restoring some socket options before binding.");
          typedef map< int, map< int,
                                 jalib::JBuffer > >::iterator levelIterator;
          typedef map< int, jalib::JBuffer >::iterator optionIterator;

          for (levelIterator lvl = _sockOptions.begin();
               lvl!=_sockOptions.end(); ++lvl) {
            if (lvl->first == IPPROTO_IPV6) {
              for (optionIterator opt = lvl->second.begin();
                   opt!=lvl->second.end(); ++opt) {
                if (opt->first == IPV6_V6ONLY) {
                  if (really_verbose) {
                    JTRACE("Restoring socket option.")
                      (_fds[0]) (opt->first) (opt->second.size());
                  }
                  int ret = _real_setsockopt(_fds[0], lvl->first, opt->first,
                                              opt->second.buffer(),
                                              opt->second.size());
                  JASSERT(ret == 0) (JASSERT_ERRNO) (_fds[0]) (lvl->first)
                    (opt->first) (opt->second.buffer()) (opt->second.size())
                    .Text("Restoring setsockopt failed.");
                }
              }
            }
          }
        }

        if (really_verbose) {
          JTRACE("Binding socket.") (id());
        }
        errno = 0;
        JWARNING(sock.bind((sockaddr*) &_bindAddr,_bindAddrlen))
          (JASSERT_ERRNO) (id())
          .Text("Bind failed.");
        if (_type == TCP_BIND) break;

        if (really_verbose) {
          JTRACE("Listening socket.") (id());
        }
        errno = 0;
        JWARNING(sock.listen(_listenBacklog))
          (JASSERT_ERRNO) (id()) (_listenBacklog)
          .Text("Bind failed.");
        if (_type == TCP_LISTEN) break;

      }
      break;
    case TCP_ACCEPT:
      JASSERT(!_remotePeerId.isNull()) (id()) (_remotePeerId) (_fds[0])
        .Text("Can't restore a TCP_ACCEPT socket with null acceptRemoteId.\n"
              "  Perhaps handshake went wrong?");
      JTRACE("registerOutgoing") (id()) (_remotePeerId) (_fds[0]);
      ConnectionRewirer::instance().registerOutgoing(_remotePeerId, this);
      break;
    case TCP_CONNECT:
      JTRACE("registerIncoming") (id()) (_remotePeerId) (_fds[0]);
      ConnectionRewirer::instance().registerIncoming(id(), this);
      break;
      //    case TCP_EXTERNAL_CONNECT:
      //      int sockFd = _real_socket(_sockDomain, _sockType, _sockProtocol);
      //      JASSERT(sockFd >= 0);
      //      JASSERT(_real_dup2(sockFd, _fds[0]) == _fds[0]);
      //      JWARNING(0 == _real_connect(sockFd,(sockaddr*) &_connectAddr,
      //                                  _connectAddrlen))
      //        (_fds[0]) (JASSERT_ERRNO)
      //        .Text("Unable to connect to external process");
      //      break;
  }
}

void dmtcp::TcpConnection::sendHandshake(int remotefd,
                                         const ConnectionIdentifier& coordId)
{
  jalib::JSocket remote(remotefd);
  ConnMsg msg(ConnMsg::HANDSHAKE);
  msg.from = id();
  msg.coordId = coordId;
  remote << msg;
}

void dmtcp::TcpConnection::recvHandshake(int remotefd,
                                         const ConnectionIdentifier& coordId)
{
  jalib::JSocket remote(remotefd);
  ConnMsg msg;
  msg.poison();
  remote >> msg;

  msg.assertValid(ConnMsg::HANDSHAKE);
  JASSERT(msg.coordId == coordId) (msg.coordId) (coordId)
    .Text("Peer has a different dmtcp_coordinator than us!\n"
          "  It must be the same.");

  if (_remotePeerId.isNull()) {
    //first time
    _remotePeerId = msg.from;
    JASSERT(!_remotePeerId.isNull())
      .Text("Read handshake with invalid 'from' field.");
  } else {
    //next time
    JASSERT(_remotePeerId == msg.from)
      (_remotePeerId) (msg.from)
      .Text("Read handshake with a different 'from' field"
            " than a previous handshake.");
  }
}

void dmtcp::TcpConnection::serializeSubClass(jalib::JBinarySerializer& o)
{
  JSERIALIZE_ASSERT_POINT("dmtcp::TcpConnection");
  o & _listenBacklog & _bindAddrlen & _bindAddr & _remotePeerId;
  SocketConnection::serialize(o);
}

/*****************************************************************************
 * RawSocket Connection
 *****************************************************************************/
/*onSocket*/
dmtcp::RawSocketConnection::RawSocketConnection(int domain, int type,
                                                int protocol)
  : Connection(RAW)
    , SocketConnection(domain, type, protocol)
{
  JASSERT(type == -1 ||(type & SOCK_RAW));
  JASSERT(domain == -1 || domain == AF_NETLINK) (domain)
    .Text("Only Netlink raw socket supported");
  JTRACE("Creating Raw socket.") (id()) (domain) (type) (protocol);
}

void dmtcp::RawSocketConnection::drain()
{
  JASSERT(_fds.size() > 0) (id());

  if ((_fcntlFlags & O_ASYNC) != 0) {
    if (really_verbose) {
      JTRACE("Removing O_ASYNC flag during checkpoint.") (_fds[0]) (id());
    }
    errno = 0;
    JASSERT(fcntl(_fds[0], F_SETFL, _fcntlFlags & ~O_ASYNC) == 0)
      (JASSERT_ERRNO) (_fds[0]) (id());
  }
}

void dmtcp::RawSocketConnection::refill(bool isRestart)
{
  if ((_fcntlFlags & O_ASYNC) != 0) {
    JTRACE("Re-adding O_ASYNC flag.") (_fds[0]) (id());
    restoreSocketOptions(_fds);
  } else if (isRestart) {
    restoreSocketOptions(_fds);
  }
}

void dmtcp::RawSocketConnection::postRestart()
{
  JASSERT(_fds.size() > 0);
  if (really_verbose) {
    JTRACE("Restoring socket.") (id()) (_fds[0]);
  }

  int sockfd = _real_socket(_sockDomain,_sockType,_sockProtocol);
  JASSERT(sockfd != -1);
  Util::dupFds(sockfd, _fds);
}

void dmtcp::RawSocketConnection::serializeSubClass(jalib::JBinarySerializer& o)
{
  JSERIALIZE_ASSERT_POINT("dmtcp::RawSocketConnection");
  SocketConnection::serialize(o);
}
