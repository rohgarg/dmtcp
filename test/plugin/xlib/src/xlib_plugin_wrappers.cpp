#include "xlib_plugin_wrappers.h"
#include "xlib_plugin_virtualization.h"

#define VIRTUALIZE 0

/* This is just a place-holder; the real purpose is for the python script to
 * generate code to virtualize different ids*/
#if VIRTUALIZE
 virtualization_func=virtual_to_real_display_pointer;
 virtualization_id=Display*;
 virtualization_func=virtual_to_real_window;
 virtualization_id=Window;
 virtualization_func=virtual_to_real_gc;
 virtualization_id=GC;
#endif
/* Auto generated code starts below */
extern "C" XFontStruct *XLoadQueryFont(Display* display ,_Xconst char* name ) {
  DPRINTF("XLoadQueryFont()\n");
  return _real_XLoadQueryFont(display,name);
}

extern "C" XFontStruct *XQueryFont(Display* display ,XID font_ID ) {
  DPRINTF("XQueryFont()\n");
  return _real_XQueryFont(display,font_ID);
}

extern "C" XTimeCoord *XGetMotionEvents(Display* display ,Window w ,Time start ,Time stop ,int* nevents_return ) {
  DPRINTF("XGetMotionEvents()\n");
  return _real_XGetMotionEvents(display,w,start,stop,nevents_return);
}

extern "C" XModifierKeymap *XDeleteModifiermapEntry(XModifierKeymap* modmap ,
#if NeedWidePrototypes
    unsigned int keycode_entry ,
#else
    KeyCode keycode_entry ,
#endif
    int modifier ) {
  DPRINTF("XDeleteModifiermapEntry()\n");
  return _real_XDeleteModifiermapEntry(modmap,keycode_entry,modifier);
}

extern "C" XModifierKeymap	*XGetModifierMapping(Display* display ) {
  DPRINTF("XGetModifierMapping()\n");
  return _real_XGetModifierMapping(display);
}

extern "C" XModifierKeymap	*XInsertModifiermapEntry(XModifierKeymap* modmap ,
#if NeedWidePrototypes
    unsigned int keycode_entry ,
#else
    KeyCode keycode_entry ,
#endif
    int modifier ) {
  DPRINTF("XInsertModifiermapEntry()\n");
  return _real_XInsertModifiermapEntry(modmap,keycode_entry,modifier);
}

extern "C" XModifierKeymap *XNewModifiermap(int max_keys_per_mod ) {
  DPRINTF("XNewModifiermap()\n");
  return _real_XNewModifiermap(max_keys_per_mod);
}

extern "C" XImage *XCreateImage(Display* display ,Visual* visual ,unsigned int depth ,int format ,int offset ,char* data ,unsigned int width ,unsigned int height ,int bitmap_pad ,int bytes_per_line ) {
  DPRINTF("XCreateImage()\n");
  return _real_XCreateImage(display,visual,depth,format,offset,data,width,height,bitmap_pad,bytes_per_line);
}

extern "C" Status XInitImage(XImage* image ) {
  DPRINTF("XInitImage()\n");
  return _real_XInitImage(image);
}

extern "C" XImage *XGetImage(Display* display ,Drawable d ,int x ,int y ,unsigned int width ,unsigned int height ,unsigned long plane_mask ,int format ) {
  DPRINTF("XGetImage()\n");
  return _real_XGetImage(display,d,x,y,width,height,plane_mask,format);
}

extern "C" XImage *XGetSubImage(Display* display ,Drawable d ,int x ,int y ,unsigned int width ,unsigned int height ,unsigned long plane_mask ,int format ,XImage* dest_image ,int dest_x ,int dest_y ) {
  DPRINTF("XGetSubImage()\n");
  return _real_XGetSubImage(display,d,x,y,width,height,plane_mask,format,dest_image,dest_x,dest_y);
}

extern "C" Display *XOpenDisplay(_Xconst char* display_name ) {
  DPRINTF("XOpenDisplay()\n");
  Display *dp =  _real_XOpenDisplay(display_name);
  XLIB_VIRT_CALL_FUNC.save_display(dp);
  XLIB_VIRT_SAVE_FUNC_CALL("XOpenDisplay()");
  return XLIB_VIRT_CALL_FUNC.get_virtual_dp();
}

extern "C" void XrmInitialize(void) {
  DPRINTF("XrmInitialize()\n");
  _real_XrmInitialize();
}

extern "C" char *XFetchBytes(Display* display ,int* nbytes_return ) {
  DPRINTF("XFetchBytes()\n");
  return _real_XFetchBytes(display,nbytes_return);
}

extern "C" char *XFetchBuffer(Display* display ,int* nbytes_return ,int buffer ) {
  DPRINTF("XFetchBuffer()\n");
  return _real_XFetchBuffer(display,nbytes_return,buffer);
}

extern "C" char *XGetAtomName(Display* display ,Atom atom ) {
  DPRINTF("XGetAtomName()\n");
  return _real_XGetAtomName(display,atom);
}

extern "C" Status XGetAtomNames(Display* dpy ,Atom* atoms ,int count ,char** names_return ) {
  DPRINTF("XGetAtomNames()\n");
  return _real_XGetAtomNames(dpy,atoms,count,names_return);
}

extern "C" char *XGetDefault(Display* display ,_Xconst char* program ,_Xconst char* option ) {
  DPRINTF("XGetDefault()\n");
  return _real_XGetDefault(display,program,option);
}

extern "C" char *XDisplayName(_Xconst char* string ) {
  DPRINTF("XDisplayName()\n");
  return _real_XDisplayName(string);
}

extern "C" char *XKeysymToString(KeySym keysym ) {
  DPRINTF("XKeysymToString()\n");
  return _real_XKeysymToString(keysym);
}

/*
extern "C" int (*XSynchronize(Display* display ,Bool onoff ))(Display* display ) {
  DPRINTF("()\n");
  return _real_();
}
*/

/*
extern "C" int (*XSetAfterFunction(Display* display ,int (*) (Display* display ) procedure ))(Display* display ) {
  DPRINTF("()\n");
  return _real_();
}
*/

extern "C" Atom XInternAtom(Display* display ,_Xconst char* atom_name ,Bool only_if_exists ) {
  DPRINTF("XInternAtom()\n");
  return _real_XInternAtom(display,atom_name,only_if_exists);
}

extern "C" Status XInternAtoms(Display* dpy ,char** names ,int count ,Bool onlyIfExists ,Atom* atoms_return ) {
  DPRINTF("XInternAtoms()\n");
  return _real_XInternAtoms(dpy,names,count,onlyIfExists,atoms_return);
}

extern "C" Colormap XCopyColormapAndFree(Display* display ,Colormap colormap ) {
  DPRINTF("XCopyColormapAndFree()\n");
  return _real_XCopyColormapAndFree(display,colormap);
}

extern "C" Colormap XCreateColormap(Display* display ,Window w ,Visual* visual ,int alloc ) {
  DPRINTF("XCreateColormap()\n");
  return _real_XCreateColormap(display,w,visual,alloc);
}

extern "C" Cursor XCreatePixmapCursor(Display* display ,Pixmap source ,Pixmap mask ,XColor* foreground_color ,XColor* background_color ,unsigned int x ,unsigned int y ) {
  DPRINTF("XCreatePixmapCursor()\n");
  return _real_XCreatePixmapCursor(display,source,mask,foreground_color,background_color,x,y);
}

extern "C" Cursor XCreateGlyphCursor(Display* display ,Font source_font ,Font mask_font ,unsigned int source_char ,unsigned int mask_char ,XColor _Xconst * foreground_color ,XColor _Xconst * background_color ) {
  DPRINTF("XCreateGlyphCursor()\n");
  return _real_XCreateGlyphCursor(display,source_font,mask_font,source_char,mask_char,foreground_color,background_color);
}

extern "C" Cursor XCreateFontCursor(Display* display ,unsigned int shape ) {
  DPRINTF("XCreateFontCursor()\n");
  return _real_XCreateFontCursor(display,shape);
}

extern "C" Font XLoadFont(Display* display ,_Xconst char* name ) {
  DPRINTF("XLoadFont()\n");
  return _real_XLoadFont(display,name);
}

extern "C" GC XCreateGC(Display* display ,Drawable d ,unsigned long valuemask ,XGCValues* values ) {
  DPRINTF("XCreateGC()\n");
  return _real_XCreateGC(display,d,valuemask,values);
}

extern "C" GContext XGContextFromGC(GC gc ) {
  DPRINTF("XGContextFromGC()\n");
  return _real_XGContextFromGC(gc);
}

extern "C" void XFlushGC(Display* display ,GC gc ) {
  DPRINTF("XFlushGC()\n");
  _real_XFlushGC(display,gc);
}

extern "C" Pixmap XCreatePixmap(Display* display ,Drawable d ,unsigned int width ,unsigned int height ,unsigned int depth ) {
  DPRINTF("XCreatePixmap()\n");
  return _real_XCreatePixmap(display,d,width,height,depth);
}

extern "C" Pixmap XCreateBitmapFromData(Display* display ,Drawable d ,_Xconst char* data ,unsigned int width ,unsigned int height ) {
  DPRINTF("XCreateBitmapFromData()\n");
  return _real_XCreateBitmapFromData(display,d,data,width,height);
}

extern "C" Pixmap XCreatePixmapFromBitmapData(Display* display ,Drawable d ,char* data ,unsigned int width ,unsigned int height ,unsigned long fg ,unsigned long bg ,unsigned int depth ) {
  DPRINTF("XCreatePixmapFromBitmapData()\n");
  return _real_XCreatePixmapFromBitmapData(display,d,data,width,height,fg,bg,depth);
}

extern "C" Window XCreateSimpleWindow(Display* display ,Window parent ,int x ,int y ,unsigned int width ,unsigned int height ,unsigned int border_width ,unsigned long border ,unsigned long background ) {
  DPRINTF("XCreateSimpleWindow()\n");
  Window win =  _real_XCreateSimpleWindow(display,parent,x,y,width,height,border_width,border,background);
  return win;
}

extern "C" Window XGetSelectionOwner(Display* display ,Atom selection ) {
  DPRINTF("XGetSelectionOwner()\n");
  return _real_XGetSelectionOwner(display,selection);
}

extern "C" Window XCreateWindow(Display* display ,Window parent ,int x ,int y ,unsigned int width ,unsigned int height ,unsigned int border_width ,int depth ,unsigned int cl ,Visual* visual ,unsigned long valuemask ,XSetWindowAttributes* attributes ) {
  DPRINTF("XCreateWindow()\n");
  return _real_XCreateWindow(display,parent,x,y,width,height,border_width,depth,cl,visual,valuemask,attributes);
}

extern "C" Colormap *XListInstalledColormaps(Display* display ,Window w ,int* num_return ) {
  DPRINTF("XListInstalledColormaps()\n");
  return _real_XListInstalledColormaps(display,w,num_return);
}

extern "C" char **XListFonts(Display* display ,_Xconst char* pattern ,int maxnames ,int* actual_count_return ) {
  DPRINTF("XListFonts()\n");
  return _real_XListFonts(display,pattern,maxnames,actual_count_return);
}

extern "C" char **XListFontsWithInfo(Display* display ,_Xconst char* pattern ,int maxnames ,int* count_return ,XFontStruct** info_return ) {
  DPRINTF("XListFontsWithInfo()\n");
  return _real_XListFontsWithInfo(display,pattern,maxnames,count_return,info_return);
}

extern "C" char **XGetFontPath(Display* display ,int* npaths_return ) {
  DPRINTF("XGetFontPath()\n");
  return _real_XGetFontPath(display,npaths_return);
}

extern "C" char **XListExtensions(Display* display ,int* nextensions_return ) {
  DPRINTF("XListExtensions()\n");
  return _real_XListExtensions(display,nextensions_return);
}

extern "C" Atom *XListProperties(Display* display ,Window w ,int* num_prop_return ) {
  DPRINTF("XListProperties()\n");
  return _real_XListProperties(display,w,num_prop_return);
}

extern "C" XHostAddress *XListHosts(Display* display ,int* nhosts_return ,Bool* state_return ) {
  DPRINTF("XListHosts()\n");
  return _real_XListHosts(display,nhosts_return,state_return);
}

extern "C" KeySym XKeycodeToKeysym(Display* display ,
#if NeedWidePrototypes
unsigned int keycode ,
#else
KeyCode keycode ,
#endif
int index ) {
  DPRINTF("XKeycodeToKeysym()\n");
  return _real_XKeycodeToKeysym(display,keycode,index);
}

extern "C" KeySym XLookupKeysym(XKeyEvent* key_event ,int index ) {
  DPRINTF("XLookupKeysym()\n");
  return _real_XLookupKeysym(key_event,index);
}

extern "C" KeySym *XGetKeyboardMapping(Display* display ,
#if NeedWidePrototypes
unsigned int first_keycode ,
#else
KeyCode first_keycode ,
#endif
int keycode_count ,int* keysyms_per_keycode_return ) {
  DPRINTF("XGetKeyboardMapping()\n");
  return _real_XGetKeyboardMapping(display,first_keycode,keycode_count,keysyms_per_keycode_return);
}

extern "C" KeySym XStringToKeysym(_Xconst char* string ) {
  DPRINTF("XStringToKeysym()\n");
  return _real_XStringToKeysym(string);
}

extern "C" long XMaxRequestSize(Display* display ) {
  DPRINTF("XMaxRequestSize()\n");
  return _real_XMaxRequestSize(display);
}

extern "C" long XExtendedMaxRequestSize(Display* display ) {
  DPRINTF("XExtendedMaxRequestSize()\n");
  return _real_XExtendedMaxRequestSize(display);
}

extern "C" char *XResourceManagerString(Display* display ) {
  DPRINTF("XResourceManagerString()\n");
  return _real_XResourceManagerString(display);
}

extern "C" char *XScreenResourceString(Screen* screen ) {
  DPRINTF("XScreenResourceString()\n");
  return _real_XScreenResourceString(screen);
}

extern "C" unsigned long XDisplayMotionBufferSize(Display* display ) {
  DPRINTF("XDisplayMotionBufferSize()\n");
  return _real_XDisplayMotionBufferSize(display);
}

extern "C" VisualID XVisualIDFromVisual(Visual* visual ) {
  DPRINTF("XVisualIDFromVisual()\n");
  return _real_XVisualIDFromVisual(visual);
}

extern "C" Status XInitThreads(void) {
  DPRINTF("XInitThreads()\n");
  return _real_XInitThreads();
}

extern "C" void XLockDisplay(Display* display ) {
  DPRINTF("XLockDisplay()\n");
  _real_XLockDisplay(display);
}

extern "C" void XUnlockDisplay(Display* display ) {
  DPRINTF("XUnlockDisplay()\n");
  _real_XUnlockDisplay(display);
}

extern "C" XExtCodes *XInitExtension(Display* display ,_Xconst char* name ) {
  DPRINTF("XInitExtension()\n");
  return _real_XInitExtension(display,name);
}

extern "C" XExtCodes *XAddExtension(Display* display ) {
  DPRINTF("XAddExtension()\n");
  return _real_XAddExtension(display);
}

extern "C" XExtData *XFindOnExtensionList(XExtData** structure ,int number ) {
  DPRINTF("XFindOnExtensionList()\n");
  return _real_XFindOnExtensionList(structure,number);
}

extern "C" XExtData **XEHeadOfExtensionList(XEDataObject object ) {
  DPRINTF("XEHeadOfExtensionList()\n");
  return _real_XEHeadOfExtensionList(object);
}

extern "C" Window XRootWindow(Display* display ,int screen_number ) {
  DPRINTF("XRootWindow()\n");
  return _real_XRootWindow(display,screen_number);
}

extern "C" Window XDefaultRootWindow(Display* display ) {
  DPRINTF("XDefaultRootWindow()\n");
  return _real_XDefaultRootWindow(display);
}

extern "C" Window XRootWindowOfScreen(Screen* screen ) {
  DPRINTF("XRootWindowOfScreen()\n");
  return _real_XRootWindowOfScreen(screen);
}

extern "C" Visual *XDefaultVisual(Display* display ,int screen_number ) {
  DPRINTF("XDefaultVisual()\n");
  return _real_XDefaultVisual(display,screen_number);
}

extern "C" Visual *XDefaultVisualOfScreen(Screen* screen ) {
  DPRINTF("XDefaultVisualOfScreen()\n");
  return _real_XDefaultVisualOfScreen(screen);
}

extern "C" GC XDefaultGC(Display* display ,int screen_number ) {
  DPRINTF("XDefaultGC()\n");
  return _real_XDefaultGC(display,screen_number);
}

extern "C" GC XDefaultGCOfScreen(Screen* screen ) {
  DPRINTF("XDefaultGCOfScreen()\n");
  return _real_XDefaultGCOfScreen(screen);
}

extern "C" unsigned long XBlackPixel(Display* display ,int screen_number ) {
  DPRINTF("XBlackPixel()\n");
  return _real_XBlackPixel(display,screen_number);
}

extern "C" unsigned long XWhitePixel(Display* display ,int screen_number ) {
  DPRINTF("XWhitePixel()\n");
  return _real_XWhitePixel(display,screen_number);
}

extern "C" unsigned long XAllPlanes(void) {
  DPRINTF("XAllPlanes()\n");
  return _real_XAllPlanes();
}

extern "C" unsigned long XBlackPixelOfScreen(Screen* screen ) {
  DPRINTF("XBlackPixelOfScreen()\n");
  return _real_XBlackPixelOfScreen(screen);
}

extern "C" unsigned long XWhitePixelOfScreen(Screen* screen ) {
  DPRINTF("XWhitePixelOfScreen()\n");
  return _real_XWhitePixelOfScreen(screen);
}

extern "C" unsigned long XNextRequest(Display* display ) {
  DPRINTF("XNextRequest()\n");
  return _real_XNextRequest(display);
}

extern "C" unsigned long XLastKnownRequestProcessed(Display* display ) {
  DPRINTF("XLastKnownRequestProcessed()\n");
  return _real_XLastKnownRequestProcessed(display);
}

extern "C" char *XServerVendor(Display* display ) {
  DPRINTF("XServerVendor()\n");
  return _real_XServerVendor(display);
}

extern "C" char *XDisplayString(Display* display ) {
  DPRINTF("XDisplayString()\n");
  return _real_XDisplayString(display);
}

extern "C" Colormap XDefaultColormap(Display* display ,int screen_number ) {
  DPRINTF("XDefaultColormap()\n");
  return _real_XDefaultColormap(display,screen_number);
}

extern "C" Colormap XDefaultColormapOfScreen(Screen* screen ) {
  DPRINTF("XDefaultColormapOfScreen()\n");
  return _real_XDefaultColormapOfScreen(screen);
}

extern "C" Display *XDisplayOfScreen(Screen* screen ) {
  DPRINTF("XDisplayOfScreen()\n");
  return _real_XDisplayOfScreen(screen);
}

extern "C" Screen *XScreenOfDisplay(Display* display ,int screen_number ) {
  DPRINTF("XScreenOfDisplay()\n");
  return _real_XScreenOfDisplay(display,screen_number);
}

extern "C" Screen *XDefaultScreenOfDisplay(Display* display ) {
  DPRINTF("XDefaultScreenOfDisplay()\n");
  return _real_XDefaultScreenOfDisplay(display);
}

extern "C" long XEventMaskOfScreen(Screen* screen ) {
  DPRINTF("XEventMaskOfScreen()\n");
  return _real_XEventMaskOfScreen(screen);
}

extern "C" int XScreenNumberOfScreen(Screen* screen ) {
  DPRINTF("XScreenNumberOfScreen()\n");
  return _real_XScreenNumberOfScreen(screen);
}

extern "C" XErrorHandler XSetErrorHandler (XErrorHandler handler ) {
  DPRINTF("XSetErrorHandler()\n");
  return _real_XSetErrorHandler(handler);
}

extern "C" XIOErrorHandler XSetIOErrorHandler (XIOErrorHandler handler ) {
  DPRINTF("XSetIOErrorHandler()\n");
  return _real_XSetIOErrorHandler(handler);
}

extern "C" XPixmapFormatValues *XListPixmapFormats(Display* display ,int* count_return ) {
  DPRINTF("XListPixmapFormats()\n");
  return _real_XListPixmapFormats(display,count_return);
}

extern "C" int *XListDepths(Display* display ,int screen_number ,int* count_return ) {
  DPRINTF("XListDepths()\n");
  return _real_XListDepths(display,screen_number,count_return);
}

extern "C" Status XReconfigureWMWindow(Display* display ,Window w ,int screen_number ,unsigned int mask ,XWindowChanges* changes ) {
  DPRINTF("XReconfigureWMWindow()\n");
  return _real_XReconfigureWMWindow(display,w,screen_number,mask,changes);
}

extern "C" Status XGetWMProtocols(Display* display ,Window w ,Atom** protocols_return ,int* count_return ) {
  DPRINTF("XGetWMProtocols()\n");
  return _real_XGetWMProtocols(display,w,protocols_return,count_return);
}

extern "C" Status XSetWMProtocols(Display* display ,Window w ,Atom* protocols ,int count ) {
  DPRINTF("XSetWMProtocols()\n");
  return _real_XSetWMProtocols(display,w,protocols,count);
}

extern "C" Status XIconifyWindow(Display* display ,Window w ,int screen_number ) {
  DPRINTF("XIconifyWindow()\n");
  return _real_XIconifyWindow(display,w,screen_number);
}

extern "C" Status XWithdrawWindow(Display* display ,Window w ,int screen_number ) {
  DPRINTF("XWithdrawWindow()\n");
  return _real_XWithdrawWindow(display,w,screen_number);
}

extern "C" Status XGetCommand(Display* display ,Window w ,char*** argv_return ,int* argc_return ) {
  DPRINTF("XGetCommand()\n");
  return _real_XGetCommand(display,w,argv_return,argc_return);
}

extern "C" Status XGetWMColormapWindows(Display* display ,Window w ,Window** windows_return ,int* count_return ) {
  DPRINTF("XGetWMColormapWindows()\n");
  return _real_XGetWMColormapWindows(display,w,windows_return,count_return);
}

extern "C" Status XSetWMColormapWindows(Display* display ,Window w ,Window* colormap_windows ,int count ) {
  DPRINTF("XSetWMColormapWindows()\n");
  return _real_XSetWMColormapWindows(display,w,colormap_windows,count);
}

extern "C" void XFreeStringList(char** list ) {
  DPRINTF("XFreeStringList()\n");
  _real_XFreeStringList(list);
}

extern "C" int XSetTransientForHint(Display* display ,Window w ,Window prop_window ) {
  DPRINTF("XSetTransientForHint()\n");
  return _real_XSetTransientForHint(display,w,prop_window);
}

extern "C" int XActivateScreenSaver(Display* display ) {
  DPRINTF("XActivateScreenSaver()\n");
  return _real_XActivateScreenSaver(display);
}

extern "C" int XAddHost(Display* display ,XHostAddress* host ) {
  DPRINTF("XAddHost()\n");
  return _real_XAddHost(display,host);
}

extern "C" int XAddHosts(Display* display ,XHostAddress* hosts ,int num_hosts ) {
  DPRINTF("XAddHosts()\n");
  return _real_XAddHosts(display,hosts,num_hosts);
}

extern "C" int XAddToExtensionList(struct _XExtData** structure ,XExtData* ext_data ) {
  DPRINTF("XAddToExtensionList()\n");
  return _real_XAddToExtensionList(structure,ext_data);
}

extern "C" int XAddToSaveSet(Display* display ,Window w ) {
  DPRINTF("XAddToSaveSet()\n");
  return _real_XAddToSaveSet(display,w);
}

extern "C" Status XAllocColor(Display* display ,Colormap colormap ,XColor* screen_in_out ) {
  DPRINTF("XAllocColor()\n");
  return _real_XAllocColor(display,colormap,screen_in_out);
}

extern "C" Status XAllocColorCells(Display* display ,Colormap colormap ,Bool contig ,unsigned long* plane_masks_return ,unsigned int nplanes ,unsigned long* pixels_return ,unsigned int npixels ) {
  DPRINTF("XAllocColorCells()\n");
  return _real_XAllocColorCells(display,colormap,contig,plane_masks_return,nplanes,pixels_return,npixels);
}

extern "C" Status XAllocColorPlanes(Display* display ,Colormap colormap ,Bool contig ,unsigned long* pixels_return ,int ncolors ,int nreds ,int ngreens ,int nblues ,unsigned long* rmask_return ,unsigned long* gmask_return ,unsigned long* bmask_return ) {
  DPRINTF("XAllocColorPlanes()\n");
  return _real_XAllocColorPlanes(display,colormap,contig,pixels_return,ncolors,nreds,ngreens,nblues,rmask_return,gmask_return,bmask_return);
}

extern "C" Status XAllocNamedColor(Display* display ,Colormap colormap ,_Xconst char* color_name ,XColor* screen_def_return ,XColor* exact_def_return ) {
  DPRINTF("XAllocNamedColor()\n");
  return _real_XAllocNamedColor(display,colormap,color_name,screen_def_return,exact_def_return);
}

extern "C" int XAllowEvents(Display* display ,int event_mode ,Time time ) {
  DPRINTF("XAllowEvents()\n");
  return _real_XAllowEvents(display,event_mode,time);
}

extern "C" int XAutoRepeatOff(Display* display ) {
  DPRINTF("XAutoRepeatOff()\n");
  return _real_XAutoRepeatOff(display);
}

extern "C" int XAutoRepeatOn(Display* display ) {
  DPRINTF("XAutoRepeatOn()\n");
  return _real_XAutoRepeatOn(display);
}

extern "C" int XBell(Display* display ,int percent ) {
  DPRINTF("XBell()\n");
  return _real_XBell(display,percent);
}

extern "C" int XBitmapBitOrder(Display* display ) {
  DPRINTF("XBitmapBitOrder()\n");
  return _real_XBitmapBitOrder(display);
}

extern "C" int XBitmapPad(Display* display ) {
  DPRINTF("XBitmapPad()\n");
  return _real_XBitmapPad(display);
}

extern "C" int XBitmapUnit(Display* display ) {
  DPRINTF("XBitmapUnit()\n");
  return _real_XBitmapUnit(display);
}

extern "C" int XCellsOfScreen(Screen* screen ) {
  DPRINTF("XCellsOfScreen()\n");
  return _real_XCellsOfScreen(screen);
}

extern "C" int XChangeActivePointerGrab(Display* display ,unsigned int event_mask ,Cursor cursor ,Time time ) {
  DPRINTF("XChangeActivePointerGrab()\n");
  return _real_XChangeActivePointerGrab(display,event_mask,cursor,time);
}

extern "C" int XChangeGC(Display* display ,GC gc ,unsigned long valuemask ,XGCValues* values ) {
  DPRINTF("XChangeGC()\n");
  return _real_XChangeGC(display,gc,valuemask,values);
}

extern "C" int XChangeKeyboardControl(Display* display ,unsigned long value_mask ,XKeyboardControl* values ) {
  DPRINTF("XChangeKeyboardControl()\n");
  return _real_XChangeKeyboardControl(display,value_mask,values);
}

extern "C" int XChangeKeyboardMapping(Display* display ,int first_keycode ,int keysyms_per_keycode ,KeySym* keysyms ,int num_codes ) {
  DPRINTF("XChangeKeyboardMapping()\n");
  return _real_XChangeKeyboardMapping(display,first_keycode,keysyms_per_keycode,keysyms,num_codes);
}

extern "C" int XChangePointerControl(Display* display ,Bool do_accel ,Bool do_threshold ,int accel_numerator ,int accel_denominator ,int threshold ) {
  DPRINTF("XChangePointerControl()\n");
  return _real_XChangePointerControl(display,do_accel,do_threshold,accel_numerator,accel_denominator,threshold);
}

extern "C" int XChangeProperty(Display* display ,Window w ,Atom property ,Atom type ,int format ,int mode ,_Xconst unsigned char* data ,int nelements ) {
  DPRINTF("XChangeProperty()\n");
  return _real_XChangeProperty(display,w,property,type,format,mode,data,nelements);
}

extern "C" int XChangeSaveSet(Display* display ,Window w ,int change_mode ) {
  DPRINTF("XChangeSaveSet()\n");
  return _real_XChangeSaveSet(display,w,change_mode);
}

extern "C" int XChangeWindowAttributes(Display* display ,Window w ,unsigned long valuemask ,XSetWindowAttributes* attributes ) {
  DPRINTF("XChangeWindowAttributes()\n");
  return _real_XChangeWindowAttributes(display,w,valuemask,attributes);
}

/*
extern "C" Bool XCheckIfEvent(Display* display ,XEvent* event_return ,Bool (*) (Display* display ,XEvent* event ,XPointer arg ) predicate ,XPointer arg ) {
  DPRINTF("XCheckIfEvent()\n");
  return _real_XCheckIfEvent(display,event_return,);
}
*/

extern "C" Bool XCheckMaskEvent(Display* display ,long event_mask ,XEvent* event_return ) {
  DPRINTF("XCheckMaskEvent()\n");
  return _real_XCheckMaskEvent(display,event_mask,event_return);
}

extern "C" Bool XCheckTypedEvent(Display* display ,int event_type ,XEvent* event_return ) {
  DPRINTF("XCheckTypedEvent()\n");
  return _real_XCheckTypedEvent(display,event_type,event_return);
}

extern "C" Bool XCheckTypedWindowEvent(Display* display ,Window w ,int event_type ,XEvent* event_return ) {
  DPRINTF("XCheckTypedWindowEvent()\n");
  return _real_XCheckTypedWindowEvent(display,w,event_type,event_return);
}

extern "C" Bool XCheckWindowEvent(Display* display ,Window w ,long event_mask ,XEvent* event_return ) {
  DPRINTF("XCheckWindowEvent()\n");
  return _real_XCheckWindowEvent(display,w,event_mask,event_return);
}

extern "C" int XCirculateSubwindows(Display* display ,Window w ,int direction ) {
  DPRINTF("XCirculateSubwindows()\n");
  return _real_XCirculateSubwindows(display,w,direction);
}

extern "C" int XCirculateSubwindowsDown(Display* display ,Window w ) {
  DPRINTF("XCirculateSubwindowsDown()\n");
  return _real_XCirculateSubwindowsDown(display,w);
}

extern "C" int XCirculateSubwindowsUp(Display* display ,Window w ) {
  DPRINTF("XCirculateSubwindowsUp()\n");
  return _real_XCirculateSubwindowsUp(display,w);
}

extern "C" int XClearArea(Display* display ,Window w ,int x ,int y ,unsigned int width ,unsigned int height ,Bool exposures ) {
  DPRINTF("XClearArea()\n");
  return _real_XClearArea(display,w,x,y,width,height,exposures);
}

extern "C" int XClearWindow(Display* display ,Window w ) {
  DPRINTF("XClearWindow()\n");
  return _real_XClearWindow(display,w);
}

extern "C" int XCloseDisplay(Display* display ) {
  DPRINTF("XCloseDisplay()\n");
  return _real_XCloseDisplay(display);
}

extern "C" int XConfigureWindow(Display* display ,Window w ,unsigned int value_mask ,XWindowChanges* values ) {
  DPRINTF("XConfigureWindow()\n");
  return _real_XConfigureWindow(display,w,value_mask,values);
}

extern "C" int XConnectionNumber(Display* display ) {
  DPRINTF("XConnectionNumber()\n");
  return _real_XConnectionNumber(display);
}

extern "C" int XConvertSelection(Display* display ,Atom selection ,Atom target ,Atom property ,Window requestor ,Time time ) {
  DPRINTF("XConvertSelection()\n");
  return _real_XConvertSelection(display,selection,target,property,requestor,time);
}

extern "C" int XCopyArea(Display* display ,Drawable src ,Drawable dest ,GC gc ,int src_x ,int src_y ,unsigned int width ,unsigned int height ,int dest_x ,int dest_y ) {
  DPRINTF("XCopyArea()\n");
  return _real_XCopyArea(display,src,dest,gc,src_x,src_y,width,height,dest_x,dest_y);
}

extern "C" int XCopyGC(Display* display ,GC src ,unsigned long valuemask ,GC dest ) {
  DPRINTF("XCopyGC()\n");
  return _real_XCopyGC(display,src,valuemask,dest);
}

extern "C" int XCopyPlane(Display* display ,Drawable src ,Drawable dest ,GC gc ,int src_x ,int src_y ,unsigned int width ,unsigned int height ,int dest_x ,int dest_y ,unsigned long plane ) {
  DPRINTF("XCopyPlane()\n");
  return _real_XCopyPlane(display,src,dest,gc,src_x,src_y,width,height,dest_x,dest_y,plane);
}

extern "C" int XDefaultDepth(Display* display ,int screen_number ) {
  DPRINTF("XDefaultDepth()\n");
  return _real_XDefaultDepth(display,screen_number);
}

extern "C" int XDefaultDepthOfScreen(Screen* screen ) {
  DPRINTF("XDefaultDepthOfScreen()\n");
  return _real_XDefaultDepthOfScreen(screen);
}

extern "C" int XDefaultScreen(Display* display ) {
  DPRINTF("XDefaultScreen()\n");
  return _real_XDefaultScreen(display);
}

extern "C" int XDefineCursor(Display* display ,Window w ,Cursor cursor ) {
  DPRINTF("XDefineCursor()\n");
  return _real_XDefineCursor(display,w,cursor);
}

extern "C" int XDeleteProperty(Display* display ,Window w ,Atom property ) {
  DPRINTF("XDeleteProperty()\n");
  return _real_XDeleteProperty(display,w,property);
}

extern "C" int XDestroyWindow(Display* display ,Window w ) {
  DPRINTF("XDestroyWindow()\n");
  return _real_XDestroyWindow(display,w);
}

extern "C" int XDestroySubwindows(Display* display ,Window w ) {
  DPRINTF("XDestroySubwindows()\n");
  return _real_XDestroySubwindows(display,w);
}

extern "C" int XDoesBackingStore(Screen* screen ) {
  DPRINTF("XDoesBackingStore()\n");
  return _real_XDoesBackingStore(screen);
}

extern "C" Bool XDoesSaveUnders(Screen* screen ) {
  DPRINTF("XDoesSaveUnders()\n");
  return _real_XDoesSaveUnders(screen);
}

extern "C" int XDisableAccessControl(Display* display ) {
  DPRINTF("XDisableAccessControl()\n");
  return _real_XDisableAccessControl(display);
}

extern "C" int XDisplayCells(Display* display ,int screen_number ) {
  DPRINTF("XDisplayCells()\n");
  return _real_XDisplayCells(display,screen_number);
}

extern "C" int XDisplayHeight(Display* display ,int screen_number ) {
  DPRINTF("XDisplayHeight()\n");
  return _real_XDisplayHeight(display,screen_number);
}

extern "C" int XDisplayHeightMM(Display* display ,int screen_number ) {
  DPRINTF("XDisplayHeightMM()\n");
  return _real_XDisplayHeightMM(display,screen_number);
}

extern "C" int XDisplayKeycodes(Display* display ,int* min_keycodes_return ,int* max_keycodes_return ) {
  DPRINTF("XDisplayKeycodes()\n");
  return _real_XDisplayKeycodes(display,min_keycodes_return,max_keycodes_return);
}

extern "C" int XDisplayPlanes(Display* display ,int screen_number ) {
  DPRINTF("XDisplayPlanes()\n");
  return _real_XDisplayPlanes(display,screen_number);
}

extern "C" int XDisplayWidth(Display* display ,int screen_number ) {
  DPRINTF("XDisplayWidth()\n");
  return _real_XDisplayWidth(display,screen_number);
}

extern "C" int XDisplayWidthMM(Display* display ,int screen_number ) {
  DPRINTF("XDisplayWidthMM()\n");
  return _real_XDisplayWidthMM(display,screen_number);
}

extern "C" int XDrawArc(Display* display ,Drawable d ,GC gc ,int x ,int y ,unsigned int width ,unsigned int height ,int angle1 ,int angle2 ) {
  DPRINTF("XDrawArc()\n");
  return _real_XDrawArc(display,d,gc,x,y,width,height,angle1,angle2);
}

extern "C" int XDrawArcs(Display* display ,Drawable d ,GC gc ,XArc* arcs ,int narcs ) {
  DPRINTF("XDrawArcs()\n");
  return _real_XDrawArcs(display,d,gc,arcs,narcs);
}

extern "C" int XDrawImageString(Display* display ,Drawable d ,GC gc ,int x ,int y ,_Xconst char* string ,int length ) {
  DPRINTF("XDrawImageString()\n");
  return _real_XDrawImageString(display,d,gc,x,y,string,length);
}

extern "C" int XDrawImageString16(Display* display ,Drawable d ,GC gc ,int x ,int y ,_Xconst XChar2b* string ,int length ) {
  DPRINTF("XDrawImageString16()\n");
  return _real_XDrawImageString16(display,d,gc,x,y,string,length);
}

extern "C" int XDrawLine(Display* display ,Drawable d ,GC gc ,int x1 ,int y1 ,int x2 ,int y2 ) {
  DPRINTF("XDrawLine()\n");
  return _real_XDrawLine(display,d,gc,x1,y1,x2,y2);
}

extern "C" int XDrawLines(Display* display ,Drawable d ,GC gc ,XPoint* points ,int npoints ,int mode ) {
  DPRINTF("XDrawLines()\n");
  return _real_XDrawLines(display,d,gc,points,npoints,mode);
}

extern "C" int XDrawPoint(Display* display ,Drawable d ,GC gc ,int x ,int y ) {
  DPRINTF("XDrawPoint()\n");
  return _real_XDrawPoint(display,d,gc,x,y);
}

extern "C" int XDrawPoints(Display* display ,Drawable d ,GC gc ,XPoint* points ,int npoints ,int mode ) {
  DPRINTF("XDrawPoints()\n");
  return _real_XDrawPoints(display,d,gc,points,npoints,mode);
}

extern "C" int XDrawRectangle(Display* display ,Drawable d ,GC gc ,int x ,int y ,unsigned int width ,unsigned int height ) {
  DPRINTF("XDrawRectangle()\n");
  return _real_XDrawRectangle(display,d,gc,x,y,width,height);
}

extern "C" int XDrawRectangles(Display* display ,Drawable d ,GC gc ,XRectangle* rectangles ,int nrectangles ) {
  DPRINTF("XDrawRectangles()\n");
  return _real_XDrawRectangles(display,d,gc,rectangles,nrectangles);
}

extern "C" int XDrawSegments(Display* display ,Drawable d ,GC gc ,XSegment* segments ,int nsegments ) {
  DPRINTF("XDrawSegments()\n");
  return _real_XDrawSegments(display,d,gc,segments,nsegments);
}

extern "C" int XDrawString(Display* display ,Drawable d ,GC gc ,int x ,int y ,_Xconst char* string ,int length ) {
  DPRINTF("XDrawString()\n");
  return _real_XDrawString(display,d,gc,x,y,string,length);
}

extern "C" int XDrawString16(Display* display ,Drawable d ,GC gc ,int x ,int y ,_Xconst XChar2b* string ,int length ) {
  DPRINTF("XDrawString16()\n");
  return _real_XDrawString16(display,d,gc,x,y,string,length);
}

extern "C" int XDrawText(Display* display ,Drawable d ,GC gc ,int x ,int y ,XTextItem* items ,int nitems ) {
  DPRINTF("XDrawText()\n");
  return _real_XDrawText(display,d,gc,x,y,items,nitems);
}

extern "C" int XDrawText16(Display* display ,Drawable d ,GC gc ,int x ,int y ,XTextItem16* items ,int nitems ) {
  DPRINTF("XDrawText16()\n");
  return _real_XDrawText16(display,d,gc,x,y,items,nitems);
}

extern "C" int XEnableAccessControl(Display* display ) {
  DPRINTF("XEnableAccessControl()\n");
  return _real_XEnableAccessControl(display);
}

extern "C" int XEventsQueued(Display* display ,int mode ) {
  DPRINTF("XEventsQueued()\n");
  return _real_XEventsQueued(display,mode);
}

extern "C" Status XFetchName(Display* display ,Window w ,char** window_name_return ) {
  DPRINTF("XFetchName()\n");
  return _real_XFetchName(display,w,window_name_return);
}

extern "C" int XFillArc(Display* display ,Drawable d ,GC gc ,int x ,int y ,unsigned int width ,unsigned int height ,int angle1 ,int angle2 ) {
  DPRINTF("XFillArc()\n");
  return _real_XFillArc(display,d,gc,x,y,width,height,angle1,angle2);
}

extern "C" int XFillArcs(Display* display ,Drawable d ,GC gc ,XArc* arcs ,int narcs ) {
  DPRINTF("XFillArcs()\n");
  return _real_XFillArcs(display,d,gc,arcs,narcs);
}

extern "C" int XFillPolygon(Display* display ,Drawable d ,GC gc ,XPoint* points ,int npoints ,int shape ,int mode ) {
  DPRINTF("XFillPolygon()\n");
  return _real_XFillPolygon(display,d,gc,points,npoints,shape,mode);
}

extern "C" int XFillRectangle(Display* display ,Drawable d ,GC gc ,int x ,int y ,unsigned int width ,unsigned int height ) {
  DPRINTF("XFillRectangle()\n");
  return _real_XFillRectangle(display,d,gc,x,y,width,height);
}

extern "C" int XFillRectangles(Display* display ,Drawable d ,GC gc ,XRectangle* rectangles ,int nrectangles ) {
  DPRINTF("XFillRectangles()\n");
  return _real_XFillRectangles(display,d,gc,rectangles,nrectangles);
}

extern "C" int XFlush(Display* display ) {
  DPRINTF("XFlush()\n");
  return _real_XFlush(display);
}

extern "C" int XForceScreenSaver(Display* display ,int mode ) {
  DPRINTF("XForceScreenSaver()\n");
  return _real_XForceScreenSaver(display,mode);
}

extern "C" int XFree(void* data ) {
  DPRINTF("XFree()\n");
  return _real_XFree(data);
}

extern "C" int XFreeColormap(Display* display ,Colormap colormap ) {
  DPRINTF("XFreeColormap()\n");
  return _real_XFreeColormap(display,colormap);
}

extern "C" int XFreeColors(Display* display ,Colormap colormap ,unsigned long* pixels ,int npixels ,unsigned long planes ) {
  DPRINTF("XFreeColors()\n");
  return _real_XFreeColors(display,colormap,pixels,npixels,planes);
}

extern "C" int XFreeCursor(Display* display ,Cursor cursor ) {
  DPRINTF("XFreeCursor()\n");
  return _real_XFreeCursor(display,cursor);
}

extern "C" int XFreeExtensionList(char** list ) {
  DPRINTF("XFreeExtensionList()\n");
  return _real_XFreeExtensionList(list);
}

extern "C" int XFreeFont(Display* display ,XFontStruct* font_struct ) {
  DPRINTF("XFreeFont()\n");
  return _real_XFreeFont(display,font_struct);
}

extern "C" int XFreeFontInfo(char** names ,XFontStruct* free_info ,int actual_count ) {
  DPRINTF("XFreeFontInfo()\n");
  return _real_XFreeFontInfo(names,free_info,actual_count);
}

extern "C" int XFreeFontNames(char** list ) {
  DPRINTF("XFreeFontNames()\n");
  return _real_XFreeFontNames(list);
}

extern "C" int XFreeFontPath(char** list ) {
  DPRINTF("XFreeFontPath()\n");
  return _real_XFreeFontPath(list);
}

extern "C" int XFreeGC(Display* display ,GC gc ) {
  DPRINTF("XFreeGC()\n");
  return _real_XFreeGC(display,gc);
}

extern "C" int XFreeModifiermap(XModifierKeymap* modmap ) {
  DPRINTF("XFreeModifiermap()\n");
  return _real_XFreeModifiermap(modmap);
}

extern "C" int XFreePixmap(Display* display ,Pixmap pixmap ) {
  DPRINTF("XFreePixmap()\n");
  return _real_XFreePixmap(display,pixmap);
}

extern "C" int XGeometry(Display* display ,int screen ,_Xconst char* position ,_Xconst char* default_position ,unsigned int bwidth ,unsigned int fwidth ,unsigned int fheight ,int xadder ,int yadder ,int* x_return ,int* y_return ,int* width_return ,int* height_return ) {
  DPRINTF("XGeometry()\n");
  return _real_XGeometry(display,screen,position,default_position,bwidth,fwidth,fheight,xadder,yadder,x_return,y_return,width_return,height_return);
}

extern "C" int XGetErrorDatabaseText(Display* display ,_Xconst char* name ,_Xconst char* message ,_Xconst char* default_string ,char* buffer_return ,int length ) {
  DPRINTF("XGetErrorDatabaseText()\n");
  return _real_XGetErrorDatabaseText(display,name,message,default_string,buffer_return,length);
}

extern "C" int XGetErrorText(Display* display ,int code ,char* buffer_return ,int length ) {
  DPRINTF("XGetErrorText()\n");
  return _real_XGetErrorText(display,code,buffer_return,length);
}

extern "C" Bool XGetFontProperty(XFontStruct* font_struct ,Atom atom ,unsigned long* value_return ) {
  DPRINTF("XGetFontProperty()\n");
  return _real_XGetFontProperty(font_struct,atom,value_return);
}

extern "C" Status XGetGCValues(Display* display ,GC gc ,unsigned long valuemask ,XGCValues* values_return ) {
  DPRINTF("XGetGCValues()\n");
  return _real_XGetGCValues(display,gc,valuemask,values_return);
}

extern "C" Status XGetGeometry(Display* display ,Drawable d ,Window* root_return ,int* x_return ,int* y_return ,unsigned int* width_return ,unsigned int* height_return ,unsigned int* border_width_return ,unsigned int* depth_return ) {
  DPRINTF("XGetGeometry()\n");
  return _real_XGetGeometry(display,d,root_return,x_return,y_return,width_return,height_return,border_width_return,depth_return);
}

extern "C" Status XGetIconName(Display* display ,Window w ,char** icon_name_return ) {
  DPRINTF("XGetIconName()\n");
  return _real_XGetIconName(display,w,icon_name_return);
}

extern "C" int XGetInputFocus(Display* display ,Window* focus_return ,int* revert_to_return ) {
  DPRINTF("XGetInputFocus()\n");
  return _real_XGetInputFocus(display,focus_return,revert_to_return);
}

extern "C" int XGetKeyboardControl(Display* display ,XKeyboardState* values_return ) {
  DPRINTF("XGetKeyboardControl()\n");
  return _real_XGetKeyboardControl(display,values_return);
}

extern "C" int XGetPointerControl(Display* display ,int* accel_numerator_return ,int* accel_denominator_return ,int* threshold_return ) {
  DPRINTF("XGetPointerControl()\n");
  return _real_XGetPointerControl(display,accel_numerator_return,accel_denominator_return,threshold_return);
}

extern "C" int XGetPointerMapping(Display* display ,unsigned char* map_return ,int nmap ) {
  DPRINTF("XGetPointerMapping()\n");
  return _real_XGetPointerMapping(display,map_return,nmap);
}

extern "C" int XGetScreenSaver(Display* display ,int* timeout_return ,int* interval_return ,int* prefer_blanking_return ,int* allow_exposures_return ) {
  DPRINTF("XGetScreenSaver()\n");
  return _real_XGetScreenSaver(display,timeout_return,interval_return,prefer_blanking_return,allow_exposures_return);
}

extern "C" Status XGetTransientForHint(Display* display ,Window w ,Window* prop_window_return ) {
  DPRINTF("XGetTransientForHint()\n");
  return _real_XGetTransientForHint(display,w,prop_window_return);
}

extern "C" int XGetWindowProperty(Display* display ,Window w ,Atom property ,long long_offset ,long long_length ,Bool doDelete ,Atom req_type ,Atom* actual_type_return ,int* actual_format_return ,unsigned long* nitems_return ,unsigned long* bytes_after_return ,unsigned char** prop_return ) {
  DPRINTF("XGetWindowProperty()\n");
  return _real_XGetWindowProperty(display,w,property,long_offset,long_length,doDelete,req_type,actual_type_return,actual_format_return,nitems_return,bytes_after_return,prop_return);
}

extern "C" Status XGetWindowAttributes(Display* display ,Window w ,XWindowAttributes* window_attributes_return ) {
  DPRINTF("XGetWindowAttributes()\n");
  return _real_XGetWindowAttributes(display,w,window_attributes_return);
}

extern "C" int XGrabButton(Display* display ,unsigned int button ,unsigned int modifiers ,Window grab_window ,Bool owner_events ,unsigned int event_mask ,int pointer_mode ,int keyboard_mode ,Window confine_to ,Cursor cursor ) {
  DPRINTF("XGrabButton()\n");
  return _real_XGrabButton(display,button,modifiers,grab_window,owner_events,event_mask,pointer_mode,keyboard_mode,confine_to,cursor);
}

extern "C" int XGrabKey(Display* display ,int keycode ,unsigned int modifiers ,Window grab_window ,Bool owner_events ,int pointer_mode ,int keyboard_mode ) {
  DPRINTF("XGrabKey()\n");
  return _real_XGrabKey(display,keycode,modifiers,grab_window,owner_events,pointer_mode,keyboard_mode);
}

extern "C" int XGrabKeyboard(Display* display ,Window grab_window ,Bool owner_events ,int pointer_mode ,int keyboard_mode ,Time time ) {
  DPRINTF("XGrabKeyboard()\n");
  return _real_XGrabKeyboard(display,grab_window,owner_events,pointer_mode,keyboard_mode,time);
}

extern "C" int XGrabPointer(Display* display ,Window grab_window ,Bool owner_events ,unsigned int event_mask ,int pointer_mode ,int keyboard_mode ,Window confine_to ,Cursor cursor ,Time time ) {
  DPRINTF("XGrabPointer()\n");
  return _real_XGrabPointer(display,grab_window,owner_events,event_mask,pointer_mode,keyboard_mode,confine_to,cursor,time);
}

extern "C" int XGrabServer(Display* display ) {
  DPRINTF("XGrabServer()\n");
  return _real_XGrabServer(display);
}

extern "C" int XHeightMMOfScreen(Screen* screen ) {
  DPRINTF("XHeightMMOfScreen()\n");
  return _real_XHeightMMOfScreen(screen);
}

extern "C" int XHeightOfScreen(Screen* screen ) {
  DPRINTF("XHeightOfScreen()\n");
  return _real_XHeightOfScreen(screen);
}

/*
extern "C" int XIfEvent(Display* display ,XEvent* event_return ,Bool (*) (Display* display ,XEvent* event ,XPointer arg ) predicate ,XPointer arg ) {
  DPRINTF("XIfEvent()\n");
  return _real_XIfEvent(display,event_return,);
}
*/

extern "C" int XImageByteOrder(Display* display ) {
  DPRINTF("XImageByteOrder()\n");
  return _real_XImageByteOrder(display);
}

extern "C" int XInstallColormap(Display* display ,Colormap colormap ) {
  DPRINTF("XInstallColormap()\n");
  return _real_XInstallColormap(display,colormap);
}

extern "C" KeyCode XKeysymToKeycode(Display* display ,KeySym keysym ) {
  DPRINTF("XKeysymToKeycode()\n");
  return _real_XKeysymToKeycode(display,keysym);
}

extern "C" int XKillClient(Display* display ,XID resource ) {
  DPRINTF("XKillClient()\n");
  return _real_XKillClient(display,resource);
}

extern "C" Status XLookupColor(Display* display ,Colormap colormap ,_Xconst char* color_name ,XColor* exact_def_return ,XColor* screen_def_return ) {
  DPRINTF("XLookupColor()\n");
  return _real_XLookupColor(display,colormap,color_name,exact_def_return,screen_def_return);
}

extern "C" int XLowerWindow(Display* display ,Window w ) {
  DPRINTF("XLowerWindow()\n");
  return _real_XLowerWindow(display,w);
}

extern "C" int XMapRaised(Display* display ,Window w ) {
  DPRINTF("XMapRaised()\n");
  return _real_XMapRaised(display,w);
}

extern "C" int XMapSubwindows(Display* display ,Window w ) {
  DPRINTF("XMapSubwindows()\n");
  return _real_XMapSubwindows(display,w);
}

extern "C" int XMapWindow(Display* display ,Window w ) {
  DPRINTF("XMapWindow()\n");
  return _real_XMapWindow(display,w);
}

extern "C" int XMaskEvent(Display* display ,long event_mask ,XEvent* event_return ) {
  DPRINTF("XMaskEvent()\n");
  return _real_XMaskEvent(display,event_mask,event_return);
}

extern "C" int XMaxCmapsOfScreen(Screen* screen ) {
  DPRINTF("XMaxCmapsOfScreen()\n");
  return _real_XMaxCmapsOfScreen(screen);
}

extern "C" int XMinCmapsOfScreen(Screen* screen ) {
  DPRINTF("XMinCmapsOfScreen()\n");
  return _real_XMinCmapsOfScreen(screen);
}

extern "C" int XMoveResizeWindow(Display* display ,Window w ,int x ,int y ,unsigned int width ,unsigned int height ) {
  DPRINTF("XMoveResizeWindow()\n");
  return _real_XMoveResizeWindow(display,w,x,y,width,height);
}

extern "C" int XMoveWindow(Display* display ,Window w ,int x ,int y ) {
  DPRINTF("XMoveWindow()\n");
  return _real_XMoveWindow(display,w,x,y);
}

extern "C" int XNextEvent(Display* display ,XEvent* event_return ) {
  DPRINTF("XNextEvent()\n");
  return _real_XNextEvent(display,event_return);
}

extern "C" int XNoOp(Display* display ) {
  DPRINTF("XNoOp()\n");
  return _real_XNoOp(display);
}

extern "C" Status XParseColor(Display* display ,Colormap colormap ,_Xconst char* spec ,XColor* exact_def_return ) {
  DPRINTF("XParseColor()\n");
  return _real_XParseColor(display,colormap,spec,exact_def_return);
}

extern "C" int XParseGeometry(_Xconst char* parsestring ,int* x_return ,int* y_return ,unsigned int* width_return ,unsigned int* height_return ) {
  DPRINTF("XParseGeometry()\n");
  return _real_XParseGeometry(parsestring,x_return,y_return,width_return,height_return);
}

extern "C" int XPeekEvent(Display* display ,XEvent* event_return ) {
  DPRINTF("XPeekEvent()\n");
  return _real_XPeekEvent(display,event_return);
}

/*
extern "C" int XPeekIfEvent(Display* display ,XEvent* event_return ,Bool (*) (Display* display ,XEvent* event ,XPointer arg ) predicate ,XPointer arg ) {
  DPRINTF("XPeekIfEvent()\n");
  return _real_XPeekIfEvent(display,event_return,);
}
*/

extern "C" int XPending(Display* display ) {
  DPRINTF("XPending()\n");
  return _real_XPending(display);
}

extern "C" int XPlanesOfScreen(Screen* screen ) {
  DPRINTF("XPlanesOfScreen()\n");
  return _real_XPlanesOfScreen(screen);
}

extern "C" int XProtocolRevision(Display* display ) {
  DPRINTF("XProtocolRevision()\n");
  return _real_XProtocolRevision(display);
}

extern "C" int XProtocolVersion(Display* display ) {
  DPRINTF("XProtocolVersion()\n");
  return _real_XProtocolVersion(display);
}

extern "C" int XPutBackEvent(Display* display ,XEvent* event ) {
  DPRINTF("XPutBackEvent()\n");
  return _real_XPutBackEvent(display,event);
}

extern "C" int XPutImage(Display* display ,Drawable d ,GC gc ,XImage* image ,int src_x ,int src_y ,int dest_x ,int dest_y ,unsigned int width ,unsigned int height ) {
  DPRINTF("XPutImage()\n");
  return _real_XPutImage(display,d,gc,image,src_x,src_y,dest_x,dest_y,width,height);
}

extern "C" int XQLength(Display* display ) {
  DPRINTF("XQLength()\n");
  return _real_XQLength(display);
}

extern "C" Status XQueryBestCursor(Display* display ,Drawable d ,unsigned int width ,unsigned int height ,unsigned int* width_return ,unsigned int* height_return ) {
  DPRINTF("XQueryBestCursor()\n");
  return _real_XQueryBestCursor(display,d,width,height,width_return,height_return);
}

extern "C" Status XQueryBestSize(Display* display ,int cl ,Drawable which_screen ,unsigned int width ,unsigned int height ,unsigned int* width_return ,unsigned int* height_return ) {
  DPRINTF("XQueryBestSize()\n");
  return _real_XQueryBestSize(display,cl,which_screen,width,height,width_return,height_return);
}

extern "C" Status XQueryBestStipple(Display* display ,Drawable which_screen ,unsigned int width ,unsigned int height ,unsigned int* width_return ,unsigned int* height_return ) {
  DPRINTF("XQueryBestStipple()\n");
  return _real_XQueryBestStipple(display,which_screen,width,height,width_return,height_return);
}

extern "C" Status XQueryBestTile(Display* display ,Drawable which_screen ,unsigned int width ,unsigned int height ,unsigned int* width_return ,unsigned int* height_return ) {
  DPRINTF("XQueryBestTile()\n");
  return _real_XQueryBestTile(display,which_screen,width,height,width_return,height_return);
}

extern "C" int XQueryColor(Display* display ,Colormap colormap ,XColor* def_in_out ) {
  DPRINTF("XQueryColor()\n");
  return _real_XQueryColor(display,colormap,def_in_out);
}

extern "C" int XQueryColors(Display* display ,Colormap colormap ,XColor* defs_in_out ,int ncolors ) {
  DPRINTF("XQueryColors()\n");
  return _real_XQueryColors(display,colormap,defs_in_out,ncolors);
}

extern "C" Bool XQueryExtension(Display* display ,_Xconst char* name ,int* major_opcode_return ,int* first_event_return ,int* first_error_return ) {
  DPRINTF("XQueryExtension()\n");
  return _real_XQueryExtension(display,name,major_opcode_return,first_event_return,first_error_return);
}

extern "C" int XQueryKeymap(Display* display ,char keys_return[32]) {
  DPRINTF("XQueryKeymap()\n");
  return _real_XQueryKeymap(display,keys_return);
}

extern "C" Bool XQueryPointer(Display* display ,Window w ,Window* root_return ,Window* child_return ,int* root_x_return ,int* root_y_return ,int* win_x_return ,int* win_y_return ,unsigned int* mask_return ) {
  DPRINTF("XQueryPointer()\n");
  return _real_XQueryPointer(display,w,root_return,child_return,root_x_return,root_y_return,win_x_return,win_y_return,mask_return);
}

extern "C" int XQueryTextExtents(Display* display ,XID font_ID ,_Xconst char* string ,int nchars ,int* direction_return ,int* font_ascent_return ,int* font_descent_return ,XCharStruct* overall_return ) {
  DPRINTF("XQueryTextExtents()\n");
  return _real_XQueryTextExtents(display,font_ID,string,nchars,direction_return,font_ascent_return,font_descent_return,overall_return);
}

extern "C" int XQueryTextExtents16(Display* display ,XID font_ID ,_Xconst XChar2b* string ,int nchars ,int* direction_return ,int* font_ascent_return ,int* font_descent_return ,XCharStruct* overall_return ) {
  DPRINTF("XQueryTextExtents16()\n");
  return _real_XQueryTextExtents16(display,font_ID,string,nchars,direction_return,font_ascent_return,font_descent_return,overall_return);
}

extern "C" Status XQueryTree(Display* display ,Window w ,Window* root_return ,Window* parent_return ,Window** children_return ,unsigned int* nchildren_return ) {
  DPRINTF("XQueryTree()\n");
  return _real_XQueryTree(display,w,root_return,parent_return,children_return,nchildren_return);
}

extern "C" int XRaiseWindow(Display* display ,Window w ) {
  DPRINTF("XRaiseWindow()\n");
  return _real_XRaiseWindow(display,w);
}

extern "C" int XReadBitmapFile(Display* display ,Drawable d ,_Xconst char* filename ,unsigned int* width_return ,unsigned int* height_return ,Pixmap* bitmap_return ,int* x_hot_return ,int* y_hot_return ) {
  DPRINTF("XReadBitmapFile()\n");
  return _real_XReadBitmapFile(display,d,filename,width_return,height_return,bitmap_return,x_hot_return,y_hot_return);
}

extern "C" int XReadBitmapFileData(_Xconst char* filename ,unsigned int* width_return ,unsigned int* height_return ,unsigned char** data_return ,int* x_hot_return ,int* y_hot_return ) {
  DPRINTF("XReadBitmapFileData()\n");
  return _real_XReadBitmapFileData(filename,width_return,height_return,data_return,x_hot_return,y_hot_return);
}

extern "C" int XRebindKeysym(Display* display ,KeySym keysym ,KeySym* list ,int mod_count ,_Xconst unsigned char* string ,int bytes_string ) {
  DPRINTF("XRebindKeysym()\n");
  return _real_XRebindKeysym(display,keysym,list,mod_count,string,bytes_string);
}

extern "C" int XRecolorCursor(Display* display ,Cursor cursor ,XColor* foreground_color ,XColor* background_color ) {
  DPRINTF("XRecolorCursor()\n");
  return _real_XRecolorCursor(display,cursor,foreground_color,background_color);
}

extern "C" int XRefreshKeyboardMapping(XMappingEvent* event_map ) {
  DPRINTF("XRefreshKeyboardMapping()\n");
  return _real_XRefreshKeyboardMapping(event_map);
}

extern "C" int XRemoveFromSaveSet(Display* display ,Window w ) {
  DPRINTF("XRemoveFromSaveSet()\n");
  return _real_XRemoveFromSaveSet(display,w);
}

extern "C" int XRemoveHost(Display* display ,XHostAddress* host ) {
  DPRINTF("XRemoveHost()\n");
  return _real_XRemoveHost(display,host);
}

extern "C" int XRemoveHosts(Display* display ,XHostAddress* hosts ,int num_hosts ) {
  DPRINTF("XRemoveHosts()\n");
  return _real_XRemoveHosts(display,hosts,num_hosts);
}

extern "C" int XReparentWindow(Display* display ,Window w ,Window parent ,int x ,int y ) {
  DPRINTF("XReparentWindow()\n");
  return _real_XReparentWindow(display,w,parent,x,y);
}

extern "C" int XResetScreenSaver(Display* display ) {
  DPRINTF("XResetScreenSaver()\n");
  return _real_XResetScreenSaver(display);
}

extern "C" int XResizeWindow(Display* display ,Window w ,unsigned int width ,unsigned int height ) {
  DPRINTF("XResizeWindow()\n");
  return _real_XResizeWindow(display,w,width,height);
}

extern "C" int XRestackWindows(Display* display ,Window* windows ,int nwindows ) {
  DPRINTF("XRestackWindows()\n");
  return _real_XRestackWindows(display,windows,nwindows);
}

extern "C" int XRotateBuffers(Display* display ,int rotate ) {
  DPRINTF("XRotateBuffers()\n");
  return _real_XRotateBuffers(display,rotate);
}

extern "C" int XRotateWindowProperties(Display* display ,Window w ,Atom* properties ,int num_prop ,int npositions ) {
  DPRINTF("XRotateWindowProperties()\n");
  return _real_XRotateWindowProperties(display,w,properties,num_prop,npositions);
}

extern "C" int XScreenCount(Display* display ) {
  DPRINTF("XScreenCount()\n");
  return _real_XScreenCount(display);
}

extern "C" int XSelectInput(Display* display ,Window w ,long event_mask ) {
  DPRINTF("XSelectInput()\n");
  return _real_XSelectInput(display,w,event_mask);
}

extern "C" Status XSendEvent(Display* display ,Window w ,Bool propagate ,long event_mask ,XEvent* event_send ) {
  DPRINTF("XSendEvent()\n");
  return _real_XSendEvent(display,w,propagate,event_mask,event_send);
}

extern "C" int XSetAccessControl(Display* display ,int mode ) {
  DPRINTF("XSetAccessControl()\n");
  return _real_XSetAccessControl(display,mode);
}

extern "C" int XSetArcMode(Display* display ,GC gc ,int arc_mode ) {
  DPRINTF("XSetArcMode()\n");
  return _real_XSetArcMode(display,gc,arc_mode);
}

extern "C" int XSetBackground(Display* display ,GC gc ,unsigned long background ) {
  DPRINTF("XSetBackground()\n");
  return _real_XSetBackground(display,gc,background);
}

extern "C" int XSetClipMask(Display* display ,GC gc ,Pixmap pixmap ) {
  DPRINTF("XSetClipMask()\n");
  return _real_XSetClipMask(display,gc,pixmap);
}

extern "C" int XSetClipOrigin(Display* display ,GC gc ,int clip_x_origin ,int clip_y_origin ) {
  DPRINTF("XSetClipOrigin()\n");
  return _real_XSetClipOrigin(display,gc,clip_x_origin,clip_y_origin);
}

extern "C" int XSetClipRectangles(Display* display ,GC gc ,int clip_x_origin ,int clip_y_origin ,XRectangle* rectangles ,int n ,int ordering ) {
  DPRINTF("XSetClipRectangles()\n");
  return _real_XSetClipRectangles(display,gc,clip_x_origin,clip_y_origin,rectangles,n,ordering);
}

extern "C" int XSetCloseDownMode(Display* display ,int close_mode ) {
  DPRINTF("XSetCloseDownMode()\n");
  return _real_XSetCloseDownMode(display,close_mode);
}

extern "C" int XSetCommand(Display* display ,Window w ,char** argv ,int argc ) {
  DPRINTF("XSetCommand()\n");
  return _real_XSetCommand(display,w,argv,argc);
}

extern "C" int XSetDashes(Display* display ,GC gc ,int dash_offset ,_Xconst char* dash_list ,int n ) {
  DPRINTF("XSetDashes()\n");
  return _real_XSetDashes(display,gc,dash_offset,dash_list,n);
}

extern "C" int XSetFillRule(Display* display ,GC gc ,int fill_rule ) {
  DPRINTF("XSetFillRule()\n");
  return _real_XSetFillRule(display,gc,fill_rule);
}

extern "C" int XSetFillStyle(Display* display ,GC gc ,int fill_style ) {
  DPRINTF("XSetFillStyle()\n");
  return _real_XSetFillStyle(display,gc,fill_style);
}

extern "C" int XSetFont(Display* display ,GC gc ,Font font ) {
  DPRINTF("XSetFont()\n");
  return _real_XSetFont(display,gc,font);
}

extern "C" int XSetFontPath(Display* display ,char** directories ,int ndirs ) {
  DPRINTF("XSetFontPath()\n");
  return _real_XSetFontPath(display,directories,ndirs);
}

extern "C" int XSetForeground(Display* display ,GC gc ,unsigned long foreground ) {
  DPRINTF("XSetForeground()\n");
  return _real_XSetForeground(display,gc,foreground);
}

extern "C" int XSetFunction(Display* display ,GC gc ,int function ) {
  DPRINTF("XSetFunction()\n");
  return _real_XSetFunction(display,gc,function);
}

extern "C" int XSetGraphicsExposures(Display* display ,GC gc ,Bool graphics_exposures ) {
  DPRINTF("XSetGraphicsExposures()\n");
  return _real_XSetGraphicsExposures(display,gc,graphics_exposures);
}

extern "C" int XSetIconName(Display* display ,Window w ,_Xconst char* icon_name ) {
  DPRINTF("XSetIconName()\n");
  return _real_XSetIconName(display,w,icon_name);
}

extern "C" int XSetInputFocus(Display* display ,Window focus ,int revert_to ,Time time ) {
  DPRINTF("XSetInputFocus()\n");
  return _real_XSetInputFocus(display,focus,revert_to,time);
}

extern "C" int XSetLineAttributes(Display* display ,GC gc ,unsigned int line_width ,int line_style ,int cap_style ,int join_style ) {
  DPRINTF("XSetLineAttributes()\n");
  return _real_XSetLineAttributes(display,gc,line_width,line_style,cap_style,join_style);
}

extern "C" int XSetModifierMapping(Display* display ,XModifierKeymap* modmap ) {
  DPRINTF("XSetModifierMapping()\n");
  return _real_XSetModifierMapping(display,modmap);
}

extern "C" int XSetPlaneMask(Display* display ,GC gc ,unsigned long plane_mask ) {
  DPRINTF("XSetPlaneMask()\n");
  return _real_XSetPlaneMask(display,gc,plane_mask);
}

extern "C" int XSetPointerMapping(Display* display ,_Xconst unsigned char* map ,int nmap ) {
  DPRINTF("XSetPointerMapping()\n");
  return _real_XSetPointerMapping(display,map,nmap);
}

extern "C" int XSetScreenSaver(Display* display ,int timeout ,int interval ,int prefer_blanking ,int allow_exposures ) {
  DPRINTF("XSetScreenSaver()\n");
  return _real_XSetScreenSaver(display,timeout,interval,prefer_blanking,allow_exposures);
}

extern "C" int XSetSelectionOwner(Display* display ,Atom selection ,Window owner ,Time time ) {
  DPRINTF("XSetSelectionOwner()\n");
  return _real_XSetSelectionOwner(display,selection,owner,time);
}

extern "C" int XSetState(Display* display ,GC gc ,unsigned long foreground ,unsigned long background ,int function ,unsigned long plane_mask ) {
  DPRINTF("XSetState()\n");
  return _real_XSetState(display,gc,foreground,background,function,plane_mask);
}

extern "C" int XSetStipple(Display* display ,GC gc ,Pixmap stipple ) {
  DPRINTF("XSetStipple()\n");
  return _real_XSetStipple(display,gc,stipple);
}

extern "C" int XSetSubwindowMode(Display* display ,GC gc ,int subwindow_mode ) {
  DPRINTF("XSetSubwindowMode()\n");
  return _real_XSetSubwindowMode(display,gc,subwindow_mode);
}

extern "C" int XSetTSOrigin(Display* display ,GC gc ,int ts_x_origin ,int ts_y_origin ) {
  DPRINTF("XSetTSOrigin()\n");
  return _real_XSetTSOrigin(display,gc,ts_x_origin,ts_y_origin);
}

extern "C" int XSetTile(Display* display ,GC gc ,Pixmap tile ) {
  DPRINTF("XSetTile()\n");
  return _real_XSetTile(display,gc,tile);
}

extern "C" int XSetWindowBackground(Display* display ,Window w ,unsigned long background_pixel ) {
  DPRINTF("XSetWindowBackground()\n");
  return _real_XSetWindowBackground(display,w,background_pixel);
}

extern "C" int XSetWindowBackgroundPixmap(Display* display ,Window w ,Pixmap background_pixmap ) {
  DPRINTF("XSetWindowBackgroundPixmap()\n");
  return _real_XSetWindowBackgroundPixmap(display,w,background_pixmap);
}

extern "C" int XSetWindowBorder(Display* display ,Window w ,unsigned long border_pixel ) {
  DPRINTF("XSetWindowBorder()\n");
  return _real_XSetWindowBorder(display,w,border_pixel);
}

extern "C" int XSetWindowBorderPixmap(Display* display ,Window w ,Pixmap border_pixmap ) {
  DPRINTF("XSetWindowBorderPixmap()\n");
  return _real_XSetWindowBorderPixmap(display,w,border_pixmap);
}

extern "C" int XSetWindowBorderWidth(Display* display ,Window w ,unsigned int width ) {
  DPRINTF("XSetWindowBorderWidth()\n");
  return _real_XSetWindowBorderWidth(display,w,width);
}

extern "C" int XSetWindowColormap(Display* display ,Window w ,Colormap colormap ) {
  DPRINTF("XSetWindowColormap()\n");
  return _real_XSetWindowColormap(display,w,colormap);
}

extern "C" int XStoreBuffer(Display* display ,_Xconst char* bytes ,int nbytes ,int buffer ) {
  DPRINTF("XStoreBuffer()\n");
  return _real_XStoreBuffer(display,bytes,nbytes,buffer);
}

extern "C" int XStoreBytes(Display* display ,_Xconst char* bytes ,int nbytes ) {
  DPRINTF("XStoreBytes()\n");
  return _real_XStoreBytes(display,bytes,nbytes);
}

extern "C" int XStoreColor(Display* display ,Colormap colormap ,XColor* color ) {
  DPRINTF("XStoreColor()\n");
  return _real_XStoreColor(display,colormap,color);
}

extern "C" int XStoreColors(Display* display ,Colormap colormap ,XColor* color ,int ncolors ) {
  DPRINTF("XStoreColors()\n");
  return _real_XStoreColors(display,colormap,color,ncolors);
}

extern "C" int XStoreName(Display* display ,Window w ,_Xconst char* window_name ) {
  DPRINTF("XStoreName()\n");
  return _real_XStoreName(display,w,window_name);
}

extern "C" int XStoreNamedColor(Display* display ,Colormap colormap ,_Xconst char* color ,unsigned long pixel ,int flags ) {
  DPRINTF("XStoreNamedColor()\n");
  return _real_XStoreNamedColor(display,colormap,color,pixel,flags);
}

extern "C" int XSync(Display* display ,Bool discard ) {
  DPRINTF("XSync()\n");
  return _real_XSync(display,discard);
}

extern "C" int XTextExtents(XFontStruct* font_struct ,_Xconst char* string ,int nchars ,int* direction_return ,int* font_ascent_return ,int* font_descent_return ,XCharStruct* overall_return ) {
  DPRINTF("XTextExtents()\n");
  return _real_XTextExtents(font_struct,string,nchars,direction_return,font_ascent_return,font_descent_return,overall_return);
}

extern "C" int XTextExtents16(XFontStruct* font_struct ,_Xconst XChar2b* string ,int nchars ,int* direction_return ,int* font_ascent_return ,int* font_descent_return ,XCharStruct* overall_return ) {
  DPRINTF("XTextExtents16()\n");
  return _real_XTextExtents16(font_struct,string,nchars,direction_return,font_ascent_return,font_descent_return,overall_return);
}

extern "C" int XTextWidth(XFontStruct* font_struct ,_Xconst char* string ,int count ) {
  DPRINTF("XTextWidth()\n");
  return _real_XTextWidth(font_struct,string,count);
}

extern "C" int XTextWidth16(XFontStruct* font_struct ,_Xconst XChar2b* string ,int count ) {
  DPRINTF("XTextWidth16()\n");
  return _real_XTextWidth16(font_struct,string,count);
}

extern "C" Bool XTranslateCoordinates(Display* display ,Window src_w ,Window dest_w ,int src_x ,int src_y ,int* dest_x_return ,int* dest_y_return ,Window* child_return ) {
  DPRINTF("XTranslateCoordinates()\n");
  return _real_XTranslateCoordinates(display,src_w,dest_w,src_x,src_y,dest_x_return,dest_y_return,child_return);
}

extern "C" int XUndefineCursor(Display* display ,Window w ) {
  DPRINTF("XUndefineCursor()\n");
  return _real_XUndefineCursor(display,w);
}

extern "C" int XUngrabButton(Display* display ,unsigned int button ,unsigned int modifiers ,Window grab_window ) {
  DPRINTF("XUngrabButton()\n");
  return _real_XUngrabButton(display,button,modifiers,grab_window);
}

extern "C" int XUngrabKey(Display* display ,int keycode ,unsigned int modifiers ,Window grab_window ) {
  DPRINTF("XUngrabKey()\n");
  return _real_XUngrabKey(display,keycode,modifiers,grab_window);
}

extern "C" int XUngrabKeyboard(Display* display ,Time time ) {
  DPRINTF("XUngrabKeyboard()\n");
  return _real_XUngrabKeyboard(display,time);
}

extern "C" int XUngrabPointer(Display* display ,Time time ) {
  DPRINTF("XUngrabPointer()\n");
  return _real_XUngrabPointer(display,time);
}

extern "C" int XUngrabServer(Display* display ) {
  DPRINTF("XUngrabServer()\n");
  return _real_XUngrabServer(display);
}

extern "C" int XUninstallColormap(Display* display ,Colormap colormap ) {
  DPRINTF("XUninstallColormap()\n");
  return _real_XUninstallColormap(display,colormap);
}

extern "C" int XUnloadFont(Display* display ,Font font ) {
  DPRINTF("XUnloadFont()\n");
  return _real_XUnloadFont(display,font);
}

extern "C" int XUnmapSubwindows(Display* display ,Window w ) {
  DPRINTF("XUnmapSubwindows()\n");
  return _real_XUnmapSubwindows(display,w);
}

extern "C" int XUnmapWindow(Display* display ,Window w ) {
  DPRINTF("XUnmapWindow()\n");
  return _real_XUnmapWindow(display,w);
}

extern "C" int XVendorRelease(Display* display ) {
  DPRINTF("XVendorRelease()\n");
  return _real_XVendorRelease(display);
}

extern "C" int XWarpPointer(Display* display ,Window src_w ,Window dest_w ,int src_x ,int src_y ,unsigned int src_width ,unsigned int src_height ,int dest_x ,int dest_y ) {
  DPRINTF("XWarpPointer()\n");
  return _real_XWarpPointer(display,src_w,dest_w,src_x,src_y,src_width,src_height,dest_x,dest_y);
}

extern "C" int XWidthMMOfScreen(Screen* screen ) {
  DPRINTF("XWidthMMOfScreen()\n");
  return _real_XWidthMMOfScreen(screen);
}

extern "C" int XWidthOfScreen(Screen* screen ) {
  DPRINTF("XWidthOfScreen()\n");
  return _real_XWidthOfScreen(screen);
}

extern "C" int XWindowEvent(Display* display ,Window w ,long event_mask ,XEvent* event_return ) {
  DPRINTF("XWindowEvent()\n");
  return _real_XWindowEvent(display,w,event_mask,event_return);
}

extern "C" int XWriteBitmapFile(Display* display ,_Xconst char* filename ,Pixmap bitmap ,unsigned int width ,unsigned int height ,int x_hot ,int y_hot ) {
  DPRINTF("XWriteBitmapFile()\n");
  return _real_XWriteBitmapFile(display,filename,bitmap,width,height,x_hot,y_hot);
}

extern "C" Bool XSupportsLocale (void) {
  DPRINTF("XSupportsLocale()\n");
  return _real_XSupportsLocale();
}

extern "C" char *XSetLocaleModifiers(const char* modifier_list ) {
  DPRINTF("XSetLocaleModifiers()\n");
  return _real_XSetLocaleModifiers(modifier_list);
}

extern "C" XOM XOpenOM(Display* display ,struct _XrmHashBucketRec* rdb ,_Xconst char* res_name ,_Xconst char* res_class ) {
  DPRINTF("XOpenOM()\n");
  return _real_XOpenOM(display,rdb,res_name,res_class);
}

extern "C" Status XCloseOM(XOM om ) {
  DPRINTF("XCloseOM()\n");
  return _real_XCloseOM(om);
}

extern "C" char *XSetOMValues(XOM om, ...) {
  DPRINTF("XSetOMValues()\n");
  return _real_XSetOMValues(om, NULL);
}


extern "C" char *XGetOMValues(XOM om ,...) {
  DPRINTF("XGetOMValues()\n");
  return _real_XGetOMValues(om,NULL);
}

extern "C" Display *XDisplayOfOM(XOM om ) {
  DPRINTF("XDisplayOfOM()\n");
  return _real_XDisplayOfOM(om);
}

extern "C" char *XLocaleOfOM(XOM om ) {
  DPRINTF("XLocaleOfOM()\n");
  return _real_XLocaleOfOM(om);
}

extern "C" XOC XCreateOC(XOM om ,...) {
  DPRINTF("XCreateOC()\n");
  return _real_XCreateOC(om,NULL);
}

extern "C" void XDestroyOC(XOC oc ) {
  DPRINTF("XDestroyOC()\n");
  _real_XDestroyOC(oc);
}

extern "C" XOM XOMOfOC(XOC oc ) {
  DPRINTF("XOMOfOC()\n");
  return _real_XOMOfOC(oc);
}

extern "C" char *XSetOCValues(XOC oc ,...) {
  DPRINTF("XSetOCValues()\n");
  return _real_XSetOCValues(oc,NULL);
}

extern "C" char *XGetOCValues(XOC oc ,...) {
  DPRINTF("XGetOCValues()\n");
  return _real_XGetOCValues(oc,NULL);
}

extern "C" XFontSet XCreateFontSet(Display* display ,_Xconst char* base_font_name_list ,char*** missing_charset_list ,int* missing_charset_count ,char** def_string ) {
  DPRINTF("XCreateFontSet()\n");
  return _real_XCreateFontSet(display,base_font_name_list,missing_charset_list,missing_charset_count,def_string);
}

extern "C" void XFreeFontSet(Display* display ,XFontSet font_set ) {
  DPRINTF("XFreeFontSet()\n");
  _real_XFreeFontSet(display,font_set);
}

extern "C" int XFontsOfFontSet(XFontSet font_set ,XFontStruct*** font_struct_list ,char*** font_name_list ) {
  DPRINTF("XFontsOfFontSet()\n");
  return _real_XFontsOfFontSet(font_set,font_struct_list,font_name_list);
}

extern "C" char *XBaseFontNameListOfFontSet(XFontSet font_set ) {
  DPRINTF("XBaseFontNameListOfFontSet()\n");
  return _real_XBaseFontNameListOfFontSet(font_set);
}

extern "C" char *XLocaleOfFontSet(XFontSet font_set ) {
  DPRINTF("XLocaleOfFontSet()\n");
  return _real_XLocaleOfFontSet(font_set);
}

extern "C" Bool XContextDependentDrawing(XFontSet font_set ) {
  DPRINTF("XContextDependentDrawing()\n");
  return _real_XContextDependentDrawing(font_set);
}

extern "C" Bool XDirectionalDependentDrawing(XFontSet font_set ) {
  DPRINTF("XDirectionalDependentDrawing()\n");
  return _real_XDirectionalDependentDrawing(font_set);
}

extern "C" Bool XContextualDrawing(XFontSet font_set ) {
  DPRINTF("XContextualDrawing()\n");
  return _real_XContextualDrawing(font_set);
}

extern "C" XFontSetExtents *XExtentsOfFontSet(XFontSet font_set ) {
  DPRINTF("XExtentsOfFontSet()\n");
  return _real_XExtentsOfFontSet(font_set);
}

extern "C" int XmbTextEscapement(XFontSet font_set ,_Xconst char* text ,int bytes_text ) {
  DPRINTF("XmbTextEscapement()\n");
  return _real_XmbTextEscapement(font_set,text,bytes_text);
}

extern "C" int XwcTextEscapement(XFontSet font_set ,_Xconst wchar_t* text ,int num_wchars ) {
  DPRINTF("XwcTextEscapement()\n");
  return _real_XwcTextEscapement(font_set,text,num_wchars);
}

extern "C" int Xutf8TextEscapement(XFontSet font_set ,_Xconst char* text ,int bytes_text ) {
  DPRINTF("Xutf8TextEscapement()\n");
  return _real_Xutf8TextEscapement(font_set,text,bytes_text);
}

extern "C" int XmbTextExtents(XFontSet font_set ,_Xconst char* text ,int bytes_text ,XRectangle* overall_ink_return ,XRectangle* overall_logical_return ) {
  DPRINTF("XmbTextExtents()\n");
  return _real_XmbTextExtents(font_set,text,bytes_text,overall_ink_return,overall_logical_return);
}

extern "C" int XwcTextExtents(XFontSet font_set ,_Xconst wchar_t* text ,int num_wchars ,XRectangle* overall_ink_return ,XRectangle* overall_logical_return ) {
  DPRINTF("XwcTextExtents()\n");
  return _real_XwcTextExtents(font_set,text,num_wchars,overall_ink_return,overall_logical_return);
}

extern "C" int Xutf8TextExtents(XFontSet font_set ,_Xconst char* text ,int bytes_text ,XRectangle* overall_ink_return ,XRectangle* overall_logical_return ) {
  DPRINTF("Xutf8TextExtents()\n");
  return _real_Xutf8TextExtents(font_set,text,bytes_text,overall_ink_return,overall_logical_return);
}

extern "C" Status XmbTextPerCharExtents(XFontSet font_set ,_Xconst char* text ,int bytes_text ,XRectangle* ink_extents_buffer ,XRectangle* logical_extents_buffer ,int buffer_size ,int* num_chars ,XRectangle* overall_ink_return ,XRectangle* overall_logical_return ) {
  DPRINTF("XmbTextPerCharExtents()\n");
  return _real_XmbTextPerCharExtents(font_set,text,bytes_text,ink_extents_buffer,logical_extents_buffer,buffer_size,num_chars,overall_ink_return,overall_logical_return);
}

extern "C" Status XwcTextPerCharExtents(XFontSet font_set ,_Xconst wchar_t* text ,int num_wchars ,XRectangle* ink_extents_buffer ,XRectangle* logical_extents_buffer ,int buffer_size ,int* num_chars ,XRectangle* overall_ink_return ,XRectangle* overall_logical_return ) {
  DPRINTF("XwcTextPerCharExtents()\n");
  return _real_XwcTextPerCharExtents(font_set,text,num_wchars,ink_extents_buffer,logical_extents_buffer,buffer_size,num_chars,overall_ink_return,overall_logical_return);
}

extern "C" Status Xutf8TextPerCharExtents(XFontSet font_set ,_Xconst char* text ,int bytes_text ,XRectangle* ink_extents_buffer ,XRectangle* logical_extents_buffer ,int buffer_size ,int* num_chars ,XRectangle* overall_ink_return ,XRectangle* overall_logical_return ) {
  DPRINTF("Xutf8TextPerCharExtents()\n");
  return _real_Xutf8TextPerCharExtents(font_set,text,bytes_text,ink_extents_buffer,logical_extents_buffer,buffer_size,num_chars,overall_ink_return,overall_logical_return);
}

extern "C" void XmbDrawText(Display* display ,Drawable d ,GC gc ,int x ,int y ,XmbTextItem* text_items ,int nitems ) {
  DPRINTF("XmbDrawText()\n");
  _real_XmbDrawText(display,d,gc,x,y,text_items,nitems);
}

extern "C" void XwcDrawText(Display* display ,Drawable d ,GC gc ,int x ,int y ,XwcTextItem* text_items ,int nitems ) {
  DPRINTF("XwcDrawText()\n");
  _real_XwcDrawText(display,d,gc,x,y,text_items,nitems);
}

extern "C" void Xutf8DrawText(Display* display ,Drawable d ,GC gc ,int x ,int y ,XmbTextItem* text_items ,int nitems ) {
  DPRINTF("Xutf8DrawText()\n");
  _real_Xutf8DrawText(display,d,gc,x,y,text_items,nitems);
}

extern "C" void XmbDrawString(Display* display ,Drawable d ,XFontSet font_set ,GC gc ,int x ,int y ,_Xconst char* text ,int bytes_text ) {
  DPRINTF("XmbDrawString()\n");
  _real_XmbDrawString(display,d,font_set,gc,x,y,text,bytes_text);
}

extern "C" void XwcDrawString(Display* display ,Drawable d ,XFontSet font_set ,GC gc ,int x ,int y ,_Xconst wchar_t* text ,int num_wchars ) {
  DPRINTF("XwcDrawString()\n");
  _real_XwcDrawString(display,d,font_set,gc,x,y,text,num_wchars);
}

extern "C" void Xutf8DrawString(Display* display ,Drawable d ,XFontSet font_set ,GC gc ,int x ,int y ,_Xconst char* text ,int bytes_text ) {
  DPRINTF("Xutf8DrawString()\n");
  _real_Xutf8DrawString(display,d,font_set,gc,x,y,text,bytes_text);
}

extern "C" void XmbDrawImageString(Display* display ,Drawable d ,XFontSet font_set ,GC gc ,int x ,int y ,_Xconst char* text ,int bytes_text ) {
  DPRINTF("XmbDrawImageString()\n");
  _real_XmbDrawImageString(display,d,font_set,gc,x,y,text,bytes_text);
}

extern "C" void XwcDrawImageString(Display* display ,Drawable d ,XFontSet font_set ,GC gc ,int x ,int y ,_Xconst wchar_t* text ,int num_wchars ) {
  DPRINTF("XwcDrawImageString()\n");
  _real_XwcDrawImageString(display,d,font_set,gc,x,y,text,num_wchars);
}

extern "C" void Xutf8DrawImageString(Display* display ,Drawable d ,XFontSet font_set ,GC gc ,int x ,int y ,_Xconst char* text ,int bytes_text ) {
  DPRINTF("Xutf8DrawImageString()\n");
  _real_Xutf8DrawImageString(display,d,font_set,gc,x,y,text,bytes_text);
}

extern "C" XIM XOpenIM(Display* dpy ,struct _XrmHashBucketRec* rdb ,char* res_name ,char* res_class ) {
  DPRINTF("XOpenIM()\n");
  return _real_XOpenIM(dpy,rdb,res_name,res_class);
}

extern "C" Status XCloseIM(XIM im ) {
  DPRINTF("XCloseIM()\n");
  return _real_XCloseIM(im);
}

extern "C" char *XGetIMValues(XIM im , ...) {
  DPRINTF("XGetIMValues()\n");
  return _real_XGetIMValues(im,NULL);
}

extern "C" char *XSetIMValues(XIM im , ...) {
  DPRINTF("XSetIMValues()\n");
  return _real_XSetIMValues(im,NULL);
}

extern "C" Display *XDisplayOfIM(XIM im ) {
  DPRINTF("XDisplayOfIM()\n");
  return _real_XDisplayOfIM(im);
}

extern "C" char *XLocaleOfIM(XIM im) {
  DPRINTF("XLocaleOfIM()\n");
  return _real_XLocaleOfIM(im);
}

extern "C" XIC XCreateIC(XIM im , ...) {
  DPRINTF("XCreateIC()\n");
  return _real_XCreateIC(im,NULL);
}

extern "C" void XDestroyIC(XIC ic ) {
  DPRINTF("XDestroyIC()\n");
  _real_XDestroyIC(ic);
}

extern "C" void XSetICFocus(XIC ic ) {
  DPRINTF("XSetICFocus()\n");
  _real_XSetICFocus(ic);
}

extern "C" void XUnsetICFocus(XIC ic ) {
  DPRINTF("XUnsetICFocus()\n");
  _real_XUnsetICFocus(ic);
}

extern "C" wchar_t *XwcResetIC(XIC ic ) {
  DPRINTF("XwcResetIC()\n");
  return _real_XwcResetIC(ic);
}

extern "C" char *XmbResetIC(XIC ic ) {
  DPRINTF("XmbResetIC()\n");
  return _real_XmbResetIC(ic);
}

extern "C" char *Xutf8ResetIC(XIC ic ) {
  DPRINTF("Xutf8ResetIC()\n");
  return _real_Xutf8ResetIC(ic);
}

extern "C" char *XSetICValues(XIC ic , ...) {
  DPRINTF("XSetICValues()\n");
  return _real_XSetICValues(ic,NULL);
}

extern "C" char *XGetICValues(XIC ic , ...) {
  DPRINTF("XGetICValues()\n");
  return _real_XGetICValues(ic,NULL);
}

extern "C" XIM XIMOfIC(XIC ic ) {
  DPRINTF("XIMOfIC()\n");
  return _real_XIMOfIC(ic);
}

extern "C" Bool XFilterEvent(XEvent* event ,Window window ) {
  DPRINTF("XFilterEvent()\n");
  return _real_XFilterEvent(event,window);
}

extern "C" int XmbLookupString(XIC ic ,XKeyPressedEvent* event ,char* buffer_return ,int bytes_buffer ,KeySym* keysym_return ,Status* status_return ) {
  DPRINTF("XmbLookupString()\n");
  return _real_XmbLookupString(ic,event,buffer_return,bytes_buffer,keysym_return,status_return);
}

extern "C" int XwcLookupString(XIC ic ,XKeyPressedEvent* event ,wchar_t* buffer_return ,int wchars_buffer ,KeySym* keysym_return ,Status* status_return ) {
  DPRINTF("XwcLookupString()\n");
  return _real_XwcLookupString(ic,event,buffer_return,wchars_buffer,keysym_return,status_return);
}

extern "C" int Xutf8LookupString(XIC ic ,XKeyPressedEvent* event ,char* buffer_return ,int bytes_buffer ,KeySym* keysym_return ,Status* status_return ) {
  DPRINTF("Xutf8LookupString()\n");
  return _real_Xutf8LookupString(ic,event,buffer_return,bytes_buffer,keysym_return,status_return);
}

extern "C" XVaNestedList XVaCreateNestedList(int unused, ...) {
  DPRINTF("XVaCreateNestedList()\n");
  return _real_XVaCreateNestedList(unused,NULL);
}

extern "C" Bool XRegisterIMInstantiateCallback(Display* dpy ,struct _XrmHashBucketRec* rdb ,char* res_name ,char* res_class ,XIDProc callback ,XPointer client_data ) {
  DPRINTF("XRegisterIMInstantiateCallback()\n");
  return _real_XRegisterIMInstantiateCallback(dpy,rdb,res_name,res_class,callback,client_data);
}

extern "C" Bool XUnregisterIMInstantiateCallback(Display* dpy ,struct _XrmHashBucketRec* rdb ,char* res_name ,char* res_class ,XIDProc callback ,XPointer client_data ) {
  DPRINTF("XUnregisterIMInstantiateCallback()\n");
  return _real_XUnregisterIMInstantiateCallback(dpy,rdb,res_name,res_class,callback,client_data);
}

extern "C" Status XInternalConnectionNumbers(Display* dpy ,int** fd_return ,int* count_return ) {
  DPRINTF("XInternalConnectionNumbers()\n");
  return _real_XInternalConnectionNumbers(dpy,fd_return,count_return);
}

extern "C" void XProcessInternalConnection(Display* dpy ,int fd ) {
  DPRINTF("XProcessInternalConnection()\n");
  _real_XProcessInternalConnection(dpy,fd);
}

extern "C" Status XAddConnectionWatch(Display* dpy ,XConnectionWatchProc callback ,XPointer client_data ) {
  DPRINTF("XAddConnectionWatch()\n");
  return _real_XAddConnectionWatch(dpy,callback,client_data);
}

extern "C" void XRemoveConnectionWatch(Display* dpy ,XConnectionWatchProc callback ,XPointer client_data ) {
  DPRINTF("XRemoveConnectionWatch()\n");
  _real_XRemoveConnectionWatch(dpy,callback,client_data);
}

extern "C" void XSetAuthorization(char * name ,int namelen ,char * data ,int datalen ) {
  DPRINTF("XSetAuthorization()\n");
  _real_XSetAuthorization(name,namelen,data,datalen);
}

extern "C" int _Xmbtowc(wchar_t * wstr ,
#ifdef ISC
char const * str ,size_t len 
#else
char * str ,int len 
#endif
) {
  DPRINTF("_Xmbtowc()\n");
  return _real__Xmbtowc(wstr,str,len);
}

extern "C" int _Xwctomb(char * str ,wchar_t wc ) {
  DPRINTF("_Xwctomb()\n");
  return _real__Xwctomb(str,wc);
}

extern "C" Bool XGetEventData(Display* dpy ,XGenericEventCookie* cookie) {
  DPRINTF("XGetEventData()\n");
  return _real_XGetEventData(dpy,cookie);
}

extern "C" void XFreeEventData(Display* dpy ,XGenericEventCookie* cookie) {
  DPRINTF("XFreeEventData()\n");
  _real_XFreeEventData(dpy,cookie);
}
/* Auto generated code ends */
