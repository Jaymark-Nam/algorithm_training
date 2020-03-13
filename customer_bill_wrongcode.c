///

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void input();
void writefile();
void search();
void output();

struct date {
	int month, day, year;
};

struct account {
	int number, acct_no;
	char name[20];
	float mobile_no;
	char street[30], city[20], acct_type;
	float oldbalance, newbalance, payment;
	struct date lastpayment;
}customer;

int tl, sl, ts;

void main()
{
	int i, n;
	char ch;
	printf("   CUSTOMER BILLING SYSTEM\n\n");
	printf("======================================");
	printf("\n1: Add account on list\n");
	printf("2: Search customer account\n");
	printf("3: exit\n");
	printf("======================================");

	do {
		printf("\nselect what you want to do?\n");
		ch = getche();                    //getche ?? getche() function is a function which waits for any character input from keyboard and it will also echo the input character on to the output screen.
	} while (ch <= '0' || ch > '3');

	switch (ch)
	{
	case '1':
		printf("\nhow many customer accounts?");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			input();
			if (customer.payment > 0)
				customer.acct_type = (customer.payment < 0.1*customer.oldbalance) ? 'O' : 'D';
			else
				customer.acct_type = (customer.oldbalance>0) ? 'D' : 'C';
			customer.newbalance = customer.oldbalance - customer.payment;
			writefile();
		}
		main();
	case '2':
		printf("search what?\n");
		printf("\n1---search by  customer number\n");
		printf("2---search by customer name\n");
		search();
		ch = getche();
		main();

	case '3':
		cprintf("\n Jaewoo's project ");
		exit(1);
	}
}


void input()
{
	FILE *fp = fopen("Jaewoo.dat", "rb");
	fseek(fp, 0, SEEK_END);			// // 파일 포인터를 파일의 끝으로 이동시킴
	tl = ftell(fp);				// = ftell(fp);          // 파일 포인터의 현재 위치를 얻음
	sl = sizeof(customer);
	ts = tl / sl;
	fseek(fp, (ts - 1)*sl, SEEK_SET);
	fread(&customer, sizeof(customer), 1, fp);
	printf("\ncustomer no : %d\n", ++customer.number);
	fclose(fp);
	printf("	Account number");
	scanf("%d", &customer.acct_no);

	printf("	Name");
	scanf("%s", customer.name);


	printf("	Mobile no");
	scanf("%f", &customer.mobile_no);


	printf("	Street");
	scanf("%s", customer.street);


	printf("	City");
	scanf("%s", customer.city);


	printf("	Previous Balance");
	scanf("%f", &customer.oldbalance);


	printf("	Current payment");
	scanf("%f", &customer.payment);


	printf("	paymeny date(mm/dd/yyyy)");
	scanf("%d%d%d", &customer.lastpayment.month, &customer.lastpayment.day, &customer.lastpayment.year);

	return;
}

void writefile()
{
	FILE *fp;
	fp = fopen("Jaewoo.dat", "ab");
	fwrite(&customer, sizeof(customer), 1, fp);
	fclose(fp);
	return;
}

void search()
{
	char ch, name[100];
	int n, i, m = 1;
	FILE *fp;
	fp = fopen("Jaewoo.dat", "rb");
	do {
		printf("\n enter your choice");
		ch = getche();

	} while (ch != '1' && ch != '2');		// !1, !2면 항상 루트를 돌린다는뜻
	switch (ch)
	{
	case '1':
		fseek(fp, 0, SEEK_END);
		tl = ftell(fp);
		sl = sizeof(customer);
		ts = tl / sl;
		do {
			printf("\nchoose customer number");
			scanf("%d", &n);
			if (n <= 0 || n > ts)
				printf("\nEnter correct \n");
			else
			{
				fseek(fp, (n - 1)*sl, SEEK_SET);
				fread(&customer, sl, 1, fp);
				output();
			}
			printf("\n\n again?(y/n)");
			ch = getche();
		} while (ch == 'y');
		fclose(fp);
		break;
	case '2':
		fseek(fp, 0, SEEK_END);
		tl = ftell(fp);
		sl = sizeof(customer);
		ts = tl / sl;
		fseek(fp, (ts - 1)*sl, SEEK_SET);
		fread(&customer, sizeof(customer), 1, fp);
		n = customer.number;

		do {
			printf("\nEnter the name");
			scanf("%s", name);
			fseek(fp, 0, SEEK_SET);
			for (i = 1; i <= n; i++)
			{
				fread(&customer, sizeof(customer), 1, fp);
				if (strcmp(customer.name, name) == 0)
				{
					output();
					m = 0;
					break;
				}
			}
			if (m != 0)
				printf("\n\ndoestn exist\n");
			printf("\nanother?y.n");
			ch = getche();
		} while (ch == 'y');
		fclose(fp);
	}
	return;
}


void output()
{
	printf("\n\n    Customer no    :%d\n", customer.number);
	printf("    Name 	   :%s\n", customer.name);
	printf("    Mobile no      :%.f\n", customer.mobile_no);
	printf("    Account number :%d\n", customer.acct_no);
	printf("    Street         :%s\n", customer.street);
	printf("    City           :%s\n", customer.city);
	printf("    Old balance    :%.2f\n", customer.oldbalance);
	printf("    Current payment:%.2f\n", customer.payment);
	printf("    New balance    :%.2f\n", customer.newbalance);
	printf("    Payment date   :%d/%d/%d\n\n", customer.lastpayment.month, customer.lastpayment.day, customer.lastpayment.year);
	printf("    Account status :");
	switch (customer.acct_type)
	{
	case 'C':
		cprintf("CURRENT\n\n");
		break;
	case 'O':
		cprintf("OVERDUE\n\n");
		break;
	case 'D':
		cprintf("DELINQUENT\n\n");
		break;
	default:
		cprintf("ERROR\\n\n");
	}
	return;
}
