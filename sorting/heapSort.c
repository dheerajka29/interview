#include<stdio.h>
#include<stdlib.h>

void mySwap(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void printArr(int* arr, int len)
{
	int i = 0;

	for(i; i<len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void heapify(int* arr, int n, int i)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;

	if(l < n && arr[l]>arr[largest])
		largest = l;
	if(r<n && arr[r]>arr[largest])
		largest = r;
	
	if(largest != i)
	{
		mySwap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}
}



void heapSort(int* arr, int len)
{
	int n = len;
	int i = (n/2) - 1;
	for(i; i >=0; i--)
	{
		heapify(arr, n, i);
	}
	
	for(i = n-1; i>0; i--)
	{
		mySwap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void main()
{
	int arr[] = {9, 6, 1, 8, 2, 3, 5, 4, 7};

	int length = sizeof(arr)/sizeof(arr[0]);

	printArr(arr, length);

	heapSort(arr, length);

	printArr(arr, length);
}
