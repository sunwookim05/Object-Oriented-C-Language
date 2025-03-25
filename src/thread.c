#include "thread.h"

void start(Thread* thread) {
    #ifdef _WIN32
        thread->id = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread->function, NULL, 0, NULL);
    #else
        pthread_create(&thread->id, NULL, thread->function, NULL);
    #endif
}

void join(Thread* thread) {
    #ifdef _WIN32
        WaitForSingleObject(thread->id, INFINITE);
    #else
        pthread_join(thread->id, NULL);
    #endif
}

void detach(Thread* thread) {
    #ifdef _WIN32
        CloseHandle(thread->id);
    #else
        pthread_detach(thread->id);
    #endif
}

void cancel(Thread* thread) {
    #ifdef _WIN32
        TerminateThread(thread->id, 0);
    #else
        pthread_cancel(thread->id);
    #endif
}

void exit_thread(Thread* thread) {
    #ifdef _WIN32
        ExitThread(0);
    #else
        pthread_exit(NULL);
    #endif
}

void delete_thread(Thread* thread) {
    #ifdef _WIN32
        CloseHandle(thread->id);
    #endif
    free(thread);
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
    void lock_mutex(Mutex* mutex) {
        WaitForSingleObject(mutex->id, INFINITE);
    }

    void unlock_mutex(Mutex* mutex) {
        ReleaseMutex(mutex->id);
    }

    void delete_mutex(Mutex* mutex) {
        CloseHandle(mutex->id);
    }
#else
    void lock_mutex(Mutex* mutex) {
        pthread_mutex_lock(&mutex->id);
    }

    void unlock_mutex(Mutex* mutex) {
        pthread_mutex_unlock(&mutex->id);
    }

    void delete_mutex(Mutex* mutex) {
        pthread_mutex_destroy(&mutex->id);
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