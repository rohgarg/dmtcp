#include "xlib_plugin_glx_wrappers.h"

/* Auto generated code starts below */
XVisualInfo* glXChooseVisual( Display *dpy, int screen,int *attribList ) {
  DPRINTF("glXChooseVisual()\n");
  return _real_glXChooseVisual(dpy,screen,attribList);
}

GLXContext glXCreateContext( Display *dpy, XVisualInfo *vis,GLXContext shareList, Bool direct ) {
  DPRINTF("glXCreateContext()\n");
  return _real_glXCreateContext(dpy,vis,shareList,direct);
}

void glXDestroyContext( Display *dpy, GLXContext ctx ) {
  DPRINTF("glXDestroyContext()\n");
  _real_glXDestroyContext(dpy,ctx);
}

Bool glXMakeCurrent( Display *dpy, GLXDrawable drawable,GLXContext ctx) {
  DPRINTF("glXMakeCurrent()\n");
  return _real_glXMakeCurrent(dpy,drawable,ctx);
}

void glXCopyContext( Display *dpy, GLXContext src, GLXContext dst,unsigned long mask ) {
  DPRINTF("glXCopyContext()\n");
  _real_glXCopyContext(dpy,src,dst,mask);
}

void glXSwapBuffers( Display *dpy, GLXDrawable drawable ) {
  DPRINTF("glXSwapBuffers()\n");
  _real_glXSwapBuffers(dpy,drawable);
}

GLXPixmap glXCreateGLXPixmap( Display *dpy, XVisualInfo *visual,Pixmap pixmap ) {
  DPRINTF("glXCreateGLXPixmap()\n");
  return _real_glXCreateGLXPixmap(dpy,visual,pixmap);
}

void glXDestroyGLXPixmap( Display *dpy, GLXPixmap pixmap ) {
  DPRINTF("glXDestroyGLXPixmap()\n");
  _real_glXDestroyGLXPixmap(dpy,pixmap);
}

Bool glXQueryExtension( Display *dpy, int *errorb, int *event ) {
  DPRINTF("glXQueryExtension()\n");
  return _real_glXQueryExtension(dpy,errorb,event);
}

Bool glXQueryVersion( Display *dpy, int *maj, int *min ) {
  DPRINTF("glXQueryVersion()\n");
  return _real_glXQueryVersion(dpy,maj,min);
}

Bool glXIsDirect( Display *dpy, GLXContext ctx ) {
  DPRINTF("glXIsDirect()\n");
  return _real_glXIsDirect(dpy,ctx);
}

int glXGetConfig( Display *dpy, XVisualInfo *visual,int attrib, int *value ) {
  DPRINTF("glXGetConfig()\n");
  return _real_glXGetConfig(dpy,visual,attrib,value);
}

GLXContext glXGetCurrentContext( void ) {
  DPRINTF("glXGetCurrentContext()\n");
  return _real_glXGetCurrentContext();
}

GLXDrawable glXGetCurrentDrawable( void ) {
  DPRINTF("glXGetCurrentDrawable()\n");
  return _real_glXGetCurrentDrawable();
}

void glXWaitGL( void ) {
  DPRINTF("glXWaitGL()\n");
  _real_glXWaitGL();
}

void glXWaitX( void ) {
  DPRINTF("glXWaitX()\n");
  _real_glXWaitX();
}

void glXUseXFont( Font font, int first, int count, int list ) {
  DPRINTF("glXUseXFont()\n");
  _real_glXUseXFont(font,first,count,list);
}

const char *glXQueryExtensionsString( Display *dpy, int screen ) {
  DPRINTF("glXQueryExtensionsString()\n");
  return _real_glXQueryExtensionsString(dpy,screen);
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

GLXFBConfig *glXChooseFBConfig( Display *dpy, int screen,const int *attribList, int *nitems ) {
  DPRINTF("glXChooseFBConfig()\n");
  return _real_glXChooseFBConfig(dpy,screen,attribList,nitems);
}

int glXGetFBConfigAttrib( Display *dpy, GLXFBConfig config,int attribute, int *value ) {
  DPRINTF("glXGetFBConfigAttrib()\n");
  return _real_glXGetFBConfigAttrib(dpy,config,attribute,value);
}

GLXFBConfig *glXGetFBConfigs( Display *dpy, int screen,int *nelements ) {
  DPRINTF("glXGetFBConfigs()\n");
  return _real_glXGetFBConfigs(dpy,screen,nelements);
}

XVisualInfo *glXGetVisualFromFBConfig( Display *dpy,GLXFBConfig config ) {
  DPRINTF("glXGetVisualFromFBConfig()\n");
  return _real_glXGetVisualFromFBConfig(dpy,config);
}

GLXWindow glXCreateWindow( Display *dpy, GLXFBConfig config,Window win, const int *attribList ) {
  DPRINTF("glXCreateWindow()\n");
  return _real_glXCreateWindow(dpy,config,win,attribList);
}

void glXDestroyWindow( Display *dpy, GLXWindow window ) {
  DPRINTF("glXDestroyWindow()\n");
  _real_glXDestroyWindow(dpy,window);
}

GLXPixmap glXCreatePixmap( Display *dpy, GLXFBConfig config,Pixmap pixmap, const int *attribList ) {
  DPRINTF("glXCreatePixmap()\n");
  return _real_glXCreatePixmap(dpy,config,pixmap,attribList);
}

void glXDestroyPixmap( Display *dpy, GLXPixmap pixmap ) {
  DPRINTF("glXDestroyPixmap()\n");
  _real_glXDestroyPixmap(dpy,pixmap);
}

GLXPbuffer glXCreatePbuffer( Display *dpy, GLXFBConfig config,const int *attribList ) {
  DPRINTF("glXCreatePbuffer()\n");
  return _real_glXCreatePbuffer(dpy,config,attribList);
}

void glXDestroyPbuffer( Display *dpy, GLXPbuffer pbuf ) {
  DPRINTF("glXDestroyPbuffer()\n");
  _real_glXDestroyPbuffer(dpy,pbuf);
}

void glXQueryDrawable( Display *dpy, GLXDrawable draw, int attribute,unsigned int *value ) {
  DPRINTF("glXQueryDrawable()\n");
  _real_glXQueryDrawable(dpy,draw,attribute,value);
}

GLXContext glXCreateNewContext( Display *dpy, GLXFBConfig config,int renderType, GLXContext shareList,Bool direct ) {
  DPRINTF("glXCreateNewContext()\n");
  return _real_glXCreateNewContext(dpy,config,renderType,shareList,direct);
}

Bool glXMakeContextCurrent( Display *dpy, GLXDrawable draw,GLXDrawable read, GLXContext ctx ) {
  DPRINTF("glXMakeContextCurrent()\n");
  return _real_glXMakeContextCurrent(dpy,draw,read,ctx);
}

GLXDrawable glXGetCurrentReadDrawable( void ) {
  DPRINTF("glXGetCurrentReadDrawable()\n");
  return _real_glXGetCurrentReadDrawable();
}

int glXQueryContext( Display *dpy, GLXContext ctx, int attribute,int *value ) {
  DPRINTF("glXQueryContext()\n");
  return _real_glXQueryContext(dpy,ctx,attribute,value);
}

void glXSelectEvent( Display *dpy, GLXDrawable drawable,unsigned long mask ) {
  DPRINTF("glXSelectEvent()\n");
  _real_glXSelectEvent(dpy,drawable,mask);
}

void glXGetSelectedEvent( Display *dpy, GLXDrawable drawable,unsigned long *mask ) {
  DPRINTF("glXGetSelectedEvent()\n");
  _real_glXGetSelectedEvent(dpy,drawable,mask);
}

__GLXextFuncPtr glXGetProcAddressARB (const GLubyte *name) {
  DPRINTF("glXGetProcAddressARB(%s)\n", name);
  return _real_glXGetProcAddressARB(name);
}

void (*glXGetProcAddress(const GLubyte *procname))( void ) {
  DPRINTF("glXGetProcAddress(%s)\n", procname);
  return _real_glXGetProcAddress(procname);
}

void *glXAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) {
  DPRINTF("glXAllocateMemoryNV()\n");
  return _real_glXAllocateMemoryNV(size,readfreq,writefreq,priority);
}

void glXFreeMemoryNV(GLvoid *pointer) {
  DPRINTF("glXFreeMemoryNV()\n");
  _real_glXFreeMemoryNV(pointer);
}

Bool glXBindTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer) {
  DPRINTF("glXBindTexImageARB()\n");
  return _real_glXBindTexImageARB(dpy,pbuffer,buffer);
}

Bool glXReleaseTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer) {
  DPRINTF("glXReleaseTexImageARB()\n");
  return _real_glXReleaseTexImageARB(dpy,pbuffer,buffer);
}

Bool glXDrawableAttribARB(Display *dpy, GLXDrawable draw, const int *attribList) {
  DPRINTF("glXDrawableAttribARB()\n");
  return _real_glXDrawableAttribARB(dpy,draw,attribList);
}

int glXGetFrameUsageMESA(Display *dpy, GLXDrawable drawable, float *usage) {
  DPRINTF("glXGetFrameUsageMESA()\n");
  return _real_glXGetFrameUsageMESA(dpy,drawable,usage);
}

int glXBeginFrameTrackingMESA(Display *dpy, GLXDrawable drawable) {
  DPRINTF("glXBeginFrameTrackingMESA()\n");
  return _real_glXBeginFrameTrackingMESA(dpy,drawable);
}

int glXEndFrameTrackingMESA(Display *dpy, GLXDrawable drawable) {
  DPRINTF("glXEndFrameTrackingMESA()\n");
  return _real_glXEndFrameTrackingMESA(dpy,drawable);
}

int glXQueryFrameTrackingMESA(Display *dpy, GLXDrawable drawable, int64_t *swapCount, int64_t *missedFrames, float *lastMissedUsage) {
  DPRINTF("glXQueryFrameTrackingMESA()\n");
  return _real_glXQueryFrameTrackingMESA(dpy,drawable,swapCount,missedFrames,lastMissedUsage);
}

int glXSwapIntervalMESA(unsigned int interval) {
  DPRINTF("glXSwapIntervalMESA()\n");
  return _real_glXSwapIntervalMESA(interval);
}

int glXGetSwapIntervalMESA(void) {
  DPRINTF("glXGetSwapIntervalMESA()\n");
  return _real_glXGetSwapIntervalMESA();
}

void glXBindTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer, const int *attrib_list) {
  DPRINTF("glXBindTexImageEXT()\n");
  _real_glXBindTexImageEXT(dpy,drawable,buffer,attrib_list);
}

void glXReleaseTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer) {
  DPRINTF("glXReleaseTexImageEXT()\n");
  _real_glXReleaseTexImageEXT(dpy,drawable,buffer);
}
/* Auto generated code ends */
