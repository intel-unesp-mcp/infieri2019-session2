#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

void Sum(const int* A, const int start, const int end, int & result){
    for (int j=start; j < end; j++) result += A[j];
}

int main(){
    const int N=1000;
    int* A = (int*) malloc(N*sizeof(int));
    for (int i=0; i<N; i++) A[i]=i;

    // Compute the sum with two tasks
    int sum1=0, sum2=0;

    _Cilk_spawn Sum(A, 0, N/2, sum1);
    _Cilk_spawn Sum(A, N/2, N, sum2);

    // Wait for forked off sums to complete
    _Cilk_sync;

    printf("Result=%d (must be %d)\n", sum1+sum2, ((N-1)*N)/2);

    free(A);
}
