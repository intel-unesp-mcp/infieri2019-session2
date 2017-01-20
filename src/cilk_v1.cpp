#include <stdio.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

int main(){
    const int nw=__cilkrts_get_nworkers();
    printf("Cilk Plus with %d workers\n", nw);

    _Cilk_for (int i=0; i<nw; i++) // Light workload: gets serialized
        printf("Hello World from worker %d\n", __cilkrts_get_worker_number());

#pragma cilk grainsize = 4
    _Cilk_for (int i=0; i<nw; i++){
        double f=1.0;
        while (f<1.0e40) f*=2.0; // Extra workload: gets parallelized
        printf("Hello again from worker %d (%f)\n", __cilkrts_get_worker_number(), f);
    }
}
