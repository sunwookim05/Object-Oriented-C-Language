#include "main.h"

#pragma once
#ifndef __SYSTEM_H
#define __SYSTEM_H

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
typedef struct Sys{
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
typedef struct STRING{
    string value;
}String;
#pragma pack(pop)

#pragma pack(push, 1)
typedef  struct INTEGER{
    void (*sort)(int*, SortMode);
    int (*max)(int, int);
    int (*min)(int, int);
    int (*parseInt)(string, ...);
    string (*toString)(int);
    string (*toBinaryString)(int);
    string (*toOctalString)(int);
    string (*toHexString)(int);
}INTEGER;
#pragma warning(push)

#pragma warning(pop)
#endif