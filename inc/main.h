#pragma once
#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define import extern
#define final const
#define null NULL
#define false 0
#define true 1

typedef char* String;
typedef char byte;
typedef unsigned char ubyte;
typedef uint8_t boolean;

#pragma warning(pop)
#endif