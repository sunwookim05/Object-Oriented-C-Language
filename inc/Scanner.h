#include "main.h"

#pragma once
#ifndef __Scanner_H
#define __Scanner_H

struct __stdin_t;

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
     * @return byte
     */
    byte (*nextByte)(void);

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
     * @return ubyte
     */
    ubyte (*nextUByte)(void);

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

#pragma warning(pop)
#endif