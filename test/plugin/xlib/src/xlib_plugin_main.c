#include <stdio.h>
#include <X11/Xlib.h>

#include "dmtcpplugin.h"
#include "xlib_plugin_debug.h"

void dmtcp_event_hook(DmtcpEvent_t event, DmtcpEventData_t *data)
{
  /* NOTE:  See warning in plugin/README about calls to printf here. */
  switch (event) {
  case DMTCP_EVENT_INIT:
    DPRINTF("The plugin containing %s has been initialized.\n", __FILE__);
    break;
  case DMTCP_EVENT_WRITE_CKPT:
    DPRINTF("The plugin is being called before checkpointing.\n");
    break;
  case DMTCP_EVENT_RESUME:
    DPRINTF("The plugin has now been checkpointed.\n");
    break;
  case DMTCP_EVENT_THREADS_RESUME:
    if (data->resumeInfo.isRestart) {
      DPRINTF("The plugin is now resuming or restarting from checkpointing.\n");
    } else {
      DPRINTF("The process is now resuming after checkpoint.\n");
    }
    break;
  case DMTCP_EVENT_EXIT:
    DPRINTF("The plugin is being called before exiting.\n");
    break;
  /* These events are unused and could be omitted.  See dmtcpplugin.h for
   * complete list.
   */
  case DMTCP_EVENT_RESTART:
  case DMTCP_EVENT_ATFORK_CHILD:
  case DMTCP_EVENT_THREADS_SUSPEND:
  case DMTCP_EVENT_LEADER_ELECTION:
  case DMTCP_EVENT_DRAIN:
  default:
    break;
  }
  DMTCP_NEXT_EVENT_HOOK(event, data);
}
