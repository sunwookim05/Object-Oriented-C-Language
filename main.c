/* 
    Compile Commands
        gcc -c Calculator.c
        gcc -c Systemout.c
        gcc -c main.c
        gcc -o main Calculator.o Systemout.o main.o

    Run main.exe
*/

#include "main.h"

import void setUpPublic(Calculator*);

int main(void){
    FILE *fp;
    Calculator calculator;
    boolean reply = true;
    double a, b, result;
    char op;

    fp = fopen("log.txt", "w");
    setUpPublic(&calculator);
    while(reply){
        calculator.in.inPut(&a, &b, &op);
        result = calculator.calculate(a, b, op);
        calculator.out.outPut(a, b, op, result, fp);
        calculator.requestReply(&reply);
    }
    fclose(fp);

    return 0;
}