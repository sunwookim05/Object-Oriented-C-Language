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