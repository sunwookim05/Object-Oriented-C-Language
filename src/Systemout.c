#include "main.h"
#include "System.h"

void print(const String format, ...) {va_list ap;char buf[4096];va_start(ap, format);vsprintf(buf, format, ap);va_end(ap);fprintf(stdout, "%s", buf);}
void println(const String format, ...) {va_list ap;char buf[4096];va_start(ap, format);vsprintf(buf, format, ap);va_end(ap);fprintf(stdout, "%s\n", buf);}

Sys System = {print, println};