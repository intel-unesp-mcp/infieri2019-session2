#include <stdio.h>
#include <omp.h>

int main()
{
    int varShared = 9;
    int varPrivate = 6;
    int varFirstPrivate = 3;

    #pragma omp parallel private(varPrivate) firstprivate(varFirstPrivate)
    {
        varPrivate = 0; // private variables should be initialized within the parallel region
        varShared += 1; // undefined behavior due to race condition!
        varPrivate += 1;
        varFirstPrivate += 1;
        printf("For thread %d,\t varShared=%d\t varPrivate=%d\t varFirstPrivate=%d\n",
                omp_get_thread_num(), varShared, varPrivate, varFirstPrivate);
    }
    printf("After parallel region, varShared=%d\t varPrivate=%d\t varFirstPrivate=%d\n",
            varShared, varPrivate, varFirstPrivate);
}
