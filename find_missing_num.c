/*
 *Find the Missing Number
  You are given a list of n-1 integers and these integers are in the range of 1 to n. 
  There are no duplicates in list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
 *Example :
  I/P    [1, 2, 4, ,6, 3, 7, 8]
  O/P    5
 */ 

#include <stdio.h>

int 
main(void) {
    int arr[] = {1, 2, 4, 6, 3, 7, 8};  
    int len = sizeof(arr)/sizeof(int);
    int iter = 0;
    int temp = 0;
    int n = 8;
    for(iter;iter<len;iter++){
        temp = temp ^ arr[iter];
    }	    
    for(iter=1;iter <= n ; iter++)
	temp = temp ^ iter;
    printf("%d\n",temp);
    return 0;   
}	
