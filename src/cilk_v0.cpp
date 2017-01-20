#include <stdio.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

int main()
{
    const int nworkers=__cilkrts_get_nworkers();
    printf("Cilk Plus with %d workers\n", nworkers);

    _Cilk_for (int i=0; i<nworkers; i++) // Light workload: gets serialized
        printf("Hello World from worker %d\n", __cilkrts_get_worker_number());

    _Cilk_for (int i=0; i<nworkers; i++){
        double f=1.0;
        while (f<1.0e40) f*=2.0; // Extra workload: gets parallelized
        printf("Hello again from worker %d (%f)\n", __cilkrts_get_worker_number(), f);
    }
}
