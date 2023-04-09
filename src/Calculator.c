#include "main.h"
#include "Calculator.h"
#include "System.h"
#include "Scanner.h"

import SYSTEM System;

void setUpIoBase(IOBase *this){
    import void inPut(double*, double*, char*);
    import void outPut(double, double, char, double, FILE*);

    this->inPut = inPut;
    this->outPut = outPut;
}

void setUpPublic(Calculator *this){
    import boolean requestRetry();
    import double calculate(double, double, char);

    this->requestRetry = requestRetry;
    this->calculate = calculate;
}

void setUpPrivate(Calculator *this){
    import double plus(double, double);
    import double minus(double, double);
    import double multiply(double, double);
    import double divide(double, double);
    import double mod(double, double);
    import double pow(double, double);
    
    this->plus = plus;
    this->minus = minus;
    this->multiply = multiply;
    this->divide = divide;
    this->mod = mod;
    this->pow = pow;
}

void setUpProtected(Calculator *this){
    IOBase ioBase;
    
    setUpIoBase(&ioBase);

    this->in.inPut = ioBase.inPut;
    this->out.outPut = ioBase.outPut;
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
    Scanner sc = new_Scanner(System.in);
    *a = sc.nextDouble();
    *op = sc.nextChar();
    *b = sc.nextDouble();
}

void outPut(double a, double b, char op, double result, FILE *fp){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d : ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fp, "%.10000g %c %.10000g = %.10000g\n", a, op, b, result);
    System.out.println("%.10000g %c %.10000g = %.10000g", a, op, b, result);
}

boolean requestRetry(){
    Scanner sc = new_Scanner(System.in);
    System.out.print("Do you want to play again? (y/n): ");
    char answer = sc.nextChar();

    if(!((answer|0x20)^'y')) return true;
    else if(!((answer|0x20)^'n')) return false;
    else System.out.println("Invalid input!");
    return requestRetry();
}

double calculate(double a, double b, char op){
    Calculator this = new_Calculator();
    setUpPrivate(&this);
    switch(op){
        case '+': return this.plus(a, b);
        case '-': return this.minus(a, b);
        case '*': return this.multiply(a, b);
        case '/': return this.divide(a, b);
        case '%': return this.mod(a, b);
        case '^': return this.pow(a, b);
        default: return 0;
    }
}

Calculator new_Calculator(){
    Calculator this;
    setUpPublic(&this);
    return this;
}