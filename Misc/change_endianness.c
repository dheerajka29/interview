#include<stdio.h>
#include<stdlib.h>

int changeEndianness(int a)
{
	int result = 0;

	result = (a & 0x000000ff)<<24 | (a & 0x0000ff00)<<8 | (a & 0x00ff0000)>>8 | (a & 0xff000000)>>24 ;

	return result;
}


void main()
{
	int a = 0x11223344;
	int result = 0;

	result = changeEndianness(a);
	printf("\n Changed Endianness = 0x%x", result);

	result = changeEndianness(result);
	printf("\n Changed Endianness = 0x%x", result);
}




