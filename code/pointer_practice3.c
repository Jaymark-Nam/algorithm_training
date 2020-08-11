#include <stdio.h>

const int MAX = 3; //global declaration

int main()
{
	int var[] = { 100,200,300 };
	int i; int *p;

	p = var; //store address of the first element of array in pointer variable

	for (i = 0; i < MAX; i++)
	{
		printf("Address of Var[%d]=%x \n",i, p);
		printf("Value of Var[%d]=%d \n", i, *p);

		p++;
	}
	return 0;

	


}