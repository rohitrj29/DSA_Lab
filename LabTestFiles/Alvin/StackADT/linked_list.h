#include "element.h"
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