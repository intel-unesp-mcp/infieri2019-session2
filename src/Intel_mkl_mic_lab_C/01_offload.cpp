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

#pragma offload_attribute(push,target(mic))
#include "00_gemm_mkl.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cmath>


template<typename T>
void gemm(T *RESTRICT result, const T *RESTRICT a, const T *RESTRICT b, std::size_t arows, std::size_t acols, std::size_t bcols)
{
  const int A = static_cast<int>(arows);
  const int C = static_cast<int>(acols);
  const int B = static_cast<int>(bcols);

# pragma omp parallel for
  for (int i = 0; i < A; ++i) {
    for (int j = 0; j < B; ++j) {
      result[i*B+j] = 0;
    }

    for (int k = 0; k < C; ++k) {
      for (int j = 0; j < B; ++j) {
        result[i*B+j] += a[i*C+k] * b[k*B+j];
      }
    }
  }
}


template<typename T>
void run(T* result, T* expect, const T* a, const T* b,
  std::size_t arows, std::size_t acols, std::size_t bcols,
  std::size_t nrept)
{
  dsecnd(); gemm(result, a, b, arows, acols, bcols); // warmup
  double start = dsecnd();
  for (std::size_t i = 0; i < nrept; ++i) {
    gemm(result, a, b, arows, acols, bcols);
  }
  const double time1 = (dsecnd() - start) / nrept;

  gemm_mkl(expect, a, b, arows, acols, bcols); // warmup
  start = dsecnd();
  for (std::size_t i = 0; i < nrept; ++i) {
    gemm_mkl(expect, a, b, arows, acols, bcols);
  }
  const double time2 = (dsecnd() - start) / nrept;

  std::cout << "MKL: " << std::setw(5) << std::right << static_cast<int>(1E3 * time2 + 0.5) << " ms";
  if (0 < time2) {
    std::cout << "\t(" << (static_cast<int>(1E1 * time1 / time2 + 0.5) / 1E1) << "x)\n";
  }
  std::cout << "OWN: " << std::setw(5) << std::right << static_cast<int>(1E3 * time1 + 0.5) << " ms\t";
  std::cout.flush();
}


template<typename T> void nrand(T& a)
{
  static const double scale = 1.0 / RAND_MAX;
  a = static_cast<T>(scale * (2 * std::rand() - RAND_MAX));
}


template<typename T>
void compare(const T* result, const T* expect, std::size_t size,
  std::size_t& diff_count, double& diff_abs)
{
  const double tolerance = std::abs(diff_abs);
  diff_count = 0;
  diff_abs = 0;
  for (std::size_t i = 0; i < size; ++i) {
    const double d = std::abs(static_cast<double>(result[i]) - static_cast<double>(expect[i]));
    if (tolerance < d) {
      diff_abs = std::max(diff_abs, d);
      ++diff_count;
    }
  }
}

#pragma offload_attribute(pop)


int main(int argc, char* argv[])
{
  try {
    const std::size_t arows = 1 < argc ? std::atol(argv[1]) : 512;
    const char *const type = 2 < argc ? argv[2] : "d";
    const std::size_t acols = 3 < argc ? std::atol(argv[3]) : arows;
    const std::size_t bcols = 4 < argc ? std::atol(argv[4]) : arows;
    const std::size_t nrept = 5 < argc ? std::max(std::atol(argv[5]), 1l) : 5;

    const std::size_t size = arows * bcols;
    std::size_t diff_count = 0;
    const double tolerance = 1E-03;
    double diff_abs = tolerance;

    if ('f' == type[0]) { // single-precision
      typedef float T;
      std::vector<T> va(arows * acols), vb(acols * bcols);
      std::for_each(va.begin(), va.end(), nrand<T>);
      std::for_each(vb.begin(), vb.end(), nrand<T>);
      std::vector<T> vresult(size), vexpect(size);
      T *result = &vresult[0], *expect = &vexpect[0];
      const T *a = &va[0], *b = &vb[0];
      run(/*out*/result, /*out*/expect, /*in*/a, /*in*/b, arows, acols, bcols, nrept);
      compare(result, expect, size, diff_count, diff_abs);
    }
    else if ('d' == type[0]) { // double-precision
      typedef double T;
      std::vector<T> va(arows * acols), vb(acols * bcols);
      std::for_each(va.begin(), va.end(), nrand<T>);
      std::for_each(vb.begin(), vb.end(), nrand<T>);
      std::vector<T> vresult(size), vexpect(size);
      T *result = &vresult[0], *expect = &vexpect[0];
      const T *a = &va[0], *b = &vb[0];
      run(/*out*/result, /*out*/expect, /*in*/a, /*in*/b, arows, acols, bcols, nrept);
      compare(result, expect, size, diff_count, diff_abs);
    }
    else {
      throw std::runtime_error("unknown type requested!");
    }

    std::cout << "(ok=";
    const double correct = static_cast<double>(size - diff_count) / size;
    std::cout << static_cast<int>(100.0 * correct + 0.5) << "%, tol=" << tolerance;
    if (0 < diff_count) {
      std::cout << ", err=" << diff_abs;
    }
    std::cout << ")\n";
  }
  catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  catch(...) {
    std::cerr << "Error: unknown exception caught!\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
