#include "main.h"
#include "Calculator.h"

import void setUpProtected(Calculator*);

int main(void){
    FILE *fp;
    Calculator calculator = new_Calculator();
    boolean retry = true;
    double a, b, result;
    char op;

    setUpProtected(&calculator);
    fp = fopen("log.txt", "w");

    while(retry){
        calculator.in.inPut(&a, &b, &op);
        result = calculator.calculate(a, b, op);
        calculator.out.outPut(a, b, op, result, fp);
        retry = calculator.requestRetry();
    }
    fclose(fp);

    return 0;
}