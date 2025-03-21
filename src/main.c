#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"

import SYSTEM System;

int main(void){ 
    Stack stack = new_Stack(int);
    Queue queue = new_Queue(int);
    Deque deque = new_Deque(int);
    List list = new_List(int);
    int* value = (int*)malloc(sizeof(int) * 10);

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
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

    stack.clear(&stack);
    stack.delete(&stack);

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
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

    queue.clear(&queue);
    queue.delete(&queue);

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
        deque.pushFront(&deque, value + i);
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(int*)*(deque.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        int* poppedValue = (int*)deque.popFront(&deque);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(int*)*(deque.data + j));
        System.out.println("");
    }

    System.out.println("");

    for (int i = 0; i < 10; i++) {
        *(value + i) = rand() % 100;
        deque.pushBack(&deque, value + i);
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(int*)*(deque.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        int* poppedValue = (int*)deque.popBack(&deque);
        if (poppedValue) {
            System.out.println("Popped: %d", *poppedValue);
            free(poppedValue);
        }
        for (int j = 0; j < deque.size; j++) System.out.printf("%d ", *(int*)*(deque.data + j));
        System.out.println("");
    }

    deque.clear(&deque);
    deque.delete(&deque);

    System.out.println("");

    for(int i = 0; i < 10; i++){
        *(value + i) = rand() % 100;
        list.add(&list, value + i);
        for(int j = 0; j < list.size; j++) System.out.printf("%d ", *(int*)*(list.data + j));
        System.out.println("");
    }

    for (int i = 0; i < 10; i++) {
        int* removedValue = (int*)list.remove(&list, 0);
        if (removedValue) {
            System.out.println("Popped: %d", *removedValue);
            free(removedValue);
        }
        for (int j = 0; j < list.size; j++) System.out.printf("%d ", *(int*)*(list.data + j));
        System.out.println("");
    }

    list.clear(&list);
    list.delete(&list);

    free(value);
    return 0;
}