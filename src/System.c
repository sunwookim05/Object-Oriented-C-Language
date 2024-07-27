#include "main.h"
#include "System.h"

void print(const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    fprintf(stdout, "%s", buf);
}

void println(const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    fprintf(stdout, "%s\n", buf);
}

SYSTEM System = {
    .out = {
        .printf = print,
        .println = println
    }
};

#define PARSE_INT(TYPE, FUNC, NAME) \
TYPE parse##NAME(const string str, ...) { \
    int radix = 10; \
    va_list ap; \
    va_start(ap, str); \
    radix = va_arg(ap, int); \
    va_end(ap); \
    return (TYPE)FUNC(str, null, radix); \
}

#define PARSE_FLOAT(TYPE, FUNC, NAME) \
TYPE parse##NAME(const string str) { \
    return FUNC(str, null); \
}

PARSE_INT(byte, strtol, Byte)
PARSE_INT(short, strtol, Short)
PARSE_INT(int, strtol, Integer)
PARSE_INT(long long int, strtoll, Long)
PARSE_FLOAT(float, strtof, Float)
PARSE_FLOAT(double, strtod, Double)


#define TOSTRING(TYPE, FORMAT, NAME) \
string toString##NAME(TYPE value) { \
    string str; \
    size_t size =  snprintf(NULL, 0, FORMAT, value) + 1; \
    str = (string)malloc(sizeof(char) * size); \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOSTRING(byte, "%hhd", Byte)
TOSTRING(short, "%hd", Short)
TOSTRING(int, "%d", Integer)
TOSTRING(long long int, "%lld", Long)
TOSTRING(float, "%g", Float)
TOSTRING(double, "%g", Double)

#define TOBINARAYSTRING(TYPE, SIZE, NAME) \
string toBinaryString##NAME(TYPE value) { \
    string binaryString = (string)malloc((SIZE + 1) * sizeof(char)); \
    *(binaryString + SIZE) = '\0';\
    TYPE mask = (TYPE)1 << (SIZE - 1); \
    for (size_t i = 0; i < SIZE; i++) { \
        *(binaryString + i) = (value & mask) ? '1' : '0'; \
        mask >>= 1; \
    } \
    string ptr = binaryString; \
    while (*ptr == '0' && *(ptr + 1) != '\0') ptr++; \
    if(*ptr == '\0'){ \
        ptr = binaryString; \
        *ptr = '0'; \
        *(ptr + 1) = '\0'; \
    } \
    size_t length = strlen(ptr) + 1; \
    string trimmedBinaryString = (string)malloc(length * sizeof(char)); \
    memcpy(trimmedBinaryString, ptr, length); \
    free(binaryString); \
    return trimmedBinaryString; \
}

TOBINARAYSTRING(byte, 8, Byte)
TOBINARAYSTRING(short, 16, Short)
TOBINARAYSTRING(int, 32, Integer)
TOBINARAYSTRING(long long int, 64, Long)

#define TOOCTALSTRING(TYPE, FORMAT, NAME) \
string toOctalString##NAME(TYPE value) { \
    string str; \
    size_t size =  snprintf(NULL, 0, FORMAT, value) + 1; \
    str = (string)malloc(sizeof(char) * size); \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOOCTALSTRING(byte, "%hho", Byte)
TOOCTALSTRING(short, "%ho", Short)
TOOCTALSTRING(int, "%o", Integer)
TOOCTALSTRING(long long int, "%llo", Long)

#define TOHEXSTRING(TYPE, FORMAT, NAME) \
string toHexString##NAME(TYPE value) { \
    string str; \
    size_t size =  snprintf(NULL, 0, FORMAT, value) + 1; \
    str = (string)malloc(sizeof(char) * size); \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOHEXSTRING(byte, "%hhX", Byte)
TOHEXSTRING(short, "%hX", Short)
TOHEXSTRING(int, "%X", Integer)
TOHEXSTRING(long long int, "%llX", Long)

#define BITCOUNT(TYPE, NAME) \
size_t bitCount##NAME(TYPE value) { \
    size_t count = 0; \
    while (value) { \
        count += value & 1; \
        value >>= 1; \
    } \
    return count; \
}

BITCOUNT(byte, Byte)
BITCOUNT(short, Short)
BITCOUNT(int, Integer)
BITCOUNT(long long int, Long)

#define BYTEVALUE(TYPE, NAME) \
byte byteValue##NAME(TYPE value) { \
    return (byte)value; \
}

BYTEVALUE(byte, Byte)
BYTEVALUE(short, Short)
BYTEVALUE(int, Integer)
BYTEVALUE(long long int, Long)
BYTEVALUE(float, Float)
BYTEVALUE(double, Double)
BYTEVALUE(boolean, Boolean)

#define SHORTVALUE(TYPE, NAME) \
short shortValue##NAME(TYPE value) { \
    return (short)value; \
}

SHORTVALUE(byte, Byte)
SHORTVALUE(short, Short)
SHORTVALUE(int, Integer)
SHORTVALUE(long long int, Long)
SHORTVALUE(float, Float)
SHORTVALUE(double, Double)
SHORTVALUE(boolean, Boolean)

#define INTVALUE(TYPE, NAME) \
int intValue##NAME(TYPE value) { \
    return (int)value; \
}

INTVALUE(byte, Byte)
INTVALUE(short, Short)
INTVALUE(int, Integer)
INTVALUE(long long int, Long)
INTVALUE(float, Float)
INTVALUE(double, Double)
INTVALUE(boolean, Boolean)

#define LONGVALUE(TYPE, NAME) \
long long int longValue##NAME(TYPE value) { \
    return (long long int)value; \
}

LONGVALUE(byte, Byte)
LONGVALUE(short, Short)
LONGVALUE(int, Integer)
LONGVALUE(long long int, Long)
LONGVALUE(float, Float)
LONGVALUE(double, Double)
LONGVALUE(boolean, Boolean)

#define FLOATVALUE(TYPE, NAME) \
float floatValue##NAME(TYPE value) { \
    return (float)value; \
}

FLOATVALUE(byte, Byte)
FLOATVALUE(short, Short)
FLOATVALUE(int, Integer)
FLOATVALUE(long long int, Long)
FLOATVALUE(float, Float)
FLOATVALUE(double, Double)
FLOATVALUE(boolean, Boolean)

#define DOUBLEVALUE(TYPE, NAME) \
double doubleValue##NAME(TYPE value) { \
    return (double)value; \
}

DOUBLEVALUE(byte, Byte)
DOUBLEVALUE(short, Short)
DOUBLEVALUE(int, Integer)
DOUBLEVALUE(long long int, Long)
DOUBLEVALUE(float, Float)
DOUBLEVALUE(double, Double)
DOUBLEVALUE(boolean, Boolean)

#define BOOLEANVALUE(TYPE, NAME) \
boolean booleanValue##NAME(TYPE value) { \
    return value ? true : false; \
}

BOOLEANVALUE(byte, Byte)
BOOLEANVALUE(short, Short)
BOOLEANVALUE(int, Integer)
BOOLEANVALUE(long long int, Long)
BOOLEANVALUE(float, Float)
BOOLEANVALUE(double, Double)
BOOLEANVALUE(boolean, Boolean)

#define MAX(TYPE, NAME) \
TYPE max##NAME(TYPE x, TYPE y) { \
    return x > y ? x : y; \
}

MAX(byte, Byte)
MAX(short, Short)
MAX(int, Integer)
MAX(long long int, Long)
MAX(float, Float)
MAX(double, Double)

#define MIN(TYPE, NAME) \
TYPE min##NAME(TYPE x, TYPE y) { \
    return x < y ? x : y; \
}

MIN(byte, Byte)
MIN(short, Short)
MIN(int, Integer)
MIN(long long int, Long)
MIN(float, Float)
MIN(double, Double)

#define EQUALS(TYPE, NAME) \
boolean equals##NAME(TYPE x, TYPE y) { \
    return x == y; \
}

EQUALS(char, Character)
EQUALS(byte, Byte)
EQUALS(short, Short)
EQUALS(int, Integer)
EQUALS(long long int, Long)
EQUALS(float, Float)
EQUALS(double, Double)
EQUALS(boolean, Boolean)

/*-----------------------------------String Class-----------------------------------*/
char charAt(const string str, size_t index) {
    return *(str + index);
}

boolean equals(const string str1, const string str2) {
    return !strcmp(str1, str2);
}

size_t length(const string str) {
    return strlen(str);
}

string replace(const string str, char oldChar, char newChar) {
    size_t length = strlen(str);
    string replaced = (string)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) {
        *(replaced + i) = *(str + i) == oldChar ? newChar : *(str + i);
    }
    *(replaced + length) = '\0';
    return replaced;
}

string substring(const string str, size_t beginIndex, size_t endIndex) {
    size_t length = endIndex - beginIndex;
    string substr = (string)malloc(sizeof(char) * (length + 1));
    memcpy(substr, str + beginIndex, length);
    *(substr + length) = '\0';
    return substr;
}

string stoLowerCase(const string str) {
    size_t length = strlen(str);
    string lower = (string)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) *(lower + i) = *(str + i) | 0x20;
    *(lower + length) = '\0';
    return lower;
}

string stoUpperCase(const string str) {
    size_t length = strlen(str);
    string upper = (string)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) *(upper + i) = *(str + i) & 0xDF;
    *(upper + length) = '\0';
    return upper;
}

string trim(const string str) {
    size_t length = strlen(str);
    size_t beginIndex = 0;
    size_t endIndex = length - 1;
    while (*(str + beginIndex) == ' ' || *(str + beginIndex) == '\t' || *(str + beginIndex) == '\n' || *(str + beginIndex) == '\r') beginIndex++;
    while (*(str + endIndex) == ' ' || *(str + endIndex) == '\t' || *(str + endIndex) == '\n' || *(str + endIndex) == '\r') endIndex--;
    size_t size = endIndex - beginIndex + 1;
    string trimmed = (string)malloc(sizeof(char) * (size + 1));
    memcpy(trimmed, str + beginIndex, size);
    *(trimmed + size) = '\0';
    return trimmed;
}
/*----------------------------------------------------------------------------------*/

/*---------------------------------Character Class---------------------------------*/
boolean isLetter(const char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

boolean isDigit(const char c) {
    return c >= '0' && c <= '9';
}

boolean isLetterOrDigit(const char c) {
    return isLetter(c) || isDigit(c);
}

boolean isLowerCase(const char c) {
    return c >= 'a' && c <= 'z';
}

boolean isUpperCase(const char c) {
    return c >= 'A' && c <= 'Z';
}

char ctoLowerCase(const char c) {
    return isUpperCase(c) ? c | 0x20 : c;
}

char ctoUpperCase(const char c) {
    return isLowerCase(c) ? c & 0xDF : c;
}

boolean isAlphabetic(const char c) {
    return isLetter(c) || isDigit(c);
}

boolean isSpaceChar(const char c) {
    return c == ' ';
}

boolean isDefined(const char c) {
    return c != '\0';
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------Boolean Class---------------------------------*/
int compare(const boolean x, const boolean y) {
    return x & y;
}

boolean logicalAnd(const boolean x, const boolean y) {
    return x & y;
}

boolean logicalOr(const boolean x, const boolean y) {
    return x | y;
}

boolean logicalNot(const boolean x) {
    return !x;
}

boolean logicalXor(const boolean x, const boolean y) {
    return x ^ y;
}

boolean parseBoolean(const string str) {
    return !strcmp(str, "true") ? true : false;
}

boolean valueOfBoolean(const boolean value) {
    return value;
}
/*-------------------------------------------------------------------------------*/

/*---------------------------------  new  ---------------------------------*/
String new_String(const string value) {
    return (String) {
        .value = value,
        .charAt = charAt,
        .equals = equals,
        .length = length,
        .replace = replace,
        .substring = substring,
        .toLowerCase = stoLowerCase,
        .toUpperCase = stoUpperCase,
        .trim = trim
    };
}

Character new_Character(const char value) {
    return (Character) {
        .value = value,
        .equals = equalsCharacter,
        .isLetter = isLetter,
        .isDigit = isDigit,
        .isLetterOrDigit = isLetterOrDigit,
        .isLowerCase = isLowerCase,
        .isUpperCase = isUpperCase,
        .toLowerCase = ctoLowerCase,
        .toUpperCase = ctoUpperCase,
        .isAlphabetic = isAlphabetic,
        .isSpaceChar = isSpaceChar,
        .isDefined = isDefined
    };
}

Boolean new_Boolean(const boolean value) {
    return (Boolean) {
        .value = value,
        .equals = equalsBoolean,
        .logicalAnd = logicalAnd,
        .logicalOr = logicalOr,
        .logicalNot = logicalNot,
        .logicalXor = logicalXor,
        .parseBoolean = parseBoolean,
        .valueOf = valueOfBoolean,
        .compare = compare
    };
}

Byte new_Byte(const byte value) {
    return (Byte) {
        .value = value,
        .parse = parseByte,
        .toString = toStringByte,
        .toBinaryString = toBinaryStringByte,
        .toOctalString = toOctalStringByte,
        .toHexString = toHexStringByte,
        .bitCount = bitCountByte,
        .byteValue = byteValueByte,
        .shortValue = shortValueByte,
        .intValue = intValueByte,
        .longValue = longValueByte,
        .floatValue = floatValueByte,
        .doubleValue = doubleValueByte,
        .booleanValue = booleanValueByte,
        .max = maxByte,
        .min = minByte
    };
}

Short new_Short(const short value) {
    return (Short) {
        .value = value,
        .parse = parseShort,
        .toString = toStringShort,
        .toBinaryString = toBinaryStringShort,
        .toOctalString = toOctalStringShort,
        .toHexString = toHexStringShort,
        .byteValue = byteValueShort,
        .shortValue = shortValueShort,
        .intValue = intValueShort,
        .longValue = longValueShort,
        .floatValue = floatValueShort,
        .doubleValue = doubleValueShort,
        .booleanValue = booleanValueShort,
        .max = maxShort,
        .min = minShort
    };
}

Integer new_Integer(const int value) {
    return (Integer) {
        .value = value,
        .parse = parseInteger,
        .toString = toStringInteger,
        .toBinaryString = toBinaryStringInteger,
        .toOctalString = toOctalStringInteger,
        .toHexString = toHexStringInteger,
        .bitCount = bitCountInteger,
        .byteValue = byteValueInteger,
        .shortValue = shortValueInteger,
        .intValue = intValueInteger,
        .longValue = longValueInteger,
        .floatValue = floatValueInteger,
        .doubleValue = doubleValueInteger,
        .booleanValue = booleanValueInteger,
        .max = maxInteger,
        .min = minInteger
    };
}

Long new_Long(const long long int value) {
    return (Long) {
        .value = value,
        .parse = parseLong,
        .toString = toStringLong,
        .toBinaryString = toBinaryStringLong,
        .toOctalString = toOctalStringLong,
        .toHexString = toHexStringLong,
        .byteValue = byteValueLong,
        .shortValue = shortValueLong,
        .intValue = intValueLong,
        .longValue = longValueLong,
        .floatValue = floatValueLong,
        .doubleValue = doubleValueLong,
        .booleanValue = booleanValueLong,
        .max = maxLong,
        .min = minLong
    };
}

Float new_Float(const float value) {
    return (Float) {
        .value = value,
        .parse = parseFloat,
        .toString = toStringFloat,
        .byteValue = byteValueFloat,
        .shortValue = shortValueFloat,
        .intValue = intValueFloat,
        .longValue = longValueFloat,
        .floatValue = floatValueFloat,
        .doubleValue = doubleValueFloat,
        .booleanValue = booleanValueFloat
    };
}

Double new_Double(const double value) {
    return (Double) {
        .value = value,
        .parse = parseDouble,
        .toString = toStringDouble,
        .byteValue = byteValueDouble,
        .shortValue = shortValueDouble,
        .intValue = intValueDouble,
        .longValue = longValueDouble,
        .floatValue = floatValueDouble,
        .doubleValue = doubleValueDouble,
        .booleanValue = booleanValueDouble
    };
}
/*-------------------------------------------------------------------------*/