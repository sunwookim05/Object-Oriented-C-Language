#include <stdarg.h>

#ifndef _MAIN_H
#define _MAIN_H

#define null NULL
typedef enum{false, true} boolean;
typedef char *String;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

void print(const String format, ...) {va_list ap;char buf[4096];va_start(ap, format);vsprintf(buf, format, ap);va_end(ap);fprintf(stdout, "%s", buf);}
void println(const String format, ...) {va_list ap;char buf[4096];va_start(ap, format);vsprintf(buf, format, ap);va_end(ap);fprintf(stdout, "%s\n", buf);}

#pragma pack(push, 1)
typedef struct _System{
    struct _OUT_{
        void (*print)(const String, ...);
        void (*println)(const String, ...);
    }out;
}Sys;
#pragma pack(pop)

Sys System = {print, println};

#endif