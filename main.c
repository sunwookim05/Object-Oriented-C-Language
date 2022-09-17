#include "main.h"

int main(void){
    FILE *fp;
    Calculator calculator;
    boolean reply = true;
    double a, b, result;
    char op;

    import void setUpPublic(Calculator*);
    import void setUpProtected(Calculator*);

    fp = fopen("log.txt", "w");
    setUpPublic(&calculator);
    setUpProtected(&calculator);

    while(reply){
        calculator.in.inPut(&a, &b, &op);
        result = calculator.calculate(a, b, op);
        calculator.out.outPut(a, b, op, result, fp);
        calculator.requestReply(&reply);
    }
    fclose(fp);

    return 0;
}