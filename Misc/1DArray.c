#include<stdio.h>
#include<stdlib.h>

void printArray(int* a, int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
        printf("\n%d",a[i]);
    }
}
void main()
{
    int* a = NULL;
    int len = 0;
    int i = 0;

    printf("\nEnter size of array : ");
    scanf("%d",&len);
    printf("\nSize Entered by you is : %d",len);

    a = malloc(sizeof(int)*len);
    for(i = 0; i<len; i++)
    {
        printf("Enter value for %d element : ",i);
	scanf("%d",&a[i]);
    }
    printArray(a, len);
}
