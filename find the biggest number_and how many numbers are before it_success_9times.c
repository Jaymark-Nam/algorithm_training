#include <stdio.h>

int main()
{
	int num[9], max = -100;
	int i;
	int important_i;
	
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);		
		if (num[i] > max)
		{
			max = num[i];
			important_i = i;		//remember this 'i' using a variable!!
		}
	}
	printf("%d %d", max, important_i + 1);
}
