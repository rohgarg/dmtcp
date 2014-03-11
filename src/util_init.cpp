/****************************************************************************
 *   Copyright (C) 2006-2013 by Jason Ansel, Kapil Arya, and Gene Cooperman *
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

#include <string.h>
#include <sys/fcntl.h>
#include "constants.h"
#include "util.h"
#include "protectedfds.h"
#include "uniquepid.h"
#include "../jalib/jassert.h"
#include "../jalib/jfilesystem.h"
#include "../jalib/jsocket.h"

using namespace dmtcp;

void dmtcp::Util::writeCoordPortToFile(const char *port, const char *portFile)
{
  if (port != NULL && portFile != NULL) {
    int fd = open(portFile, O_CREAT|O_WRONLY|O_TRUNC, 0600);
    JWARNING(fd != -1) (JASSERT_ERRNO) (portFile)
      .Text("Failed to open port file.");
    writeAll(fd, port, strlen(port));
    fsync(fd);
    close(fd);
  }
}


void dmtcp::Util::initializeLogFile(dmtcp::string procname, dmtcp::string prevLogPath)
{
  dmtcp::UniquePid::ThisProcess(true);
#ifdef DEBUG
  // Initialize JASSERT library here
  dmtcp::ostringstream o;
  o << dmtcp::UniquePid::getTmpDir() << "/jassertlog."
    << dmtcp::UniquePid::ThisProcess()
    << "_";
  if (procname.empty()) {
    o << jalib::Filesystem::GetProgramName();
  } else {
    o << procname;
  }

  JASSERT_SET_LOG(o.str());

  dmtcp::ostringstream a;
  a << "\n========================================";
  a << "\nProcess Information";
  a << "\n========================================";
  a << "\nThis Process: " << dmtcp::UniquePid::ThisProcess()
    << "\nParent Process: " << dmtcp::UniquePid::ParentProcess();

  if (!prevLogPath.empty()) {
    a << "\nPrev JAssertLog path: " << prevLogPath;
  }

  a << "\nArgv: ";
  dmtcp::vector<dmtcp::string> args = jalib::Filesystem::GetProgramArgs();
  size_t i;
  for (i = 0; i < args.size(); i++) {
    a << " " << args[i];
  }

  a << "\nEnvironment: ";
  for (i = 0; environ[i] != NULL; i++) {
    a << " " << environ[i] << ";";
  }
  a << "\n========================================\n";

  JLOG(a.str().c_str());
#endif
  if (getenv(ENV_VAR_QUIET)) {
    jassert_quiet = *getenv(ENV_VAR_QUIET) - '0';
  } else {
    jassert_quiet = 0;
  }
  unsetenv(ENV_VAR_STDERR_PATH);
}
