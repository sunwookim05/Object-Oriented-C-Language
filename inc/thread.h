#include "main.h"

#ifndef __THREAD_H
#define __THREAD_H

#ifdef _WIN32
    #include <windows.h>
    #include <process.h>
    typedef HANDLE ThreadHandle;  // Thread handle type for Windows
    typedef HANDLE MutexHandle;   // Mutex handle type for Windows
    #define THREAD_FUNC_RETURN DWORD WINAPI  // Thread function return type for Windows
    #define THREAD_FUNC_PARAM LPVOID         // Thread function parameter type for Windows
    #define SLEEP(ms) Sleep(ms)              // Sleep function for Windows
#else
    #include <pthread.h>
    #include <unistd.h>
    typedef pthread_t ThreadHandle;  // Thread handle type for POSIX
    typedef pthread_mutex_t MutexHandle; // Mutex handle type for POSIX
    #define THREAD_FUNC_RETURN void*     // Thread function return type for POSIX
    #define THREAD_FUNC_PARAM void*      // Thread function parameter type for POSIX
    #define SLEEP(ms) usleep((ms)*1000)  // Sleep function for POSIX
#endif

#pragma pack(push, 1)
/**
 * @struct THREAD
 * @brief Structure representing a thread object.
 */
typedef struct THREAD {
    ThreadHandle id; /**< Thread identifier */
    void* (*function)(void*); /**< Function pointer for thread execution */
    
    /**
     * @brief Starts the thread.
     * @param self Pointer to the THREAD structure.
     * @param ... Additional arguments (platform-dependent usage).
     */
    void (*start)(struct THREAD*, ...);
    
    /**
     * @brief Waits for the thread to finish execution.
     * @param self Pointer to the THREAD structure.
     */
    void (*join)(struct THREAD*);
    
    /**
     * @brief Detaches the thread, allowing it to run independently.
     * @param self Pointer to the THREAD structure.
     */
    void (*detach)(struct THREAD*);
    
    /**
     * @brief Cancels the thread execution.
     * @param self Pointer to the THREAD structure.
     */
    void (*cancel)(struct THREAD*);
    
    /**
     * @brief Exits the thread.
     * @param self Pointer to the THREAD structure.
     */
    void (*exit)(struct THREAD*);
    
    /**
     * @brief Deletes the thread object and releases resources.
     * @param self Pointer to the THREAD structure.
     */
    void (*delete)(struct THREAD*);
} Thread;
#pragma pack(pop)

/**
 * @struct MUTEX
 * @brief Structure representing a mutex object.
 */
typedef struct MUTEX {
    MutexHandle id; /**< Mutex identifier */
    
    /**
     * @brief Locks the mutex.
     * @param self Pointer to the MUTEX structure.
     */
    void (*lock)(struct MUTEX*);
    
    /**
     * @brief Unlocks the mutex.
     * @param self Pointer to the MUTEX structure.
     */
    void (*unlock)(struct MUTEX*);
    
    /**
     * @brief Deletes the mutex object and releases resources.
     * @param self Pointer to the MUTEX structure.
     */
    void (*delete)(struct MUTEX*);
} Mutex;

/**
 * @brief Creates a new thread object.
 * @param function Function pointer that the thread will execute.
 * @return A Thread structure initialized with the given function.
 */
Thread new_Thread(void* (*function)(void*));

/**
 * @brief Creates a new mutex object.
 * @return A Mutex structure initialized and ready for use.
 */
Mutex new_Mutex();

#endif
