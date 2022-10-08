#include "main.h"
#include "Calculator.h"
#include "System.h"
#include "Scanner.h"

import Sys System;

void setUpIoBase(IOBase *this){
    import void inPut(long double*, long double*, char*);
    import void outPut(long double, long double, char, long double, FILE*);

    this->inPut = inPut;
    this->outPut = outPut;
}

void setUpPublic(Calculator *this){
    import void requestReply(boolean*);
    import long double calculate(long double, long double, char);

    this->requestReply = requestReply;
    this->calculate = calculate;
}

void setUpPrivate(Calculator *this){
    setUpPublic(this);
    import long double plus(long double, long double);
    import long double minus(long double, long double);
    import long double multiply(long double, long double);
    import long double divide(long double, long double);
    import long double mod(long double, long double);
    import long double power(long double, long double);
    
    this->plus = plus;
    this->minus = minus;
    this->multiply = multiply;
    this->divide = divide;
    this->mod = mod;
    this->power = power;
}

void setUpProtected(Calculator *this){
    IOBase ioBase;
    
    setUpIoBase(&ioBase);

    this->in.inPut = ioBase.inPut;
    this->out.outPut = ioBase.outPut;
}

long double plus(long double a, long double b){
    return a + b;
}

long double minus(long double a, long double b){
    return a - b;
}

long double multiply(long double a, long double b){
    return a * b;
}

long double divide(long double a, long double b){
    return a / b;
}

long double mod(long double a, long double b){
    return ((int64_t)a) % ((int64_t)b);
}

long double power(long double a, long double b){
    long double result = a; 
    if(!b) 
        return 1;
    else if(!a) 
        return 0; 
    else 
        for(long double i = 0; i < (b - 1); i++) 
            result *= a; 
    return result;
}

void inPut(long double *a, long double *b, char *op){
    Scanner sc = new_Scanner(System.in);
    *a = sc.nextLDouble();
    *op = sc.nextChar();
    *b = sc.nextLDouble();
}

void outPut(long double a, long double b, char op, long double result, FILE *fp){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d : ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fp, "%g %c %g = %g\n", a, op, b, result);
    System.out.println("%g %c %g = %g", a, op, b, result);
}

void requestReply(boolean *reply){
    Scanner sc = new_Scanner(System.in);
    System.out.print("Do you want to play again? (y/n): ");
    char answer = sc.nextChar();

    if(answer == 'y' || answer == 'Y'){
        *reply = true;
    }else if(answer == 'n' || answer == 'N'){
        *reply = false;
    }else{
        System.out.println("Invalid input!");
        requestReply(reply);
    }
}

long double calculate(long double a, long double b, char op){
    Calculator this = new_Calculator();
    setUpPrivate(&this);
    switch(op){
        case '+': return this.plus(a, b);
        case '-': return this.minus(a, b);
        case '*': return this.multiply(a, b);
        case '/': return this.divide(a, b);
        case '%': return this.mod(a, b);
        case '^': return this.power(a, b);
        default: return 0;
    }
}

/**
 * @brief Create a new Calculator object
 * @return Calculator 
 */
Calculator new_Calculator(){
    Calculator this;
    setUpPublic(&this);
    return this;
}