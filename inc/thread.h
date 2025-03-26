#include "main.h"

#ifndef __THREAD_H
#define __THREAD_H

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
