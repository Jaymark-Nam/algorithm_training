/*
 Suppose there is n given, write the code of "sum of n"
a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열 (0 ≤ a[i] ≤ 1,000,000, 1 ≤ n ≤ 3,000,000)
n: 합을 구해야 하는 정수의 개수
리턴값: a에 포함되어 있는 정수 n개의 합
*/

#include <stdio.h>

long long sum(int *a, int n)			//it is better to write a function instead of putting all the codes in side main code!
{
	int i, sum=0;

	for (i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}

	printf("%d", sum);
}

void main()
{
	int i;
	int a[1000] = { 0 } , n;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sum(&a, n);			//at first, I used *a. but it didnt work! so I changed into & and it worked properly! :)
}