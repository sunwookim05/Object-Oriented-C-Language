#include "main.h"
#include "System.h"
#include "Scanner.h"

static void consumeLineBreak(void) {
    int c = getchar();
    if (c == '\r') {
        int next = getchar();
        if (next != '\n' && next != EOF) ungetc(next, stdin);
    } else if (c != '\n' && c != EOF) {
        ungetc(c, stdin);
    }
}

char nextChar(void){
    char c = '\0';
    if (scanf("%c", &c) != 1) return '\0';
    consumeLineBreak();
    return c;
}

int8_t nextByte(void){
    int8_t b = 0;
    if (scanf("%" SCNd8, &b) != 1) return 0;
    consumeLineBreak();
    return b;
}

int16_t nextShort(void){
    int16_t s = 0;
    if (scanf("%" SCNd16, &s) != 1) return 0;
    consumeLineBreak();
    return s;
}

int32_t nextInt(void){
    int32_t i = 0;
    if (scanf("%" SCNd32, &i) != 1) return 0;
    consumeLineBreak();
    return i;
}

int64_t nextLong(void){
    int64_t l = 0;
    if (scanf("%" SCNd64, &l) != 1) return 0;
    consumeLineBreak();
    return l;
}

uint8_t nextUByte(void){
    uint8_t b = 0;
    if (scanf("%" SCNu8, &b) != 1) return 0;
    consumeLineBreak();
    return b;
}

uint16_t nextUShort(void){
    uint16_t s = 0;
    if (scanf("%" SCNu16, &s) != 1) return 0;
    consumeLineBreak();
    return s;
}

uint32_t nextUInt(void){
    uint32_t i = 0;
    if (scanf("%" SCNu32, &i) != 1) return 0;
    consumeLineBreak();
    return i;
}

uint64_t nextULong(void){
    uint64_t l = 0;
    if (scanf("%" SCNu64, &l) != 1) return 0;
    consumeLineBreak();
    return l;
}

boolean nextBoolean(void){
    char s[6] = {0};
    if (scanf("%5s", s) != 1) return false;
    consumeLineBreak();

    if (strcmp(s, "1") == 0) return true;
    return ((s[0] | 0x20) == 't' &&
            (s[1] | 0x20) == 'r' &&
            (s[2] | 0x20) == 'u' &&
            (s[3] | 0x20) == 'e' &&
            s[4] == '\0') ? true : false;
}

float nextFloat(void){
    float f = 0.0f;
    if (scanf("%f", &f) != 1) return 0.0f;
    consumeLineBreak();
    return f;
}

double nextDouble(void){
    double d = 0.0;
    if (scanf("%lf", &d) != 1) return 0.0;
    consumeLineBreak();
    return d;
}

long double nextLDouble(void){
    long double ld = 0.0L;
    if (scanf("%Lf", &ld) != 1) return 0.0L;
    consumeLineBreak();
    return ld;
}

string next(void){
    string s = (string)calloc(4096, sizeof(char));
    if (s == null) return null;

    if (scanf("%4095s", s) != 1) {
        free(s);
        return null;
    }

    string resized = (string)realloc(s, strlen(s) + 1);
    if (resized != null) s = resized;
    consumeLineBreak();
    return s;
}

string nextLine(void){
    int c;
    size_t i = 0;
    string s = (string)malloc(1);
    if (s == null) return null;

    while ((i < 4096 - 1) && ((c = fgetc(stdin)) != EOF) && (c != '\n')) {
        string resized = (string)realloc(s, i + 2);
        if (resized == null) break;
        s = resized;
        *(s + i++) = (char)c;
    }

    *(s + i) = '\0';
    return s;
}

Scanner new_Scanner(struct __stdin_t source){
    (void)source;

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
