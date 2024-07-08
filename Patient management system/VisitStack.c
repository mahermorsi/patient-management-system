#include "VisitStack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    stack->items = (Visit**)malloc(INITIAL_CAPACITY * sizeof(Visit*));
    if (!stack->items) {
        fprintf(stderr, "Memory allocation failed\n");
        free(stack);
        return NULL;
    }

    stack->top = -1;  // Initialize top to -1 (empty stack)
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, Visit* item) {
    if (stack->top == stack->capacity - 1) {
        // Stack is full, resize the array
        int newCapacity = stack->capacity * 2;
        Visit** resizedItems = (Visit**)realloc(stack->items, newCapacity * sizeof(Visit*));
        if (!resizedItems) {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }
        stack->items = resizedItems;
        stack->capacity = newCapacity;
    }

    stack->items[++stack->top] = item;
}

Visit* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return NULL;  // Return NULL indicating underflow
    }
    return stack->items[stack->top--];
}

Visit* peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;  // Return NULL indicating empty stack
    }
    return stack->items[stack->top];
}

void freeStack(Stack* stack) {
    if (stack) {
        if (stack->items) {
            free(stack->items);
        }
        free(stack);
    }
}
