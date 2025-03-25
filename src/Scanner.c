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
    scanf("%" SCNd8, &b);
    getchar();
    return b;
}

int16_t nextShort(void){
    int16_t s;
    scanf("%" SCNd16, &s);
    getchar();
    return s;
}

int32_t nextInt(void){
    int32_t i;
    scanf("%" SCNd32, &i);
    getchar();
    return i;
}

int64_t nextLong(void){
    int64_t l;
    scanf("%" SCNd64, &l);
    getchar();
    return l;
}

uint8_t nextUByte(void){
    uint8_t b;
    scanf("%" SCNu8, &b);
    getchar();
    return b;
}

uint16_t nextUShort(void){
    uint16_t s;
    scanf("%" SCNu16, &s);
    getchar();
    return s;
}

uint32_t nextUInt(void){
    uint32_t i;
    scanf("%" SCNu32, &i);
    getchar();
    return i;
}

uint64_t nextULong(void){
    uint64_t l;
    scanf("%" SCNu64, &l);
    getchar();
    return l;
}

boolean nextBoolean(void){
    boolean b = false;
    string s = (string)calloc(0, sizeof(char) * 5);
    scanf("%5s", s);
    if(atoi(s) | !(((*(s+0)|0x20)^'t') ^ ((*(s+1)|0x20)^'r') ^ ((*(s+2)|0x20)^'u') ^ ((*(s+3)|0x20)^'e'))) b = true;
    free(s);
    return b;
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

string next(void){
    string s = (string)calloc(4096, sizeof(char));
    scanf("%4095s", s);
    s = (string)realloc(s, sizeof(char) * (strlen(s) + 1));
    getchar();
    return s;
}

string nextLine(void){
    char c;
    uint16_t i = 0;
    string s = (string)calloc(0, sizeof(char) * 2);
    while ((i < 4096 - 1) && ((c = fgetc(stdin)) != EOF) && (c != '\n')) {
        *(s + i++) = c;
        s = (string)realloc(s, sizeof(char) * (i + 1));
    }
    *(s + i) = '\0';
    return s;
}

Scanner new_Scanner(struct __stdin_t source){
    return (Scanner){
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
}
