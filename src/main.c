#include "main.h"
#include "Calculator.h"

import void setUpProtected(Calculator*);

int main(void){
    FILE *fp;
    Calculator calculator = new_Calculator();
    boolean reply = true;
    long double a, b, result;
    char op;

    setUpProtected(&calculator);
    fp = fopen("log.txt", "w");
    
    while(reply){
        calculator.in.inPut(&a, &b, &op);
        result = calculator.calculate(a, b, op);
        calculator.out.outPut(a, b, op, result, fp);
        calculator.requestReply(&reply);
    }
    fclose(fp);

    return 0;
}   