#include<stdio.h>
#include<stdlib.h>

void printArr(int* arr, int len)
{
	int i = 0;

	for(i; i<len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void mySwap(int* a, int* b)
{
	printf("swapping %d and %d\n", *a, *b);
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;

}

int partition(int* arr, int low, int high)
{
	int pivot = arr[low];
	int i = low+1;
	int index = i;

	for(index; index<=high; index++)
	{
		if(arr[index] < pivot)
		{
			mySwap(&arr[i], &arr[index]);
			i++;
		}
	}
	mySwap(&arr[i-1], &arr[low]);
	return (i-1);
}


void quickSort(int* arr, int low, int high)
{
	int pi = 0;
	
	if(low<high)
	{
		pi = partition(arr, low, high);
		printf("Element %d is at right position\n",arr[pi]);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

void main()
{
	int arr[] = {8, 4, 2, 1, 3, 7, 5, 6};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArr(arr, len);

	quickSort(arr, 0, len-1);

	printArr(arr, len);

	return;
}
