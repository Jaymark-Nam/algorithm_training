

#include <stdio.h>

int main()
{
	char aa[100];
	char bb[100];

	printf("\n Enter the first string :");
	gets(aa);

	printf("\n Enter the second string :");
	gets(bb);

	char *a = aa;
	char *b = bb;


	//pointing to the end ot 1st string
	while (*a)	//till it doesnt point null string
	{
		a++;	// point to next letter of string
	}
	while (*b)	//till second string isnt empty
	{
		*a = *b;
		b++;
		a++;
	}

	*a = '\0';	//string should end with \0
	printf("\n The string is %s", aa);
}