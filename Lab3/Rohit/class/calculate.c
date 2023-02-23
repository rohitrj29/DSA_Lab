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


int computeSpans(char exp[], int n)
{
    Stack s1;
   for (int i = 0; i < n; i++)
        {
            
            if(exp[i] == '*'|| exp[i] == '/'||exp[i] == '-'||exp[i] == '+')
            {
                int a = top(s1);
                s1=pop(s1);
                int b = top(s1);
                s1=pop(s1);
                if (exp[i] == '*')
                {
                    a = a * b;
                }
                else if (exp[i] == '/')
                {
                    a = b / a;
                }
                else if (exp[i] == '+')
                {
                    a = b + a;
                }
                else if (exp[i] == '-')
                {
                    a = b - a;
                }
                s1=push(a, s1);
            }
            else 
               s1= push(exp[i]-48,s1);
            
        }
        return(top(s1));
}

int main()
{
    char str[] = "1346*--42/+";
   int sum=computeSpans(str,strlen(str));
    printf("%d"+sum);
    
    printf("\n");
    return 0;
}