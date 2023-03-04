#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void countingSort(char* A, char* B, int k, int n)
{
    int C[26];
    for(int i=0; i<26; i++)
        C[i] = 0;
    for(int j=0; j<n; j++)
    {
        int x = (int)A[j] - 65;
        printf("int: %d\t",x);
        C[x] = C[x]+1;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d\n",C[i]);
    }

    for (int i = 1; i < 26; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    

    for(int j= n-1; j>=0; j--)
    {
        int x = (int)A[j] - 65;
        B[C[x]-1]  = A[j];
        C[x]--;
    }
}

int main()
{
    char *str;
    str = (char*)malloc(10);
    scanf("%s",str);
    int n = strlen(str);
    //printf("length: %d",n);
    char *ans;
    ans = (char*)malloc(10);
    countingSort(str, ans, 26, n);
    printf("%s",ans);
    return 0;

}