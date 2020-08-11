/*This program is to find the biggest number in array, and find out the order of it.
for example if there are numbers, 10 20 30 40 15, program needs to export 40, 4th number
I succeeded finding out the biggest number, but failed to figure out the order of it.
*/

#include <stdio.h>

int main() 
{
	int n, i;
	int num[100];
	int max = -1000000;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] > max)
			max = num[i];
	}
	printf("The biggest number is %d, %d th number", max, i);

}
