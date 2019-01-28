#!/bin/sh

# *********************************************
# *** Please modify the following settings  ***
# *** according to your configuration.      ***
# *********************************************

# root of QUEST directory tree:
QUEST_HOME=/home/qsdl/new
export QUEST_HOME

# Add path to quest binary directory:
PATH=$PATH:$QUEST_HOME/bin/$HOSTTYPE
export PATH

# root of directory tree holding user directories
# for generated code.
QUEST_OUTPUT_DIR=$QUEST_HOME/output
export QUEST_OUTPUT_DIR

# directory holding specifications
QUEST_SPEC_DIR=$QUEST_HOME/specifications
export QUEST_SPEC_DIR

# the compiler to be used:
QUEST_CC=g++
export QUEST_CC

# default compiler flags:
QUEST_CC_FLAGS='-c'
export QUEST_CC_FLAGS

# debug flags for compiler:
QUEST_CC_DEBUG='-O6'
export QUEST_CC_DEBUG

# linker flags:
QUEST_LD_FLAGS='-o'
export QUEST_LD_FLAGS

# Path to X11 include files:
QUEST_X11_INC_DIR=/usr/X11/include
export QUEST_X11_INC_DIR

# Path to X11 libraries:
QUEST_X11_LIB_DIR=/usr/X11/lib
export QUEST_X11_LIB_DIR

# Path to Motif includes:
QUEST_MOTIF_INC_DIR=/usr/X11/include
export QUEST_MOTIF_INC_DIR

# Path to Motif libraries:
QUEST_MOTIF_LIB_DIR=/usr/X11/lib
export QUEST_MOTIF_LIB_DIR

# Path to socket and network libraries:
QUEST_SOCKET_LIBS=''
export QUEST_SOCKET_LIBS


# **********************************************
# *** DO NOT MODIFY ANYTHING BELOW THIS LINE ***
# *** unless you know what you are doing ;-) ***
# **********************************************

# the include path for QUEST include files:
QUEST_INC_DIR=$QUEST_HOME/include
export QUEST_INC_DIR

# the library path for QUEST libraries
QUEST_LIB_DIR=$QUEST_HOME/lib/$HOSTTYPE
export QUEST_LIB_DIR

# thread type to be used by evaluator.
QUEST_THREAD_TYPE=PThreads
export QUEST_THREAD_TYPE

# this if you need any strange includes.
QUEST_ADDITIONAL_INC_DIR=.
export QUEST_ADDITIONAL_INC_DIR
