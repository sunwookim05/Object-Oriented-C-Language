#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "main.h"

struct __stdin_t;

typedef enum SORTMODE{
    ASC,
    DES
}SortMode;

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
        void (*printf)(const String, ...);
        /** 
        * @brief System out println function
        * @param format
        * @return void
        */
        void (*println)(const String, ...);
    }out;
    struct __stdin_t{
        int (*read)();
    } in;
}SYSTEM;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct BOOLEAN{
    int (*compareTo)(boolean, boolean);
    String (*toString)(boolean);
}BOOLEAN;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct BYTE{
    void (*sort)(byte*, SortMode);
    int (*compareTo)(byte, byte);
    byte (*decode)(String);
    String (*toString)(byte);
}BYTE;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct SHORT{
    void (*sort)(short*, SortMode);
    int (*compareTo)(short, short);
    short (*decode)(String);
    String (*toString)(short);
}SHORT;
#pragma pack(pop)

#pragma pack(push, 1)
typedef  struct INTEGER{
    void (*sort)(int*, SortMode);
    int (*max)(int, int);
    int (*min)(int, int);
    int (*bitCount)(int);
    int (*parseInt)(const String, ...);
    String (*toString)(int);
    String (*toBinaryString)(int);
    String (*toOctalString)(int);
    String (*toHexString)(int);
}INTEGER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct LONG{
    String (*toString)(long long);
}LONG;
#pragma pack(pop)

#endif