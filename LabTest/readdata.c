#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Locality *ReadFileintoLists(char *filename)
{
	char buffer[100];
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("File not found");
		return NULL;
	}
	Locality *head = NULL;
	Locality *prevloc = NULL;
	while (fgets(buffer, 100, fp) != NULL)
	{	
		char *data=strtok(buffer,",");
		int n=atoi(data);
		data=strtok(NULL,",");
		Locality *loc = malloc(sizeof(Locality));
		if (prevloc == NULL)
		{
			prevloc = loc;
			head = loc;
		}
		else
		{
			prevloc->next = loc;
			loc->next = NULL;
			prevloc = loc;
		}
		loc->count = n;
		Member *prev = NULL;
		for(int i = 0; i < n; i++)
		{
			Member *n = malloc(sizeof(Member));

			int val=atoi(data);
			n->id = val;
			data=strtok(NULL,",");
			if (i == 0)
			{
				loc->first = n;
				n->next = NULL;
				prev = n;
			}
			else
			{
				prev->next = n;
				n->next = NULL;
				prev = n;
			}
		}
		/* code */
	}

	return head;
}

void PrintLists(Locality *start)
{
	Locality* loc;
	Member* mem;
	loc = start;
	while(loc!=NULL){
		mem=loc->first;
		while(mem!=NULL){
			printf("%d -> ",mem->id);
			mem=mem->next;
		}
		loc=loc->next;
		printf("\n");
	}
}
