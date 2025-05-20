#include "algorithm.h"

static void stackPush(Stack* self, void* data) {
    self->data = (void**)realloc(self->data, (self->top + 1) * sizeof(void*));
    *(self->data + self->top) = malloc(self->byteSize);
    memcpy(*(self->data + self->top), data, self->byteSize);
    self->top++;
    self->size = self->top * sizeof(void*);
}

static void* stackPop(Stack* self) {
    void* removedData = *(self->data + self->top - 1);
    self->top--;
    self->size = self->top * sizeof(void*);
    self->data = (void**)realloc(self->data, self->size);
    return removedData;
}

static void stackClear(Stack* self) {
    for (size_t i = 0; i < self->top; i++) free(*(self->data + i));
    self->top = 0;
    self->size = 0;
    free(self->data);
    self->data = null;
}

static void stackDelete(Stack* self) {
    stackClear(self);
    self->byteSize = 0;
    self->data = null;
}

Stack new_stack(size_t type) {
    return (Stack) {
        .data = null,
        .byteSize = type,
        .push = stackPush,
        .pop = stackPop,
        .clear = stackClear,
        .delete = stackDelete,
        .top = 0,
        .size = 0
    };
}

static void queuePush(Queue* self, void* data) {
    self->data = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    *(self->data + self->size) = malloc(self->byteSize);
    memcpy(*(self->data + self->size), data, self->byteSize);
    self->size++;
}

static void* queuePop(Queue* self) {
    void* removedData = *(self->data);
    memmove(self->data, self->data + 1, (self->size - 1) * sizeof(void*));
    self->data = (void**)realloc(self->data, (self->size - 1) * sizeof(void*));
    self->size--;
    return removedData;
}

static void queueClear(Queue* self) {
    for (size_t i = 0; i < self->size; i++) free(*(self->data + i));
    free(self->data);
    self->data = null;
    self->size = 0;
}

static void queueDelete(Queue* self) {
    queueClear(self);
    self->byteSize = 0;
    self->data = null;
}

Queue new_queue(size_t type) {
    return (Queue){
        .data = null,
        .byteSize = type,
        .push = queuePush,
        .pop = queuePop,
        .clear = queueClear,
        .delete = queueDelete,
        .size = 0
    };
}

static void dequePushFront(Deque* self, void* data) {
    self->data = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    memmove(self->data + 1, self->data, self->size * sizeof(void*));
    *(self->data) = malloc(self->byteSize);
    memcpy(*(self->data), data, self->byteSize);
    self->size++;
}

static void dequePushBack(Deque* self, void* data) {
    self->data = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    *(self->data + self->size) = malloc(self->byteSize);
    memcpy(*(self->data + self->size), data, self->byteSize);
    self->size++;
}

static void* dequePopFront(Deque* self) {
    void* removedData = *(self->data);
    memmove(self->data, self->data + 1, (self->size - 1) * sizeof(void*));
    self->data = (void**)realloc(self->data, (self->size - 1) * sizeof(void*));
    self->size--;
    return removedData;
}

static void* dequePopBack(Deque* self) {
    void* removedData = *(self->data + self->size - 1);
    self->data = (void**)realloc(self->data, (self->size - 1) * sizeof(void*));
    self->size--;

    return removedData;
}

static void dequeClear(Deque* self) {
    for (size_t i = 0; i < self->size; i++) free(*(self->data + i));
    free(self->data);
    self->data = null;
    self->size = 0;
}

static void dequeDelete(Deque* self) {
    dequeClear(self);
    self->byteSize = 0;
    self->data = null;
}

Deque new_deque(size_t type) {
    return (Deque) {
        .data = null,
        .byteSize = type,
        .pushFront = dequePushFront,
        .pushBack = dequePushBack,
        .popFront = dequePopFront,
        .popBack = dequePopBack,
        .clear = dequeClear,
        .delete = dequeDelete,
        .size = 0
    };
}

static void listAdd(List* self, void* data) {
    self->data = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    *(self->data + self->size) = malloc(self->byteSize);
    memcpy(*(self->data + self->size), data, self->byteSize);
    self->size++;
}

static void* listRemove(List* self, size_t index) {
    void* removedData = *(self->data + index);
    memmove(self->data + index, self->data + index + 1, (self->size - index - 1) * sizeof(void*));
    self->data = (void**)realloc(self->data, (self->size - 1) * sizeof(void*));
    self->size--;
    return removedData;
}

static void listClear(List* self) {
    for (size_t i = 0; i < self->size; i++) free(*(self->data + i));
    free(self->data);
    self->data = null;
    self->size = 0;
}

static void listDelete(List* self) {
    listClear(self);
    self->byteSize = 0;
    self->data = null;
}

List new_list(size_t type) {
    return (List) {
        .data = null,
        .byteSize = type,
        .add = listAdd,
        .remove = listRemove,
        .clear = listClear,
        .delete = listDelete,
        .size = 0
    };
} 