#include <stdio.h>

void function()
{
	int a, b, c;
	int count[10] = { 0 };
	int m;
	char tmp[100];
	int i;
	
	scanf("%d %d %d", &a, &b, &c);
	m = a*b*c;
	sprintf(tmp, "%d", m);		//sprintf stands for "String print".  int m--> char tmp
	printf("%s \n", tmp);		//lets see "string" tmp
	for (i = 0; i < strlen(tmp); i++)	//until "tmp" length
		count[tmp[i] - '0']++;		// -'0' : turns to int   ___ +'0': to string
	for (i = 0; i < 10; i++)		// 0-9
		printf("%d \n", count[i]);		//count[i]??
}
int main()
{
	function();
}

