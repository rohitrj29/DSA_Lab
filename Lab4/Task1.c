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
void insertInOrder(Person v, Person A[], int last);
void insertInOrder(Person v, Person A[], int last)
{
    int j = last - 1;
    while (j >= 0 && v.height < A[j].height)
    {
        A[j + 1] = A[j];
        j--;
    }
    A[j + 1] = v;
}
void insertionSort(Person A[], int n);
void insertionSort(Person A[], int n)
{
    for (int j = 1; j < n; j++)
    {
        insertInOrder(A[j], A, j);
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
        fscanf(fp, "%d,%[^,],%d,%d,%d\n", &p.id, p.name, &p.age, &p.height, &p.weight);
        arr[i] = p;
    }
    print(arr, n);
    
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}