
#include <stdio.h>

int main()
{
	int n, i, *ptr; int sum = 0;

	printf("Enter number of elements \n");
	scanf("%d", &n);

	//dynamc memory allocation using malloc
	ptr = (int*)malloc(n * sizeof(int));

	if (ptr == NULL)
	{
		printf("Memory not allocated");
		return 0;
	}

	printf("Enter elements of array \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", ptr + i);
		sum = sum + *(ptr + i);
	}

	printf("The elements of array are \n");
	for (i = 0; i < n; i++)
	{
		printf("\t %d ", ptr[i]);	//same as *(ptr + i)
	}

	free(ptr);

	return 0;
}