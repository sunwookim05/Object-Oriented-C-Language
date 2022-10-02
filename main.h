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
typedef uint8_t boolean;

#pragma pack(push, 1)
/** 
 * @brief System class
 */ 
typedef struct _System{
    struct _OUT_{
        /**
        * @brief System out print function
        * @param format
        * @return void
        */
        void (*print)(const String, ...);
        /** 
        * @brief System out println function
        * @param format
        * @return void
        */
        void (*println)(const String, ...);
    }out;
    struct __stdin_t{
        int (*read)();
    } in;
}Sys;
#pragma pack(pop)

#pragma pack(push, 1)
/** 
 * @brief Calculator class
 */
typedef struct Scanner{
    /**
    * @brief User input char
    * @param in 
    * @return char
    */    
    char (*nextChar)(void);
    /**
     * @brief User input Byte
     * @param in
     * @return int8_t
     */
    int8_t (*nextByte)(void);
    /**
     * @brief User input Short
     * @param in
     * @return int16_t
     */
    int16_t (*nextShort)(void);
    /**
     * @brief User input Int
     * @param in
     * @return int32_t
     */
    int32_t (*nextInt)(void);
    /**
     * @brief User input Long
     * @param in
     * @return int64_t
     */
    int64_t (*nextLong)(void);
    /**
     * @brief User input Unsigned Byte
     * @param in
     * @return uint8_t
     */
    uint8_t (*nextUByte)(void);
    /**
     * @brief User input Unsigned Short
     * @param in
     * @return uint16_t
     */
    uint16_t (*nextUShort)(void);
    /**
     * @brief User input Unsigned Int
     * @param in
     * @return uint32_t
     */
    uint32_t (*nextUInt)(void);
    /**
     * @brief User input Unsigned Long
     * @param in
     * @return uint64_t
     */
    uint64_t (*nextULong)(void);
    /**
     * @brief User input boolean
     * @param in
     * @return boolean
     */
    boolean (*nextBoolean)(void);
    /**
     * @brief User input Float
     * @param in
     * @return float
     */
    float (*nextFloat)(void);
    /**
     * @brief User input Double
     * @param in
     * @return double
     */
    double (*nextDouble)(void);
    /**
     * @brief User input Long Double
     * @param in
     * @return long double
     */
    long double (*nextLDouble)(void);
    /**
     * @brief User input String no Spaces
     * @param in
     * @return String
     */
    String (*next)(void);
    /**
     * @brief User input String with Spaces
     * @param in
     * @return String
     */
    String (*nextLine)(void);
}Scanner;
#pragma pack(pop)

Scanner new_Scanner(struct __stdin_t);

#pragma pack(push, 1)
/** 
 * @brief IO class
 */
typedef struct _IOBase{
    /**
    * @brief User input
    * @param in 
    * @return void
    */
    void (*inPut)(double*, double*, char*);
    /**
    * @brief User output
    * @param out
    * @return void
    */
    void (*outPut)(double, double, char, double, FILE*);
}IOBase;
#pragma pack(pop)

#pragma pack(push, 1)
/** 
 * @brief Calculator class
 */
typedef struct _Calculator{
    struct _IN{
        /** 
        * @brief User input
        * @param in 
        * @return void
        */
        void (*inPut)(double*, double*, char*);
    }in;
    struct _OUT{
        /** 
         * @brief User output
         * @param out
         * @return void
         */
        void (*outPut)(double, double, char, double, FILE*);
    }out;
    /**
     * @brief Request user reply
     * @param Calculator
     * @return boolean
     */
    void (*requestReply)(boolean*);
    /**
     * @brief Calculate
     * @param Calculator
     * @return double
     */
    double (*calculate)(double, double, char);
    /**
     * @brief Add
     * @param Calculator
     * @return double
     */
    double (*plus)(double, double);
    /**
     * @brief Subtract
     * @param Calculator
     * @return double
     */
    double (*minus)(double, double);
    /**
     * @brief Multiply
     * @param Calculator
     * @return double
     */
    double (*multiply)(double, double);
    /**
     * @brief Divide
     * @param Calculator
     * @return double
     */
    double (*divide)(double, double);
    /**
     * @brief Modulus
     * @param Calculator
     * @return double
     */
    double (*mod)(double, double);
    /**
     * @brief Power
     * @param Calculator
     * @return double
     */
    double (*pow)(double, double);
    struct _Calculator *this;
}Calculator;
#pragma pack(pop)

#endif