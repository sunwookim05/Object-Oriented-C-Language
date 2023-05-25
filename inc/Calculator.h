#include "main.h"

#pragma once
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
    void (*inPut)(double*, double*, char*);
    /**
    * @brief User output
    * @param a
    * @param b
    * @param op
    * @param result
    * @param fp
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
        * @param a
        * @param b
        * @param op
        * @return void
        */
        void (*inPut)(double*, double*, char*);
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
        void (*outPut)(double, double, char, double, FILE*);
    }out;
    /**
     * @brief Request user reply
     * @param reply
     * @return void
     */
    boolean (*requestRetry)(void);
    /**
     * @brief Calculate
     * @param a
     * @param b
     * @param op
     * @return result
     */
    double (*calculate)(double, double, char);
    /**
     * @brief Add
     * @param a
     * @param b
     * @return result
     */
    double (*plus)(double, double);
    /**
     * @brief Subtract
     * @param a
     * @param b
     * @return result
     */
    double (*minus)(double, double);
    /**
     * @brief Multiply
     * @param a
     * @param b
     * @return result
     */
    double (*multiply)(double, double);
    /**
     * @brief Divide
     * @param a
     * @param b
     * @return result
     */
    double (*divide)(double, double);
    /**
     * @brief Modulus
     * @param a
     * @param b
     * @return result
     */
    double (*mod)(double, double);
    /**
     * @brief Power
     * @param a
     * @param b
     * @return result
     */
    double (*pow)(double, double);
    struct _Calculator *this;
}Calculator;
#pragma pack(pop)

/**
 * @brief Create a new Calculator object
 * @return Calculator 
 */
Calculator new_Calculator();

#pragma warning(pop)
#endif