############################################################
# Makefile for QUEST-Project
#
#
# Author: Marc Diefenbruch
# $Date: 1996/03/14 18:45:06 $
#
# (C) 1995, 1996, 1997, 1998 Universitaet GH Essen
#
# Type "make help" to see a list of supported targets.
############################################################

#################################
# Configure make
#################################

## suppress output of messages:
.SILENT:

## Declare suffixes to be used:
.SUFFIXES: .cpp .h .y .l .c .o

SHELL = /bin/sh

###############################################
# Set environment right, if not already set.
###############################################

## Don't rely on $HOSTTYPE being set correctly!
## Try to figure it out ourselves:

## Prevent make from interpreting special characters:
SCRIPT := \
	case `uname -s` in\
    	Linux)	case `uname -m` in\
					i?86) echo ix86-linux;;\
					arm*) echo arm-linux;;\
					sparc) echo sparc-linux;;\
					*) echo unknown-linux;;\
				esac;;\
		SunOS)	echo `uname -p`-SunOS;;\
		*) echo unknown-unknown;;\
	esac

## Run script and store result in variable:
QUEST_HOSTTYPE := $(shell $(SCRIPT))

## Load architecture specific information:
#include $(QUEST_INC_DIR)/makefiles/Makefile.$(QUEST_HOSTTYPE)


#######################################
## Set some variables right:
#######################################

## Set list of ultimate targets:
WORLD := quest xquest

## Set Suffixes:
BACKUP_SUFFIX := taz
LIB_SUFFIX := a

## Set programs to be used:
RM := /bin/rm
MV := /bin/mv
CP := /bin/cp
MKDIR = /bin/mkdir
#########################
## Set files and pathes:
#########################

## Top directory of source tree:
QUEST_SRC_ROOT := $(QUEST_HOME)/src

## Top directory for backup tree:
QUEST_BACKUP_ROOT := $(QUEST_SRC_ROOT)/backup

## Where to store releases:
RELEASE_TOP_DIR := $(QUEST_HOME)/release

## directories holding project components:
## ORDER IS IMPORTANT!!!
SUBDIRS := \
	ds \
	cg \
	qp \
	quest \
	scl \
	tl \
	pev

INSTALLED_INCLUDE_DIR := $(QUEST_HOME)/include
INSTALLED_LIBS_DIR := $(QUEST_HOME)/lib/$(QUEST_HOSTTYPE)
INSTALLED_BIN_DIR := $(QUEST_HOME)/bin/$(QUEST_HOSTTYPE)

INSTALLED_BINARIES := \
	quest

INSTALLED_LIBS := \
	DS \
	CG \
	QP \
	QUEST\
	SCL \
	TL \
	PEV

INSTALLED_INCLUDE_SUBDIRS := \
	DS \
	CG \
	QP \
	SCL \
	TL \
	PEV

############################################
#### Make rules
############################################

# rather than having to maintain a separate help file, all help
# is included in the makefile and marked with the character sequence
#***
# at THE BEGINNING of EACH help line. Help lines MUST come AFTER
# the commands associated with a rule!!!
# Display of the help text is accomplished via grep and less.

#***
#*** Supported make targets:
#***

help:
	grep "#\*\*\*" Makefile | less
#*** help:
#***     Display this help message.
#***

.PHONY: backup

backup:
	BACKUP_DIR=$(QUEST_BACKUP_ROOT)/`date +%d.%m.%y-%H.%M.%S`; \
	$(MKDIR) -p $$BACKUP_DIR; \
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X backup; \
		$(MV) $(QUEST_SRC_ROOT)/$$X/$$X.$(BACKUP_SUFFIX) $$BACKUP_DIR; \
	done; \
	cp $(QUEST_HOME)/src/Makefile $$BACKUP_DIR
#*** backup:
#***     Backup all parts of the project and store
#***     the archives in $(QUEST_BACKUP_PATH)/<time-stamp>
#***

all:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X; \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X install; \
	done
#*** all:
#***     Compile and install in all subdirectories.
#***     Install is needed due to dependencies
#***     between individual project parts.
#***

clean:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X clean; \
	done
#*** clean:
#***     Clean up all subdirectories.
#***

veryclean:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X veryclean; \
	done
#*** veryclean:
#***     Clean up all subdirectories and do a rcsclean.
#***

distclean:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X veryclean; \
	done; \
	for X in $(INSTALLED_LIBS); do \
		if [ -f $(INSTALLED_LIBS_DIR)/lib$$X.$(LIB_SUFFIX) ]; then \
			$(RM) -f $(INSTALLED_LIBS_DIR)/lib$$X.$(LIB_SUFFIX); \
		fi \
	done; \
	for X in $(INSTALLED_INCLUDE_SUBDIRS); do \
		$(RM) -f $(INSTALLED_INCLUDE_DIR)/$$X/*; \
	done; \
	for X in $(INSTALLED_BINARIES); do \
		if [ -f $(INSTALLED_BIN_DIR)/$$X ]; then \
			$(RM) -f $(INSTALLED_BIN_DIR)/$$X; \
		fi \
	done;
#*** distclean:
#***     Do a veryclean in all subdirectories and
#***     remove all installed files.
#***     Be careful with this!!!
#***

depend:
	for X in $(SUBDIRS); do \
		$(MAKE) -C $(QUEST_SRC_ROOT)/$$X depend; \
	done
#*** depend:
#***     Rebuild dependency databases in all subdirectories.
#***

install:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X install; \
	done
#*** install:
#***     Install all files from the subdirectories in
#***     their destination directories
#***

install-includes:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X install-includes; \
	done
#*** install-includes:
#***     Install all include files from the subdirectories in
#***     their destination directories.
#***

install-lib:
	for X in $(SUBDIRS); do \
		$(MAKE) $(QUEST_MAKEJOBS) -C $(QUEST_SRC_ROOT)/$$X install-lib; \
	done
#*** install-lib:
#***     Install all libraries from the subdirectories in
#***     their destination directories
#***

install-dirs:
	$(MKDIR) -p $(INSTALLED_LIBS_DIR); \
	for X in $(INSTALLED_INCLUDE_SUBDIRS); do \
		$(MKDIR) -p $(INSTALLED_INCLUDE_DIR)/$$X; \
	done; \
	$(MKDIR) -p $(INSTALLED_BIN_DIR)
