

#include <stdio.h>

int main()
{
	printf("pointer practice. damn I skipped 2 days of programming...\n");
	int var = 24;	//actual variable declare
	int *p;

	p = &var; // storing address of int variable in pointer p

	printf("Address of var variable is %x\n", &var);
	
	//address stored in pointer variable
	printf("Address stored in pointer variable p %x\n", p);

	//access value using pointer variable
	printf("Value of var variable or the value stored at address p is %d\n", *p);

	return 0;


}