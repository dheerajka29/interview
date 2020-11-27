#include<stdio.h>
#include<stdlib.h>

void main()
{
	uint x = 1;

	if((char*)&x)
		printf("\nLittle Endian");
	else
		printf("\nBig Endian");
}
