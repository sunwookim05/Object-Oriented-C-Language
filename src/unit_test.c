/* 
    result
    원본 선언 :0.008374
    extern: 0.007954
*/
#include <stdio.h>
#include <time.h>

int main(void){
    double start, end;
    int a;
    double r;

    // extern int plus(int, int);
    int plus(int a, int b);

    for(int i = 0; i < 1000; i++){
        start = ((double)clock() / CLOCKS_PER_SEC);    
        a = plus(1, 2);
        end = ((double)clock() / CLOCKS_PER_SEC);
        a = 0;
        r += (end - start);
    }
    printf("time: %lf\n", r);
}

int plus(int a, int b){
    return a + b;
}