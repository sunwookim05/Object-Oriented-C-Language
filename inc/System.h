#include "main.h"

#ifndef __SYSTEM_H
#define __SYSTEM_H

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
        int32_t (*read)();
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
    string (*trim)(const string, ...);
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
    int32_t (*compare)(const boolean, const boolean);
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
    int16_t (*shortValue)(byte);
    int32_t (*intValue)(byte);
    int64_t (*longValue)(byte);
    float (*floatValue)(byte);
    double (*doubleValue)(byte);
    boolean (*booleanValue)(byte);
    byte (*min)(byte, byte);
    byte (*max)(byte, byte);
}Byte;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Short{
    int16_t value;
    int16_t (*parse)(const string, ...);
    string (*toString)(int16_t);
    string (*toBinaryString)(int16_t);
    string (*toOctalString)(int16_t);
    string (*toHexString)(int16_t);
    size_t (*bitCount)(int16_t);
    byte (*byteValue)(int16_t);
    int16_t (*shortValue)(int16_t);
    int32_t (*intValue)(int16_t);
    int64_t (*longValue)(int16_t);
    float (*floatValue)(int16_t);
    double (*doubleValue)(int16_t);
    boolean (*booleanValue)(int16_t);
    int16_t (*min)(int16_t, int16_t);
    int16_t (*max)(int16_t, int16_t);
}Short;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Intrger{
    int32_t value;
    int32_t (*parse)(const string, ...);
    string (*toString)(int32_t);
    string (*toBinaryString)(int32_t);
    string (*toOctalString)(int32_t);
    string (*toHexString)(int32_t);
    size_t (*bitCount)(int32_t);
    byte (*byteValue)(int32_t);
    int16_t (*shortValue)(int32_t);
    int32_t (*intValue)(int32_t);
    int64_t (*longValue)(int32_t);
    float (*floatValue)(int32_t);
    double (*doubleValue)(int32_t);
    boolean (*booleanValue)(int32_t);
    int32_t (*min)(int32_t, int32_t);
    int32_t (*max)(int32_t, int32_t);
}Integer;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Long{
    int64_t value;
    int64_t (*parse)(const string, ...);
    string (*toString)(int64_t);
    string (*toBinaryString)(int64_t);
    string (*toOctalString)(int64_t);
    string (*toHexString)(int64_t);
    size_t (*bitCount)(int64_t);
    byte (*byteValue)(int64_t);
    int16_t (*shortValue)(int64_t);
    int32_t (*intValue)(int64_t);
    int64_t (*longValue)(int64_t);
    float (*floatValue)(int64_t);
    double (*doubleValue)(int64_t);
    boolean (*booleanValue)(int64_t);
    int64_t (*min)(int64_t, int64_t);
    int64_t (*max)(int64_t, int64_t);
}Long;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Float{
    float value;
    float (*parse)(const string);
    string (*toString)(float);
    byte (*byteValue)(float);
    int16_t (*shortValue)(float);
    int32_t (*intValue)(float);
    int64_t (*longValue)(float);
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
    int16_t (*shortValue)(double);
    int32_t (*intValue)(double);
    int64_t (*longValue)(double);
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
Short new_Short(int16_t s);
Integer new_Integer(int32_t i);
Long new_Long(int64_t l);
Float new_Float(float f);
Double new_Double(double d);
Boolean new_Boolean(boolean b);

#endif