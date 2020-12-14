#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringReverse(char* str, int low, int high)
{
	char temp = '\0';
	while(low<high)
	{
	//	printf("\nSwapping %c and %c", str[low], str[high]);
		temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		low++;
		high--;
	}
	//printf("\nReversed string is %s", str);
	return;
}

void reverseIndex(char* str)
{
	int low_index = 0;
	int high_index = 0;
	int len = strlen(str);
	int index = 0;

	while(index <= len)
	{
		if((str[index] == ' ') || (str[index] == '\0'))
		{
			printf("\nentered");
			stringReverse(str, low_index, index-1);
			low_index = index + 1;
		}
		index++;
	}
}

void main()
{
	char buf[50] ;
	char *str = NULL;
	int len = 0;
	int low_index = 0;
	int high_index = 0;

	printf("\nEnter desired string : ");
	gets(buf);

	printf("\nEntered string is %s", buf);

	str = malloc(strlen(buf) + 1);
	strcpy(str, buf);

	len = strlen(str);
	//stringReverse(str, 0, len-1);

	printf("\nReversed string is %s", str);

	reverseIndex(str);

	printf("\nReversed string is %s", str);
}
