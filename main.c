#include "main.h"

int main(void){
    FILE *fp;
    Calculator calculator = new_Calculator();
    boolean reply = true;
    double a, b, result;
    char op;

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