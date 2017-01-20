#include <stdio.h>
#include <cilk/reducer_opadd.h>
#include <cilk/cilk_api.h>

int main(){
    const int N=20;
    cilk::reducer_opadd<int> sum;
    sum.set_value(0);
    _Cilk_for (int i=0; i<N; i++){
        printf("%d\t%d:%d\n", __cilkrts_get_worker_number(), i, sum.get_value());
        sum = sum + i;
    }
    printf("Result=%d (must be %d)\n", sum.get_value(), ((N-1)*N)/2);
}
