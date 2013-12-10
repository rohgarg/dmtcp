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

#endif
