#ifndef _XLIB_PLUGIN_VIRTUALIZATION_H_
#define _XLIB_PLUGIN_VIRTUALIZATION_H_

#include "Singleton.h"
#include <X11/Xlib.h>
#include <vector>
#include <string>

#define XLIB_VIRT_CALL_FUNC XlibVirt::GetInstance()
#define XLIB_VIRT_SAVE_FUNC_CALL(msg) XLIB_VIRT_CALL_FUNC.save_func_and_params(msg)

using namespace std;

class XlibVirtualization
{
  private:
    Display *g_real_dp, *g_virtual_dp;
    Window g_real_win, g_virtual_win;
    GC g_real_gc, g_virtual_gc;
    vector<string> g_func_calls_log_buff;

  public:
    void save_func_and_params(string /* p_func_call */);

    /* Virtualization functions */
    Display* virtual_to_real_display_pointer(Display* /* p_virt_dp */);
    Window virtual_to_real_window(Window /* p_virt_win */);
    GC virtual_to_real_gc(GC /* p_virt_gc */);

    /* Helper functions for wrappers */
    void save_display(Display* /* p_real_display */);

    /* Getters and Setters */
    Display* get_virtual_dp();
    Display* get_real_dp();
};
typedef Singleton<XlibVirtualization> XlibVirt;

#endif
