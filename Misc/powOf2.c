#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a = 0;
	int temp =0;

	printf ("\n Enter value to be checked : ");
	scanf("%d", &a);

	while(a)
	{
		a = a & (a-1);
		temp++;
	}

	printf("\n\nvalue of a: %d", a);
	printf("\nvalue of temp: %d\n", temp);

}


