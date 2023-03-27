#include "main.h"
#include "System.h"
#include "Scanner.h"

char nextChar(void){
    char c;
    scanf("%c", &c);
    getchar();
    return c;
}

byte nextByte(void){
    byte b;
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

ubyte nextUByte(void){
    ubyte b;
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
    scanf("%5s", s);
    if(atoi(s)| !(((s[0]|0x20)^'t') ^ ((s[1]|0x20)^'r') ^ ((s[2]|0x20)^'u') ^ ((s[3]|0x20)^'e'))){
        free(s);
        return true;
    }
    free(s);
    return false;
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
    scanf("%4095s", s);
    s = (String)realloc(s, sizeof(char) * (strlen(s) + 1));
    getchar();
    return s;
}

String nextLine(void){
    char c;
    uint16_t i = 0;
    String s = (String)calloc(0, sizeof(char) * 1);
    while (i < 4096 - 1 & (c = fgetc(stdin)) != EOF & c != '\n') {
        s[i++] = c;
        s = (String)realloc(s, sizeof(char) * (i + 1));
    }
    s[i] = '\0';
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
