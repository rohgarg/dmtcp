# To demonstrate, do:  make check    [Checkpoints every 5 seconds]

# The name will be the same as the current directory name.
NAME=${shell basename $$PWD}

# By default, your resulting library will have this name.
LIBNAME=dmtcp_${NAME}hijack

# Modify if your DMTCP_ROOT is located elsewhere.
ifndef DMTCP_ROOT
  DMTCP_ROOT=../../..
endif
DMTCP_INCLUDE=${DMTCP_ROOT}/dmtcp/include

PLUGIN_INC_DIR=./include
PLUGIN_SRC_DIR=./src
PLUGIN_OBJ_DIR=./obj
PLUGIN_TEST_DIR=./tests

CSOURCES = $(wildcard $(PLUGIN_SRC_DIR)/*.c)
CXXSOURCES = $(wildcard ${PLUGIN_SRC_DIR}/*.cpp)

COBJECTS=$(patsubst ${PLUGIN_SRC_DIR}/%.c, ${PLUGIN_OBJ_DIR}/%.o, ${CSOURCES})
CXXOBJECTS=$(patsubst ${PLUGIN_SRC_DIR}/%.cpp, ${PLUGIN_OBJ_DIR}/%.o, ${CXXSOURCES})

X11_INCLUDES=$(shell pkg-config --cflags x11)
X11_LIBS=$(shell pkg-config --libs x11)

ifdef DEBUGGING
  DEBUG_FLAGS=-g -O0 -DXLIB_PLUGIN_DEBUG
endif

CFLAGS += -I${DMTCP_INCLUDE} -I${PLUGIN_INC_DIR} ${X11_INCLUDES} -DDMTCP -fPIC --std=gnu99 ${DEBUG_FLAGS}
CXXFLAGS += -I${DMTCP_INCLUDE} -I${PLUGIN_INC_DIR} ${X11_INCLUDES} -DDMTCP -fPIC ${DEBUG_FLAGS}

DEMO_PORT=7781

MKDIR=mkdir -p
REMOVE=rm -f
REMOVEDIR=rmdir
CHDIR=cd
MAKE=make

default: ${PLUGIN_OBJ_DIR} ${LIBNAME}.so

${PLUGIN_TEST_DIR}/Xlib_Beginner/Xlib_Beginner:
	${CHDIR} ${PLUGIN_TEST_DIR}/Xlib_Beginner; ${MAKE} link

check: ${PLUGIN_OBJ_DIR} ${LIBNAME}.so ${PLUGIN_TEST_DIR}/Xlib_Beginner/Xlib_Beginner
	# Note that full path of plugin (using $$PWD in this case) is required.
	${DMTCP_ROOT}/bin/dmtcp_launch --port ${DEMO_PORT}  \
	  --with-plugin $$PWD/${LIBNAME}.so ${PLUGIN_TEST_DIR}/Xlib_Beginner/Xlib_Beginner

# We link the library using C++ for compatibility with the main libdmtcp.so
${LIBNAME}.so: ${COBJECTS} ${CXXOBJECTS}
	${CXX} -shared -fPIC -o $@ $^ ${X11_LIBS}

${PLUGIN_OBJ_DIR}:
	${MKDIR} ${PLUGIN_OBJ_DIR}

${PLUGIN_OBJ_DIR}/%.o : ${PLUGIN_SRC_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@

${PLUGIN_OBJ_DIR}/%.o : ${PLUGIN_SRC_DIR}/%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

tidy:
	${REMOVE} *~ .*.swp dmtcp_restart_script*.sh ckpt_*.dmtcp

clean:
	${REMOVE} ${COBJECTS} ${CXXOBJECTS} ${LIBNAME}.so
	${REMOVEDIR} ${PLUGIN_OBJ_DIR}
	${CHDIR} ${PLUGIN_TEST_DIR}/Xlib_Beginner; ${MAKE} clean

distclean: clean
	${REMOVE} ${LIBNAME}.so *~ .*.swp dmtcp_restart_script*.sh ckpt_*.dmtcp
	${REMOVEDIR} ${PLUGIN_OBJ_DIR}
	${CHDIR} ${PLUGIN_TEST_DIR}/Xlib_Beginner; ${MAKE} clean

dist: distclean
	dir=`basename $$PWD`; cd ..; \
	  tar czvf $$dir.tar.gz --exclude-vcs ./$$dir
	dir=`basename $$PWD`; ls -l ../$$dir.tar.gz

.PHONY: default clean dist distclean
