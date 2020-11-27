#include<stdio.h>
#include<stdlib.h>

#define INT_BITS sizeof(int)*8
void main()
{
	int x = 8;
	int temp = 0;
	int i = 0;

	for(i; i<INT_BITS; i++)
	{
		if(x & (1UL<<i))
		{
			temp |= (1<<INT_BITS - i - 1);
		}
	}
	printf("\n Reversed bit number is %d", temp);
}

	
