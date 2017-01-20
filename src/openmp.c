#include <stdio.h>
#include <omp.h>

int main()
{
    const int nthreads=omp_get_max_threads();
    printf("OpenMP is running with %d threads\n", nthreads);

#pragma omp parallel
    printf("Hello World from thread %d\n", omp_get_thread_num());
}
