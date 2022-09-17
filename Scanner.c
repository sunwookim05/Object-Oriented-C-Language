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

String next(void){
    String s = (String)malloc(sizeof(char) * 1000);
    scanf("%s", s);
    getchar();
    String str = s;
    free(s);
    return str;
}

String nextLine(void){
    String s = (String)malloc(sizeof(char) * 1000);
    scanf("%[^\n]", s);
    String str = s;
    free(s);
    return str;
}

Scanner sc = {
    nextChar,
    nextByte,
    nextShort,
    nextInt,
    nextLong,
    nextFloat,
    nextDouble,
    next,
    nextLine
};