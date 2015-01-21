#include <stdio.h>

int factorial1(int x);
int factorial2(int x);

int main (void) 
{

	int argument;
	
	printf("Podaj argument silni\n");
	scanf("%d",&argument);

	int product1 = factorial1(argument);
	int product2 = factorial2(argument);

	printf("Silnia z %d liczona iteracyjnie to: %d\n",argument,product1);
	printf("Silnia z %d liczona rekurencyjnie to: %d\n",argument,product2);

	return 0;
}

int factorial1(int x)
{

	if(x==0) return 1;

	int i=1;
	int product = 1;
	
	for(i=1; i<=x; i++)
	{
		product *=i;
	}

	return product;
}

int factorial2(int x)
{
	if(x==0) return 1;

	if(x==1) return 1;
	return factorial2(x-1) * x;
}
