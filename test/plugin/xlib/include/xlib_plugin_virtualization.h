#ifndef _XLIB_PLUGIN_VIRTUALIZATION_H_
#define _XLIB_PLUGIN_VIRTUALIZATION_H_

#include "Singleton.h"
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <vector>
#include <map>
#include <string>

#define VIRT_WINDOW_ID_BASE 1000
#define VIRT_COLORMAP_ID_BASE 2000
#define VIRT_PIXMAP_ID_BASE 3000
#define VIRT_CURSOR_ID_BASE 4000
#define VIRT_XIM_ID_BASE 5000

#define XLIB_VIRT_CALL_FUNC XlibVirt::GetInstance()
#define XLIB_VIRT_SAVE_FUNC_CALL(msg) XLIB_VIRT_CALL_FUNC.save_func_and_params(msg)

using namespace std;

class XlibVirtualization
{
  private:
    /* Real->Virtual Tables */
    map<Display*, Display*> display_virtual_table;
    map<GC, GC> gc_virtual_table;
    map<XImage*, XImage*> ximg_virtual_table;
    map<Window, Window> window_virtual_table;
    map<Colormap, Colormap> colormap_virtual_table;
    map<Pixmap, Pixmap> pixmap_virtual_table;
    map<Cursor, Cursor> cursor_virtual_table;
    map<XIM, XIM> xim_virtual_table;
    map<GLXContext, GLXContext> glxctx_virtual_table;
    map<GLXDrawable, GLXDrawable> glxdrawable_virtual_table;

    /* Virtual ID Counters */
    Window g_virt_window_id;
    Colormap g_virt_colormap_id;
    Pixmap g_virt_pixmap_id;
    Cursor g_virt_cursor_id;
    XIM g_virt_xim_id;
    GC g_real_gc, g_virtual_gc; /* TODO: Not used anymore */

    /* Buffer to save log of function calls */
    vector<string> g_func_calls_log_buff;
    void init();

  public:
    void save_func_and_params(string /* p_func_call */);
    const vector<string>& get_xlib_calls_log();

    /* Virtualization functions */
    Display* virtual_to_real_display_pointer(Display* /* p_virt_dp */);
    Display* real_to_virtual_display_pointer(Display* /* p_real_dp */);
    Window virtual_to_real_window(Window /* p_virt_win */);
    Window real_to_virtual_window(Window /* p_real_win */);
    Drawable virtual_to_real_drawable(Drawable /* p_virt_drawable */);
    Colormap virtual_to_real_colormap(Colormap /* p_virt_cmp */);
    Colormap real_to_virtual_colormap(Colormap /* p_real_cmp */);
    Pixmap virtual_to_real_pixmap(Pixmap /* p_virt_pmp */);
    Pixmap real_to_virtual_pixmap(Pixmap /* p_real_pmp */);
    Cursor virtual_to_real_cursor(Cursor /* p_virt_cursor */);
    Cursor real_to_virtual_cursor(Cursor /* p_real_cursor */);
    XIM virtual_to_real_xim(XIM /* p_virt_xim */);
    XIM real_to_virtual_xim(XIM /* p_real_xim */);
    XImage* virtual_to_real_ximg(XImage* /* p_virt_ximg */);
    XImage* real_to_virtual_ximg(XImage* /* p_real_ximg */);
    GLXContext virtual_to_real_glxcontext(GLXContext /* p_virt_glxcontext */);
    GLXContext real_to_virtual_glxcontext(GLXContext /* p_real_glxcontext */);
    GLXDrawable virtual_to_real_glxdrawable(GLXDrawable /* p_virt_drawable */);
    GLXDrawable real_to_virtual_glxdrawable(GLXDrawable /* p_real_drawable */);
    GC virtual_to_real_gc(GC /* p_virt_gc */);

    /* Helper functions for wrappers */
    Display* save_display(Display* /* p_real_display */);
    Window save_window(Window /* p_real_window */);
    GC save_gc(GC /* p_real_gc */);
    Colormap save_colormap(Colormap /* p_real_cmp */);
    Pixmap save_pixmap(Pixmap /* p_real_pixmap */);
    Cursor save_cursor(Cursor /* p_real_cursor */);
    XIM save_xim(XIM /* p_real_xim */);
    XImage* save_ximg(XImage* /* p_real_ximg */);
    GLXContext save_glxctx(GLXContext /* p_real_glxctx */);
    int remove_display(Display* /* p_virt_display */);
    int remove_window(Window /* p_virt_window */);
    int remove_gc(GC /* p_virt_gc */);
    int remove_colormap(Colormap /* p_virt_colormap */);
    int remove_pixmap(Pixmap /* p_virt_pixmap */);
    int remove_cursor(Cursor /* p_virt_cursor */);
    int remove_xim(XIM /* p_virt_xim */);
    int remove_ximg(XImage* /* p_virt_ximg */);
    void update_display_mapping(Display* /* p_virt_dp */, Display* /* p_real_dp */);
    void update_window_mapping(Window /* p_virt_win */, Window /* p_real_win */);
    void update_gc_mapping(GC /* p_virt_gc */, GC /* p_real_gc */);

    void close_connection();

    /* Getters and Setters */
    void set_virtual_gc(GC /* p_virt_gc */);
    void set_real_gc(GC /* p_real_gc */);
};
typedef Singleton<XlibVirtualization> XlibVirt;

#endif
