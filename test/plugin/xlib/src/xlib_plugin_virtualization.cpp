#include <iostream>
#include "xlib_plugin_virtualization.h"

using namespace std;

void XlibVirtualization::save_func_and_params(string p_func_call)
{
  g_func_calls_log_buff.push_back(p_func_call);
}

/* Virtualization functions */
Display* XlibVirtualization::virtual_to_real_display_pointer(Display* p_virt_dp)
{
  if (g_virtual_dp == p_virt_dp)
    return g_real_dp;
  else
    return NULL;
}

Window XlibVirtualization::virtual_to_real_window(Window p_virt_win)
{
  if (g_virtual_win == p_virt_win)
    return g_real_win;
  else
    return 0;
}

GC XlibVirtualization::virtual_to_real_gc(GC p_virt_gc)
{
  if (g_virtual_gc == p_virt_gc)
    return g_real_gc;
  else
    return NULL;
}

/* Helper functions for wrappers */
void XlibVirtualization::save_display(Display* p_real_display)
{
  g_real_dp = g_virtual_dp = p_real_display;
}

/* Getters and Setters */
Display* XlibVirtualization::get_virtual_dp()
{
  return g_virtual_dp;
}

Display* XlibVirtualization::get_real_dp()
{
  return g_real_dp;
}
