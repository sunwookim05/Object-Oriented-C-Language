#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#pragma once
#ifndef __MAIN_H
#define __MAIN_H

#define import extern
#define final const
#define null NULL
#define false 0
#define true 1

typedef char *String;
typedef char byte;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char ubyte;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint8_t boolean;

#pragma warning(pop)
#endif