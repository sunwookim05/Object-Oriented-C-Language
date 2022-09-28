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

#pragma pack(push, 1)
typedef struct _System{
    struct _OUT_{
        void (*print)(const String, ...);
        void (*println)(const String, ...);
    }out;
}Sys;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _Scanner{
    /**
     * @brief Get a char from the user.
     * @return char
     */
    char (*nextChar)(void);
    /**
     * @brief Get a int8_t from the user.
     * @return int8_t
     */
    int8_t (*nextByte)(void);
    /**
     * @brief Get a int16_t from the user.
     * @return int16_t
     */
    int16_t (*nextShort)(void);
    /**
     * @brief Get a int32_t from the user.
     * @return int32_t
     */
    int32_t (*nextInt)(void);
    /**
     * @brief Get a int64_t from the user.
     * @return int64_t
     */
    int64_t (*nextLong)(void);
    /**
     * @brief Get a uint8_t from the user.
     * @return uint8_t
     */
    uint8_t (*nextUByte)(void);
    /**
     * @brief Get a uint16_t from the user.
     * @return uint16_t
     */
    uint16_t (*nextUShort)(void);
    /**
     * @brief Get a uint32_t from the user.
     * @return uint32_t
     */
    uint32_t (*nextUInt)(void);
    /**
     * @brief Get a uint64_t from the user.
     * @return uint64_t
     */
    uint64_t (*nextULong)(void);
    /**
     * @brief Get a float32_t from the user.
     * @return float32_t
     */
    boolean (*nextBoolean)(void);
    /**
     * @brief Get a float32_t from the user.
     * @return float32_t
     */
    float (*nextFloat)(void);
    /**
     * @brief Get a float64_t from the user.
     * @return float64_t
     */
    double (*nextDouble)(void);
    /**
     * @brief Get the next String object
     * @return String
     */
    String (*next)(void);
    /**
     * @brief Get the next Line object
     * @return String
     */
    String (*nextLine)(void);
}Scanner;
#pragma pack(pop)

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