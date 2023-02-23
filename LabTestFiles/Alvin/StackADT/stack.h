#ifdef __cplusplus
extern "C"
{
#endif

#ifndef STACK_H
#define STACK_H

#include "element.h"
#include <stdbool.h>

    typedef struct Stack Stack;

    Stack *newStack();
    bool push(Stack *stack, Element element);
    Element *top(Stack *stack);
    Element *pop(Stack *stack);
    bool isEmpty(Stack *stack);
    void freeStack(Stack *stack);
    void printStack(Stack *stack);

#endif

#ifdef __cplusplus
}
#endif