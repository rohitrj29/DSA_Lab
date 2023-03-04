#include "node.h"
#include <stdio.h>

extern int *Arr[N];
extern int Num_Elements[N];

void InsertionSort_GM(int arr[], int n)
{
    for (int j = 1; j < n; j++)
    {
        insertInOrder(arr[j], arr, j);
    }
}
void insertInOrder(int v, int A[], int last)
{
    int j = last - 1;
    while (j >= 0 && IsLower_GM(v,A[j]))
    {
        A[j + 1] = A[j];
        j--;
    }
    A[j + 1] = v;
}

void InsertionSort_Arr()
{
    for (int j = 0; j < N; j++)
    {
        InsertionSort_GM(Arr[j], Num_Elements[j]);
    }
}
