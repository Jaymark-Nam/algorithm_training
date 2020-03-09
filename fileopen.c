#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("file.txt", "w");
	fprintf(fp, "%s", "file open");
	
	fclose(fp);

	return(0);
}