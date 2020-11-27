#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strReverse(char* str, int low, int high)
{
	int i = low;
	int j = high;
	char temp;
	for(i; i<j; i++,j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("\nReversed String = %s",str);

}
void main()
{
	int i = 0;
	int j = 0;
	char temp;
	char str[] = "my name is dheeraj";

	printf("\nSizeof string is %d", sizeof(str));
	printf("\nStrlen of string is %d\n", strlen(str));

	printf("\nOriginal string is %s", str);
	printf("\n\nReversing String\n");

	j = strlen(str)-1;
	for(i = 0; i<j; i++,j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("\nReversed String = %s",str);

	strReverse(str, 0, strlen(str)-1);
	j = 0;
	for(i=0; i<(strlen(str)-1); i++)
	{
		while(str[j] != ' ' && str[j] != '\0')
		{
			j++;
		}
		strReverse(str, i, j-1);
		i = j;
		j++;
	}
	printf("\n\n Reversed String = %s",str);

	char newstr[] = "my name is dheeraj";
	printf("\nOriginal string is %s\n", newstr);

	strReverse(str, 0, strlen(str)-1);

}
