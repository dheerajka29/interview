#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int
main(void) {
#if 0
   /*Naive Approach*/	
   int num = 34;
   int iter = 2;
   int i = 2;
   bool is_prime = true;
   for(iter;iter<=num;iter++) {
       int temp = sqrt(iter);
       for(i = 2;i <= temp;i++) {
	   if(iter%i == 0) {
	      is_prime = false;
	      break;	
   	   }
	   is_prime = true;	   
       }
       if(is_prime == true)
	  printf("%d\n",iter);	       
   }	   
   return 0;
#endif 
   int num = 7;
   if(num == 0 || num == 1)
      return 1;
   bool arr[num-1];
   memset(arr,false,sizeof(arr));
   int iter = 2,i;
   for(iter;iter*iter <=num;iter++) {
       if(arr[iter-2] == false) {
          //Not traversed yet. 
	  for(i= iter*2;i <= num;i += iter){
	      arr[i-2] = true;
	  }	  
       }		       
   }
   for(iter=0;iter<num-1;iter++)
	if(arr[iter] == false)
           printf("%d\n",iter+2);
   return 0;   
}	
