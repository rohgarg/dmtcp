#include <sstream>
#include <cstring>
#include "xlib_plugin_glx_wrappers.h"
#include "xlib_plugin_virtualization.h"

/* Auto generated code starts below */
extern "C" XVisualInfo* glXChooseVisual (Display *dpy, int screen, int *attribList)
{
  DPRINTF("glXChooseVisual()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  /* TODO: Check if this needs to be replayed:
   *         - Do we need to save attribList (ends at None)
   *         - Do we need to save the return value
   */
  return _real_glXChooseVisual(l_real_dp, screen, attribList);
}

extern "C" GLXContext glXCreateContext (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct)
{
  DPRINTF("glXCreateContext()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  GLXContext l_real_shareList = XLIB_VIRT_CALL_FUNC.virtual_to_real_glxcontext(shareList);
  XVisualInfo *l_vis_buff = NULL;
  if (vis)
  {
    l_vis_buff = new XVisualInfo;
    memcpy(l_vis_buff, vis, sizeof(XVisualInfo));
  }
  std::ostringstream funcCall;
  funcCall << "glXCreateContext(" << (void*)dpy << "," << (void*)l_vis_buff << "," << shareList << "," << direct << ")";
  XLIB_VIRT_SAVE_FUNC_CALL(funcCall.str());
  GLXContext l_real_glxctx =  _real_glXCreateContext(l_real_dp,l_vis_buff,l_real_shareList,direct);
  return XLIB_VIRT_CALL_FUNC.save_glxctx(l_real_glxctx);
}

extern "C" void glXDestroyContext (Display *dpy, GLXContext ctx)
{
  DPRINTF("glXDestroyContext()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  GLXContext l_real_ctx = XLIB_VIRT_CALL_FUNC.virtual_to_real_glxcontext(ctx);
  std::ostringstream funcCall;
  funcCall << "glXDestroyContext(" << (void*)dpy << "," << ctx << ")";
  XLIB_VIRT_SAVE_FUNC_CALL(funcCall.str());
  _real_glXDestroyContext(l_real_dp,l_real_ctx);
}

extern "C" Bool glXMakeCurrent (Display *dpy, GLXDrawable drawable, GLXContext ctx)
{
  DPRINTF("glXMakeCurrent()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  GLXContext l_real_ctx = XLIB_VIRT_CALL_FUNC.virtual_to_real_glxcontext(ctx);
  GLXDrawable l_real_d = XLIB_VIRT_CALL_FUNC.virtual_to_real_glxdrawable(drawable);
  std::ostringstream funcCall;
  funcCall << "glXMakeCurrent(" << (void*)dpy << "," << drawable << "," << ctx << ")";
  XLIB_VIRT_SAVE_FUNC_CALL(funcCall.str());
  return _real_glXMakeCurrent(l_real_dp,l_real_d,l_real_ctx);
}

extern "C" void glXCopyContext( Display *dpy, GLXContext src, GLXContext dst,unsigned long mask ) {
  DPRINTF("glXCopyContext()\n");
  _real_glXCopyContext(dpy,src,dst,mask);
}

extern "C" void glXSwapBuffers (Display *dpy, GLXDrawable drawable)
{
  DPRINTF("glXSwapBuffers()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  GLXDrawable l_real_d = XLIB_VIRT_CALL_FUNC.virtual_to_real_glxdrawable(drawable);
  std::ostringstream funcCall;
  funcCall << "glXSwapBuffers(" << (void*)dpy << "," << drawable << ")";
  XLIB_VIRT_SAVE_FUNC_CALL(funcCall.str());
  _real_glXSwapBuffers(dpy,drawable);
}

extern "C" GLXPixmap glXCreateGLXPixmap( Display *dpy, XVisualInfo *visual,Pixmap pixmap ) {
  DPRINTF("glXCreateGLXPixmap()\n");
  return _real_glXCreateGLXPixmap(dpy,visual,pixmap);
}

extern "C" void glXDestroyGLXPixmap( Display *dpy, GLXPixmap pixmap ) {
  DPRINTF("glXDestroyGLXPixmap()\n");
  _real_glXDestroyGLXPixmap(dpy,pixmap);
}

extern "C" Bool glXQueryExtension( Display *dpy, int *errorb, int *event ) {
  DPRINTF("glXQueryExtension()\n");
  return _real_glXQueryExtension(dpy,errorb,event);
}

extern "C" Bool glXQueryVersion (Display *dpy, int *maj, int *min)
{
  DPRINTF("glXQueryVersion()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  return _real_glXQueryVersion(l_real_dp,maj,min);
}

extern "C" Bool glXIsDirect( Display *dpy, GLXContext ctx ) {
  DPRINTF("glXIsDirect()\n");
  return _real_glXIsDirect(dpy,ctx);
}

extern "C" int glXGetConfig( Display *dpy, XVisualInfo *visual,int attrib, int *value ) {
  DPRINTF("glXGetConfig()\n");
  return _real_glXGetConfig(dpy,visual,attrib,value);
}

extern "C" GLXContext glXGetCurrentContext( void ) {
  DPRINTF("glXGetCurrentContext()\n");
  return _real_glXGetCurrentContext();
}

extern "C" GLXDrawable glXGetCurrentDrawable( void ) {
  DPRINTF("glXGetCurrentDrawable()\n");
  return _real_glXGetCurrentDrawable();
}

extern "C" void glXWaitGL( void ) {
  DPRINTF("glXWaitGL()\n");
  _real_glXWaitGL();
}

extern "C" void glXWaitX( void ) {
  DPRINTF("glXWaitX()\n");
  _real_glXWaitX();
}

extern "C" void glXUseXFont( Font font, int first, int count, int list ) {
  DPRINTF("glXUseXFont()\n");
  _real_glXUseXFont(font,first,count,list);
}

const char *glXQueryExtensionsString (Display *dpy, int screen)
{
  DPRINTF("glXQueryExtensionsString()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  return _real_glXQueryExtensionsString(l_real_dp,screen);
}

const char *glXQueryServerString( Display *dpy, int screen, int name ) {
  DPRINTF("glXQueryServerString()\n");
  return _real_glXQueryServerString(dpy,screen,name);
}

const char *glXGetClientString( Display *dpy, int name ) {
  DPRINTF("glXGetClientString()\n");
  return _real_glXGetClientString(dpy,name);
}

Display *glXGetCurrentDisplay( void ) {
  DPRINTF("glXGetCurrentDisplay()\n");
  return _real_glXGetCurrentDisplay();
}

extern "C" GLXFBConfig *glXChooseFBConfig (Display *dpy, int screen, const int *attribList, int *nitems)
{
  DPRINTF("glXChooseFBConfig()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  return _real_glXChooseFBConfig(l_real_dp,screen,attribList,nitems);
}

extern "C" int glXGetFBConfigAttrib (Display *dpy, GLXFBConfig config, int attribute, int *value)
{
  DPRINTF("glXGetFBConfigAttrib()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  return _real_glXGetFBConfigAttrib(l_real_dp,config,attribute,value);
}

extern "C" GLXFBConfig *glXGetFBConfigs( Display *dpy, int screen,int *nelements ) {
  DPRINTF("glXGetFBConfigs()\n");
  return _real_glXGetFBConfigs(dpy,screen,nelements);
}

extern "C" XVisualInfo *glXGetVisualFromFBConfig (Display *dpy, GLXFBConfig config)
{
  DPRINTF("glXGetVisualFromFBConfig()\n");
  Display *l_real_dp = XLIB_VIRT_CALL_FUNC.virtual_to_real_display_pointer(dpy);
  return _real_glXGetVisualFromFBConfig(l_real_dp,config);
}

extern "C" GLXWindow glXCreateWindow( Display *dpy, GLXFBConfig config,Window win, const int *attribList ) {
  DPRINTF("glXCreateWindow()\n");
  return _real_glXCreateWindow(dpy,config,win,attribList);
}

extern "C" void glXDestroyWindow( Display *dpy, GLXWindow window ) {
  DPRINTF("glXDestroyWindow()\n");
  _real_glXDestroyWindow(dpy,window);
}

extern "C" GLXPixmap glXCreatePixmap( Display *dpy, GLXFBConfig config,Pixmap pixmap, const int *attribList ) {
  DPRINTF("glXCreatePixmap()\n");
  return _real_glXCreatePixmap(dpy,config,pixmap,attribList);
}

extern "C" void glXDestroyPixmap( Display *dpy, GLXPixmap pixmap ) {
  DPRINTF("glXDestroyPixmap()\n");
  _real_glXDestroyPixmap(dpy,pixmap);
}

extern "C" GLXPbuffer glXCreatePbuffer( Display *dpy, GLXFBConfig config,const int *attribList ) {
  DPRINTF("glXCreatePbuffer()\n");
  return _real_glXCreatePbuffer(dpy,config,attribList);
}

extern "C" void glXDestroyPbuffer( Display *dpy, GLXPbuffer pbuf ) {
  DPRINTF("glXDestroyPbuffer()\n");
  _real_glXDestroyPbuffer(dpy,pbuf);
}

extern "C" void glXQueryDrawable( Display *dpy, GLXDrawable draw, int attribute,unsigned int *value ) {
  DPRINTF("glXQueryDrawable()\n");
  _real_glXQueryDrawable(dpy,draw,attribute,value);
}

extern "C" GLXContext glXCreateNewContext( Display *dpy, GLXFBConfig config,int renderType, GLXContext shareList,Bool direct ) {
  DPRINTF("glXCreateNewContext()\n");
  return _real_glXCreateNewContext(dpy,config,renderType,shareList,direct);
}

extern "C" Bool glXMakeContextCurrent( Display *dpy, GLXDrawable draw,GLXDrawable read, GLXContext ctx ) {
  DPRINTF("glXMakeContextCurrent()\n");
  return _real_glXMakeContextCurrent(dpy,draw,read,ctx);
}

extern "C" GLXDrawable glXGetCurrentReadDrawable( void ) {
  DPRINTF("glXGetCurrentReadDrawable()\n");
  return _real_glXGetCurrentReadDrawable();
}

extern "C" int glXQueryContext( Display *dpy, GLXContext ctx, int attribute,int *value ) {
  DPRINTF("glXQueryContext()\n");
  return _real_glXQueryContext(dpy,ctx,attribute,value);
}

extern "C" void glXSelectEvent( Display *dpy, GLXDrawable drawable,unsigned long mask ) {
  DPRINTF("glXSelectEvent()\n");
  _real_glXSelectEvent(dpy,drawable,mask);
}

extern "C" void glXGetSelectedEvent( Display *dpy, GLXDrawable drawable,unsigned long *mask ) {
  DPRINTF("glXGetSelectedEvent()\n");
  _real_glXGetSelectedEvent(dpy,drawable,mask);
}

__GLXextFuncPtr glXGetProcAddressARB (const GLubyte *name) {
  DPRINTF("glXGetProcAddressARB(%s)\n", name);
  return _real_glXGetProcAddressARB(name);
}

extern "C" void (*glXGetProcAddress(const GLubyte *procname))( void ) {
  DPRINTF("glXGetProcAddress(%s)\n", procname);
  return _real_glXGetProcAddress(procname);
}

extern "C" void *glXAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) {
  DPRINTF("glXAllocateMemoryNV()\n");
  return _real_glXAllocateMemoryNV(size,readfreq,writefreq,priority);
}

extern "C" void glXFreeMemoryNV(GLvoid *pointer) {
  DPRINTF("glXFreeMemoryNV()\n");
  _real_glXFreeMemoryNV(pointer);
}

extern "C" Bool glXBindTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer) {
  DPRINTF("glXBindTexImageARB()\n");
  return _real_glXBindTexImageARB(dpy,pbuffer,buffer);
}

extern "C" Bool glXReleaseTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer) {
  DPRINTF("glXReleaseTexImageARB()\n");
  return _real_glXReleaseTexImageARB(dpy,pbuffer,buffer);
}

extern "C" Bool glXDrawableAttribARB(Display *dpy, GLXDrawable draw, const int *attribList) {
  DPRINTF("glXDrawableAttribARB()\n");
  return _real_glXDrawableAttribARB(dpy,draw,attribList);
}

extern "C" int glXGetFrameUsageMESA(Display *dpy, GLXDrawable drawable, float *usage) {
  DPRINTF("glXGetFrameUsageMESA()\n");
  return _real_glXGetFrameUsageMESA(dpy,drawable,usage);
}

extern "C" int glXBeginFrameTrackingMESA(Display *dpy, GLXDrawable drawable) {
  DPRINTF("glXBeginFrameTrackingMESA()\n");
  return _real_glXBeginFrameTrackingMESA(dpy,drawable);
}

extern "C" int glXEndFrameTrackingMESA(Display *dpy, GLXDrawable drawable) {
  DPRINTF("glXEndFrameTrackingMESA()\n");
  return _real_glXEndFrameTrackingMESA(dpy,drawable);
}

extern "C" int glXQueryFrameTrackingMESA(Display *dpy, GLXDrawable drawable, int64_t *swapCount, int64_t *missedFrames, float *lastMissedUsage) {
  DPRINTF("glXQueryFrameTrackingMESA()\n");
  return _real_glXQueryFrameTrackingMESA(dpy,drawable,swapCount,missedFrames,lastMissedUsage);
}

extern "C" int glXSwapIntervalMESA(unsigned int interval) {
  DPRINTF("glXSwapIntervalMESA()\n");
  return _real_glXSwapIntervalMESA(interval);
}

extern "C" int glXGetSwapIntervalMESA(void) {
  DPRINTF("glXGetSwapIntervalMESA()\n");
  return _real_glXGetSwapIntervalMESA();
}

extern "C" void glXBindTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer, const int *attrib_list) {
  DPRINTF("glXBindTexImageEXT()\n");
  _real_glXBindTexImageEXT(dpy,drawable,buffer,attrib_list);
}

extern "C" void glXReleaseTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer) {
  DPRINTF("glXReleaseTexImageEXT()\n");
  _real_glXReleaseTexImageEXT(dpy,drawable,buffer);
}
/* Auto generated code ends */
