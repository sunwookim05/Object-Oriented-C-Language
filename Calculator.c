#include "main.h"

import Sys System;

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

double plus(double a, double b){
    return a + b;
}

double minus(double a, double b){
    return a - b;
}

double multiply(double a, double b){
    return a * b;
}

double divide(double a, double b){
    return a / b;
}

double mod(double a, double b){
    return ((int64_t)a) % ((int64_t)b);
}

double pow(double a, double b){
    double result = a; 
    if(b == 0) 
        return 1;
    else if(a == 0) 
        return 0; 
    else 
        for(int i = 0; i < (b - 1); i++) 
            result *= a; 
    return result;
}

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