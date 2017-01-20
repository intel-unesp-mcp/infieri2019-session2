#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    const int N=10000;
    int sum = 0;

#pragma omp parallel for reduction(+:sum)
    for (i=0; i<N; i++) sum += i;
    
    printf("sum = %d (must be %d)\n", sum, ((N-1)*N)/2);
}
