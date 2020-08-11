/*
This question is to find the biggest and smallest number in an array.
I used pack[5] for an array, and used variables(tmp{which is the abbreviation of temporary}, big, small) to track 2 numbers which are the biggest + smallest.
I used 'for' and 'if' function to find the special numbers.
unfortunately it occured a compile error.
I'll try another way to fix it out.


#include <stdio.h>

int main() 
{
	int pack[5], tmp, big,small;
	int i;
	pack[5] = (20, 10, 35, 30, 7);

	for (i = 0; i < sizeof(pack); i++)
	{
		if (pack[i + 1] > pack[i])
			return tmp= pack[i + 1];
		else return tmp = pack[i];
		big = tmp;
	}
	for (i = 0; i < sizeof(pack); i++)
	{
		if (pack[i + 1] < pack[i])
			return tmp = pack[i + 1];
		else return tmp = pack[i];
		small = tmp;
	}
	printf("%d %d", big, small);
}

