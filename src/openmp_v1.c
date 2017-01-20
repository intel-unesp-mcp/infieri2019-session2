#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    const int nthreads=omp_get_max_threads();
    printf("OpenMP is running with %d threads\n", nthreads);

#pragma omp parallel for
    for (i=0; i< nthreads; i++)
        printf("Hello World from thread %d on %d iteration\n", omp_get_thread_num(), i);
}
