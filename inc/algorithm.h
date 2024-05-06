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

Stack new_stack(size_t size);

#define new_Stack(type) new_stack(sizeof(type))

#pragma warning(pop)
#endif