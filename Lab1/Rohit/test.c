#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addtobeg(char** arr, int n, char* s)
{
for(int i = n-1; i>=0; i--)
{
arr[i+1] = arr[i];
}
arr[0] = calloc(50, sizeof(char));
arr[0] = s;
}

void delele(char** arr, int n, int ind)
{

for(int i = ind; i<n-1; i++)
{
arr[i] = arr[i+1];
}
free(arr[n-1]);
}

int main()
{
 int n;
 printf("Enter the initial length of the array.");
scanf("%d",&n);
printf("%d\n", n);
char** arr = calloc(n, sizeof(char*));
printf("Enter the strings\n");
for(int i=0; i<n; i++)
{
arr[i] = calloc(50, sizeof(char));
scanf("%s", arr[i]);
}
while(1)
{
printf("Enter 1 to add a string to the end of the array\n");
printf("Enter 2 to add a string to the beginning of the array\n");
printf("Enter 3 to delete the element at index ‘x’ (taken as input) of the array\n");
printf("Enter 4 to display the length of the array\n");
printf("Enter 5 to display all the elements of the array in sequence order\n");
printf("Enter anything else to exit\n");

int x;
scanf("%d", &x);
switch(x)
{

case 1:
arr = realloc(arr, (n+1)*sizeof(char*));
if (arr == NULL)
{
printf("Unable to allocate memory\n");
return -1;
}
printf("Enter the string");
arr[n] = calloc(50, sizeof(char));
scanf("%s", arr[n]);
n++;
break;

case 2:
arr = realloc(arr, (n+1)*sizeof(char*));
if (arr == NULL)
{
printf("Unable to allocate memory\n");
return -1;
}
n++;
printf("Enter the string");
char s[50];
scanf("%s", s);
addtobeg(arr, n, s);
break;

case 3:

printf("Enter the index");
int ind;
scanf("%d", &ind);
delele(arr,n,ind);
/*arr = realloc(arr, (n-1)*sizeof(char*));
if (arr == NULL)
{
printf("Unable to allocate memory\n");
return -1;
}*/
n--;
break;

case 4:
printf("The length of the array is: %d\n", n);
break;

case 5:
printf("The array elements are:\n");
for(int i=0; i<n; i++)
{
printf("%s\n", arr[i]);
}
break;

default:
return -1;
}
}
}