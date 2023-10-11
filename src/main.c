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

int main(void){
    int* value = (int*)malloc(sizeof(int) * 5);
    srand(time(null));
    for(int i = 0; i < 5; i++){
        value[i] = rand() % 100;
    }
    System.out.println("Before sort");
    for(int i = 0; i < 5; i++){
        System.out.printf("%d ", value[i]);
    }
    System.out.println("");
    Integer.sort(value, ASC);
    System.out.println("After sort");
    for(int i = 0; i < 5; i++){
        System.out.printf("%d ", value[i]);
    }
    System.out.println("");
    for(int i = 0; i < 5; i++){
        value[i] = rand() % 100;
    }
    System.out.println("Before sort");
    for(int i = 0; i < 5; i++){
        System.out.printf("%d ", value[i]);
    }
    System.out.println("");
    Integer.sort(value, DES);
    System.out.println("After sort");
    for(int i = 0; i < 5; i++){
        System.out.printf("%d ", value[i]);
    }
    System.out.println("");
    free(value);

    System.out.println(Integer.toString(12345));


    return 0;
}