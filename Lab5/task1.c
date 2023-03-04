#include <stdio.h>
#include <stdlib.h>

struct person
{
    int id;
    char name[20];
    int age;
    int height;
    int weight;
};
typedef struct person Person;
void print(Person *arr, int size);
void print(Person *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ID:%d , Name:%s , Age:%d , Height:%d , Weight: %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
    return;
}


void swap(Person Ls[], int i, int j)
{
    Person temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp;
}

int part(Person Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo].height;
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt].height <= pv; lt++)
            ;
        // Ls[j]<=pv for j in lo..lt-1
        for (; Ls[rt].height > pv; rt--)
            ;
        // Ls[j]>pv for j in rt+1..hi
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt].height < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in
    return pivPos;
}

int qselect(Person L[], int n, int k)
{
int pivot = 0;
int lo = 0;
int hi = n - 1;
int pInd = part(L, lo, hi, pivot);
if (k <= pInd)
return qselect(L, pInd, k);
else if (k > pInd + 1)
return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
else
return pInd;
}

void qs(Person Ls[], int lo, int hi)
{
    int k=(hi-lo+1)/2;
if (lo < hi)
{
    int p = lo;              // Ls[p] is the pivot
    p = part(Ls, lo, hi, p); // Ls[p] is the pivot
    qs(Ls, lo, p - 1);
    qs(Ls, p + 1, hi);
}
}

int main()
{
FILE *fp = fopen("task1.csv", "r");
int n;
fscanf(fp, "%d\n", &n);
Person arr[n];
for (int i = 0; i < n; i++)
{
    Person p;
    fscanf(fp, "%d,%[^,],%d,%d,%d", &p.id, p.name, &p.age, &p.height, &p.weight);
    arr[i] = p;
}
print(arr, n);

qs(arr, 0,n-1);
print(arr, n);
return 0;
}