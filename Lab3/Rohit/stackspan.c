#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct stacknode *StackNode;
struct stacknode
{
    int e;
    StackNode next;
};

typedef struct
{
    StackNode top;
    int size;
} Stack;

Stack createStack()
{
    Stack s;
    s.top = NULL;
    s.size = 0;
    return s;
}

bool isEmpty(Stack s)
{
    return (s.top == NULL) ? true : false;
}

Stack push(int e, Stack s)
{ // e=5
    Stack s1;
    s1.top = (StackNode)malloc(sizeof(struct stacknode));
    s1.top->e = e; // copy element
    s1.top->next = s.top;
    s1.size = s.size + 1;
    return s1;
}

Stack pop(Stack s)
{
    Stack s1;
    StackNode temp;
    temp = s.top;
    s1.top = s.top->next;
    s1.size = s.size - 1;
    free(temp);
    return s1;
}

int top(Stack s)
{
    return s.top->e;
}


void computeSpans(int *inputs, int *spans, int n)
{
    Stack s1 = createStack();
    //int n = sizeof(inputs)/sizeof(inputs[0]);
    spans[0] = 1;
    push(inputs[0],s1);
    for(int i=1; i<n; i++)
    {
        if(inputs[i] < inputs[i-1])
        {
            s1 = push(1,s1);
            spans[i] = 1;
        }
        else
         {
            int x = 1+ top(s1);
            s1 = pop(s1);
            s1 = push(x,s1);
            spans[i] = x;
         }  
    }
}

int main()
{
    int inputs[] = {6, 3, 4, 5, 2};
    int spans[5];
   
    computeSpans(inputs, spans, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", spans[i]);
    }
    printf("\n");
    int inputs2[] = {100, 80, 60, 70, 60, 75, 85};
    int spans2[7];
    computeSpans(inputs2, spans2, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", spans2[i]);
    }
    printf("\n");
    return 0;
}