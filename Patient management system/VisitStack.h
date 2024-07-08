#ifndef STACK_H
#define STACK_H

#include "Visit.h"  // Include the Visit structure

#define INITIAL_CAPACITY 10

typedef struct {
    Visit** items;  // Array of Visit pointers
    int top;
    int capacity;
} Stack;

Stack* createStack();
int isEmpty(Stack* stack);
void push(Stack* stack, Visit* item);
Visit* pop(Stack* stack);
Visit* peek(Stack* stack);
void freeStack(Stack* stack);

#endif // STACK_H
