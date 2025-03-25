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

Thread* new_Thread(void* (*function)(void*, ...)) {
    Thread* thread = (Thread*)malloc(sizeof(Thread));
    if (!thread) {
        perror("Thread 메모리 할당 실패");
        exit(EXIT_FAILURE);
    }
    thread->function = function;
    thread->start = start;
    thread->join = join;
    thread->detach = detach;
    thread->cancel = cancel;
    thread->exit = exit_thread;
    thread->delete = delete_thread;
    return thread;
}