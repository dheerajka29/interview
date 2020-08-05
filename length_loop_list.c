#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_st {
    int data;	
    struct node_st *next;	
} node_st_;	

node_st_ *
mem_allocator(int data){
    node_st_ * temp = malloc(sizeof(node_st_));
    if(temp == NULL) {
       return NULL;
    } else {
      temp->data = data;
      temp->next = NULL; 
    }	    
    return temp;
}	

node_st_ *
insert_linked_list(node_st_ * head, int data) {
    node_st_ * temp = head;	
    if (temp == NULL) {
        temp = mem_allocator(data);
	head = temp;
    } else {
        while(temp->next != NULL)
	      temp = temp->next;
	temp->next = mem_allocator(data);      	      
    }	    
    return head;
}	

void
print_linked_list(node_st_ * head){
    while(head) {
          printf("%d->",head->data);
	  head = head->next;
    }
    printf("\n");    
}	

void
destroy_linked_list(node_st_ * head) {
    if(head){
          destroy_linked_list(head->next);
	  free(head);
    }	    
}

int
length_loop_list(node_st_ * head) {
    if(head == NULL)
       return -1;
    if(head->next == NULL)
       return -1;
    node_st_ * tortoise = head;
    node_st_ * hare = head;
    while(hare != NULL && hare->next != NULL) {
          tortoise = tortoise->next;
          hare = hare->next->next;
          if(tortoise == hare)
             break; 
    }
    if(hare == NULL )
       return -1;
    else if (hare->next == NULL)
       return -1;
    int count = 0;
    tortoise = tortoise->next;
    while(tortoise != hare) {
           count++;
           tortoise = tortoise->next;
    }
    return count;     
}

int 
main(void) {
    node_st_ * head = NULL, *head2 = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,15);
    head->next->next->next = head;
    printf("Length is %d\n",length_loop_list(head));
    return 0;
}