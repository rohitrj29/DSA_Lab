#include <stdio.h>
#include "node.h"

extern int *Arr[N];
extern int Num_Elements[N];

void Merge_GM(int *L1, int *L2, int *L3)
{
    int i, j, k;
    // Traverse both arrays
    i = 0;
    j = 0;
    k = 0;
    int e1 = sizeof(L1) / sizeof(int) - 1;
    int e2 = sizeof(L2) / sizeof(int) - 1;
    while (i <= e1 && j <= e2)
    {
        // Check if current element of first array is smaller
        // than current element of second array
        // If yes, store first array element and increment first
        // array index. Otherwise do same with second array
        if (IsLower_GM(L1[i], L2[j]))
            L3[k++] = L1[i++];
        else
            L3[k++] = L2[j++];
    }
    // Store remaining elements of first array
    while (i <= e1)
        L3[k++] = L1[i++];
    // Store remaining elements of second array
    while (j <= e2)
        L3[k++] = L2[j++];
}

int *Merge_Arr()
{

    for (int i = 0; i < N; i++)
    {
        Merge_GM(Arr[i], Arr[i + 1], Arr[i + 2]);
    }
}
