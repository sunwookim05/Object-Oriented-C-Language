#pragma once
#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include "main.h"

#pragma pack(push, 1)
typedef struct STACK {
    void (*push)(struct STACK*, void*);
    void (*pop)(struct STACK*);
    void (*clear)(struct STACK*);
    void (*delete)(struct STACK*);
    void** data;
    size_t top;
    size_t size;
    size_t byteSize;
} Stack;
#pragma pack(pop)

Stack new_stack(size_t type);

#define new_Stack(type) new_stack(sizeof(type))

#pragma warning(pop)
#endif