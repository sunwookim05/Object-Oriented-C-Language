#include "main.h"
#include "Calculator.h"
#include "System.h"

//import void setUpProtected(Calculator*);

//int main(void){
//    FILE *fp;
//    Calculator calculator = new_Calculator();
//    boolean retry = true;
//    double a, b, result;
//    char op;
//
//    setUpProtected(&calculator);
//    fp = fopen("log.txt", "w");
//
//    while(retry){
//        calculator.in.inPut(&a, &b, &op);
//        result = calculator.calculate(a, b, op);
//        calculator.out.outPut(a, b, op, result, fp);
//        retry = calculator.requestRetry();
//    }
//    fclose(fp);
//
//    return 0;
//}

import SYSTEM System;
import INTEGER Integer;

//TEST PLACE
int main(void){
    int* arr = (int*)malloc(sizeof(int) * 10);

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }

    System.out.println("Before sort");
    for(int i = 0; i < 10; i++){
        System.out.println(Integer.toString(arr[i]));
    }

    System.out.println("After sort");
    Integer.sort(arr, ASC);

    for(int i = 0; i < 10; i++){
        System.out.println(Integer.toString(arr[i]));
    }

    free(arr);   
    return 0;
}