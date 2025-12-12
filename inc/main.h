#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#ifndef __MAIN_H
#define __MAIN_H

#ifdef _WIN32
    #include <windows.h>
    #include <process.h>
    #include <conio.h>
    #include <tlhelp32.h>
    typedef HANDLE ThreadHandle;  // Thread handle type for Windows
    typedef HANDLE MutexHandle;   // Mutex handle type for Windows
    #define THREAD_FUNC_RETURN DWORD WINAPI  // Thread function return type for Windows
    #define THREAD_FUNC_PARAM LPVOID         // Thread function parameter type for Windows
    #define sleep(ms) Sleep(ms)              // Sleep function for Windows
#else
    #include <pthread.h>
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    typedef pthread_t ThreadHandle;  // Thread handle type for POSIX
    typedef pthread_mutex_t MutexHandle; // Mutex handle type for POSIX
    #define THREAD_FUNC_RETURN void*     // Thread function return type for POSIX
    #define THREAD_FUNC_PARAM void*      // Thread function parameter type for POSIX
    #define sleep(ms) usleep((ms)*1000)  // Sleep function for POSIX
#endif

#define import extern
#define final const
#define null NULL
#define false 0
#define true 1

typedef char* string;
// typedef int8_t byte;
// typedef uint8_t ubyte;
typedef uint8_t boolean;

#endif