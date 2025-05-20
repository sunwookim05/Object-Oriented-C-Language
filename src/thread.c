#include "thread.h"

#include <stdarg.h>
#include <stdlib.h>

void start(Thread* self, ...) {
    va_list args;
    va_start(args, self);
    
    void* arg = va_arg(args, void*);
    
    va_end(args);

    #ifdef _WIN32
        self->id = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)self->function, arg, 0, NULL);
    #else
        pthread_create(&self->id, NULL, self->function, arg);
    #endif
}


void join(Thread* self) {
    #ifdef _WIN32
        WaitForSingleObject(self->id, INFINITE);
    #else
        pthread_join(self->id, NULL);
    #endif
}

void detach(Thread* self) {
    #ifdef _WIN32
        CloseHandle(self->id);
    #else
        pthread_detach(self->id);
    #endif
}

void cancel(Thread* self) {
    #ifdef _WIN32
        TerminateThread(self->id, 0);
    #else
        pthread_cancel(self->id);
    #endif
}

void exit_thread(Thread* self) {
    #ifdef _WIN32
        ExitThread(0);
    #else
        pthread_exit(NULL);
    #endif
}

void delete_thread(Thread* self) {
    #ifdef _WIN32
        CloseHandle(self->id);
    #endif
    free(self);
}

Thread new_Thread(void* (*function)(void*)) {
    return (Thread) {
        .id = 0,
        .function = function,
        .start = start,
        .join = join,
        .detach = detach,
        .cancel = cancel,
        .exit = exit_thread,    
        .delete = delete_thread
    };
}

#ifdef _WIN32
    void lock_mutex(Mutex* self) {
        WaitForSingleObject(self->id, INFINITE);
    }

    void unlock_mutex(Mutex* self) {
        ReleaseMutex(self->id);
    }

    void delete_mutex(Mutex* self) {
        CloseHandle(self->id);
    }
#else
    void lock_mutex(Mutex* self) {
        pthread_mutex_lock(&self->id);
    }

    void unlock_mutex(Mutex* self) {
        pthread_mutex_unlock(&self->id);
    }

    void delete_mutex(Mutex* self) {
        pthread_mutex_destroy(&self->id);
    }
#endif

Mutex new_Mutex() {
    Mutex mutex;

    #ifdef _WIN32
        mutex.id = CreateMutex(NULL, FALSE, NULL);
    #else
        pthread_mutex_init(&mutex.id, NULL);
    #endif
    
    mutex.lock = lock_mutex;
    mutex.unlock = unlock_mutex;
    mutex.delete = delete_mutex;
        
    return mutex;
} 