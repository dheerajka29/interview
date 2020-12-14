#include<stdio.h>
#include<stdlib.h>

void printArray(int* arr, int len)
{
	int i = 0;
	printf("\n");
	for(; i<len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int* a, int* b)
{
	if(*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}
void heapify(int* arr, int i, int len)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;

	if(l<len && arr[l] > arr[largest])
		largest = l;
	
	if(r<len && arr[r] > arr[largest])
		largest = r;
	
	if( largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, largest, len);
	}
	printArray(arr, 6);
}
void heapSort(int* arr, int len)
{
	int i = len/2 -1;
	for(;i>=0; i--)
	{
		heapify(arr, i, len);
	}
	for(i = len-1; i>=0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, 0, i);
	}
}

void main()
{
	int arr[6] = {3, 5, 6, 1, 9, 0};

	printArray(arr, 6);

	heapSort(arr, 6);
//	quickSort(arr, 0, 6);

	printArray(arr, 6);
}
