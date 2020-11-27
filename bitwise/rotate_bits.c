#include<stdio.h>
#include<stdlib.h>

#define INT_BITS sizeof(int)*8
void main()
{
	int x = 0;
	int pos = 3;
	int i = 0;

	printf("\nEnter the number to be rotated three bits :");
	scanf("%d",&x);

	for(i; i<pos; i++)
	{
		if(x & (1UL<<(INT_BITS-i-1)))
		{
			x |= (x<<1) | (1UL<<i);
		}
		else
		{
			x = x <<1;
		}
	}

	printf("\n Rotated number is %d",x);
}


