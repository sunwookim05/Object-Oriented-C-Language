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
    size_t size = _msize(value) / sizeof(int);
    quickSort(value, 0, size - 1, mode);
}

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

int parseInt(string value, ...){
    va_list args;
    va_start(args, value);
    int numBase = 10;

    int secondArg = va_arg(args, int);
    if (secondArg >= 2 && secondArg <= 36) {
        numBase = secondArg;
    }
    va_end(args);

    int result = 0;
    int len = strlen(value);

    for (int i = 0; i < len; i++) {
        char digit = value[i];
        int digitValue;

        if (digit >= '0' && digit <= '9') digitValue = digit - '0';
        else if (digit >= 'a' && digit <= 'z') digitValue = 10 + (digit - 'a');
        else if (digit >= 'A' && digit <= 'Z') digitValue = 10 + (digit - 'A');
        else return 0;

        if (digitValue >= numBase) return 0;

        result = result * numBase + digitValue;
    }

    return result;
}

string toString(int value){
    int i = snprintf(NULL, 0, "%d", value);
    string result = (char*)calloc(0, sizeof(char) * (i + 1));
    sprintf(result, "%d", value);
    return result;
}

string toBinaryString(int value){
    int i = sizeof(int) * 8;
    string str = (char*)malloc(sizeof(char) * (i + 1));

    *(str + i) = '\0';
    for(int j = i - 1; j >= 0; j--){
        *(str + j) = (value & 1) ? '1' : '0';
        value >>= 1;
    }

    string trim = str + strspn(str, "0");

    free(str);
    return !strlen(trim) ? "0" : trim;
}

string toOctalString(int value){
    int i = snprintf(NULL, 0, "%o", value);
    string result = (char*)calloc(0, sizeof(char) * (i + 1));
    sprintf(result, "%o", value);
    return result;
}

string toHexString(int value){
    int i = snprintf(NULL, 0, "%X", value);
    string result = (char*)calloc(0, sizeof(char) * (i + 1));
    sprintf(result, "%X", value);
    return result;
}

INTEGER Integer = {sort, max, min, parseInt, toString, toBinaryString, toOctalString, toHexString};
