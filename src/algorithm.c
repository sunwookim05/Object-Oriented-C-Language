#include "algorithm.h"

static void push(Stack* stack, void* data) {
    stack->data = (void**)realloc(stack->data, (stack->top + 1) * sizeof(void*));
    memcpy((char*)stack->data + stack->top * sizeof(void*), data, stack->byteSize);
    stack->top++;
    stack->size = (stack->top) * sizeof(void*);
}

static void pop(Stack* stack) {
    stack->top--;
    stack->size = (stack->top) * sizeof(void*);
    stack->data = (void**)realloc(stack->data, stack->size);
}

static void clear(Stack* stack) {
    stack->top = 0;
    stack->size = 0;
    stack->data = (void**)realloc(stack->data, stack->size);
}

static void delete(Stack* stack) {
    free(stack->data);
    stack->top = 0;
    stack->size = 0;
}

Stack new_stack(size_t type) {
    Stack stack;
    stack.data = (void**)malloc(sizeof(void*));
    stack.push = push;
    stack.pop = pop;
    stack.clear = clear;
    stack.delete = delete;
    stack.top = 0;
    stack.size = 0;
    stack.byteSize = type;
    return stack;
}