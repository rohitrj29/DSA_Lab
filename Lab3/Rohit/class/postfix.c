#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
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




int main()
{
FILE *fp = fopen("postfix.txt","r");
if(fp == NULL)
{
printf("Unable to open file\n");
exit(1);
}
Stack st = createStack();
char s[50];
while(fscanf(fp, "%s", s) == 1)
{
printf("%s",s);
    int n = strlen(s);
printf("%d\n",n);
for(int i=0; i<n; i++)
    {
    // printf("%c", s[i]);
        //if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        if(isdigit(s[i]))
        {
            st = push(s[i] - 48,st);
          //  printf("%d",atoi(s+i));
        }
        else
        {
            int n1 = top(st);
            st = pop(st);
            int n2 = top(st);
            st = pop(st);
            if(s[i] == '+')
            {
                st = push(n2+n1,st);
                continue;
            }

            else if(s[i] == '-')
            {
                st = push(n2-n1,st);
                continue;
            }

            else if(s[i] == '*')
            {
                st = push(n2*n1,st);
                continue;
            }

            else
            {
                st = push(n2/n1,st);
                continue;
            }

        }

       
    }
    printf("%d\n", top(st));
    pop(st);
    }
    fclose(fp);
}