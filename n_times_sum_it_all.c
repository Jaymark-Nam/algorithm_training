/* n times, sum it all */

#include <stdio.h>

int main()
{
	int i, d[10], n, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &d[i]);
	for (i = 0; i < n; i++)
		sum = sum + d[i];
		printf("%d \n", sum);
}
