#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void counting_sort(char *A, char *B, int k, int n)
{
    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }
    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++)
    {
        C[(int)A[j]-65]++;
    }
    // Place the elements of A in B in the correct position
    // by computing the running sum
    for (int i = 1; i < k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

}
int main(){
    int n;
    char *A = (char *)malloc(10);
    char *B = (char *)malloc(10);
    scanf("%s", A);
    n=strlen(A);
    int k = 26;
    counting_sort(A, B, k, n);
        printf("%s ", B);
    return 0;
}