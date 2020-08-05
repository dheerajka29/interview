/*
 * https://www.geeksforgeeks.org/add-two-bit-strings/
 * Add two bit strings
   Given two bit sequences as strings, write a function to return the addition of the two sequences. 
   Bit strings can be of different lengths also. For example, if string 1 is “1100011” and second string 2 is “10”, then the function should return “1100101”.
 */ 

#include <stdio.h>
#include <string.h>

int
main(void) {
   char str1[7] = "110011";
   char str2[3] = "10";
   /*
    * Take length of 2 input string.
    */ 
   int len1 = strlen(str1);
   int len2 = strlen(str2);

   int result_len = len1 > len2 ? len1 : len2;
   
   // Temp to store the larger string of the input, we will just memcpy to it below.
   char temp[result_len + 1];
   // Result Buffer greater than +1 since addition may return extra bit.
   char result[result_len + 2];

   // Another temp buffer to make smaller string equal to larger one.
   char temp1[result_len+1];

   memset(temp,0,sizeof(temp));
   memset(result,0,sizeof(result));
   memset(temp1,0,sizeof(temp1));

   int iter = 0;
   
   //Logic to equalize smaller string length to larger string padding with 0.
   if(len1 < len2) {
      for(iter = 0;iter < (len2 - len1);iter++){
          temp[iter] = '0'; 
      }	
      memcpy(temp + iter,str1,sizeof(str1));
      memcpy(temp1,str2,sizeof(str2));      
   } else {
      for(iter = 0;iter < len1 - len2;iter++){
          temp[iter] = '0'; 
      }
      memcpy(temp + iter,str2,sizeof(str2));
      memcpy(temp1,str1,sizeof(str1));
   }
   
   int carry = 0;
   //Karnaugh map for the addition.
   for(iter = result_len-1; iter >=0;iter--){
       result[iter] = ((temp1[iter] - '0') ^ (temp[iter] - '0') ^ carry) ? '1':'0';
       carry = ((temp1[iter] - '0') & (temp[iter] - '0')) | ((temp1[iter] - '0') & carry) | (carry & (temp[iter] - '0'));
   }
   printf("%s\n",result);
   return 0;   
}	
