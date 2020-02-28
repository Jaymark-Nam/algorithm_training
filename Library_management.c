#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>			//contains strcmp(), strcpy(), strlen()...
#include <ctype.h>			//contains toupper(), tolower()..
#include <dos.h>			//contains _dos_getdate
#include <time.h>

#define RETURNTIME 15
/* */
void mainmenu();
void addbooks();
int getdata();
int checkid(int);


char catagories[][15] = { "Computer","Electronics","Electrical","Civil","Mechnnical","Architecture" };

FILE *fp, *ft, *fs;
COORD coord = { 0,0 };
int s;
char findbook;
char password[10] = { "password" };


void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;		//X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
	int mm, dd, yy;
};

struct books
{
	int id;
	char stname[20];
	char name[20];
	char Author[20];
	int quantity;
	float Price;
	int count;
	int rackno;
	char *cat;
	struct meroDate issued;
	struct meroDate duedate;
};
struct books a;


void mainmenu()
{
	char choose;
	system("cls");
	int i;
	gotoxy(20, 3);
	printf("**Main Menu**");
	gotoxy(20, 5);
	printf("1. Add Books   ");
	gotoxy(20, 7);
	printf("2. Delete books");
	gotoxy(20, 9);
	printf("3. Search Books");
	gotoxy(20, 11);
	printf("4. Issue Books");
	gotoxy(20, 13);
	printf("5. View Book list");
	gotoxy(20, 15);
	printf("6. Edit Book's Record");
	gotoxy(20, 17);
	printf("7. Close Application");
	gotoxy(20, 19);

	printf("Enter your choice:");

	choose = getch();
	switch (choose)
	{
	case '1':
		addbooks();
	case '2':

	case '3':

	case '4':

	case '5':

	case '6':

	case '7':
	{
		int i;
		system("cls");

		gotoxy(50, 15);
		for (i = 0; i < 20; i++)
		{
			Sleep(50);
			printf("*");
		}

		gotoxy(50, 17);
		printf("Library Management System");

		gotoxy(50, 19);
		for (i = 0; i < 20; i++)
		{
			Sleep(50);
			printf("*");
		}

		gotoxy(50, 30);
		printf("Exiting in 3 second...........>");
		Sleep(3000);
		exit(0);
	}
	/*
	default:
	{
		gotoxy(10, 23);
		printf("Wrong entry!!");
		if (getch())
			mainmenu();
	}*/
	}

}


void addbooks()
{
	system("cls");
	int i;
	gotoxy(20, 5);
	printf("Select categories");

	gotoxy(20, 7);
	printf("1. Computer");

	gotoxy(20, 9);
	printf("2. Electronics");

	gotoxy(20, 11);
	printf("3. Electrical");

	gotoxy(20, 13);
	printf("4. Civil");

	gotoxy(20, 15);
	printf("5. Mechanical");

	gotoxy(20, 17);
	printf("6. Architecture");

	gotoxy(20, 19);
	printf("7. Back to Main menu");

	gotoxy(20, 22);
	printf("Enter your choice");
	scanf("%d", &s);
	if (s == 7)
		mainmenu();

	system("cls");
	fp = fopen("Bibek.dat", "ab+");
	if (getdata() == 1)
	{
		a.cat = catagories[s - 1];
		fseek(fp, 0, SEEK_END);
		fwrite(&a, sizeof(a), 1,  fp);
		fclose(fp);
		gotoxy(21, 15);
		printf("Save anymore? y.n");
		if (getch() == 'n')
			mainmenu();
		else
			system("cls");
		addbooks();
	}
}

void Password()
{
	system("cls");
	char d[25] = "Password Protect";
	char ch, pass[10];
	int i = 0, j;
	gotoxy(10, 4);
	for (j = 0; j < 19; j++)
	{
		Sleep(50);
		printf("*");
	}
	gotoxy(11, 5);
	for (j = 0; j < 20; j++)
	{
		Sleep(50);					// what is SLEEP?
		printf("%c", d[j]);			//d[25]="Password Protect 을 천천히
	}
	gotoxy(10, 6);
	for (j = 0; j < 19; j++)
	{
		Sleep(50);
		printf("*");
	}
	gotoxy(40, 10);
	printf("Enter Password:");
	/*
	while(ch!='\n')
	{
	ch = getch();				//When you run this program, it exits only when you press a character. Try pressing num lock, shift key, etc. (program will not exit if you press these keys) as these are not characters.
	putch('*');					//shows * in password enter screen
	pass[i] = ch;
	i++;
	}
	*/
	scanf("%s", pass);


	if (strcmp(pass, password) == 0)
	{
		gotoxy(50, 15);
		printf("***Password match!!***");
		gotoxy(50, 17);
		printf("press any key to continue");
		getch();
		mainmenu();
	}
	else {
		gotoxy(50, 13);
		printf("WRONG!");
		getch();		//I tried getche(), getchar()
		Password();		//To password menu again!
	}
}



int getdata()		//whats the data I wanna add?
{
	int t;
	gotoxy(20, 3);
	printf("Enter the information below");

	gotoxy(21, 5);
	printf("Category");
	gotoxy(31, 5);
	printf("%s", catagories[s - 1]);


	gotoxy(21, 6);
	printf("Book ID:\t");
	gotoxy(30, 6);
	scanf("%d", &t);

	
	if (checkid(t) == 0)
	{
		gotoxy(21, 13);
		printf("The book id already exists");
		getch(); mainmenu(); return 0;
	}
	a.id = t;


	gotoxy(21, 7);
	printf("Book Name:"); gotoxy(33, 7);
	scanf("%s", a.name);

	gotoxy(21, 8);
	printf("Author:"); gotoxy(30, 8);
	scanf("%s", a.Author);

	gotoxy(21, 9);
	printf("Quantity:"); gotoxy(31, 9);
	scanf("%d", &a.quantity);

	gotoxy(21, 10);
	printf("Price:"); gotoxy(28, 10);
	scanf("%f", &a.Price);

	gotoxy(21, 11);
	printf("Rack No:"); gotoxy(30, 11);
	scanf("%d", &a.rackno);
	return 1;
}

int checkid(int t)
{
	rewind(fp);
	while (fread(&a, sizeof(a), 1, fp) == 1)
		if (a.id == t)
			return 0; // if book exists
	return 1; //return 1 if it doesnt exist
}




int main()
{
	Password();
	getch();
	return 0;
};

