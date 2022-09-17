#include "main.h"

import Sys System;
import Scanner sc;

void setUpIoBase(IOBase *this){
    import void inPut(double*, double*, char*);
    import void outPut(double, double, char, double, FILE*);

    this->inPut = inPut;
    this->outPut = outPut;
}

void setUpPublic(Calculator *this){
    import void requestReply(boolean*);
    import double calculate(double, double, char);

    this->requestReply = requestReply;
    this->calculate = calculate;
}

void setUpPrivate(Calculator *this){
    setUpPublic(this);
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
    *a = sc.nextDouble();
    *op = sc.nextChar();
    *b = sc.nextDouble();
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
    char answer = sc.nextChar();

    if(answer == 'y' || answer == 'Y')
        *reply = true;
    else if(answer == 'n' || answer == 'N')
        *reply = false;
    else{
        System.out.println("Invalid input!");
        requestReply(reply);
    }
}

double calculate(double a, double b, char op){
    Calculator this;
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