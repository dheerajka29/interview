/*
 * Merge two sorted linked lists such that merged list is in reverse order
   Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order (reverse order).

   Examples:

   Input:  a: 5->10->15->40
        b: 2->3->20 
   Output: res: 40->20->15->10->5->3->2

   Input:  a: NULL
        b: 2->3->20 
   Output: res: 20->3->2
   https://www.geeksforgeeks.org/merge-two-sorted-linked-lists-such-that-merged-list-is-in-reverse-order/
 */

#include <stdio.h>
#include <stdlib.h>

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

node_st_ * 
merged_linked_list(node_st_ * head1, node_st_ * head) {
    node_st_ * temp = NULL;
    node_st_ * ptr = NULL;
    while (head1 != NULL && head != NULL) {
	 /*
	  * 
	  */     
          if(head1->data <= head->data) {
	     ptr = head1;
	     head1 = head1->next; 
	     ptr->next = temp;
	     temp = ptr;
	  } else {
             ptr = head;
	     head = head->next; 
	     ptr->next = temp;
	     temp = ptr;
	  }	
    }
    while(head != NULL) {
          ptr = head;
	  head = head->next;
	  ptr->next = temp;
	  temp = ptr;
    }	    
    while(head1 != NULL) {
          ptr = head1;
          head1 = head1->next;
          ptr->next = temp;
          temp = ptr;
    }	    
    return temp;
}	

int 
main(void) {
    node_st_ * head = NULL, *head2 = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,40);
    print_linked_list(head);
    head2 = insert_linked_list(head2,2);
    head2 = insert_linked_list(head2,3);
    head2 = insert_linked_list(head2,5);
    head2 = insert_linked_list(head2,20);
    print_linked_list(head2);
    node_st_ * final = merged_linked_list(head2,head);
    print_linked_list(final);
    destroy_linked_list(final);
    head = NULL;
    head2 = NULL;
    final = NULL;
    return 0;
}	
