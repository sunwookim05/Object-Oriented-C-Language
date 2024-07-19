#pragma once
#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include "main.h"

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

#pragma warning(pop)
#endif