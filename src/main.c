#include "main.h"
#include "System.h"
#include "algorithm.h"

import SYSTEM System;

int main(void){ 
    Stack stack = new_Stack(int);
    Queue queue = new_Queue(int);
    int* value = (int*)malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++) {
        *(value + i) = i;
        stack.push(&stack, value + i);
        for (int j = 0; j < stack.top; j++) System.out.printf("%d ", *(int*)*(stack.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        int* poppedValue = (int*)stack.pop(&stack);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < stack.top; j++) System.out.printf("%d ", *(int*)*(stack.data + j));
        System.out.println("");
    }

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = i;
        queue.push(&queue, value + i);
        for (int j = 0; j < queue.size; j++) System.out.printf("%d ", *(int*)*(queue.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        int* poppedValue = (int*)queue.pop(&queue);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < queue.size; j++) System.out.printf("%d ", *(int*)*(queue.data + j));
        System.out.println("");
    }

    stack.clear(&stack);
    stack.delete(&stack);
    queue.clear(&queue);
    queue.delete(&queue);
    free(value);
    return 0;
}