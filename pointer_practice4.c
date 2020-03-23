#include <stdio.h>

int main()
{
	int var[] = { 100,200,300 };

	int MAX = sizeof(var);
	int i; int *p;

	p = &var[2];

	for (i = 3; i > 0; i--)
	{
		printf("Address of var[%d] = %x", i, p);
		printf("Value of var[%d]=%d \n",i,*p);
		p--;
	}
	return 0;
}