#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>			//contains strcmp(), strcpy(), strlen()...
#include <ctype.h>			//contains toupper(), tolower()..
#include <dos.h>			//contains _dos_getdate
#include <time.h>
//-
#define RETURNTIME 15
/* */
void mainmenu();
void addbooks();
void deletebooks();
void searchbooks();
void issuebooks();
void viewbooks();
void editbooks();
int getdata();
int checkid(int);
void returnfunc();
void issuerecord();


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
		deletebooks();
	case '3':
		searchbooks();
	case '4':
		issuebooks();
	case '5':
		viewbooks();
	case '6':
		editbooks();
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
	fp = fopen("Bibek.dat", "ab+");	/*add file in "BIBEK.DAT".....   ab+ : Open a binary file in append mode for reading or updating at the end of the file. fopen() creates the file if it does not exist.   */
	if (getdata() == 1)
	{
		a.cat = catagories[s - 1];
		fseek(fp, 0, SEEK_END);
		fwrite(&a, sizeof(a), 1, fp);
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

void deletebooks()
{
	system("cls");
	int d;
	char another = 'y';
	while (another == 'y')	//infinite loop
	{
		system("cls");
		gotoxy(10, 5);
		printf("Enter book ID to delete");
		scanf("%d", &d);
		fp = fopen("Bibek.dat", "rb+");  //Open fp,  BIBEK.DAT for both reading and writing in binary mode.
		rewind(fp);
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{
				gotoxy(10, 7);
				printf("The book record is useful");

				gotoxy(10, 8);
				printf("Book name is %s", a.name);

				gotoxy(10, 9);
				printf("Rack No. is %d", a.rackno);
				findbook = 't';
			}
		}
		if (findbook != 't')
		{
			gotoxy(10, 10);
			printf("No record is found!");
			if (getch())
				mainmenu();
		}
		if (findbook == 't')
		{
			gotoxy(10, 9);
			printf("Do you want to delete? y.n");
			if (getch() == 'y')
			{
				ft = fopen("test.dat", "wb+");	//ft === temp file for delete  ...  wb indicates that the file is opened for writing in binary mode.
				rewind(fp);
				while (fread(&a, sizeof(a), 1, fp) == 1)		//while you're reading "fp"
				{
					if (a.id != d)		//files that you didnt choose
					{
						fseek(ft, 0, SEEK_CUR);	// ft!!  fseek() is used to move file pointer associated with a given file to a specific position
						fwrite(&a, sizeof(a), 1, ft);	//write all in ft (temp fil)
					}
				}
				fclose(ft);
				fclose(fp);
				remove("Bibek.dat");
				rename("test.dat", "Bibek.dat");	//copy all item from temp fil to fp except that
				fp = fopen("Bibek.dat", "rb+");
				if (findbook == 't')
				{
					gotoxy(10, 10);
					printf("The record is successfully deleted");
					gotoxy(10, 11);
					printf("Delete another record? y.n");
				}
			}
			else
				mainmenu();
			fflush(stdin);
			another = getch();
		}
	}
	gotoxy(10, 15);
	mainmenu();
}



void searchbooks()
{
	system("cls");
	int d;
	printf("*****************************Search Books*********************************");
	gotoxy(20, 10);
	printf("1. Search by ID");
	gotoxy(20, 14);
	printf("2. Search by Name");
	gotoxy(15, 20);
	printf("Enter your choice");   //until here, when you open searchbooks(), it closes in 1 second

	fp = fopen("Bibek.dat", "rb+");		//open file for reading
	rewind(fp);		//move pointer to beginning of file

	switch (getch())   //!!!! because of this, searchbooks() doesn't get quit in a second~
	{
	case '1':
	{
		system("cls");
		gotoxy(25, 4);
		printf("Search books by ID");

		gotoxy(20, 5);
		printf("Enter the book ID  :  ");
		scanf("%d", &d);

		gotoxy(20, 7);
		printf("Searching..");

		while (fread(&a, sizeof(a), 1, fp) == 1)		//while u are reading fp
		{
			if (a.id == d)
			{
				Sleep(2);
				gotoxy(20, 7);
				printf("The books is available");
				gotoxy(20, 9);
				printf("ID:%d", a.id);
				gotoxy(20, 10);
				printf("Name:%s", a.name);
				gotoxy(20, 11);
				printf("Author:%s ", a.Author);;
				gotoxy(20, 12);
				printf("Quantity:%d ", a.quantity);
				gotoxy(20, 13);
				printf("Price:Rs.%f", a.Price);
				gotoxy(20, 14);
				printf("Rack No:%d ", a.rackno);
				findbook = 't';
			}
		}
		if (findbook != 't')
		{
			gotoxy(22, 9);
			printf("No record Found");
		}
		gotoxy(20, 17);
		printf("Try another search y.n");
		if (getch() == 'y')
			searchbooks();
		else
			mainmenu();
		break;
	}

	case '2':
	{
		char s[15];
		system("cls");
		gotoxy(25, 4);
		printf("Search books by Name");

		gotoxy(20, 5);
		printf("Enter book Name  :  ");

		scanf("%s", s);
		int d = 0;
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (strcmp(a.name, s) == 0)
			{
				gotoxy(20, 7);
				printf("This book is available");

				gotoxy(20, 9);
				printf(" ID:%d", a.id);
				gotoxy(20, 10);
				printf(" Name:%s", a.name);
				gotoxy(20, 11);
				printf(" Author:%s", a.Author);
				gotoxy(20, 12);
				printf(" Qantity:%d", a.quantity);
				gotoxy(20, 13);
				printf(" Price:Rs.%f", a.Price);
				gotoxy(20, 14);
				printf(" Rack No:%d ", a.rackno);
				d++;
			}
		}
		if (d == 0)
		{
			gotoxy(22, 9);
			printf("No record");
		}
		gotoxy(20, 17);
		printf("Try another search? y.n");
		if (getch() == 'y')
			searchbooks();
		else mainmenu();
		break;
	}
	default:
		getch();
		searchbooks();
	}
	fclose(fp);
}




void issuebooks()
{
	int t;

	system("cls");
	printf("********************************ISSUE SECTION**************************");

	gotoxy(10, 5);
	printf("1. Issue a Book");
	gotoxy(10, 7);
	printf("2. View Issued Book");
	gotoxy(10, 9);
	printf("3. Search Issued Book");
	gotoxy(10, 11);
	printf("4. Remove Issued Book");
	gotoxy(10, 14);
	printf("Enter a Choice:");

	switch (getch())
	{
	case '1':
		system("cls");
		int c = 0;
		char another = 'y';
		while (another == 'y')
		{
			system("cls");
			gotoxy(15, 4);
			printf("Issue Book Section");

			gotoxy(10, 6);
			printf("Enter the book Id  :  ");

			scanf("%d", &t);

			fp = fopen("Bibek.dat", "rb+");
			fs = fopen("Issue.dat", "ab+");		//make Issue.dat

			if (checkid(t) == 0)	//issues those which are present in library
			{
				gotoxy(10, 8);
				printf("The book record is available");

				gotoxy(10, 9);
				printf("There are %d unissued books in library", a.quantity);

				gotoxy(10, 10);
				printf("The name of book is %s", a.name);

				gotoxy(10, 11);
				printf("Enter student name");
				scanf("%s", a.stname);

				gotoxy(10, 12);
				printf("Issued date = %d %d %d", a.issued.dd, a.issued.mm, a.issued.yy);

				gotoxy(10, 13);
				printf("The book of ID %d is issued", a.id);

				a.duedate.dd = a.issued.dd + RETURNTIME;
				a.duedate.mm = a.issued.mm;
				a.duedate.yy = a.issued.yy;

				if (a.duedate.dd > 30)
				{
					a.duedate.mm = a.duedate.mm + a.duedate.dd / 30.;
					a.duedate.dd = a.duedate.dd - 30;
				}

				if (a.duedate.mm > 12)
				{
					a.duedate.yy = a.duedate.yy + a.duedate.mm / 12;
					a.duedate.mm = a.duedate.mm - 12;
				}

				gotoxy(10, 14);
				printf("To be return %d %d %d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
				fseek(fs, sizeof(a), SEEK_END);
				fwrite(&a, sizeof(a), 1, fs);
				fclose(fs);
				c = 1;
			}
			if (c == 0)
			{
				gotoxy(10, 11);
				printf("No record found");
			}
			gotoxy(10, 15);
			printf("Issue any more? y.n ");
			fflush(stdin);
			if (getch() == 'n')
				mainmenu();
			else

			fclose(fp);
			
		}
		break;
	case '2':
	{
		system("cls");
		int j = 4;
		printf("*******************************Issued book list*******************************\n");
		gotoxy(2, 2);
		printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");

		fs = fopen("Issue.dat", "rb");			//open Issue.dat file
		while (fread(&a, sizeof(a), 1, fs) == 1)
		{
			gotoxy(2, j);
			printf("%s", a.stname);  //printf("Enter student name"); scanf("%s", a.stname);

			gotoxy(18, j);
			printf("%s", a.cat);

			gotoxy(30, j);
			printf("%d", a.id);

			gotoxy(36, j);
			printf("%s", a.name);

			gotoxy(51, j);
			printf("%d %d %d", a.issued.dd, a.issued.mm, a.issued.yy);

			gotoxy(65, j);
			printf("%d %d %d", a.duedate.dd, a.duedate.mm, a.duedate.yy);

			j++;
		}
		fclose(fp);
		gotoxy(1, 25);
		returnfunc();
	}
	break;

	case '3':		//search books by Id
	{
		system("cls");
		gotoxy(10, 6);
		printf("Enter book ID");
		int p; int c = 0;

		char another = 'y';
		while (another == 'y')
		{
			scanf("%d", &p);
			fs = fopen("Issue.dat", "rb");
			while (fread(&a, sizeof(a), 1, fs) == 1)
			{
				if (a.id = p)
				{
					issuerecord();
					gotoxy(10, 12);
					printf("press any key");
					getch();
					issuerecord();
					c = 1;
				}
			}
			fflush(stdin);
			fclose(fp);

			if (c == 0)
			{
				gotoxy(10, 8);
				printf("No record found");
			}
			gotoxy(10, 13);
			printf("Try another search? y.n");
			another = getch();
		}
	}
	break;

	}
}







void viewbooks()		//show the lists of book
{
	int i = 0; int j;
	system("cls");
	gotoxy(1, 1);
	printf("*********************************Book List*****************************");
	gotoxy(2, 2);
	printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
	j = 4;
	fp = fopen("Bibek.dat", "rb+");
	//rewind(fp);

	fseek(fp, 0, SEEK_END);
	while (fread(&a, sizeof(a), 1, fp) == 1)
	{
		gotoxy(3, j);
		printf("%s", a.cat);

		gotoxy(16, j);
		printf("%d", a.id);

		gotoxy(22, j);
		printf("%s", a.name);

		gotoxy(36, j);
		printf("%s", a.Author);
		
		gotoxy(50, j);
		printf("%d", a.quantity);
		
		gotoxy(57, j);
		printf("%f", a.Price);

		gotoxy(69, j);
		printf("%d", a.rackno);
		j++;
		i = i + a.quantity;
	}

	gotoxy(3, 25);
	printf("Total books = %d", i);
	fclose(fp);
	gotoxy(35, 25);
	returnfunc();

}





void editbooks()
{
	system("cls");
	int c = 0;
	int d, e;
	gotoxy(20, 4);
	printf("****Edit Books Section****");
	char another = 'y';
	while (another == 'y')
	{
		system("cls");
		gotoxy(15, 6);
		printf("Enter book ID to be edited");
		scanf("%d", &d);
		fp = fopen("Bibek.dat", "rb+");
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (checkid(d) == 0)
			{
				gotoxy(15, 7);
				printf("The book is available");
				gotoxy(15, 8);
				printf("The book id is %d ", a.id);
				gotoxy(15, 9);
				printf("Enter new name");
				scanf("%s", a.name);
				gotoxy(15, 10);
				printf("Enter new Author:"); scanf("%s", a.Author);
				gotoxy(15, 11);
				printf("Enter new quantity:"); scanf("%d", &a.quantity);
				gotoxy(15, 12);
				printf("Enter new price:"); scanf("%f", &a.Price);
				gotoxy(15, 13);
				printf("Enter new rackno:"); scanf("%d", &a.rackno);
				gotoxy(15, 14);
				printf("The record is modified");

				fseek(fp, ftell(fp) - sizeof(a), 0);
				fwrite(&a, sizeof(a), 1, fp);
				fclose(fp);
				c = 1;
			}
			if (c == 0)
			{
				gotoxy(15, 9);
				printf("No Record Found");
			}
		}
		gotoxy(15, 16);
		printf("Modify another record? y.n");
		fflush(stdin);
		another = getch();
	
	}
	returnfunc();

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

void returnfunc()
{
	{
		printf("Press Enter to return main menu");
	}
a:
	if (getch() == 13)		//allow only use of enter
		mainmenu();
	else
		goto a;
}


void issuerecord()	//display issued books information
{
	system("cls");
	gotoxy(10, 8);
	printf("The book had taken by Mr %s ", a.stname);
	gotoxy(10, 9);
	printf("Issued Date %d %d %d", a.issued.dd, a.issued.mm, a.issued.yy);
	gotoxy(10, 10);
	printf("Returning Date %d %d %d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
}

int main()
{
	Password();
	getch();
	return 0;
}