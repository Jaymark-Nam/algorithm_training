//black jack

#include <stdio.h>

int main()
{
	int n, m, i, j, k, a[101], t, answer;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i=0 ; i < n ; i++)
		for(j=0; j<n;j++)
			for (k = 0; k<n; k++)
				if (i != j && j != k && k != i)
				{
					t = a[i] + a[j] + a[k];
						if (t <= m && answer < t)
							answer = t;
				}
	printf("%d", answer);
	return 0;

}
