#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    const int nthreads=omp_get_max_threads();
    printf("OpenMP is running with %d threads\n", nthreads);

#pragma omp parallel
    {
        // any code placed here will be executed by all threads
        int private_integer=0;

#pragma omp for
        for (i=0; i< nthreads; i++) {
            // iteration will be distributed across all available threads
            printf("Hello World from thread %d (private_integer =  %d)\n", omp_get_thread_num(), private_integer);
        }
        // any code placed here will be executed by all threads
    }
}
