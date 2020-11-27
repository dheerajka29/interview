#include<stdio.h>
#include<stdlib.h>

void printArray(int** a, int row, int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
    {
        for(j = 0; j<col; j++)
	{
	     printf("\n%d",a[i][j]);
	 }
    }

    printf("\n\n");
}
void main()
{
    int** a = NULL;
    int row = 0;
    int j = 0;
    int col = 0;
    int i = 0;

    printf("\nEnter size of row : ");
    scanf("%d",&row);
    printf("\nSize Entered for row is : %d",row);

    printf("\nEnter size of col : ");
    scanf("%d",&col);
    printf("\nSize Entered for col is : %d",col);


    a = malloc(sizeof(int*)*row);
    for(i = 0; i<row; i++)
    {
        a[i] = malloc(sizeof(int)*col);
    }

    for(i = 0; i<row; i++)
    {
        for(j = 0; j<col; j++)
	{
	    printf("Enter value for element a[%d][%d] : ",i,j);
	    scanf("%d",&a[i][j]);
	}
    }
    printArray(a, row, col);
}
