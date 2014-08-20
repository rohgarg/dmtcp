#include <stdio.h>
#include <X11/Xlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "dmtcp.h"
#include "xlib_plugin_virtualization.h"
#include "xlib_plugin_wrappers.h"
#include "xlib_plugin_debug.h"

using namespace std;

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

template<typename TYPE>
static string to_string(TYPE data)
{
  ostringstream convert; /*stream used for the conversion*/
  convert << data;
  return convert.str();
}

template<typename TYPE>
static TYPE string_to_given_type(string str)
{
  TYPE num;
  istringstream(str) >> num;
  return num;
}

/*
 * Returns the name of the function.
 *
 * Expects strings of the form: function(arg1, arg2, arg3)
 *
 * Returns:
 *  The name of the function as C++ string
 */
static string tokenize_xlib_callname(string xcall)
{
  size_t first_open_paren = xcall.find("(");
  size_t len = first_open_paren;
  string xcall_name = xcall.substr(0, len);
  return xcall_name;
}

/*
 * Returns the list of arguments to the function.
 *
 * Expects strings of the form: function(arg1, arg2, arg3)
 *
 * Returns:
 *  The list of the function arguments.
 */
static vector<string> tokenize_xlib_callparams(string xcall)
{
  size_t position = xcall.find("(")+1;
  size_t closed_paren = xcall.find(")");
  size_t len = closed_paren - position;
  vector<string> params;
  /*no param*/
  if (len == 0) {
    return params;
  }
  string _sparams = xcall.substr(position,len);
  /* only one param */
  if (_sparams.find(",") == string::npos) {
    params.push_back(_sparams);
  } else {
    position = 0;
    size_t comma_pos = _sparams.find(",");
    while (comma_pos != string::npos) {
      string param = _sparams.substr(position, comma_pos - position);
      params.push_back(param);
      _sparams = _sparams.substr(comma_pos + 1, closed_paren - comma_pos - 2);
      comma_pos = _sparams.find(",");
    }
    params.push_back(_sparams);
  }
  return params;
}

static void execute_xcall(string xcall_name, vector<string> xcall_params)
{
  if (xcall_name == "XOpenDisplay") {
    void *l_virt_dp = string_to_given_type<void*>(xcall_params[0]);
    void *display_name = string_to_given_type<void*>(xcall_params[1]);
    Display *l_real_dp = _real_XOpenDisplay((char*)display_name);
    XLIB_VIRT_CALL_FUNC.update_display_mapping((Display *)l_virt_dp, l_real_dp);
  } else if (xcall_name == "XCreateSimpleWindow") {
    Window l_virt_win = string_to_given_type<Window>(xcall_params[0]);
    void *l_virt_dp = string_to_given_type<void*>(xcall_params[1]);
    Window l_virt_parent = string_to_given_type<Window>(xcall_params[2]);
    int x = string_to_given_type<int>(xcall_params[3]);
    int y = string_to_given_type<int>(xcall_params[4]);
    unsigned int width = string_to_given_type<unsigned int>(xcall_params[5]);
    unsigned int height = string_to_given_type<unsigned int>(xcall_params[6]);
    unsigned int border_width = string_to_given_type<unsigned int>(xcall_params[7]);
    unsigned long border = string_to_given_type<unsigned long>(xcall_params[8]);
    unsigned long background = string_to_given_type<unsigned long>(xcall_params[9]);
    Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer((Display*)l_virt_dp);
    Window l_real_parent = XLIB_VIRT_CALL_FUNC.virtual_to_real_window(l_virt_parent);
    Window l_real_win = _real_XCreateSimpleWindow(l_real_dp, l_real_parent, x, y, width, height, border_width, border, background);
    XLIB_VIRT_CALL_FUNC.update_window_mapping(l_virt_win, l_real_win);
  } else if (xcall_name == "XMapWindow") {
    void *l_virt_dp = string_to_given_type<void*>(xcall_params[0]);
    Window l_virt_win = string_to_given_type<Window>(xcall_params[1]);
    Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer((Display*)l_virt_dp);
    Window l_real_win = XLIB_VIRT_CALL_FUNC.virtual_to_real_window(l_virt_win);
    int res = _real_XMapWindow((Display *)l_real_dp, l_real_win);
    res = res + 1;
  } else if (xcall_name == "XCreateGC") {
    void *l_virt_gc = string_to_given_type<void*>(xcall_params[0]);
    void *l_virt_dp = string_to_given_type<void*>(xcall_params[1]);
    Drawable l_virt_d = string_to_given_type<Drawable>(xcall_params[2]);
    unsigned long valuemask = string_to_given_type<unsigned long >(xcall_params[3]);
    void *l_values_buff = string_to_given_type<void*>(xcall_params[4]);
    Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer((Display*)l_virt_dp);
    Drawable l_real_d = XLIB_VIRT_CALL_FUNC.virtual_to_real_drawable(l_virt_d);
    GC l_real_gc = _real_XCreateGC(l_real_dp, l_real_d, valuemask, (XGCValues*)l_values_buff);
    XLIB_VIRT_CALL_FUNC.update_gc_mapping((GC)l_virt_gc, l_real_gc);
  } else if (xcall_name == "") {
  } else if (xcall_name == "") {
  } else if (xcall_name == "") {
  } else if (xcall_name == "") {
  } else if (xcall_name == "") {
  } else {
  }
}

static void parse_xlib_calls_log()
{
  string xcall, xcall_name;
  int count = -1;

  ifstream infile;
  vector<string> calls_log = XLIB_VIRT_CALL_FUNC.get_xlib_calls_log();
  while (++count < calls_log.size()) {
    xcall = calls_log[count];
    if (xcall.size() < 1) {
      break;
    }
    xcall_name = tokenize_xlib_callname(xcall);
    vector<string> xcall_params = tokenize_xlib_callparams(xcall);
    execute_xcall(xcall_name, xcall_params);
  }
}
