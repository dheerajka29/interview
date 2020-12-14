#include<stdio.h>
#include<stdlib.h>

void printArray(int* arr, int len)
{
	printf("\n");
	while (len)
	{
		printf(" %d",arr[len-1]);
		len--;
	}
	printf("\n");
}

void myswap(int* x, int* y)
{
	if(*x != *y)
	{
		printf("\nSwapping %d and %d", *x, *y);
		*x = *x ^ *y;
		*y = *x ^ *y;
		*x = *x ^ *y;
	}
}
int partition(int* arr, int low, int high)
{
	int pivot = arr[low];
	int i = low+1;
	int index = low;

	for(i; i<=high; i++)
	{
		if(arr[i] < pivot)
		{
			index++;
			myswap(&arr[i], &arr[index]);
		}
	}

	myswap(&arr[low], &arr[index]);
	return (index);
}

void quickSort(int* arr, int low, int high)
{
	int pi = 0;

	if(low<high)
	{
		pi = partition(arr, low, high);
		printArray(arr,8);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

void main()
{
	int arr[] = {4,6,23,8,24,9,1,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,len);
	quickSort(arr, 0, len-1);
//	heapSort(arr, len);

	printArray(arr,len);
}
