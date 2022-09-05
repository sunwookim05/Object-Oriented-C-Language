#include "main.h"
#include <time.h>

#pragma pack(push, 1)
typedef struct _Calculator{
    struct _IN{
        void (*inPut)(double*, double*, char*);
    }in;
    struct _OUT{
        void (*outPut)(double, double, char, double, FILE*);
    }out;
    void (*requestReply)(boolean*);
    double (*calculate)(double, double, char);
    double (*plus)(double, double);
    double (*minus)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);
    double (*mod)(double, double);
    double (*pow)(double, double);
}Calculator;
#pragma pack(pop)

void setUpPublic(Calculator *calculator){
    import void inPut(double*, double*, char*);
    import void outPut(double, double, char, double, FILE*);
    import void requestReply(boolean*);
    import double calculate(double, double, char);

    calculator->in.inPut = inPut;
    calculator->out.outPut = outPut;
    calculator->requestReply = requestReply;
    calculator->calculate = calculate;
}

void setUpPrivate(Calculator *calculator){
    setUpPublic(calculator);
    import double plus(double, double);
    import double minus(double, double);
    import double multiply(double, double);
    import double divide(double, double);
    import double mod(double, double);
    import double pow(double, double);
    
    calculator->plus = plus;
    calculator->minus = minus;
    calculator->multiply = multiply;
    calculator->divide = divide;
    calculator->mod = mod;
    calculator->pow = pow;
}

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

double calculate(double a, double b, char op);  
double plus(double a, double b){return a + b;}
double minus(double a, double b){return a - b;}
double multiply(double a, double b){return a * b;}
double divide(double a, double b){return a / b;}
double mod(double a, double b){return ((int64_t)a) % ((int64_t)b);}
double pow(double a, double b){double result = a; if(b == 0) return 1;else if(a == 0) return 0; else for(int i = 0; i < (b - 1); i++) result *= a; return result;}

void inPut(double *a, double *b, char *op){
    scanf("%lf %c %lf", a, op, b);
}

void outPut(double a, double b, char op, double result, FILE *fp){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d : ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fp, "%g %c %g = %g\n", a, op, b, result);
    System.out.println("%g %c %g = %g", a, op, b, result);
}
void requestReply(boolean *reply){
    System.out.print("Do you want to play again? (y/n): ");
    char answer;

    scanf(" %c", &answer);
    if(answer == 'y')
        *reply = true;
    else
        *reply = false;
}

double calculate(double a, double b, char op){
    Calculator calculator;
    setUpPrivate(&calculator);
    switch(op){
        case '+': return calculator.plus(a, b);
        case '-': return calculator.minus(a, b);
        case '*': return calculator.multiply(a, b);
        case '/': return calculator.divide(a, b);
        case '%': return calculator.mod(a, b);
        case '^': return calculator.pow(a, b);
        default: return 0;
    }
}