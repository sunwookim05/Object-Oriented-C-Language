#include "main.h"
#include "System.h"
#include "Scanner.h"

char nextChar(void){
    char c;
    scanf("%c", &c);
    getchar();
    return c;
}

int8_t nextByte(void){
    int8_t b;
    scanf("%hhd", &b);
    getchar();
    return b;
}

int16_t nextShort(void){
    int16_t s;
    scanf("%hd", &s);
    getchar();
    return s;
}

int32_t nextInt(void){
    int32_t i;
    scanf("%d", &i);
    getchar();
    return i;
}

int64_t nextLong(void){
    int64_t l;
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
    s = (String)realloc(s, sizeof(char) * (strlen(s) + 1));
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
* Constructs a new {@code Scanner} that produces values scanned
* from the specified input stream. Bytes from the stream are converted
* into characters using the underlying platform's
*
* @param  source An input stream to be scanned
*/
Scanner new_Scanner(struct __stdin_t source){
    Scanner scanner = {
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
    return scanner;
}
