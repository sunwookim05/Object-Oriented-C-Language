#include "algorithm.h"

static void stackPush(Stack* self, void* data) {
    if (self == null || data == null || self->byteSize == 0) return;

    void** resized = (void**)realloc(self->data, (self->top + 1) * sizeof(void*));
    if (resized == null) return;

    self->data = resized;
    *(self->data + self->top) = malloc(self->byteSize);
    if (*(self->data + self->top) == null) return;

    memcpy(*(self->data + self->top), data, self->byteSize);
    self->top++;
    self->size = self->top;
}

static void* stackPop(Stack* self) {
    if (self == null || self->top == 0 || self->data == null) return null;

    void* removedData = *(self->data + self->top - 1);
    self->top--;
    self->size = self->top;

    if (self->top == 0) {
        free(self->data);
        self->data = null;
    } else {
        void** resized = (void**)realloc(self->data, self->top * sizeof(void*));
        if (resized != null) self->data = resized;
    }

    return removedData;
}

static void stackClear(Stack* self) {
    if (self == null) return;
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
    if (self == null || data == null || self->byteSize == 0) return;

    void** resized = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    if (resized == null) return;

    self->data = resized;
    *(self->data + self->size) = malloc(self->byteSize);
    if (*(self->data + self->size) == null) return;

    memcpy(*(self->data + self->size), data, self->byteSize);
    self->size++;
}

static void* queuePop(Queue* self) {
    if (self == null || self->size == 0 || self->data == null) return null;

    void* removedData = *(self->data);
    self->size--;

    if (self->size == 0) {
        free(self->data);
        self->data = null;
    } else {
        memmove(self->data, self->data + 1, self->size * sizeof(void*));
        void** resized = (void**)realloc(self->data, self->size * sizeof(void*));
        if (resized != null) self->data = resized;
    }

    return removedData;
}

static void queueClear(Queue* self) {
    if (self == null) return;
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
    if (self == null || data == null || self->byteSize == 0) return;

    void** resized = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    if (resized == null) return;

    self->data = resized;
    void* newItem = malloc(self->byteSize);
    if (newItem == null) return;

    memmove(self->data + 1, self->data, self->size * sizeof(void*));
    *(self->data) = newItem;
    memcpy(newItem, data, self->byteSize);
    self->size++;
}

static void dequePushBack(Deque* self, void* data) {
    if (self == null || data == null || self->byteSize == 0) return;

    void** resized = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    if (resized == null) return;

    self->data = resized;
    *(self->data + self->size) = malloc(self->byteSize);
    if (*(self->data + self->size) == null) return;

    memcpy(*(self->data + self->size), data, self->byteSize);
    self->size++;
}

static void* dequePopFront(Deque* self) {
    if (self == null || self->size == 0 || self->data == null) return null;

    void* removedData = *(self->data);
    self->size--;

    if (self->size == 0) {
        free(self->data);
        self->data = null;
    } else {
        memmove(self->data, self->data + 1, self->size * sizeof(void*));
        void** resized = (void**)realloc(self->data, self->size * sizeof(void*));
        if (resized != null) self->data = resized;
    }

    return removedData;
}

static void* dequePopBack(Deque* self) {
    if (self == null || self->size == 0 || self->data == null) return null;

    void* removedData = *(self->data + self->size - 1);
    self->size--;

    if (self->size == 0) {
        free(self->data);
        self->data = null;
    } else {
        void** resized = (void**)realloc(self->data, self->size * sizeof(void*));
        if (resized != null) self->data = resized;
    }

    return removedData;
}

static void dequeClear(Deque* self) {
    if (self == null) return;
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
    if (self == null || data == null || self->byteSize == 0) return;

    void** resized = (void**)realloc(self->data, (self->size + 1) * sizeof(void*));
    if (resized == null) return;

    self->data = resized;
    *(self->data + self->size) = malloc(self->byteSize);
    if (*(self->data + self->size) == null) return;

    memcpy(*(self->data + self->size), data, self->byteSize);
    self->size++;
}

static void* listRemove(List* self, size_t index) {
    if (self == null || index >= self->size || self->data == null) return null;

    void* removedData = *(self->data + index);
    self->size--;

    if (index < self->size) {
        memmove(self->data + index, self->data + index + 1, (self->size - index) * sizeof(void*));
    }

    if (self->size == 0) {
        free(self->data);
        self->data = null;
    } else {
        void** resized = (void**)realloc(self->data, self->size * sizeof(void*));
        if (resized != null) self->data = resized;
    }

    return removedData;
}

static void listClear(List* self) {
    if (self == null) return;
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
