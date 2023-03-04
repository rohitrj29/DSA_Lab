#include <stdio.h>
#include <stdlib.h>

void swap(int Ls[], int a, int b)
{
    int tmp = Ls[a];
    Ls[a] = Ls[b];
    Ls[b] = tmp;
}

int part(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt] <= pv; lt++)
            ;
        // Ls[j]<=pv for j in lo..lt-1
        for (; Ls[rt] > pv; rt--)
            ;
        // Ls[j]>pv for j in rt+1..hi
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1)s and (Ls[j]>pv for j inpivPos+1..hi)
    return pivPos;
}

// void qs(int Ls[], int lo, int hi)
// {
//     if (lo < hi)
//     {
//         int p = lo;
//         // printf("Pivot: %d\n", Ls[p]);
//         p = part(Ls, lo, hi, p); // Ls[p] is the pivot
//         /*
//         (Ls[j]<=Ls[p] for j in lo..pPos-1) and
//         (Ls[j]>Ls[p] for j in pPos+1..hi)
//         */
//         qs(Ls, lo, p - 1);
//         qs(Ls, p + 1, hi);
//     }
// }

void qsort_hybrid(int Ls[], int lo, int hi)
{
    if (hi - lo < 10)
    {
        //insertionsort(Ls, lo, hi);
        return;
    }
    else if (lo < hi)
    {
        //int p = pivot(Ls, lo, hi);
        int p=lo;
        p = part(Ls, lo, hi, p);
        qsort_hybrid(Ls, lo, p - 1);
        qsort_hybrid(Ls, p + 1, hi);
    }
}

void is(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    FILE *fp = fopen("int0.txt", "r");
    int cap = 100;
    int *arr = (int*)malloc(cap*sizeof(int));
    int i=0;

    while(!feof(fp))
    {
        if(i == cap)
        {
            cap *=2;
            arr = realloc(arr, cap*sizeof(int));
        }
        fscanf(fp,"%d",&arr[i]);
        //printf("%d",arr[i]);
        i++;
    }

    // for(int j=0; j<10; j++)
    // {
    //     printf("\n%d",arr[j]);
    // } 

    qsort_hybrid(arr, 0, i-1);
    is(arr,i);

    for(int j=0; j<1000; j++)
    {
        printf("%d\t",arr[j]);
    }   
    return 0;
}