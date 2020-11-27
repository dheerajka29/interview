#include<stdio.h>
#include<stdlib.h>

#define MYSIZEOF(x) (char*)(&x + 1) - (char*)(&x)
void main()
{
	int x = 0;

	printf("\n sizeof integer is %d and sizeof integer through MACRO is %d\n", sizeof(x), MYSIZEOF(x));
}
