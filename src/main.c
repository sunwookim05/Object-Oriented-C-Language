#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"

import SYSTEM System;

int main(void){ 
    Stack stack = new_Stack(int);
    Queue queue = new_Queue(int);
    Deque deque = new_Deque(int);
    short* value = (short*)malloc(sizeof(int) * 10);

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
        stack.push(&stack, value + i);
        for (int j = 0; j < stack.top; j++) System.out.printf("%d ", *(short*)*(stack.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        short* poppedValue = (short*)stack.pop(&stack);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < stack.top; j++) System.out.printf("%d ", *(short*)*(stack.data + j));
        System.out.println("");
    }

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
        queue.push(&queue, value + i);
        for (int j = 0; j < queue.size; j++) System.out.printf("%d ", *(short*)*(queue.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        short* poppedValue = (short*)queue.pop(&queue);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < queue.size; j++) System.out.printf("%d ", *(short*)*(queue.data + j));
        System.out.println("");
    }

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
        deque.pushFront(&deque, value + i);
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(short*)*(deque.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        short* poppedValue = (short*)deque.popFront(&deque);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(short*)*(deque.data + j));
        System.out.println("");
    }

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
        deque.pushBack(&deque, value + i);
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(short*)*(deque.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        short* poppedValue = (short*)deque.popBack(&deque);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(short*)*(deque.data + j));
        System.out.println("");
    }

    deque.clear(&deque);
    deque.delete(&deque);
    stack.clear(&stack);
    stack.delete(&stack);
    queue.clear(&queue);
    queue.delete(&queue);
    free(value);
    return 0;
}