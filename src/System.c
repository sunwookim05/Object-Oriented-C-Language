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

SYSTEM System = {print, println};

void sort(int* value, SortMode mode){
    size_t size = 0;
    while (value[size] != '\0') {
        size++;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if(!mode ? value[j] > value[j + 1] : value[j] < value[j + 1]){
                int temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;
            }
        }
    }
}

string toString(int value){
    char *result = (char*)calloc(0, sizeof(char) * 4096);
    sprintf(result, "%d", value);
    result = (char*)realloc(result, sizeof(char) * (strlen(result) + 1));
    return result;
}

INTEGER Integer = {sort, toString};
