#include "element.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};
Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL)
        s->top = -1;
    return s;
}
bool push(Stack *s, Element e)
{
    if (s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}
void printStack(Stack *s)
{
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i].int_value);
    }
    printf("\n");
}