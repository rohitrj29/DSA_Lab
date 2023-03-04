#include"node.h"
#include<stdio.h>
#include<stdlib.h>
extern int *Arr[N];
extern int Num_Elements[N];
void ConvertListstoArray(Locality *start)
{
    int i=0;
    while(start != NULL)
    {
        Num_Elements[i] = start->count;
        Arr[i] = (int*)malloc(start->count*sizeof(int));
        // Member *temp = start->first;
        int j=0;
        while(start->first != NULL)
        {
            Arr[i][j] = start->first->id;
            j++;
            start->first = start->first->next;
            //start->first = start->first->next;
        }
        start = start->next;
        i++;
    }
}
