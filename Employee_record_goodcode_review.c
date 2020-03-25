
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
//
COORD coord = { 0,0 };

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	FILE *fp, *ft;	//file pointers
	char another, choice, trick;

	struct emp {
		char name[40];
		int age;
		float bs;
	}e;

	char empname[40];
	int recsize;

	fp = fopen("EMP.dat", "rb+");

	if (fp == NULL)
	{
		fp = fopen("EMP.dat", "wb+");
		if (fp == NULL)
		{
			printf("cant open");
			exit(1);
		}
	}
	recsize = sizeof(e);	//size of each record i.e size of structure 


	while (1)
	{
		system("cls");
		gotoxy(30, 10);
		printf("1. ADD RECORD");

		gotoxy(30, 12);
		printf("2. LIST RECORD");

		gotoxy(30, 14);
		printf("3. MODIFY RECORD");

		gotoxy(30, 16);
		printf("4. DELETE RECORD");

		gotoxy(30, 18);
		printf("5. EDIT");

		printf("your choice");

		fflush(stdin);

		choice = getche();

		switch (choice)
		{
		case '1':
			system("cls");
			fseek(fp, 0, SEEK_END);			//move cursor to end of file
			another = ' y';
			while (another == 'y')
			{
				printf("\n Enter name");
				scanf("%s", e.name);

				printf("\n Enter age");
				scanf("%d", &e.age);

				printf("\n Enter basic salary ");
				scanf("%f", &e.bs);

				fwrite(&e, recsize, 1, fp);		//write record in the file

				printf("\n Add another record(y/n) ");
				fflush(stdin);
				another = getche();
			}
			
			break;
		case '2':
			system("cls");
			rewind(fp);			//this moves file cursor to start of file. because we added at the end of file
			while (fread(&e, recsize, 1, fp) == 1)
			{
				printf("\n %s %d %.2f", e.name, e.age, e.bs);

			}
			getch();
			break;

		case '3':
			system("cls");
			another = 'y';
			while (another == 'y')
			{
				printf("Enter the employee name to modify. Enter 'q' is you want to go back");
				scanf("%s", empname);
				if (empname == 'q')
				{
					break;
				}
				rewind(fp);
				while (fread(&e, recsize, 1, fp) == 1)		//bring back all record from file
				{
					if (strcmp(e.name, empname) == 0)			//if entered name matches with  that in file
					{
						printf("\n Enter new new name, age and bs");
						scanf("%s %d %f", e.name, &e.age, &e.bs);
						fseek(fp, -recsize, SEEK_CUR);		//move the cursor 1 step back from current position

						fwrite(&e, sizeof(e), 1, fp);		//recsize = sizeof(e);
						break;
					}
				}
				printf("\n Modify another record (y/n) ");
				fflush(stdin);
				another = getche();
			}
			break;
		case '4':
			system("cls");
			another = 'y';
			while (another == 'y');
			{
				printf("\n Enter name of employee to delete");
				scanf("%s", empname);
				ft = fopen("Temp.dat", "wb");	//a temp storage--for delete
				rewind(fp);			//start of the file

				while (fread(&e, recsize, 1, fp) == 1)		//while reading all records from files
				{
					if (strcmp(e.name, empname) != 0)
					{
						fwrite(&e, recsize, 1, ft);
					}
				}
				fclose(fp);
				fclose(ft);
				remove("EMP.dat", "rb+");
				printf("delete another record (y.n)");
				fflush(stdin);
				another = getche();
			}
			break;

		case '5':
			fclose(fp);
			exit(0);
		}
	}
	return 0;
}
