#include "main.h"

#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#pragma pack(push, 1)
typedef struct STACK {
    void** data;
    size_t top;
    size_t size;
    size_t byteSize;
    void (*push)(struct STACK*, void*);
    void* (*pop)(struct STACK*);
    void (*clear)(struct STACK*);
    void (*delete)(struct STACK*);
} Stack;
#pragma pack(pop)

Stack new_stack(size_t type);

#define new_Stack(type) new_stack(sizeof(type))

#pragma pack(push, 1)
typedef struct QUEUE {
    void** data;
    size_t size;
    size_t byteSize;
    void (*push)(struct QUEUE*, void*);
    void* (*pop)(struct QUEUE*);
    void (*clear)(struct QUEUE*);
    void (*delete)(struct QUEUE*);
} Queue;
#pragma pack(pop)

Queue new_queue(size_t type);

#define new_Queue(type) new_queue(sizeof(type))

#pragma pack(push, 1)
typedef struct DEQUE {
    void** data;
    size_t size;
    size_t byteSize;
    void (*pushFront)(struct DEQUE*, void*);
    void (*pushBack)(struct DEQUE*, void*);
    void* (*popFront)(struct DEQUE*);
    void* (*popBack)(struct DEQUE*);
    void (*clear)(struct DEQUE*);
    void (*delete)(struct DEQUE*);
} Deque;
#pragma pack(pop)

Deque new_deque(size_t type);

#define new_Deque(type) new_deque(sizeof(type))

#pragma pack(push, 1)
typedef struct LIST {
    void** data;
    size_t size;
    size_t byteSize;
    void (*add)(struct LIST*, void*);
    void* (*remove)(struct LIST*, size_t);
    void (*clear)(struct LIST*);
    void (*delete)(struct LIST*);
} List;
#pragma pack(pop)

List new_list(size_t type);

#define new_List(type) new_list(sizeof(type))

#endif