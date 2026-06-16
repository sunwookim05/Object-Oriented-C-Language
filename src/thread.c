#include "thread.h"

#include <stdarg.h>
#include <stdlib.h>

#ifdef _WIN32
static DWORD WINAPI thread_entry(LPVOID arg) {
    Thread* self = (Thread*)arg;
    if (self == NULL || self->function == NULL) return 1;

    self->function(self->arg);
    return 0;
}
#else
static void* thread_entry(void* arg) {
    Thread* self = (Thread*)arg;
    if (self == NULL || self->function == NULL) return NULL;

    return self->function(self->arg);
}
#endif

void start(Thread* self, ...) {
    if (self == NULL || self->function == NULL) return;

    va_list args;
    va_start(args, self);
    
    self->arg = va_arg(args, void*);
    
    va_end(args);

    #ifdef _WIN32
        self->id = CreateThread(NULL, 0, thread_entry, self, 0, NULL);
    #else
        pthread_create(&self->id, NULL, thread_entry, self);
    #endif
}


void join(Thread* self) {
    if (self == NULL) return;

    #ifdef _WIN32
        if (self->id != NULL) WaitForSingleObject(self->id, INFINITE);
    #else
        pthread_join(self->id, NULL);
    #endif
}

void detach(Thread* self) {
    if (self == NULL) return;

    #ifdef _WIN32
        if (self->id != NULL) {
            CloseHandle(self->id);
            self->id = NULL;
        }
    #else
        pthread_detach(self->id);
    #endif
}

void cancel(Thread* self) {
    if (self == NULL) return;

    #ifdef _WIN32
        if (self->id != NULL) TerminateThread(self->id, 0);
    #else
        pthread_cancel(self->id);
    #endif
}

void exit_thread(Thread* self) {
    (void)self;

    #ifdef _WIN32
        ExitThread(0);
    #else
        pthread_exit(NULL);
    #endif
}

void delete_thread(Thread* self) {
    if (self == NULL) return;

    #ifdef _WIN32
        if (self->id != NULL) {
            CloseHandle(self->id);
            self->id = NULL;
        }
    #endif
    self->function = NULL;
    self->arg = NULL;
}

Thread new_Thread(void* (*function)(void*)) {
    return (Thread) {
        .id = 0,
        .function = function,
        .arg = NULL,
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
