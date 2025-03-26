#include "main.h"

#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#pragma pack(push, 1)
/**
 * @struct STACK
 * @brief Stack structure for storing generic data.
 */
typedef struct STACK {
    void** data;       ///< Pointer to the stack data array
    size_t top;        ///< Index of the top element
    size_t size;       ///< Total capacity of the stack
    size_t byteSize;   ///< Size of each element in bytes
    
    /**
     * @brief Pushes an element onto the stack.
     * @param stack Pointer to the stack.
     * @param element Pointer to the element to push.
     */
    void (*push)(struct STACK*, void*);
    
    /**
     * @brief Pops an element from the stack.
     * @param stack Pointer to the stack.
     * @return Pointer to the popped element.
     */
    void* (*pop)(struct STACK*);
    
    /**
     * @brief Clears all elements from the stack.
     * @param stack Pointer to the stack.
     */
    void (*clear)(struct STACK*);
    
    /**
     * @brief Deletes the stack and frees memory.
     * @param stack Pointer to the stack.
     */
    void (*delete)(struct STACK*);
} Stack;
#pragma pack(pop)

/**
 * @brief Creates a new stack with a given element size.
 * @param byteSize Size of each element in bytes.
 * @return A new Stack instance.
 */
Stack new_stack(size_t);

/**
 * @brief Macro to create a stack with a specified data type.
 */
#define new_Stack(type) new_stack(sizeof(type))

#pragma pack(push, 1)
/**
 * @struct QUEUE
 * @brief Queue structure for storing generic data.
 */
typedef struct QUEUE {
    void** data;       ///< Pointer to the queue data array
    size_t size;       ///< Total capacity of the queue
    size_t byteSize;   ///< Size of each element in bytes
    
    /**
     * @brief Pushes an element into the queue.
     * @param queue Pointer to the queue.
     * @param element Pointer to the element to push.
     */
    void (*push)(struct QUEUE*, void*);
    
    /**
     * @brief Pops an element from the queue.
     * @param queue Pointer to the queue.
     * @return Pointer to the popped element.
     */
    void* (*pop)(struct QUEUE*);
    
    /**
     * @brief Clears all elements from the queue.
     * @param queue Pointer to the queue.
     */
    void (*clear)(struct QUEUE*);
    
    /**
     * @brief Deletes the queue and frees memory.
     * @param queue Pointer to the queue.
     */
    void (*delete)(struct QUEUE*);
} Queue;
#pragma pack(pop)

/**
 * @brief Creates a new queue with a given element size.
 * @param byteSize Size of each element in bytes.
 * @return A new Queue instance.
 */
Queue new_queue(size_t);

/**
 * @brief Macro to create a queue with a specified data type.
 */
#define new_Queue(type) new_queue(sizeof(type))

#pragma pack(push, 1)
/**
 * @struct DEQUE
 * @brief Deque (double-ended queue) structure for storing generic data.
 */
typedef struct DEQUE {
    void** data;       ///< Pointer to the deque data array
    size_t size;       ///< Total capacity of the deque
    size_t byteSize;   ///< Size of each element in bytes
    
    /**
     * @brief Pushes an element to the front of the deque.
     * @param deque Pointer to the deque.
     * @param element Pointer to the element to push.
     */
    void (*pushFront)(struct DEQUE*, void*);
    
    /**
     * @brief Pushes an element to the back of the deque.
     * @param deque Pointer to the deque.
     * @param element Pointer to the element to push.
     */
    void (*pushBack)(struct DEQUE*, void*);
    
    /**
     * @brief Pops an element from the front of the deque.
     * @param deque Pointer to the deque.
     * @return Pointer to the popped element.
     */
    void* (*popFront)(struct DEQUE*);
    
    /**
     * @brief Pops an element from the back of the deque.
     * @param deque Pointer to the deque.
     * @return Pointer to the popped element.
     */
    void* (*popBack)(struct DEQUE*);
    
    /**
     * @brief Clears all elements from the deque.
     * @param deque Pointer to the deque.
     */
    void (*clear)(struct DEQUE*);
    
    /**
     * @brief Deletes the deque and frees memory.
     * @param deque Pointer to the deque.
     */
    void (*delete)(struct DEQUE*);
} Deque;
#pragma pack(pop)

/**
 * @brief Creates a new deque with a given element size.
 * @param byteSize Size of each element in bytes.
 * @return A new Deque instance.
 */
Deque new_deque(size_t);

/**
 * @brief Macro to create a deque with a specified data type.
 */
#define new_Deque(type) new_deque(sizeof(type))

#pragma pack(push, 1)
/**
 * @struct LIST
 * @brief List structure for storing generic data.
 */
typedef struct LIST {
    void** data;       ///< Pointer to the list data array
    size_t size;       ///< Total capacity of the list
    size_t byteSize;   ///< Size of each element in bytes
    
    /**
     * @brief Adds an element to the list.
     * @param list Pointer to the list.
     * @param element Pointer to the element to add.
     */
    void (*add)(struct LIST*, void*);
    
    /**
     * @brief Removes an element from the list at the given index.
     * @param list Pointer to the list.
     * @param index Index of the element to remove.
     * @return Pointer to the removed element.
     */
    void* (*remove)(struct LIST*, size_t);
    
    /**
     * @brief Clears all elements from the list.
     * @param list Pointer to the list.
     */
    void (*clear)(struct LIST*);
    
    /**
     * @brief Deletes the list and frees memory.
     * @param list Pointer to the list.
     */
    void (*delete)(struct LIST*);
} List;
#pragma pack(pop)

/**
 * @brief Creates a new list with a given element size.
 * @param byteSize Size of each element in bytes.
 * @return A new List instance.
 */
List new_list(size_t);

/**
 * @brief Macro to create a list with a specified data type.
 */
#define new_List(type) new_list(sizeof(type))

#endif
