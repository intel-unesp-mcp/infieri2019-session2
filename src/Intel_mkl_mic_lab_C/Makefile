
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

include Makefile.inc

TGT := 00_getting_started
NAME := $(basename $(TGT))

OPT := O3
IPO := 1
FPX := 1
OMP := 1

# Disable MKL calls when compiler recognizes matrix multiplication code
ICC += -no-opt-matmul
IFC += -no-opt-matmul
ICL += -Qopt-matmul-
IFW += -Qopt-matmul-

DEFINES := \
	NDEBUG \
	$(NULL)

HEADERS := \
	$(NULL)

SOURCES := \
	$(NAME).cpp \
	$(NULL)

SOURCES_FORTRAN := \
	02_gemm.f90 \
	02_gemm_solution.f90 \
	$(NULL)

INCLUDE_PATHS := \
	. \
	$(call path,$(MKLROOT)/include) \
	$(NULL)

LD_PATHS := \
	$(call path,$(MKLROOT)/lib/$(IA)) \
	$(NULL)

LD_LIBS := \
	mkl_intel$(MKLBITS) \
	mkl_$(MKLCTRT)_thread \
	mkl_core \
	rt \
	$(NULL)

LD_PATHS_WIN := \
	$(call path,$(MKLROOT)/lib/$(IA)) \
	$(NULL)

LD_LIBS_WIN := \
	mkl_rt \
	$(NULL)

LD_PATHS_MIC := \
	$(call path,$(MKLROOT)/lib/mic) \
	$(NULL)

LD_LIBS_MIC := \
	mkl_intel$(MKLBITS) \
	mkl_$(MKLCTRT)_thread \
	mkl_core \
	rt \
	$(NULL)

# Other adjustments
ICL += -Qdiag-disable:161
IFW += -Qdiag-disable:161

include Makefile.rules
