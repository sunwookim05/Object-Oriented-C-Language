#include "main.h"

/**
 * @brief Get a char value from the user.
 * @return char 
 */
char nextChar(void){
    char c;
    scanf("%c", &c);
    getchar();
    return c;
}

/**
 * @brief Get a int8_t value from the user.
 * @return int8_t 
 */
int8_t nextByte(void){
    uint8_t b;
    scanf("%hhd", &b);
    getchar();
    return b;
}

/**
 * @brief Get a int16_t value from the user.
 * @return int16_t 
 */
int16_t nextShort(void){
    uint16_t s;
    scanf("%hd", &s);
    getchar();
    return s;
}

/**
 * @brief Get a int32_t value from the user.
 * @return int32_t 
 */
int32_t nextInt(void){
    uint32_t i;
    scanf("%d", &i);
    getchar();
    return i;
}

/**
 * @brief Get a int64_t value from the user.
 * @return int64_t
 */
int64_t nextLong(void){
    uint64_t l;
    scanf("%lld", &l);
    getchar();
    return l;
}

/**
 * @brief Get a uint8_t value from the user.
 * @return uint8_t 
 */
uint8_t nextUByte(void){
    uint8_t b;
    scanf("%hhu", &b);
    getchar();
    return b;
}

/**
 * @brief Get a uint16_t from the user.
 * @return uint16_t 
 */
uint16_t nextUShort(void){
    uint16_t s;
    scanf("%hu", &s);
    getchar();
    return s;
}

/**
 * @brief Get a uint32_t value from the user.
 * @return uint32_t 
 */
uint32_t nextUInt(void){
    uint32_t i;
    scanf("%u", &i);
    getchar();
    return i;
}

/**
 * @brief Get a uint64_t value from the user.
 * @return uint64_t
 */
uint64_t nextULong(void){
    uint64_t l;
    scanf("%llu", &l);
    getchar();
    return l;
}

/**
 * @brief Get a boolean value from the user
 * @return boolean 
 */
boolean nextBoolean(void){
    String s = (String)malloc(sizeof(char) * 5);
    scanf("%s", s);
    if(atoi(s) >= 1 || strcmp(s, "true") == 0){
        free(s);
        return true;
    }else{
        free(s);
        return false;
    }
}

/**
 * @brief Get a float number from the user.
 * @return float
 */
float nextFloat(void){
    float f;
    scanf("%f", &f);
    getchar();
    return f;
}

/**
 * @brief Get a double from the user.
 * @return double 
 */
double nextDouble(void){
    double d;
    scanf("%lf", &d);
    getchar();
    return d;
}

/**
 * @brief Get the next String object
 * @return String 
 */
String next(void){
    String s = (String)calloc(0, sizeof(char) * 1000);
    scanf("%s", s);
    getchar();
    String str = s;
    return str;
}

/**
 * @brief Get the next Line object
 * @return String 
 */
String nextLine(void){
    String s = (String)calloc(0, sizeof(char) * 1000);
    scanf("%[^\n]", s);
    getchar();
    String str = s;
    return str;
}

Scanner sc = {
    nextChar,
    nextByte,
    nextShort,
    nextInt,
    nextLong,
    nextUByte,
    nextUShort,
    nextUInt,
    nextULong,
    nextBoolean,
    nextFloat,
    nextDouble,
    next,
    nextLine
};