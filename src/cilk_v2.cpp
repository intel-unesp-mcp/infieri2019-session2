#include <stdio.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

void Recurse(const int task){
    if (task<10){
        printf("Creating task %d...\n", task+1);
        _Cilk_spawn Recurse(task+1);
        long val=0; for (long i=0; i<(1L<<30L); i++) val+=i;
        printf("Result of task %d in worker %d is %ld\n", task,
            __cilkrts_get_worker_number(), val);
    }
}

int main()
{
    Recurse(0);
}
