#include "main.h"
#include "algorithm.h"

void push(Stack* stack, void* data) {
    stack->data = (void**)realloc(stack->data, (stack->top + 1) * stack->dataSize);
    memcpy((char*)stack->data + stack->top * stack->dataSize, data, stack->dataSize);
    stack->top++;
    stack->size = stack->top * stack->dataSize;
}

void pop(Stack* stack) {
    stack->top--;
    stack->size = stack->top * stack->dataSize;
    stack->data = (void**)realloc(stack->data, stack->size);
}

void clear(Stack* stack) {
    stack->top = 0;
    stack->size = 0;
    stack->data = (void**)realloc(stack->data, stack->size);
}

void delete(Stack* stack) {
    free(stack->data);
    stack->top = 0;
    stack->size = 0;
}