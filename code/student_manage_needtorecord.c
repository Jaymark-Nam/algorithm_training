#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct student {
	char ID[15];
	char name[20];
	char add[20];
	char parname[20];
	int Class;
	long unsigned int phone_no;
};

struct student stu;


void window() {
	gotoxy(28, 2);
	printf("STUDENT RECORD SYSTEM");
	gotoxy(25, 24);
}
/*
void get_password(char* pass)
{
	char temp_passP[25];
	int i = 0;
	while (1)
	{
		temp_passP[i] = getch();
		if (temp_passP[i] == 13) { break; }
		else if (temp_passP[i] == 8)
		{
			if (i != 0) {
				printf("\b \b");
				i--;
			}
			else { printf("\a"); }
		}
		else
		{
			printf("*");
			*(pass + i) = temp_passP[i];
			i++;
		}
		*(pass + i) = '\0';
	}
}

void use_pass_field() {
	int x = 15, y = 16;
	int use;
	char pass[10];
	gotoxy(15, 12); printf("The database is password protected.");
	gotoxy(15, 13); printf(" Enter Valid username and password");

	gotoxy(20, x); printf("USERNAME:- ");
	gotoxy(20, y); printf("PASSWORD:- ");
	gotoxy(34, x); scanf("%d", use);
	gotoxy(34, y); get_password(pass);
}


int conf_record(char id[]) {
	// left for you
	//it checks whether the entered id for
	//new record is already in the database.
}
*/
void add_student() {
	system("cls");
	printf("Add Record");
	int print = 37;
	FILE *fp;
	fp = fopen("record.txt", "ab+");
	if (fp == NULL) {
		//MessageBox(0, "Error in Opening file\nMake sure your file is not write protected", "Warning", 0);

	}
	else {
		fflush(stdin);
		gotoxy(print, 10); printf("ID: "); gets(stu.ID);
		//here you can confirms the ID
		gotoxy(print, 12); printf("Name: "); gets(stu.name);
		gotoxy(print, 14); printf("Address: "); gets(stu.add);
		gotoxy(print, 16); printf("Parent's name: "); gets(stu.parname);
		gotoxy(print, 18); printf("Class: "); scanf("%d", &stu.Class);
		gotoxy(print, 20); printf("Phone Number: "); scanf("%ld", &stu.phone_no);
		fwrite(&stu, sizeof(stu), 1, fp);
		gotoxy(40, 22); printf("The record is sucessfully added");
	}
	fclose(fp);
	return;
}

void search_student() {
	system("cls");
	printf("Search Record");
	char s_id[15];
	int isFound = 0;
	gotoxy(37, 10); printf("Enter ID to Search: "); fflush(stdin);
	gets(s_id);
	FILE *fp;
	fp = fopen("record.txt", "rb");
	while (fread(&stu, sizeof(stu), 1, fp) == 1) {
		if (strcmp(s_id, stu.ID) == 0) {
			isFound = 1;
			break;
		}
	}
	if (isFound == 1) {
		gotoxy(37, 12); printf("The record is Found");
		gotoxy(37, 14); printf("ID: %s", stu.ID);
		gotoxy(37, 15); printf("Name: %s", stu.name);
		gotoxy(37, 16); printf("Address: %s", stu.add);
		gotoxy(37, 17); printf("Parent's Name: %s", stu.parname);
		gotoxy(37, 18); printf("Class: %d", stu.Class);
		gotoxy(37, 19); printf("Phone No: %ld", stu.phone_no);
	}
	else {
		gotoxy(37, 12); printf("Sory, No record found in the database");
	}
	fclose(fp);
	return;
}

void mod_student() {
	system("cls");
	printf("Modify Record");
	char s_id[15];
	int isFound = 0, print = 37;
	gotoxy(37, 10); printf("Enter ID to Modify: "); fflush(stdin);
	gets(s_id);
	FILE *fp;
	fp = fopen("record.txt", "rb+");
	while (fread(&stu, sizeof(stu), 1, fp) == 1) {
		if (strcmp(s_id, stu.ID) == 0) {
			fflush(stdin);
			gotoxy(print, 12); printf("ID: "); gets(stu.ID);
			gotoxy(print, 13); printf("Name: "); gets(stu.name);
			gotoxy(print, 14); printf("Address: "); gets(stu.add);
			gotoxy(print, 15); printf("Parent's name: "); gets(stu.parname);
			gotoxy(print, 16); printf("Class: "); scanf("%d", &stu.Class);
			gotoxy(print, 17); printf("Phone Number: "); scanf("%ld", &stu.phone_no);
			fseek(fp, -sizeof(stu), SEEK_CUR);
			fwrite(&stu, sizeof(stu), 1, fp);
			isFound = 1;
			break;
		}
	}
	if (!isFound) {
		gotoxy(print, 12); printf("No Record Found");
	}
	fclose(fp);
	return;
}


void delete_student() {
	system("cls");
	printf("Delete Record");
	char s_id[15];
	int isFound = 0, print = 37;
	gotoxy(37, 10); printf("Enter ID to Modify: "); fflush(stdin);
	gets(s_id);
	FILE *fp, *temp;
	fp = fopen("record.txt", "rb");
	temp = fopen("temp.txt", "wb");
	while (fread(&stu, sizeof(stu), 1, fp) == 1) {
		if (strcmp(s_id, stu.ID) == 0) {
			fwrite(&stu, sizeof(stu), 1, temp);
		}
	}
	fclose(fp);
	fclose(temp);
	remove("record.txt");
	rename("temp.txt", "record.txt");
	gotoxy(37, 12); printf("The record is sucessfully deleted");
	return;
}

void main_window() {
	int choice;
	int x = 2;
	while (1) {
		gotoxy(x, 8); printf("1. Add Student");
		gotoxy(x, 10); printf("2. Search Student");
		gotoxy(x, 12); printf("3. Modify Student Record");
		gotoxy(x, 14); printf("4. Generate Marksheet");
		gotoxy(x, 16); printf("5. Delete Student Record");
		gotoxy(x, 18); printf("6. Change password");
		gotoxy(x, 20); printf("7. Exit");
		gotoxy(x, 22); printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add_student();
			break;
		case 2:
			search_student();
			break;
		case 3:
			mod_student();
			break;
		case 4:
			break;
		case 5:
			delete_student();
			break;
		case 6:
			break;
		case 7:
			exit(0);
			break;
		default:
			break;
		}

	}

}

int main() {
	window();
	//use_pass_field();
	main_window();
	return 0;
}
