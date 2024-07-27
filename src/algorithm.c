#include "algorithm.h"

static void stackPush(Stack* stack, void* data) {
    stack->data = (void**)realloc(stack->data, (stack->top + 1) * sizeof(void*));
    *(stack->data + stack->top) = malloc(stack->byteSize);
    memcpy(*(stack->data + stack->top), data, stack->byteSize);
    stack->top++;
    stack->size = stack->top * sizeof(void*);
}

static void* stackPop(Stack* stack) {
    void* removedData = *(stack->data + stack->top - 1);
    stack->top--;
    stack->size = stack->top * sizeof(void*);
    stack->data = (void**)realloc(stack->data, stack->size);
    return removedData;
}

static void stackClear(Stack* stack) {
    for (size_t i = 0; i < stack->top; i++) free(*(stack->data + i));
    stack->top = 0;
    stack->size = 0;
    free(stack->data);
    stack->data = null;
}

static void stackDelete(Stack* stack) {
    stackClear(stack);
    stack->byteSize = 0;
    stack->data = null;
}

Stack new_stack(size_t type) {
    Stack stack;
    stack.data = null;
    stack.push = stackPush;
    stack.pop = stackPop;
    stack.clear = stackClear;
    stack.delete = stackDelete;
    stack.top = 0;
    stack.size = 0;
    stack.byteSize = type;
    return stack;
}

static void queuePush(Queue* queue, void* data) {
    queue->data = (void**)realloc(queue->data, (queue->size + 1) * sizeof(void*));
    *(queue->data + queue->size) = malloc(queue->byteSize);
    memcpy(*(queue->data + queue->size), data, queue->byteSize);
    queue->size++;
}

static void* queuePop(Queue* queue) {
    void* removedData = *(queue->data);
    memmove(queue->data, queue->data + 1, (queue->size - 1) * sizeof(void*));
    queue->data = (void**)realloc(queue->data, (queue->size - 1) * sizeof(void*));
    queue->size--;

    return removedData;
}

static void queueClear(Queue* queue) {
    for (size_t i = 0; i < queue->size; i++) {
        free(*(queue->data + i));
    }
    free(queue->data);
    queue->data = null;
    queue->size = 0;
}

static void queueDelete(Queue* queue) {
    queueClear(queue);
    queue->byteSize = 0;
    queue->data = null;
}

Queue new_queue(size_t type) {
    Queue queue;
    queue.data = null;
    queue.byteSize = type;
    queue.push = queuePush;
    queue.pop = queuePop;
    queue.clear = queueClear;
    queue.delete = queueDelete;
    queue.size = 0;
    return queue;
}