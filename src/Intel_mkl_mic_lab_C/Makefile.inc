
 # Copyright 2003-2013 Intel Corporation. All Rights Reserved.
 
 # The source code contained or described herein and all documents related 
 # to the source code ("Material") are owned by Intel Corporation or its
 # suppliers or licensors.  Title to the Material remains with Intel Corporation
 # or its suppliers and licensors.  The Material is protected by worldwide
 # copyright and trade secret laws and treaty provisions.  No part of the
 # Material may be used, copied, reproduced, modified, published, uploaded,
 # posted, transmitted, distributed, or disclosed in any way without Intel's
 # prior express written permission.
 
 # No license under any patent, copyright, trade secret or other intellectual
 # property right is granted to or conferred upon you by disclosure or delivery
 # of the Materials, either expressly, by implication, inducement, estoppel
 # or otherwise.  Any license under such intellectual property rights must
 # be express and approved by Intel in writing.

RM := rm -rf
MD := mkdir -p
MV := mv
TOUCH := touch
TRUNC := cat /dev/null >

ifneq (,$(filter $(shell uname -m),x86_64))
	IA := intel64
else ifneq (,$(filter AMD64, $(PROCESSOR_ARCHITEW6432) $(PROCESSOR_ARCHITECTURE)))
	IA := intel64
else
	IA := ia32
endif

MIC := 0
ifeq (2,$(MIC))
	IA := mic
endif

NULL :=
NAME := $(NULL)
BINX := $(NULL)
OPTX := $(NULL)

ifeq ($(IA),ia32)
	MKLBITS := $(NULL)
	BITS := 32
	LA := $(NULL)
	WA := Win32
	XA := x86
	EA := x86
else
	MKLBITS := _lp64
	BITS := 64
	LA := 64
	WA := x64
	XA := x64
	EA := em64t
endif

ifeq ($(TBBROOT),)
	TBBROOT := $(TBB30_INSTALL_DIR)
endif
ifeq ($(TBB_TARGET_VS),)
	TBB_TARGET_VS := vc9
endif

ifeq ($(OCLROOT),)
	OCLROOT := $(INTELOCLSDKROOT)
endif

# prefer the Intel compiler
ifneq ($(shell which icpc 2> /dev/null),)
	CXX := icpc
else ifneq ($(shell which icc 2> /dev/null),)
	CXX := icc
else ifneq ($(shell which icl 2> /dev/null),)
	CXX := icl
else ifneq ($(shell which cl 2> /dev/null),)
	CXX := cl
endif

BLD := build/$(IA)
BIN := bin/$(IA)

OPT := O2
HOST := 1
DIR := 1
EXT := 1
FMA := 1
FPX := 0
IPO := 0
OMP := 0
PAR := 0
MPI := 0
PGO := 0
GAP := 0
DBG := 0

FORTRAN := 1

# 0: no aliasing assumed
ALI := 0

VEC := 1
VEC-THRESHOLD := 100

SSA := 0
SSA-DIR := $(BLD)

RPT := $(NULL)
RPT-LEVEL := 1
RPT-FILE := $(NULL)
RPT-GENERATION := $(NULL)

# example: granularity=thread,compact
KMP := $(NULL)

MKLCTRT := intel
IS_GCC := 0
IS_ICC := 0
IS_ICL := 0
IS_LCC := 0
IS_VCC := 0
IS_PGC := 0

LNK := $(CXX)
EXE := $(NULL)
OBJ := o
COMPILE := -c
CXOUT = -o $@
LDOUT = -o $@

COMPILER := $(basename $(notdir $(CXX)))
ifneq (,$(filter $(COMPILER),g++ gcc))
	IS_GCC := 1
	MKLCTRT := gnu
	LDIR := -L
	LINC := -l
	LEXT := $(NULL)
	FC := gfortran
else ifneq (,$(filter $(COMPILER),icc icpc mpiicc))
	IS_ICC := 1
	LDIR := -L
	LINC := -l
	LEXT := $(NULL)
	FC := ifort
else ifneq (,$(filter $(COMPILER),icl mpicc mpicxx))
	IS_ICL := 1
	LDIR := -LIBPATH:
	LINC := $(NULL)
	LEXT := .lib
	OBJ := obj
	EXE := .exe
	FC := ifort
else ifneq (,$(filter $(COMPILER),clang clang++))
	IS_LCC := 1
	MKLCTRT := gnu
	LDIR := -L
	LINC := -l
	LEXT := $(NULL)
else ifneq (,$(filter $(COMPILER),cl mpicl))
	IS_VCC := 1
	LDIR := -LIBPATH:
	LINC := $(NULL)
	LEXT := .lib
	OBJ := obj
	EXE := .exe
	CXOUT := $(NULL)
	LDOUT = -OUT:$@
else ifeq (pgcpp,$(COMPILER))
	IS_PGC := 1
	MKLCTRT := pgi
	LDIR := -L
	LINC := $(NULL)
	LEXT := .lib
	OBJ := obj
	EXE := .exe
	FC := pgf90
endif

GCC := $(NULL)
GFC := $(NULL)
ICC := $(NULL)
ICL := $(NULL)
IFC := $(NULL)
IFW := $(NULL)
LCC := $(NULL)
VCC := $(NULL)
PGC := $(NULL)
PGF := $(NULL)
MIC_CXXFLAGS := $(NULL)
MIC_LDFLAGS  := $(NULL)

DEFINES := $(NULL)

HEADERS := \
	$(wildcard *.hpp) \
	$(wildcard *.h) \
	$(NULL)

VPATH := \
	$(NULL)

SOURCES := \
	$(wildcard *.cpp) \
	$(wildcard *.c) \
	$(NULL)

SOURCES_FORTRAN := \
	$(wildcard *.f90) \
	$(wildcard *.f) \
	$(NULL)

INCLUDE_PATHS := .
LD_PATHS := $(NULL)
LD_LIBS := $(NULL)
LD_PATHS_WIN := $(NULL)
LD_LIBS_WIN := $(NULL)
LD_PATHS_MIC := $(NULL)
LD_LIBS_MIC := $(NULL)
LDLIBS_FORTRAN := $(NULL)
ARGS := $(NULL)

.PHONY: default

DEFAULT = \
	$(BIN)/$(NAME)$(BINX)$(EXE) \
	$(NULL)

CLEAN = \
	$(OBJECTS) \
	$(NULL)

PGOCLEAN = \
	*.dyn \
	pgopti.dpi \
	pgopti.dpi.lock \
	$(NULL)

REALCLEAN = \
	$(DEFAULT) \
	$(RPT-FILE) \
	$(NULL)

path = $(subst $(NULL) ,?,$1)
