#include "main.h"

#ifndef __THREAD_H
#define __THREAD_H

#ifdef _WIN32
    #include <windows.h>
    #include <process.h>
    typedef HANDLE ThreadHandle;
    typedef HANDLE MutexHandle;
    #define THREAD_FUNC_RETURN DWORD WINAPI
    #define THREAD_FUNC_PARAM LPVOID
    #define SLEEP(ms) Sleep(ms)
#else
    #include <pthread.h>
    #include <unistd.h>
    typedef pthread_t ThreadHandle;
    typedef pthread_mutex_t MutexHandle;
    #define THREAD_FUNC_RETURN void*
    #define THREAD_FUNC_PARAM void*
    #define SLEEP(ms) usleep((ms)*1000)
#endif

#pragma pack(push, 1)
typedef struct THREAD {
    ThreadHandle id;
    void* (*function)(void*);
    void (*start)(struct THREAD*);
    void (*join)(struct THREAD*);
    void (*detach)(struct THREAD*);
    void (*cancel)(struct THREAD*);
    void (*exit)(struct THREAD*);
    void (*delete)(struct THREAD*);
} Thread;
#pragma pack(pop)

typedef struct MUTEX {
    MutexHandle id;
    void (*lock)(struct MUTEX*);
    void (*unlock)(struct MUTEX*);
    void (*delete)(struct MUTEX*);
} Mutex;

Thread new_Thread(void* (*function)(void*));
Mutex new_Mutex();

#endif