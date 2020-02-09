 

#include <stdio.h>

#include <stdlib.h>       //srand

#include <time.h>     //time

#include <sys/timeb.h>

 

void word(char *string);

int checkCorrect(char *myword, char ch);

int checkAlreadyGuessed(char *alreadyGuessed, char ch);

int includeMinus(char *str);

int enteredCorrect(char *myword, char *currentCorrect, char ch);

 

int checkAlreadyGuessed(char *alreadyGuessed, char ch)

{

	/* return 1 if a user already guessed this character, otherwise return 0 */

	return 0;

}

 

int enteredCorrect(char *myword, char *currentCorrect, char ch)

{

 

	return 1;

}

 

int AllLower(char *str)

{

	for (; *str; str++)

		if (!islower(*str)) return 0;

	return 1;

}

 

int cleanWord(char str[])

{

	int i;

	if (strlen(str) < 6) return 0;

	for (i = 0; str[i]; ++i) if (!islower(str[i])) return 0;

}

 

 

int Strlen(char *str)				//문자열 길이

{

	int i;

	for (i = 0; str[i]; i++);

	return i;

}

 

 

int Strcpy(char *a, char *b)		//문자열 복사

{

	int i;

	for (i = 0; a[i] = b[i]; i++);

}

 

void word(char *string)

{

	FILE *fp;

	char str[100];

	int i, fi, nthWord;

	int exit = 0;

	// linux struct timeval tv ;

	fp = fopen("C:\\Users\\user\\Documents\\linux_words.txt", "r");

	if (fp == 0) {

		fprintf(stderr, "words.txt 없음.\n");

		strcpy(string, "");

		return 0;

	}

	srand(time(0));													 // linux srand(tv.tv_sec * tv.tv_usec) ;

	printf("%d %d\n", RAND_MAX, rand());

 

 

#define LASTWORD 479623

#define MIN_LENGTH 6

 

	nthWord = (int)((float)rand() / (float)RAND_MAX * ((float)LASTWORD) + 0.5);

 

	if (nthWord + 100 > LASTWORD)

		nthWord = nthWord - 100;

	printf("nth word = %d\n", nthWord);

 

	/* skip until nth word */

	for (i = 1; i < nthWord; i++)

	{

		fi = fscanf(fp, "%s", str);

		if (fi == EOF)

			break;

	}

 

	/* use only long enough words */

	for (;;)

	{

		if (strlen(str) >= MIN_LENGTH && AllLower(str))

		{

			printf("My selected word %s\n", str);

			strcpy(string, str);

			break;

		}

		fi = fscanf(fp, "%s", str);

		if (fi == EOF)

			break;

 

	}

	fclose(fp);

	return 0;

 

}

 

void main()

{

	int lotto[5][6];

	int num, i, j, k, hi;

	int exit = 0;

	int chance, fin = 0;

	char myword[100], ch, in[10], alreadyGuessed[20] = { 0 };

	char currentCorrect[100] = "*****************************************************";

 

	srand(time(NULL));

 

	for (i = 0; i < 5; ++i)

	{

		for (j = 0; j < 6; j++)

			lotto[i][j] = rand() % 45 + 1;

	}

 

	for (i = 0; i < 5; ++i)

	{

		for (j = 0; j < 6; j++)

		{

			printf("%d ", lotto[i][j]);

		}

		printf("\n");

	}

	if (lotto[0][0] > 0 && lotto[0][0] <= 9)

	{

		chance = 1;

		printf("You have %d life \n", chance);

	}

	else if (lotto[0][0] >= 10 && lotto[0][0] <= 19)

	{

		chance = 2;

		printf("You have %d lives \n", chance);

	}

	else if (lotto[0][0] >= 20 && lotto[0][0] <= 29)

	{

		chance = 3;

		printf("You have %d lives \n", chance);

	}

	else if (lotto[0][0] >= 30 && lotto[0][0] <= 39)

	{

		chance = 4;

		printf("You have %d lives \n", chance);

	}

 

	else {

		chance = 5;

		printf("You have %d lives \n", chance);

	}

	word(myword);

 

	printf("selected & retuned words >%s<\n", myword);

 

	currentCorrect[strlen(myword)] = 0;

 

	//printf("selected word : %s\n", myword) ;

 

	printf("You have only %d chances left\n guess a character\n", chance);

 

	//hi = strlen(myword);

 

	//printf("%s", currentCorrect);

	/*

	for ( ; chance > 0; --chance)

	{

	printf("You have only %d chances left\n guess a character\n", chance);

 

	printf(" 글자를 입력하시오 \n");

	scanf("%c", &ch);

	{

	if (ch == '\n')

	continue;

	else

	printf("you have entered %c\n", ch);

	}

	for (i = 0; i < strlen(myword); i++)

	if (currentCorrect[i] == '*' && myword[i] == ch)

	{

	currentCorrect[i] = ch;

	}

 

	printf("current guessed string is %s \n", currentCorrect);

 

 

 

 

	return 0;

	}

 

	*/

	while (chance > 0 && fin == 0)

	{

		scanf("%c", &ch);

		// fgets(in,10, stdin) ;

		//printf("INPUT->%s\n", in) ;

		//ch = in[0] ;

		if (ch == '\n')

			continue;

		else

			printf("you have entered %c\n", ch);

 

		chance = chance - 1;

		for(i=0; i<strlen(myword) ; i++)

		{

			if (currentCorrect[i] == '*' && myword[i] == ch)

			{

				currentCorrect[i] = ch;

				chance = chance + 1;

			}

			else if (currentCorrect[i] == ch && myword[i] == ch)

			{

				printf("dont write same words!!! \n");

				chance = chance + 1;

			}

		}

		printf("You have only %d chances left\n", chance);

		printf("Current guessed string is %s\nguess a character\n", currentCorrect);

 

		fflush(stdout);

 

		for (i = 0; currentCorrect[i]; i++)

		{

			if (currentCorrect[i] == '*')

			{

				exit = 0;

				break;

			}

			exit = 1;

		}

		if (exit)

			break;

 

	}

 

 

 

	if (chance>0)

	{

		printf("Great\n");

		return 0;

	}

 

	else

	{

			printf("Sorry, try more words\n");

			printf("correct word was %s\n", myword);

	}

	

	getchar();

 

	return 0;

 

}

 