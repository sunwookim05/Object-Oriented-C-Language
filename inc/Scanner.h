#include "main.h"

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
     * @brief User input string no Spaces
     * @param void
     * @return string
     */
    string (*next)(void);

    /**
     * @brief User input string with Spaces
     * @param void
     * @return string
     */
    string (*nextLine)(void);
}Scanner;
#pragma pack(pop)

/**
* Constructs a new {@code Scanner} that produces values scanned
* from the specified input stream. Bytes from the stream are converted
* into characters using the underlying platform's
*
* @param  source An input stream to be scanned
*/
Scanner new_Scanner(struct __stdin_t);

#endif