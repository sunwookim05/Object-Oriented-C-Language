#include "main.h"

char nextChar(void){
    char c;
    scanf("%c", &c);
    getchar();
    return c;
}

int8_t nextByte(void){
    uint8_t b;
    scanf("%hhd", &b);
    getchar();
    return b;
}

int16_t nextShort(void){
    uint16_t s;
    scanf("%hd", &s);
    getchar();
    return s;
}

int32_t nextInt(void){
    uint32_t i;
    scanf("%d", &i);
    getchar();
    return i;
}

int64_t nextLong(void){
    uint64_t l;
    scanf("%lld", &l);
    getchar();
    return l;
}

uint8_t nextUByte(void){
    uint8_t b;
    scanf("%hhu", &b);
    getchar();
    return b;
}

uint16_t nextUShort(void){
    uint16_t s;
    scanf("%hu", &s);
    getchar();
    return s;
}

uint32_t nextUInt(void){
    uint32_t i;
    scanf("%u", &i);
    getchar();
    return i;
}

uint64_t nextULong(void){
    uint64_t l;
    scanf("%llu", &l);
    getchar();
    return l;
}

boolean nextBoolean(void){
    String s = (String)malloc(sizeof(char) * 5);
    scanf("%s", s);
    if(atoi(s) >= 1 || strncmp(s, "true", 4) == 0){
        free(s);
        return true;
    }else{
        free(s);
        return false;
    }
}

float nextFloat(void){
    float f;
    scanf("%f", &f);
    getchar();
    return f;
}

double nextDouble(void){
    double d;
    scanf("%lf", &d);
    getchar();
    return d;
}

long double nextLDouble(void){
    long double ld;
    scanf("%Lf", &ld);
    getchar();
    return ld;
}

String next(void){
    String s = (String)calloc(0, sizeof(char) * 4096);
    scanf("%s", s);
    getchar();
    return s;
}

String nextLine(void){
    String s = (String)calloc(0, sizeof(char) * 4096);
    scanf("%[^\n]", s);
    getchar();
    return s;
}

/**
 * @brief Creates a new Scanner object
 * @return Scanner 
 */
Scanner new_Scanner(struct __stdin_t in){
    Scanner ret = {
        .nextChar = nextChar,
        .nextByte = nextByte,
        .nextShort = nextShort,
        .nextInt = nextInt,
        .nextLong = nextLong,
        .nextUByte = nextUByte,
        .nextUShort = nextUShort,
        .nextUInt = nextUInt,
        .nextULong = nextULong,
        .nextBoolean = nextBoolean,
        .nextFloat = nextFloat,
        .nextDouble = nextDouble,
        .nextLDouble = nextLDouble,
        .next = next,
        .nextLine = nextLine
    };
    return ret;
}