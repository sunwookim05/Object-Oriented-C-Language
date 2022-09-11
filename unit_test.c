#include "main.h"
#include <time.h>

int main(void){
    double start, end;

    // import int plus(int, int);
    int plus(int a, int b);

    start = (double)clock() / CLOCKS_PER_SEC;
    printf("%d\n", plus(1, 2));
    end = (double)clock() / CLOCKS_PER_SEC;
    printf("time: %lf\n", (end - start));
}

int plus(int a, int b){
    return a + b;
}