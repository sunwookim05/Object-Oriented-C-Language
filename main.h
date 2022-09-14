#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

#ifndef _MAIN_H
#define _MAIN_H

#define import extern
#define null NULL
#define false 0
#define true 1
typedef char *String;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint8_t boolean;

#pragma pack(push, 1)
typedef struct _System{
    struct _OUT_{
        void (*print)(const String, ...);
        void (*println)(const String, ...);
    }out;
}Sys;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _IOBase{
    void (*inPut)(double*, double*, char*);
    void (*outPut)(double, double, char, double, FILE*);
}IOBase;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _Calculator{
    struct _Calculator *this;
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

#endif