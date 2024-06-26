#include "main.h"
#include "System.h"

void print(const String format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    fprintf(stdout, "%s", buf);
}

void println(const String format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    fprintf(stdout, "%s\n", buf);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high, SortMode mode) {
    int pivot = *(arr + high);
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if(!mode ? *(arr + j) < pivot : *(arr + j) > pivot){
            i++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + i + 1), (arr + high));
    return (i + 1);
}

void quickSort(int* arr, int low, int high, SortMode mode) {
    if (low < high) {
        int pi = partition(arr, low, high, mode);
        quickSort(arr, low, pi - 1, mode);
        quickSort(arr, pi + 1, high, mode);
    }
}

void sort(int* value, SortMode mode){
    size_t size = sizeof(value) / sizeof(int);
    quickSort(value, 0, size - 1, mode);
}

int iMax(int a, int b){
    return a > b ? a : b;
}

int iMin(int a, int b){
    return a < b ? a : b;
}

long long int _parse(char* value, size_t size, uint8_t arg) {
    uint8_t base = 10;
    va_list ap;
    if (arg < 17 && arg > 1) base = arg;
    return strtoll(value, NULL, base);
}

#define parse(value, type, arg) _parse(value, sizeof(type), arg)

int parseInt(const String value, ...){
    uint8_t arg;
    va_list ap;
    va_start(ap, value);
    arg = va_arg(ap, int);
    va_end(ap);
    return (int)parse(value, int, arg);
}

String tostring(void* value, int type) {
    char* result;
    int i = 0;
    switch (type) {
        case 1: // byte
            i = snprintf(NULL, 0, "%hhd", *((byte*)value));
            result = (byte*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%hhd", *((byte*)value));
            break;
        case 2: // short
            i = snprintf(NULL, 0, "%hd", *((short*)value));
            result = (char*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%hd", *((short*)value));
            break;
        case 3: // int
            i = snprintf(NULL, 0, "%d", *((int*)value));
            result = (char*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%d", *((int*)value));
            break;
        case 4: // long long
            i = snprintf(NULL, 0, "%lld", *((long long*)value));
            result = (char*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%lld", *((long long*)value));
            break;
        case 5: // float
            i = snprintf(NULL, 0, "%f", *((float*)value));
            result = (char*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%f", *((float*)value));
            break;
        case 6: // double
            i = snprintf(NULL, 0, "%lf", *((double*)value));
            result = (char*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%lf", *((double*)value));
            break;
        case 7: // long double
            i = snprintf(NULL, 0, "%Lf", *((long double*)value));
            result = (char*)calloc(0, sizeof(char) * (i + 1));
            sprintf(result, "%Lf", *((long double*)value));
            break;
        default:
            result = NULL;
            break;
    }
    return result;
}

String intToString(int value){
    return tostring(&value, 3);
}

String toBinaryString(int value){
    int i = sizeof(int) * 8;
    String str = (char*)malloc(sizeof(char) * (i + 1));

    *(str + i) = '\0';
    for(int j = i - 1; j >= 0; j--){
        *(str + j) = (value & 1) ? '1' : '0';
        value >>= 1;
    }

    String trim = str + strspn(str, "0");

    free(str);
    return !strlen(trim) ? "0" : trim;
}

String toOctalString(int value){
    int i = snprintf(NULL, 0, "%o", value);
    String result = (char*)calloc(0, sizeof(char) * (i + 1));
    sprintf(result, "%o", value);
    return result;
}

String toHexString(int value){
    int i = snprintf(NULL, 0, "%X", value);
    String result = (char*)calloc(0, sizeof(char) * (i + 1));
    sprintf(result, "%X", value);
    return result;
}

int bitCount(int value){
    int count = 0;
    while (value) {
        count += value & 1;
        value >>= 1;
    }
    return count;
}

SYSTEM System = {print, println};
INTEGER Integer = {sort, iMax, iMin, bitCount, parseInt, intToString, toBinaryString, toOctalString, toHexString};