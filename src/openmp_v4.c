#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    const int N = 10000;
    int sum = 0;

    #pragma omp parallel for
    for (i=0; i<N; i++) { // race condition!
        sum = sum + i;
    }
    printf("sum = %d (should be %d)\n", sum, ((N-1)*N)/2);
}
