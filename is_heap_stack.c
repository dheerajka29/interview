#include <stdio.h>
#include <stdlib.h>
void
check_is_heap_or_stack(void * addr) {
    int a = 0;
    if ((void *) &a > addr) {
        printf("It is Heap\n");
    } else {
        printf("It is stack\n");
    }	    
}	

int main(void) {
    int * num = malloc(sizeof(int));
    int b = 0;
    check_is_heap_or_stack(&b);
    check_is_heap_or_stack(num);
    free(num);
}	
