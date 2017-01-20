/*
// Copyright 2003-2013 Intel Corporation. All Rights Reserved.
// 
// The source code contained or described herein and all documents related 
// to the source code ("Material") are owned by Intel Corporation or its
// suppliers or licensors.  Title to the Material remains with Intel Corporation
// or its suppliers and licensors.  The Material is protected by worldwide
// copyright and trade secret laws and treaty provisions.  No part of the
// Material may be used, copied, reproduced, modified, published, uploaded,
// posted, transmitted, distributed, or disclosed in any way without Intel's
// prior express written permission.
// 
// No license under any patent, copyright, trade secret or other intellectual
// property right is granted to or conferred upon you by disclosure or delivery
// of the Materials, either expressly, by implication, inducement, estoppel
// or otherwise.  Any license under such intellectual property rights must
// be express and approved by Intel in writing.

*/
#ifndef GEMM_MKL_HPP
#define GEMM_MKL_HPP

#include <stdexcept>

#if !defined(USE_GEMM_CBLAS)
# define USE_GEMM_CBLAS
#endif

#if defined(USE_GEMM_CBLAS)
# include <mkl_cblas.h>
#else
# include <mkl_blas.h>
#endif
#include <mkl.h>

#if defined(_WIN32)
# define ATTRIBUTE(A) __declspec(A)
#elif defined(__GNUC__)
# define ATTRIBUTE(A) __attribute__((A))
#else
# define ATTRIBUTE(A)
#endif

#if defined(__INTEL_OFFLOAD) && !defined(_WIN32)
# define TARGET(A) ATTRIBUTE(target(A))
#else
# define TARGET(A)
#endif

#if defined(__INTEL_COMPILER)
// compiler option: -restrict (Windows: /Qrestrict)
# define RESTRICT restrict
#elif defined(__GNUC__)
# define RESTRICT __restrict__
#else
# define RESTRICT
#endif


template<typename T>
void gemm_mkl(T* result, const T* a, const T* b, std::size_t arows, std::size_t acols, std::size_t bcols)
{
  struct TARGET(mic) local {
    static void gemm(...) { throw std::runtime_error("not implemented for this type combination!"); }
    static void gemm(float* result, const float* a, const float* b, MKL_INT arows, MKL_INT acols, MKL_INT bcols) {
      const float alpha = 1.f, beta = 0.f;
#if defined(USE_GEMM_CBLAS)
      cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, arows, bcols, acols, alpha, a, acols, b, bcols, beta, result, bcols);
#else
      const char trans = 'N';
      SGEMM(&trans, &trans, &bcols, &arows, &acols, &alpha, b, &bcols, a, &acols, &beta, result, &bcols);
#endif
    }
    static void gemm(double* result, const double* a, const double* b, MKL_INT arows, MKL_INT acols, MKL_INT bcols) {
      const double alpha = 1.0, beta = 0.0;
#if defined(USE_GEMM_CBLAS)
      cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, arows, bcols, acols, alpha, a, acols, b, bcols, beta, result, bcols);
#else
      const char trans = 'N';
      DGEMM(&trans, &trans, &bcols, &arows, &acols, &alpha, b, &bcols, a, &acols, &beta, result, &bcols);
#endif
    }
  };

  local::gemm(result, a, b, static_cast<MKL_INT>(arows), static_cast<MKL_INT>(acols), static_cast<MKL_INT>(bcols));
}

#endif // GEMM_MKL_HPP
