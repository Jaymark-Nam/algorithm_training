#include <stdio.h>

int main()
{
	double a, b, c, cost, income;   // a : static cost   b : variable cost    c : price
	double n;  // n : number

	scanf("%lf %lf %lf", &a, &b, &c);
	n = a / (c - b);

	cost = a + n*b;
	income = c * n;
	printf(" %lf  %lf ", n, income);

}