
#include <stdio.h>

#include<string.h>
int main()
{
	char buff[1024];

	memset(buff, '\0', sizeof(buff));
	
	//stdout means u r printing output on the main output device for the session..
	
	fprintf(stdout, "going to set full buffering on");
	setvbuf(stdout, buff, _IOFBF, 1024);
	fprintf(stdout, "this is my programming");
	fprintf(stdout, "this output will go into buff");
	fflush(stdout);
	//A buffer flush is the transfer of computer data from a temporary storage area to the computer's permanent memory. For instance if we make any changes in a file, the changes we see on one computer screen are stored temporarily in a buffer. ... The reason is flush function flushed the output to the file/terminal instantly.


	fprintf(stdout, "and this will appear when program");
	fprintf(stdout, "will com after sleeping 5 secs");

	sleep(5);
	return(0);
}





/* int ferror(FILE*stream)		tests the error indicator for the given stream
int main()
{
	FILE *fp;
	char c;

	fp = fopen("file.txt", "w");

	c = fgetc(fp);
	if (ferror(fp))
	{
		printf("Error reading from file");
	}
	clearerr(fp);

	if (ferror(fp))
	{
		printf("error reading from file");
	}
	fclose(fp);

	return(0);
}



  int feof(FILE *stream)    Tests the end-of-file indicator for the given stream.


int main()
{
	FILE *fp;
	int c;

	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		perror("Error in opening file");
		return(-1);
	}
	while (1)
	{
		c = fget(fp);
		if (feof(fp))
		{
			break;
		}
		printf("%c", c);
	}
	fclose(fp));
	return(0);
}




void clearerr(FILE*stream)     clears the end of file and error indicators for the given stream
int main()
{
	FILE *fp;
	char c;

	fp = fopen("C:\\linux_words.txt", "w");

	c = fgetc(fp);
	if (ferror(fp))
	{
		printf("Error in reading file \n");
	}
	clearerr(fp);

	if (ferror(fp))
	{
		printf("Error in reading from file \n");
	}

	fclose(fp);

	return(0);
}
*/