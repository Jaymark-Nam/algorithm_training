include <stdio.h>

int main() {

	int n, i;
	int min = 1000001;
	int max = -1000001;
	int tmp = 0;

	scanf("%d", &n);  //enter how many times you want to repeat!

	for (i = 0; i < n; i++)  //repeat n times
	{
		scanf("%d", &tmp);		//enter numbers you want inside the array

		if (tmp < min)			//if tmp < min, tmp becomes min
			min = tmp;
		if (tmp > max)			//same logic
			max = tmp;
	}
	printf("%d %d", min, max);		//print min and max;
}