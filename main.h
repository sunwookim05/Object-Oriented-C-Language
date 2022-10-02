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
 * The {@code System} class contains several useful class fields
 * and methods. It cannot be instantiated.
 *
 * Among the facilities provided by the {@code System} class
 * are standard input, standard output, and error output streams;
 * access to externally defined properties and environment
 * variables; a means of loading files and libraries; and a utility
 * method for quickly copying a portion of an array.
 *
 * @since   1.0
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
 * @brief Scanner class
 */
typedef struct Scanner{
    /**
    * @brief User input char
    * @param void
    * @return char
    */    
    char (*nextChar)(void);
    /**
     * @brief User input Byte
     * @param void
     * @return int8_t
     */
    int8_t (*nextByte)(void);
    /**
     * @brief User input Short
     * @param void
     * @return int16_t
     */
    int16_t (*nextShort)(void);
    /**
     * @brief User input Int
     * @param void
     * @return int32_t
     */
    int32_t (*nextInt)(void);
    /**
     * @brief User input Long
     * @param void
     * @return int64_t
     */
    int64_t (*nextLong)(void);
    /**
     * @brief User input Unsigned Byte
     * @param void
     * @return uint8_t
     */
    uint8_t (*nextUByte)(void);
    /**
     * @brief User input Unsigned Short
     * @param void
     * @return uint16_t
     */
    uint16_t (*nextUShort)(void);
    /**
     * @brief User input Unsigned Int
     * @param void
     * @return uint32_t
     */
    uint32_t (*nextUInt)(void);
    /**
     * @brief User input Unsigned Long
     * @param void
     * @return uint64_t
     */
    uint64_t (*nextULong)(void);
    /**
     * @brief User input boolean
     * @param void
     * @return boolean
     */
    boolean (*nextBoolean)(void);
    /**
     * @brief User input Float
     * @param void
     * @return float
     */
    float (*nextFloat)(void);
    /**
     * @brief User input Double
     * @param void
     * @return double
     */
    double (*nextDouble)(void);
    /**
     * @brief User input Long Double
     * @param void
     * @return long double
     */
    long double (*nextLDouble)(void);
    /**
     * @brief User input String no Spaces
     * @param void
     * @return String
     */
    String (*next)(void);
    /**
     * @brief User input String with Spaces
     * @param void
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
    * @param double*
    * @param double*
    * #param char*
    * @return void
    */
    void (*inPut)(double*, double*, char*);
    /**
    * @brief User output
    * @param double
    * @param double
    * @param char
    * @param double
    * @param FILE*
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
        * @param double*
        * @param double*
        * @param char*
        * @return void
        */
        void (*inPut)(double*, double*, char*);
    }in;
    struct _OUT{
        /** 
         * @brief User output
         * @param double
         * @param double
         * @param char
         * @param double
         * @param FILE*
         * @return void
         */
        void (*outPut)(double, double, char, double, FILE*);
    }out;
    /**
     * @brief Request user reply
     * @param boolean*
     * @return void
     */
    void (*requestReply)(boolean*);
    /**
     * @brief Calculate
     * @param double
     * @param double
     * @param char
     * @return double
     */
    double (*calculate)(double, double, char);
    /**
     * @brief Add
     * @param double
     * @param double
     * @return double
     */
    double (*plus)(double, double);
    /**
     * @brief Subtract
     * @param double
     * @param double
     * @return double
     */
    double (*minus)(double, double);
    /**
     * @brief Multiply
     * @param double
     * @param double
     * @return double
     */
    double (*multiply)(double, double);
    /**
     * @brief Divide
     * @param double
     * @param double
     * @return double
     */
    double (*divide)(double, double);
    /**
     * @brief Modulus
     * @param double
     * @param double
     * @return double
     */
    double (*mod)(double, double);
    /**
     * @brief Power
     * @param double
     * @param double
     * @return double
     */
    double (*pow)(double, double);
    struct _Calculator *this;
}Calculator;
#pragma pack(pop)

Calculator new_Calculator();

#endif