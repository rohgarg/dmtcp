#ifndef _XLIB_PLUGIN_DEBUG_H_
#define _XLIB_PLUGIN_DEBUG_H_

#define DEBUG_SIGNATURE "DEBUG [Xlib Plugin]: "

/* Enable this for debugging
 * #define XLIB_PLUGIN_DEBUG
 */

#ifdef XLIB_PLUGIN_DEBUG
#define DPRINTF(fmt, ...) \
    do { fprintf(stderr, DEBUG_SIGNATURE fmt, ## __VA_ARGS__); } while (0)
#else
#define DPRINTF(fmt, ...) \
    do { } while (0)
#endif

#ifdef PLUGIN_ISOLATED_RUN
 #undef NEXT_FNC
 #define NEXT_FNC(func)                                                      \
   ({                                                                        \
      static __typeof__(&func) _real_##func = (__typeof__(&func)) -1;        \
      if (_real_##func == (__typeof__(&func)) -1) {                          \
        __typeof__(&dlsym) dlsym_fnptr;                                      \
        dlsym_fnptr = &dlsym;                                                \
        _real_##func = (__typeof__(&func)) (*dlsym_fnptr) (RTLD_NEXT, #func);\
      }                                                                      \
    _real_##func;})  
#endif

#endif
