#include "main.h"

#pragma once
#ifndef __ALGORITHM_H
#define __ALGORITHM_H

typedef struct  STACK{
    void** data;
    void (*push)(struct STACK*, void*);
    void (*pop)(struct STACK*);
    void (*clear)(struct STACK*);
    void (*delete)(struct STACK*);
    size_t top;
    size_t size;
    size_t dataSize;
}Stack;

void push(Stack*, void*);
void pop(Stack*);
void clear(Stack*);
void delete(Stack*);

#define new_Stack(type) \
({ \
    Stack stack; \
    stack.data = (void**)malloc(sizeof(void*)); \
    stack.push = push; \
    stack.pop = pop; \
    stack.clear = clear; \
    stack.delete = delete; \
    stack.top = 0; \
    stack.size = 0; \
    stack.dataSize = sizeof(type); \
    stack; \
})


#pragma warning(pop)
#endif