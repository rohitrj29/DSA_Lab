#include <stdio.h>
int main()
{
int num;
FILE *fptr;
fptr = fopen("program.txt", "w");
if(fptr == NULL)
{
printf("Error opening file!");
exit(1);
}
printf("Enter num: ");
scanf("%d", &num);
fprintf(fptr, "%d", num);
fclose(fptr);
return 0;
}