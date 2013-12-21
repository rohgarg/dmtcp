# DMTCP Plugin for X Client Applications

## Introduction

## X Window System Architecture

                                 +---------+
                                 |  App2   |
         +------+    +------+    +---------+
         | App1 |    |  WM  |    | Toolkit |
         +------+    +------+    +---------+
         | Xlib |    | Xlib |    |   Xlib  |
         +------+    +------+    +---------+
            ^           ^             ^
            |           |             |
     ===============X Protocol===================
                        |
                        v
        +-------------------------------------+
        |                 X Server            |
        +-------------------------------------+
        |             Device Drivers          |
        +-------------------------------------+


## Design of the plugin

## Build steps

    make [DEBUGGING=1] [PYTHON_TEST=1] [PLUGIN_ISOLATED_RUN=1] [check[-*]]

### Prerequisites

## Debugging
  
- Debug build:
    + Use `make DEBUGGING=1` for a debug build

- Testing the plugin without DMTCP:
    + Use `make PLUGIN_ISOLATED_RUN=1` to enable this option
    + Run the application using:

            LD_PRELOAD=./dmtcp_xlibhijack.so /path/to/application <args>

    + Debug the application using: 

            LD_PRELOAD=./dmtcp_xlibhijack.so gdb --args /path/to/application <args>

## References
