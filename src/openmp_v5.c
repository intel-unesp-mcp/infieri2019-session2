#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    const int N = 10000;
    int sum = 0;

    #pragma omp parallel for
    for (i=0; i<N; i++) {
    #pragma omp critical
        sum = sum + i; // only one thread at a time can execute this section
    }
    printf("sum = %d (must be %d)\n", sum, ((N-1)*N)/2);
}
