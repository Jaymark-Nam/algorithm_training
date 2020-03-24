

#include <stdio.h>

int main()
{
	int *p; int *pp;
	p = (int*)3;
	pp = (int*)2;

	if (pp > p)
		printf("pp is bigger than p");
	else
		printf("pp isn't bigger than p");
}



#include <stdio.h>

int main()
{
	int *p; float *pp;
	p = (int*)1000;
	pp = (int*)2000;

	if (pp > p)
		printf("pp is bigger than p");
	else
		printf("pp isn't bigger than p");
}






#include <stdio.h>

int main()
{
	int var;
	int *p;
	int **pp;

	var = 50;

	p = &var;
	pp = &p;


	printf("\n Value of var %d", var);

	printf("\n Value available at *p = %d", *p);
	printf("\n Value available at **pp = %d", **pp);

}






