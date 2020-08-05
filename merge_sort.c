#include <stdio.h>

void
worker_func(int * arr, int low, int mid, int high) {
    int a_len = mid - low + 1;
    int b_len = high - mid;
    int A[a_len];
    int B[b_len];
    int iter = 0;
    for(iter;iter<a_len;iter++)
        A[iter] = arr[iter+low];
    for(iter = 0;iter < b_len;iter++)
	B[iter] = arr[iter+mid+1];   
    int i = 0, j = 0,k = low;
    while(i < a_len && j < b_len) {
          if(A[i] < B[j]){
	     arr[k] = B[j];	  
	     j++;
	     k++;
	  } else {
	     arr[k] = A[i];	  
	     i++;
	     k++;
	  }	  
    }
    while(i < a_len){
	  arr[k] = A[i]; 
          i++;
	  k++;
    }	      
    while(j < b_len) {
          arr[k] = B[j];
	  j++;
	  k++;
    }	    
}	

void
merge_sort_arr(int * arr, int low, int high) {
     if(low < high) {
        int mid = (low+high)/2;
	merge_sort_arr(arr,low,mid);
	merge_sort_arr(arr,mid+1,high);
	worker_func(arr,low,mid,high);
     }	     
}	

int
main(void) {
    int arr[6] = {3,4,1,7,6,2};
    int size = sizeof(arr)/sizeof(int);
    merge_sort_arr(arr,0,size-1);
    int iter = 0;
    for(iter;iter<size;iter++)
	printf("%d ",arr[iter]);
    printf("\n");
    return 0;    
}	
