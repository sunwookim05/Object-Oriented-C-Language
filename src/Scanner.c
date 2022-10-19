#include "main.h"
#include "System.h"
#include "Scanner.h"

void* nextChar(void){
    char c;
    scanf("%c", &c);
    getchar();
    return c;
}

void* nextByte(void){
    uint8_t b;
    scanf("%hhd", &b);
    getchar();
    return b;
}

void* nextShort(void){
    uint16_t s;
    scanf("%hd", &s);
    getchar();
    return s;
}

void* nextInt(void){
    uint32_t i;
    scanf("%d", &i);
    getchar();
    return i;
}

void* nextLong(void){
    uint64_t l;
    scanf("%lld", &l);
    getchar();
    return l;
}

void* nextUByte(void){
    uint8_t b;
    scanf("%hhu", &b);
    getchar();
    return b;
}

void* nextUShort(void){
    uint16_t s;
    scanf("%hu", &s);
    getchar();
    return s;
}

void* nextUInt(void){
    uint32_t i;
    scanf("%u", &i);
    getchar();
    return i;
}

void* nextULong(void){
    uint64_t l;
    scanf("%llu", &l);
    getchar();
    return l;
}

void* nextBoolean(void){
    String s = (String)calloc(0, sizeof(char) * 5);
    scanf("%s", s);
    if(atoi(s)|| !strncmp(s, "true", 4) || !strncmp(s, "True", 4) || !strncmp(s, "TRUE", 4)){
        free(s);
        return true;
    }else{
        free(s);
        return false;
    }
}

void* nextFloat(void){
    float f;
    scanf("%f", &f);
    getchar();
    return f;
}

void* nextDouble(void){
    double d;
    scanf("%lf", &d);
    getchar();
    return d;
}

void* nextLDouble(void){
    long double ld;
    scanf("%Lf", &ld);
    getchar();
    return ld;
}

void* next(void){
    String s = (String)calloc(0, sizeof(char) * 4096);
    scanf("%s", s);
    getchar();
    return s;
}

void* nextLine(void){
    String s = (String)calloc(0, sizeof(char) * 4096);
    scanf("%[^\n]", s);
    getchar();
    return s;
}

/**
* Constructs a new {@code Scanner} that produces values scanned
* from the specified input stream. Bytes from the stream are converted
* into characters using the underlying platform's
*
* @param  source An input stream to be scanned
*/
Scanner new_Scanner(struct __stdin_t source){
    Scanner scanner = {
        .nextChar = (char)nextChar,
        .nextByte = (int8_t)nextByte,
        .nextShort = (int16_t)nextShort,
        .nextInt = (int32_t)nextInt,
        .nextLong = (int64_t)nextLong,
        .nextUByte = (uint8_t)nextUByte,
        .nextUShort = (uint16_t)nextUShort,
        .nextUInt = (uint32_t)nextUInt,
        .nextULong = (uint64_t)nextULong,
        .nextBoolean = (boolean)nextBoolean,
        .nextFloat = (float)nextFloat,
        .nextDouble = (double)nextDouble,
        .nextLDouble = (long double)nextLDouble,
        .next = (String)next,
        .nextLine = (String)nextLine
    };
    return scanner;
}
