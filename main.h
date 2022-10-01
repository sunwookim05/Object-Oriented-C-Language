#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#ifndef _MAIN_H
#define _MAIN_H

#define import extern
#define final const
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
typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;
typedef uint8_t boolean;

// struct Scanner;
// typedef struct Scanner Scanner;

#pragma pack(push, 1)
typedef struct _System{
    struct _OUT_{
        void (*print)(const String, ...);
        void (*println)(const String, ...);
    }out;
    struct __stdin_t{
        int(*read)();
    } in;
}Sys;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Scanner{
    char (*nextChar)(void);
    int8_t (*nextByte)(void);
    int16_t (*nextShort)(void);
    int32_t (*nextInt)(void);
    int64_t (*nextLong)(void);
    uint8_t (*nextUByte)(void);
    uint16_t (*nextUShort)(void);
    uint32_t (*nextUInt)(void);
    uint64_t (*nextULong)(void);
    boolean (*nextBoolean)(void);
    float (*nextFloat)(void);
    double (*nextDouble)(void);
    long double (*nextLDouble)(void);
    String (*next)(void);
    String (*nextLine)(void);
}Scanner;
#pragma pack(pop)

struct Scanner new_Scanner(struct __stdin_t);

#pragma pack(push, 1)
typedef struct _IOBase{
    void (*inPut)(double*, double*, char*);
    void (*outPut)(double, double, char, double, FILE*);
}IOBase;
#pragma pack(pop)

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
    struct _Calculator *this;
}Calculator;
#pragma pack(pop)

#endif