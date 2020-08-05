/*
 * Reverse a linked list
   Given pointer to the head node of a linked list, the task is to reverse 
   the linked list. We need to reverse the list by changing links between nodes.

   Examples:

   Input : Head of following linked list  
       1->2->3->4->NULL
   Output : Linked list should be changed to,
       4->3->2->1->NULL

   Input : Head of following linked list  
       1->2->3->4->5->NULL
   Output : Linked list should be changed to,
       5->4->3->2->1->NULL

   Input : NULL
   Output : NULL

   Input  : 1->NULL
   https://www.geeksforgeeks.org/iteratively-reverse-a-linked-list-using-only-2-pointers/
 */ 


#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
    int data;	
    struct node_st *next;	
} node_st_;	

node_st_ *
reverse_linked_list(node_st_ * head) {
    node_st_ * prev = NULL;
    node_st_ * temp = NULL;    
    if(head == NULL)
       return head;
    if(head->next == NULL)
       return head;
    prev = head;
    head = head->next;
    prev->next = NULL;
    while (head!= NULL) {
	   //Store the next element 
	   temp = head->next;
	   //Change the next element to prev reversed list.
           head->next = prev;
	   //prev is now the head of the reversed list.
	   prev = head;
	   //restore the current element of non-reversed list.
	   head = temp;
    }
    return prev;    
}	

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
main(void) {
    node_st_ * head = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,25);
    print_linked_list(head);
    head = reverse_linked_list(head);
    print_linked_list(head);
    destroy_linked_list(head);
    head = NULL;
    return 0;
}	
