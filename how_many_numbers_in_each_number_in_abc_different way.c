#include <stdio.h>

int main()
{
	int a, b, c;
	int total;
	int i;
	int m;
	int num[10] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	total = a*b*c;
	printf("%d \n", total);
	for (i = 0; total>0; i++)
	{
		m = total % 10;
		num[m]++;
		total = total / 10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d \n", num[i]);
	}
}

