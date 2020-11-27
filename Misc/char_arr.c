#include <stdio.h>

int main(void) {
    const char msg[] = "foo";
    char * ptr = msg;
    *ptr = 'b';
    printf("Value is %s",ptr);
}	
