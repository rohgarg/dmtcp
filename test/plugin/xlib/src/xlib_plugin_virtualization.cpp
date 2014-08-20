#include <iostream>
#include "xlib_plugin_virtualization.h"
#include "xlib_plugin_wrappers.h"

using namespace std;

void XlibVirtualization::init()
{
  g_virt_window_id = VIRT_WINDOW_ID_BASE;
  g_virt_colormap_id = VIRT_COLORMAP_ID_BASE;
  g_virt_pixmap_id = VIRT_PIXMAP_ID_BASE;
  g_virt_cursor_id = VIRT_CURSOR_ID_BASE;
}

void XlibVirtualization::save_func_and_params(string p_func_call)
{
  g_func_calls_log_buff.push_back(p_func_call);
}

const vector<string>& XlibVirtualization::get_xlib_calls_log()
{
  return g_func_calls_log_buff;
}

/****************************/
/* Virtualization functions */
/****************************/
Display* XlibVirtualization::virtual_to_real_display_pointer(Display* p_virt_dp)
{
  map<Display*, Display*>::iterator it;
  for (it = display_virtual_table.begin(); it != display_virtual_table.end(); it++)
  {
    if (p_virt_dp == it->second)
      return it->first;
  }
  return NULL;
}

Display* XlibVirtualization::real_to_virtual_display_pointer(Display* p_real_dp)
{
  map<Display*, Display*>::iterator it;
  it = display_virtual_table.find(p_real_dp);
  if (it == display_virtual_table.end())
    return NULL;
  return it->second;
}

Window XlibVirtualization::virtual_to_real_window(Window p_virt_win)
{
  map<Window, Window>::iterator it;
  for (it = window_virtual_table.begin(); it != window_virtual_table.end(); it++)
  {
    if (p_virt_win == it->second)
      return it->first;
  }
  return -1;
}

Window XlibVirtualization::real_to_virtual_window(Window p_real_win)
{
  map<Window, Window>::iterator it;
  it = window_virtual_table.find(p_real_win);
  if (it == window_virtual_table.end())
    return -1;
  return it->second;
}

Colormap XlibVirtualization::virtual_to_real_colormap(Colormap p_virt_cmp)
{
  map<Colormap, Colormap>::iterator it;
  for (it = colormap_virtual_table.begin(); it != colormap_virtual_table.end(); it++)
  {
    if (p_virt_cmp == it->second)
      return it->first;
  }
  return -1;
}

Colormap XlibVirtualization::real_to_virtual_colormap(Colormap p_real_cmp)
{
  map<Colormap, Colormap>::iterator it;
  it = colormap_virtual_table.find(p_real_cmp);
  if (it == colormap_virtual_table.end())
    return -1;
  return it->second;
}

Pixmap XlibVirtualization::virtual_to_real_pixmap(Pixmap p_virt_pmp)
{
  map<Pixmap, Pixmap>::iterator it;
  for (it = pixmap_virtual_table.begin(); it != pixmap_virtual_table.end(); it++)
  {
    if (p_virt_pmp == it->second)
      return it->first;
  }
  return -1;
}

Pixmap XlibVirtualization::real_to_virtual_pixmap(Pixmap p_real_pmp)
{
  map<Pixmap, Pixmap>::iterator it;
  it = pixmap_virtual_table.find(p_real_pmp);
  if (it == pixmap_virtual_table.end())
    return -1;
  return it->second;
}

Cursor XlibVirtualization::virtual_to_real_cursor(Cursor p_virt_cursor)
{
  map<Cursor, Cursor>::iterator it;
  for (it = cursor_virtual_table.begin(); it != cursor_virtual_table.end(); it++)
  {
    if (p_virt_cursor == it->second)
      return it->first;
  }
  return -1;
}

Cursor XlibVirtualization::real_to_virtual_cursor(Cursor p_real_cursor)
{
  map<Cursor, Cursor>::iterator it;
  it = cursor_virtual_table.find(p_real_cursor);
  if (it == cursor_virtual_table.end())
    return -1;
  return it->second;
}

Drawable XlibVirtualization::virtual_to_real_drawable(Drawable p_virt_drawable)
{
  Drawable l_d = p_virt_drawable;
  l_d = virtual_to_real_window(p_virt_drawable);
  if (l_d < 0)
  {
    l_d = virtual_to_real_pixmap(p_virt_drawable);
  }
  return l_d;
}

XIM XlibVirtualization::virtual_to_real_xim(XIM p_virt_xim)
{
  map<XIM, XIM>::iterator it;
  for (it = xim_virtual_table.begin(); it != xim_virtual_table.end(); it++)
  {
    if (p_virt_xim == it->second)
      return it->first;
  }
  return NULL;
}

XIM XlibVirtualization::real_to_virtual_xim(XIM p_real_xim)
{
  map<XIM, XIM>::iterator it;
  it = xim_virtual_table.find(p_real_xim);
  if (it == xim_virtual_table.end())
    return NULL;
  return it->second;
}

XImage* XlibVirtualization::virtual_to_real_ximg(XImage* p_virt_ximg)
{
  map<XImage*, XImage*>::iterator it;
  for (it = ximg_virtual_table.begin(); it != ximg_virtual_table.end(); it++)
  {
    if (p_virt_ximg == it->second)
      return it->first;
  }
  return NULL;
}

XImage* XlibVirtualization::real_to_virtual_ximg(XImage* p_real_ximg)
{
  map<XImage*, XImage*>::iterator it;
  it = ximg_virtual_table.find(p_real_ximg);
  if (it == ximg_virtual_table.end())
    return NULL;
  return it->second;
}

GLXContext XlibVirtualization::virtual_to_real_glxcontext(GLXContext p_virt_glxcontext)
{
  map<GLXContext, GLXContext>::iterator it;
  for (it = glxctx_virtual_table.begin(); it != glxctx_virtual_table.end(); it++)
  {
    if (p_virt_glxcontext == it->second)
      return it->first;
  }
  return NULL;
}

GLXContext XlibVirtualization::real_to_virtual_glxcontext(GLXContext p_real_glxcontext)
{
  map<GLXContext, GLXContext>::iterator it;
  it = glxctx_virtual_table.find(p_real_glxcontext);
  if (it == glxctx_virtual_table.end())
    return NULL;
  return it->second;
}

GLXDrawable XlibVirtualization::virtual_to_real_glxdrawable(GLXDrawable p_virt_glxdrawable)
{
  map<GLXDrawable, GLXDrawable>::iterator it;
  for (it = glxdrawable_virtual_table.begin(); it != glxdrawable_virtual_table.end(); it++)
  {
    if (p_virt_glxdrawable == it->second)
      return it->first;
  }
  return -1;
}

GLXDrawable XlibVirtualization::real_to_virtual_glxdrawable(GLXDrawable p_real_glxdrawable)
{
  map<GLXDrawable, GLXDrawable>::iterator it;
  it = glxdrawable_virtual_table.find(p_real_glxdrawable);
  if (it == glxdrawable_virtual_table.end())
    return -1;
  return it->second;
}

GC XlibVirtualization::virtual_to_real_gc(GC p_virt_gc)
{
  map<GC, GC>::iterator it;
  for (it = gc_virtual_table.begin(); it != gc_virtual_table.end(); it++)
  {
    if (p_virt_gc == it->second)
      return it->first;
  }
  return NULL;
}

/*********************************/
/* Helper functions for wrappers */
/*********************************/
Display* XlibVirtualization::save_display(Display* p_real_display)
{
  /* NOTE: This assumes that there is only one reference to Display */
  Display *l_virt_dp = p_real_display;
  display_virtual_table.insert(pair<Display*, Display*>(p_real_display, l_virt_dp));
  return l_virt_dp;
}

Window XlibVirtualization::save_window(Window p_real_window)
{
  Window l_virt_window = (g_virt_window_id = g_virt_window_id + 1);
  window_virtual_table.insert(pair<Window, Window>(p_real_window, l_virt_window));
  return l_virt_window;
}

Colormap XlibVirtualization::save_colormap(Colormap p_real_colormap)
{
  Colormap l_virt_colormap = (g_virt_colormap_id = g_virt_colormap_id + 1);
  colormap_virtual_table.insert(pair<Colormap, Colormap>(p_real_colormap, l_virt_colormap));
  return l_virt_colormap;
}

Pixmap XlibVirtualization::save_pixmap(Pixmap p_real_pixmap)
{
  Pixmap l_virt_pixmap = (g_virt_pixmap_id = g_virt_pixmap_id + 1);
  pixmap_virtual_table.insert(pair<Pixmap, Pixmap>(p_real_pixmap, l_virt_pixmap));
  return l_virt_pixmap;
}

Cursor XlibVirtualization::save_cursor(Cursor p_real_cursor)
{
  Cursor l_virt_cursor = (g_virt_cursor_id = g_virt_cursor_id + 1);
  cursor_virtual_table.insert(pair<Cursor, Cursor>(p_real_cursor, l_virt_cursor));
  return l_virt_cursor;
}

XIM XlibVirtualization::save_xim(XIM p_real_xim)
{
  XIM l_virt_xim = p_real_xim;
  xim_virtual_table.insert(pair<XIM, XIM>(p_real_xim, l_virt_xim));
  return l_virt_xim;
}

XImage* XlibVirtualization::save_ximg(XImage* p_real_ximg)
{
  XImage* l_virt_ximg = p_real_ximg;
  ximg_virtual_table.insert(pair<XImage*, XImage*>(p_real_ximg, l_virt_ximg));
  return l_virt_ximg;
}

GLXContext XlibVirtualization::save_glxctx(GLXContext p_real_glxctx)
{
  GLXContext l_virt_glxctx = p_real_glxctx;
  glxctx_virtual_table.insert(pair<GLXContext, GLXContext>(p_real_glxctx, l_virt_glxctx));
  return l_virt_glxctx;
}

GC XlibVirtualization::save_gc(GC p_real_gc)
{
  GC l_virt_gc = p_real_gc;
  gc_virtual_table.insert(pair<GC, GC>(p_real_gc, l_virt_gc));
  return l_virt_gc;
#if 0
  g_real_gc = g_virtual_gc = p_real_gc;
  return g_virtual_gc;
#endif
}

int XlibVirtualization::remove_display(Display* p_virt_display)
{
  return display_virtual_table.erase(virtual_to_real_display_pointer(p_virt_display));
}

int XlibVirtualization::remove_window(Window p_virt_window)
{
  return window_virtual_table.erase(virtual_to_real_window(p_virt_window));
}

int XlibVirtualization::remove_gc(GC p_virt_gc)
{
  return gc_virtual_table.erase(virtual_to_real_gc(p_virt_gc));
}

int XlibVirtualization::remove_colormap(Colormap p_virt_colormap)
{
  return colormap_virtual_table.erase(virtual_to_real_colormap(p_virt_colormap));
}

int XlibVirtualization::remove_pixmap(Pixmap p_virt_pixmap)
{
  return pixmap_virtual_table.erase(virtual_to_real_pixmap(p_virt_pixmap));
}

int XlibVirtualization::remove_cursor(Cursor p_virt_cursor)
{
  return cursor_virtual_table.erase(virtual_to_real_cursor(p_virt_cursor));
}

int XlibVirtualization::remove_xim(XIM p_virt_xim)
{
  return xim_virtual_table.erase(virtual_to_real_xim(p_virt_xim));
}

int XlibVirtualization::remove_ximg(XImage* p_virt_ximg)
{
  return ximg_virtual_table.erase(virtual_to_real_ximg(p_virt_ximg));
}

void XlibVirtualization::update_display_mapping(Display *p_virt_dp, Display *p_real_dp)
{
  display_virtual_table[p_real_dp] = p_virt_dp;
}

void XlibVirtualization::update_window_mapping(Window p_virt_win, Window p_real_win)
{
  window_virtual_table[p_real_win] = p_virt_win;
}

void XlibVirtualization::update_gc_mapping(GC p_virt_gc, GC p_real_gc)
{
  gc_virtual_table[p_real_gc] = p_virt_gc;
}

void XlibVirtualization::close_connection()
{
  map<Window, Window>::iterator itw;
  map<Display*, Display*>::iterator it;

  Display *l_real_dp = display_virtual_table.begin()->first;
  for (itw = window_virtual_table.begin(); itw != window_virtual_table.end(); itw++)
  {
    Window l_real_win = itw->first;
    if (l_real_win != RootWindow(l_real_dp, 0)) {
      _real_XDestroyWindow(l_real_dp, l_real_win);
    }
  }

  for (it = display_virtual_table.begin(); it != display_virtual_table.end(); it++)
  {
    l_real_dp = it->first;
    _real_XCloseDisplay(l_real_dp);
  }
}

/***********************/
/* Getters and Setters */
/***********************/
void XlibVirtualization::set_virtual_gc(GC p_virt_gc)
{
  g_virtual_gc = p_virt_gc;
}

void XlibVirtualization::set_real_gc(GC p_real_gc)
{
  g_real_gc = p_real_gc;
}
