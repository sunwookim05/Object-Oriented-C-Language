#include "main.h"
#include "System.h"
#include "algorithm.h"

import SYSTEM System;

int main(void){
    Stack stack = new_Stack(double);
    double* a = (double*)malloc(sizeof(double) * 10);

    for(int i = 0; i < 10; i++){
        *(a + i) = i + 0.5;
        stack.push(&stack, (a + i));
        for(int j = 0; j < stack.top; j++)
            System.out.printf("%.2f ", stack.data[j]);
        System.out.println("");
    }

    System.out.println("");

    stack.clear(&stack);

    for(int i = 0; i < 10; i++){
        *(a + i) = i + 0.5;
        stack.push(&stack, (a + i));
        for(int j = 0; j < stack.top; j++)
            System.out.printf("%.2f ", stack.data[j]);
        System.out.println("");
    }

    for(int i = 0; i < 10; i++){
        stack.pop(&stack);
        for(int j = 0; j < stack.top; j++)
            System.out.printf("%.2f ", stack.data[j]);
        System.out.println("");
    }

    stack.delete(&stack);

    free(a);
    return 0;
}