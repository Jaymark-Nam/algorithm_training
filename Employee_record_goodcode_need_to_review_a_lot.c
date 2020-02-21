
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

COORD coord = { 0,0 };

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	FILE *fp, *ft;   //File pointers
	char another, choice;

	struct emp {

		char name[40];
		int age;
		float bs;	//basic salary of employee
	};

	struct emp e;	// structure variable creation

	char empname[40];  //string to store name of employee

	long int recsize;	//size of each record of employee

	fp = fopen("EMP.dat", "rb+");
	if (fp == NULL)
	{
		fp = fopen("EMP.dat", "wb+");
			if (fp == NULL)
			{
				printf("cant open file");
				exit(1);
			}
	}
	recsize = sizeof(e);	//size of each record i.e size of structure variable e

	//infiniite loop continues until the break statement encounter

	while (1)
	{
		system("cls");	//clear the console window

		gotoxy(30, 10);  //move the cursor to position 30,10 from topleft corner(default)
		printf("1.Add record"); // option for add record


		gotoxy(30, 12);  
		printf("2.List record");

		gotoxy(30, 14);
		printf("3.Modify record");

		gotoxy(30, 16);
		printf("4.Delete record");

		gotoxy(30, 18);
		printf("5. Exit");

		printf("your choice");	//enter the choice 1,2,3,4,5
		fflush(stdin);			//flush the inpput buffer
		choice = getche();	//get input from keyboard


		switch (choice)
		{
		case '1':
			system("cls");
			fseek(fp, 0, SEEK_END);		//search the file and move cursor to end of the filee
			//here 0 means, moving 0 distance from the end of the file!

			another = 'y';
			while (another == 'y')		//if user wants to add another record
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
			rewind(fp);		//this moves file cursor to start of file
			while (fread(&e, recsize, 1, fp) == 1)		// read the file and fetch the record one record per fetch
			{
				printf("\n %s %d %.2f", e.name, e.age, e.bs);	//printf the name, age, salary
			}
			getch();
			break;
		
		case '3' :
			system("cls");
			another = 'y';
			while (another == 'y')
			{
				printf("Enter the employee name to modify");
				scanf("%s", empname);
				rewind(fp);
				while (fread(&e, recsize, 1, fp) == 1)			//fetch all record from file
				{
					if (strcmp(e.name, empname) == 0)		//if entered name matches with that in file
					{
						printf("\n Enter new name, age and  bs");
						scanf("%s %d %f", e.name, &e.age, &e.bs);
						fseek(fp, -recsize, SEEK_CUR);		//move the cursor 1 step back from current position
						fwrite(&e, recsize, 1, fp);			//override the record
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
			while (another == 'y')
			{
				printf("\n Enter name of employee to delete");
				scanf("%s", empname);
				ft = fopen("Temp.dat", "wb");		//create a intermediate file for temporary storage
				rewind(fp);		//move record to starting of file
				while (fread(&e, recsize, 1, fp) == 1)		//read all records from file
				{
					if (strcmp(e.name, empname) != 0)		//if the entered record match
					{
						fwrite(&e, recsize, 1, ft);		//move all records except the one that is to be deleted to temp file
					}
				}
				fclose(fp);
				fclose(ft);
				remove("EMP.dat", "rb+");
				printf("delete another record (y,n)");
				fflush(stdin);
				another = getche();
			}
			break;
		case '5':
			fclose(fp);		//close file
			exit(0);		//exit program
		}
	}
	return 0;
}



