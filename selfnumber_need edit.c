/* self number _ this code isn't perfect. I just chose numbers which can be made by formula (10*a+b) +a+b
which is the opposite of self number */


#include <stdio.h>

void main()
{
	int a, b, d[1000] = { 0 };
	int i=0;
	int tmp;

	for (a = 0; a < 10; a++)
		for (b = 0; b < 10; b++)
			{
				i++;
				d[i] = ((10 * a + b) + a + b);
			}
	
	for (i = 0; d[i] < 100; i++)
	{
		if (d[i] > d[i + 1])
		{
			tmp = d[i];
			d[i] = d[i + 1];
			d[i + 1] = tmp;

		}
		printf("%d \n", d[i]);

	}
}
