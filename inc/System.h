#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "main.h"

struct __stdin_t;

#pragma pack(push, 1)
/**
 * The {@code System} class contains several useful class fields
 * and methods. It cannot be instantiated.
 *
 * Among the facilities provided by the {@code System} class
 * are standard input, standard output, and error output streams;
 * access to externally defined properties and environment
 * variables; a means of loading files and libraries; and a utility
 * method for quickly copying a portion of an array.
 *
 * @since   1.0
 */
typedef struct SYSTEM{
    struct stdout_t{
        /**
        * @brief System out print function
        * @param format
        * @return void
        */
        void (*printf)(const string, ...);
        /** 
        * @brief System out println function
        * @param format
        * @return void
        */
        void (*println)(const string, ...);
    }out;
    struct __stdin_t{
        int (*read)();
    } in;
}SYSTEM;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct String{
    string value;
    char (*charAt)(const string, size_t);
    boolean (*equals)(const string, const string);
    size_t (*length)(const string);
    string (*replace)(const string, char, char);
    string (*substring)(const string, size_t, size_t);
    string (*toLowerCase)(const string);
    string (*toUpperCase)(const string);
    string (*trim)(const string);
}String;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Character{
    char value;
    boolean (*equals)(const char, const char);
    boolean (*isLetter)(const char);
    boolean (*isDigit)(const char);
    boolean (*isLetterOrDigit)(const char);
    boolean (*isLowerCase)(const char);
    boolean (*isUpperCase)(const char);
    char (*toLowerCase)(const char);
    char (*toUpperCase)(const char);
    boolean (*isAlphabetic)(const char);
    boolean (*isSpaceChar)(const char);
    boolean (*isDefined)(const char);
}Character;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Boolean{
    boolean value;
    boolean (*equals)(const boolean, const boolean);
    boolean (*logicalAnd)(const boolean, const boolean);
    boolean (*logicalOr)(const boolean, const boolean);
    boolean (*logicalNot)(const boolean);
    boolean (*logicalXor)(const boolean, const boolean);
    boolean (*parseBoolean)(const string);
    boolean (*valueOf)(const boolean);
    int (*compare)(const boolean, const boolean);
}Boolean;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Byte{
    byte value;
    byte (*parse)(const string, ...);
    string (*toString)(byte);
    string (*toBinaryString)(byte);
    string (*toOctalString)(byte);
    string (*toHexString)(byte);
    size_t (*bitCount)(byte);
    byte (*byteValue)(byte);
    short (*shortValue)(byte);
    int (*intValue)(byte);
    long long int (*longValue)(byte);
    float (*floatValue)(byte);
    double (*doubleValue)(byte);
    boolean (*booleanValue)(byte);
    byte (*min)(byte, byte);
    byte (*max)(byte, byte);
}Byte;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Short{
    short value;
    short (*parse)(const string, ...);
    string (*toString)(short);
    string (*toBinaryString)(short);
    string (*toOctalString)(short);
    string (*toHexString)(short);
    size_t (*bitCount)(short);
    byte (*byteValue)(short);
    short (*shortValue)(short);
    int (*intValue)(short);
    long long int (*longValue)(short);
    float (*floatValue)(short);
    double (*doubleValue)(short);
    boolean (*booleanValue)(short);
    short (*min)(short, short);
    short (*max)(short, short);
}Short;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Intrger{
    int value;
    int (*parse)(const string, ...);
    string (*toString)(int);
    string (*toBinaryString)(int);
    string (*toOctalString)(int);
    string (*toHexString)(int);
    size_t (*bitCount)(int);
    byte (*byteValue)(int);
    short (*shortValue)(int);
    int (*intValue)(int);
    long long int (*longValue)(int);
    float (*floatValue)(int);
    double (*doubleValue)(int);
    boolean (*booleanValue)(int);
    int (*min)(int, int);
    int (*max)(int, int);
}Integer;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Long{
    long long int value;
    long long int (*parse)(const string, ...);
    string (*toString)(long long int);
    string (*toBinaryString)(long long int);
    string (*toOctalString)(long long int);
    string (*toHexString)(long long int);
    size_t (*bitCount)(long long int);
    byte (*byteValue)(long long int);
    short (*shortValue)(long long int);
    int (*intValue)(long long int);
    long long int (*longValue)(long long int);
    float (*floatValue)(long long int);
    double (*doubleValue)(long long int);
    boolean (*booleanValue)(long long int);
    long long int (*min)(long long int, long long int);
    long long int (*max)(long long int, long long int);
}Long;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Float{
    float value;
    float (*parse)(const string);
    string (*toString)(float);
    byte (*byteValue)(float);
    short (*shortValue)(float);
    int (*intValue)(float);
    long long int (*longValue)(float);
    float (*floatValue)(float);
    double (*doubleValue)(float);
    boolean (*booleanValue)(float);
    float (*min)(float, float);
    float (*max)(float, float);
}Float;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Double{
    double value;
    double (*parse)(const string);
    string (*toString)(double);
    byte (*byteValue)(double);
    short (*shortValue)(double);
    int (*intValue)(double);
    long long int (*longValue)(double);
    float (*floatValue)(double);
    double (*doubleValue)(double);
    boolean (*booleanValue)(double);
    double (*min)(double, double);
    double (*max)(double, double);
}Double;
#pragma pack(pop)

String new_String(string str);
Character new_Character(char c);
Byte new_Byte(byte b);
Short new_Short(short s);
Integer new_Integer(int i);
Long new_Long(long long int l);
Float new_Float(float f);
Double new_Double(double d);
Boolean new_Boolean(boolean b);

#endif