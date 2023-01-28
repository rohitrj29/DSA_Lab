#include <stdio.h>
int main(){
    FILE* fptr1;
    FILE* fptr2;
    fptr1 = fopen("sampletxt1.txt","r");
    fptr2 = fopen("sampletxt2.txt","w");
    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    char line[100];
    while(fgets(line,100,fptr1)){
        fprintf(fptr2,"%s\n",line);
    }
    fclose(fptr2);
    fclose(fptr1);
    fptr1 = fopen("sampletxt1.txt","w+");
    fclose(fptr1);
    return 0;
}