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

Use DEBUGGING=1 flag for a debug build.

    make [DEBUGGING=1] [check]

### Prerequisites

## References
