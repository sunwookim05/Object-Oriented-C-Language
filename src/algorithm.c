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

static void dequePushFront(Deque* deque, void* data) {
    deque->data = (void**)realloc(deque->data, (deque->size + 1) * sizeof(void*));
    memmove(deque->data + 1, deque->data, deque->size * sizeof(void*));
    *(deque->data) = malloc(deque->byteSize);
    memcpy(*(deque->data), data, deque->byteSize);
    deque->size++;
}

static void dequePushBack(Deque* deque, void* data) {
    deque->data = (void**)realloc(deque->data, (deque->size + 1) * sizeof(void*));
    *(deque->data + deque->size) = malloc(deque->byteSize);
    memcpy(*(deque->data + deque->size), data, deque->byteSize);
    deque->size++;
}

static void* dequePopFront(Deque* deque) {
    void* removedData = *(deque->data);
    memmove(deque->data, deque->data + 1, (deque->size - 1) * sizeof(void*));
    deque->data = (void**)realloc(deque->data, (deque->size - 1) * sizeof(void*));
    deque->size--;

    return removedData;
}

static void* dequePopBack(Deque* deque) {
    void* removedData = *(deque->data + deque->size - 1);
    deque->data = (void**)realloc(deque->data, (deque->size - 1) * sizeof(void*));
    deque->size--;

    return removedData;
}

static void dequeClear(Deque* deque) {
    for (size_t i = 0; i < deque->size; i++) {
        free(*(deque->data + i));
    }
    free(deque->data);
    deque->data = null;
    deque->size = 0;
}

static void dequeDelete(Deque* deque) {
    dequeClear(deque);
    deque->byteSize = 0;
    deque->data = null;
}

Deque new_deque(size_t type) {
    Deque deque;
    deque.data = null;
    deque.byteSize = type;
    deque.pushFront = dequePushFront;
    deque.pushBack = dequePushBack;
    deque.popFront = dequePopFront;
    deque.popBack = dequePopBack;
    deque.clear = dequeClear;
    deque.delete = dequeDelete;
    deque.size = 0;
    return deque;
}

static void listAdd(List* list, void* data) {
    list->data = (void**)realloc(list->data, (list->size + 1) * sizeof(void*));
    *(list->data + list->size) = malloc(list->byteSize);
    memcpy(*(list->data + list->size), data, list->byteSize);
    list->size++;
}

static void* listRemove(List* list, size_t index) {
    void* removedData = *(list->data + index);
    memmove(list->data + index, list->data + index + 1, (list->size - index - 1) * sizeof(void*));
    list->data = (void**)realloc(list->data, (list->size - 1) * sizeof(void*));
    list->size--;

    return removedData;
}

static void listClear(List* list) {
    for (size_t i = 0; i < list->size; i++) {
        free(*(list->data + i));
    }
    free(list->data);
    list->data = null;
    list->size = 0;
}

static void listDelete(List* list) {
    listClear(list);
    list->byteSize = 0;
    list->data = null;
}

List new_list(size_t type) {
    List list;
    list.data = null;
    list.byteSize = type;
    list.add = listAdd;
    list.remove = listRemove;
    list.clear = listClear;
    list.delete = listDelete;
    list.size = 0;
    return list;
}