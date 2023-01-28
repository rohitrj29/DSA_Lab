#include <stdio.h>
int main(){
    FILE* fptr;
    FILE* fptr2;
    fptr  = fopen(__FILE__,  "r");
    fptr2 = fopen("Task5Copy.txt","w");
    if (fptr == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    char line[100];
    while(fgets(line , 100 , fptr)){
        fprintf(fptr2,"%s\n",line);
        printf("%s\n",line);
    }
    fclose(fptr);
    fclose(fptr2);

    return 0;
}