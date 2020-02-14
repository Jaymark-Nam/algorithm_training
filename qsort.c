#include <stdio.h>
#include <stdlib.h>

int values[] = { 2,35,62,15,11,26 };

int cmpfunc(const void *a, const void *b)
{
	return(*(int*)a - *(int*)b);
}

int main()
{
	int n;
	printf("Before sorting, the list is : \n");
	for (n = 0; n < 6; n++)
	{
		printf("%d  ", values[n]);
	}
	qsort(values, 6, sizeof(int), cmpfunc);
	
	printf("After sorting, the list is : \n");
	for (n = 0; n < 6; n++)
	{
		printf("%d  ", values[n]);
	}
	return 0;
}
