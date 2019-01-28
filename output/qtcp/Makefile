#
# Makefile for the QSDL simulator 'qtcp'
#
# Authors: Marc Diefenbruch (md@informatik.uni-essen.de)
#          Axel Hirche (hirche@informatik.uni-essen.de)
#
# (C) 1995-98 University of Essen
#
# All rights reserved
#
# Supported Operations:
#
# -) make [all]            : Create simulator
# -) make depend           : Create dependencies
# -) make clean            : Delete object files and executable
# -) make veryclean        : make clean + delete Log and MSC files
# -) make find-error       : Debug
# -) make tags             : Create source browser database
#

###########################
# 0. Preliminaries:       #
###########################

SCRIPT = \
	case `uname -s` in \
		Linux)	case `uname -m` in \
					i?86)	echo ix86-linux;; \
					arm*)	echo arm-linux;; \
					sparc)	echo sparc-linux;; \
					*)		echo unknown-linux;; \
				esac;; \
		SunOS)	echo `uname -p`-SunOS;; \
		*)		echo unknown-unknown;; \
	esac

QUEST_HOSTTYPE := $(shell $(SCRIPT))

###########################
# 1. Makefile directives: #
###########################

.SILENT:
.PHONY: clean all
.SUFFIXES: .cpp .cpp.new .h .h.new .o

########################
# 2. Files and pathes: #
########################

OBJBASEDIR = obj
OBJDIR = $(OBJBASEDIR)/$(QUEST_HOSTTYPE)
OUTPUT = $(OBJDIR)/qtcp
LOGFILE = $(USER).$(QUEST_HOSTTYPE).make.log
DEPFILE = .depend.$(QUEST_HOSTTYPE)
INCDIR = $(QUEST_INC_DIR)
LIBDIR = $(QUEST_LIB_DIR)
X11_INCDIR = $(QUEST_X11_INC_DIR)
X11_LIBDIR = $(QUEST_X11_LIB_DIR)

###########################################
# 3. Tools, commands and command options: #
###########################################

EDITOR = $(QUEST_EDITOR)
TAGS = ctags -t
C++ = $(QUEST_CC)
MAKE_DEPEND = $(C++) -MM
MKDIR = mkdir
MV = mv -f
SED = sed
TOUCH = touch
DIFF = cpp-diff

###################################
# 4. Compiler and linker options: #
###################################

DEFINES = 
INCLUDES = -I$(QUEST_ADDITIONAL_INC_DIR) -I$(INCDIR) -I$(X11_INCDIR)
CFLAGS = $(QUEST_CC_FLAGS)
CDEBUG = $(QUEST_CC_DEBUG)
LFLAGS = $(QUEST_LD_FLAGS)
LIBS = -L$(LIBDIR) -L$(X11_LIBDIR) -lPEV -lSCL -lpthread -lm -lX11 $(QUEST_SOCKET_LIBS)

#####################################
# 5. Source files of the simulator: #
#####################################

SOURCES = Main.cpp\
          sys_qtcp.cpp\
          blk_application.cpp\
          pcs_application_loadgenerator.cpp\
          pcs_application_applicationmanager.cpp\
          blk_tcp.cpp\
          pcs_tcp_manager.cpp\
          pcs_tcp_port.cpp\
          blk_ip.cpp\
          pcs_ip_activity.cpp\
          blk_medium.cpp\
          pcs_medium_transport.cpp\
          Templates.cpp

HEADERS = sys_qtcp.h\
          blk_application.h\
          pcs_application_loadgenerator.h\
          pcs_application_applicationmanager.h\
          blk_tcp.h\
          pcs_tcp_manager.h\
          pcs_tcp_port.h\
          blk_ip.h\
          pcs_ip_activity.h\
          blk_medium.h\
          pcs_medium_transport.h

#####################################
# 6. Object files of the simulator: #
#####################################

OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

######################
# 7. Makefileregeln: #
######################

default: clean-rubbish $(OBJDIR) $(OUTPUT)

$(OUTPUT): $(OBJS) $(LIBDIR)/libPEV.a $(LIBDIR)/libSCL.a
	@echo Linking $(OUTPUT)...
	$(C++) $(LFLAGS) $(OUTPUT) $(OBJS) $(LIBS)

all: $(OUTPUT)

$(OBJDIR)/%.o: %.cpp $(DEPFILE)
	@echo Compiling $<...
	$(C++) $(CDEBUG) $(CFLAGS) $(DEFINES) $(INCLUDES) $< -o $@ 2>> $(LOGFILE)

%.cpp: %.cpp.new
	@if [ -f $< ]; then  \
		if [ \( -f $@ \) ] && $(DIFF) $< $@; then \
			echo Removing unchanged $<...; \
			$(RM) $<; \
		else\
			echo Moving changed or new $< to $@...; \
			$(MV) $< $@; \
		fi \
	fi

%.h: %.h.new
	@if [ -f $< ]; then  \
		if [ \( -f $@ \) ] && $(DIFF) $< $@; then \
			echo Removing unchanged $<...; \
			$(RM) $<; \
		else\
			echo Moving changed or new $< to $@...; \
			$(MV) $< $@; \
		fi \
	fi

%.new:

$(OBJBASEDIR):
	@if [ ! \( -d $(OBJBASEDIR) \) ]; then \
		echo Creating $(OBJBASEDIR) ...; \
		$(MKDIR) $(OBJBASEDIR); fi

$(OBJDIR): $(OBJBASEDIR)
	@if [ ! \( -d $(OBJDIR) \) ]; then \
		echo Creating $(OBJDIR) ...; \
		$(MKDIR) $(OBJDIR); fi

clean-log:
	-$(RM) *.log *.mpr *.rep

clean-rubbish:
	-$(RM) core *.bak *.log *~ $(LOGFILE)

clean-objects:
	-$(RM) $(OBJDIR)/*.o $(OUTPUT) *.o

clean: clean-rubbish clean-objects

veryclean: clean clean-log

find-error fe:
	$(EDITOR) -p $(LOGFILE)

tags: $(SOURCES)
	-$(TAGS) $(SOURCES)

$(DEPFILE) depend: $(SOURCES) $(HEADERS)
	@echo Building dependency file $(DEPFILE) ...
	$(MAKE_DEPEND) $(DEFINES) $(SOURCES) $(INCLUDES) > $(DEPFILE)
	$(SED) 's/^\(.*\)\.o/\$$(OBJDIR)\/\1\.o/g' $(DEPFILE) > $(DEPFILE).sed
	$(MV) $(DEPFILE).sed $(DEPFILE)

-include $(DEPFILE)
