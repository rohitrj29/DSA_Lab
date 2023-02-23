#include "stack.h"
#include <stdio.h>
#include "element.h"
#include <stdlib.h>

struct node
{
    Element data;
    struct node *next;
};
typedef struct node node;
typedef node *NODE;

struct linked_list
{
    int count;
    NODE head;
    // NODE tail; // Not required for stack. Required for Queue
};
typedef struct linked_list linked_list;
typedef linked_list *LIST;
struct Stack
{
    LIST list;
};
typedef struct Stack Stack;
// Create a new, empty list and return a pointer to it
LIST createNewList()
{
    LIST newList = (LIST)malloc(sizeof(linked_list));
    if (newList != NULL)
    {
        newList->count = 0;
        newList->head = NULL;
    }
    return newList;
}

// Create a new node with the given data and return a pointer to it
NODE createNewNode(Element data)
{
    NODE newNode = (NODE)malloc(sizeof(node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Insert a node at the beginning of the list
void insertNodeIntoList(NODE node, LIST list)
{
    if (list != NULL && node != NULL)
    {
        node->next = list->head;
        list->head = node;
        list->count++;
    }
}

// Remove the first node from the list
void removeFirstNode(LIST list)
{
    if (list != NULL && list->head != NULL)
    {
        NODE firstNode = list->head;
        list->head = firstNode->next;
        free(firstNode);
        list->count--;
    }
}

// Insert a node at the end of the list
void insertNodeAtEnd(NODE node, LIST list)
{
    if (list != NULL && node != NULL)
    {
        if (list->head == NULL)
        {
            list->head = node;
        }
        else
        {
            NODE lastNode = list->head;
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
        list->count++;
    }
}
Stack *newStack()
{
    LIST list = (LIST)malloc(sizeof(linked_list));
    if (list == NULL)
    {
        return NULL;
    }
    list->count = 0;
    list->head = NULL;
    return (Stack *)list;
}

bool push(Stack *stack, Element element)
{
    NODE node = createNewNode(element);
    if (node == NULL)
    {
        return false;
    }
    insertNodeIntoList(node, stack->list);
    return true;
}

Element *top(Stack *stack)
{
    if (isEmpty(stack))
    {
        return NULL;
    }
    return &(stack->list->head->data);
}

Element *pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return NULL;
    }
    NODE nodeToRemove = stack->list->head;
    Element *poppedElement = &(nodeToRemove->data);
    removeFirstNode((LIST)stack);
    free(nodeToRemove);
    return poppedElement;
}

bool isEmpty(Stack *stack)
{
    return ((LIST)stack)->count == 0;
}

void freeStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

void printStack(Stack *stack)
{
    // NODE currentNode = stack->list->head;
    // printf("[ ");
    // while (currentNode != NULL)
    // {
    //     printf("%d ", currentNode->data.int_value);
    //     currentNode = currentNode->next;
    // }
    // printf("]\n");
    NODE currentNode = stack->list->head;
    int value = 5;
    printf("last value is: %d\n", value);
    return;
}