#include "main.h"

#ifndef __CALCULATOR_H
#define __CALCULATOR_H

#pragma pack(push, 1)
/** 
 * @brief IO class
 */
typedef struct _IOBase{
    /**
    * @brief User input
    * @param a
    * @param b
    * #param char*
    * @return void
    */
    void (*inPut)(long double*, long double*, char*);
    /**
    * @brief User output
    * @param a
    * @param b
    * @param op
    * @param result
    * @param fp
    * @return void
    */
    void (*outPut)(long double, long double, char, long double, FILE*);
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
        * @param a
        * @param b
        * @param op
        * @return void
        */
        void (*inPut)(long double*, long double*, char*);
    }in;
    struct _OUT{
        /** 
         * @brief User output
         * @param a
         * @param b
         * @param op
         * @param result
         * @param fp
         * @return void
         */
        void (*outPut)(long double, long double, char, long double, FILE*);
    }out;
    /**
     * @brief Request user reply
     * @param boolean*
     * @return void
     */
    void (*requestReply)(boolean*);
    /**
     * @brief Calculate
     * @param a
     * @param b
     * @param char
     * @return double
     */
    long double (*calculate)(long double, long double, char);
    /**
     * @brief Add
     * @param a
     * @param b
     * @return resault
     */
    long double (*plus)(long double, long double);
    /**
     * @brief Subtract
     * @param a
     * @param b
     * @return resault
     */
    long double (*minus)(long double, long double);
    /**
     * @brief Multiply
     * @param a
     * @param b
     * @return resault
     */
    long double (*multiply)(long double, long double);
    /**
     * @brief Divide
     * @param a
     * @param b
     * @return resault
     */
    long double (*divide)(long double, long double);
    /**
     * @brief Modulus
     * @param a
     * @param b
     * @return resault
     */
    long double (*mod)(long double, long double);
    /**
     * @brief Power
     * @param a
     * @param b
     * @return resault
     */
    long double (*power)(long double, long double);
    struct _Calculator *this;
}Calculator;
#pragma pack(pop)

Calculator new_Calculator();

#endif