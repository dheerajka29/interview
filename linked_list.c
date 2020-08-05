#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>

typedef struct node_st {
    int data;
    struct node_st * next;
} node_st_;

#define MAX 100
int stack_arr[MAX] = {};
int stack_index = 0; 

//Allocate the memory
//and assign the data to it.
node_st_ *
node_mem_allocator(int data) {
    node_st_ * temp = NULL;
    temp = malloc (sizeof(node_st_));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

typedef struct hash_node {
      int * addr;
} hash_node_;       	

//Global count to maintain no. of elements in hash
int count ;
/*
 * Linked list node insertion.
 * This API will take the linked list head
 * and insert a given data at the end
 * of the linked list.
 */ 
node_st_ * 
node_insert (node_st_ * node , int data) {
     // Check if node is Null , if yes , insert straight away.
    node_st_ * temp = node;
    if (node == NULL) {
        node = node_mem_allocator(data);
	return node;
    }
    //Traverse till end of the node
    //is found.
    while(temp->next != NULL ) {
	  temp = temp->next;  
    }	  
    //allocate the memory for the new node. 
    temp->next = node_mem_allocator(data);
    return node; 
}

/*
 * EDT : node_insert_front
 * This API will take the head pointer 
 * and data to be inserted .
 * it will return the new head after the
 * insertion at the front.
 */

node_st_ * 
node_insert_at_front(node_st_ * node,
		  int data) {
     node_st_* temp = NULL;
     temp = node_mem_allocator(data);
     temp->next = node;
     return temp;     
}

/*
 * EDT : node_insert_after_node
 * This API will take a pointer 
 * to the node and will insert the
 * given data after this node.
 */ 
node_st_ *
node_insert_after_node (node_st_ * node,
		        int data) {
    node_st_ * temp = node_mem_allocator(data);
    if(node == NULL) {
       return temp;
    }	   
    temp->next = node->next;
    node->next = temp;
    return node; 
}	

/*
 * EDT : display_linked_list
 * This API will take the head pointer
 * and will display the elements till
 * the end of the list is found.
 */ 
void 
display_linked_list(node_st_ * node) {
    while(node) {
          printf("%d->",node->data);
          node = node->next;
    }
    printf("\n");
}

/*
 * EDT: delete_key_linked_list
 * takes the pointer to the head node
 * and data to be deleted.
 * This API will return the modified head
 * of the tree.
 */ 
node_st_ * 
delete_key_linked_list(node_st_ * node,
		       int data) {
    node_st_ * temp = node,*prev = NULL;
    //Base case when node is empty    
    if(node == NULL) {
       return node;
    }	   
    //If head contains the key to be deleted,
    //delete the head node and return the sub list.
    if(node->data == data) {
       temp = temp->next;
       free(node);
       return temp;
    }	  
    /*
     * Case of second and so on nodes 
     * of linked list.
     * Keep track of previous node i.e head
     * and traverse from 2nd node.
     */  
    prev = node;
    temp = temp->next;
    //If forward node is not Null.
    while(temp != NULL) {
	  //If forward node has data
	  //Free this node.  
          if(temp->data == data) {
	     prev->next = temp->next;
	     free(temp);
	     break;
	  }
	  //shift the previous/forward node by 1.
          prev = temp;
          temp = temp->next;	  
    }	   
    return node;
}	

/*
 * EDT : delete_key_at_pos_linked_list
 * Delete a node when its position is given.
 * This API will first check if list is NULL 
 * or not. 
 * It will further check the head case else
 * it will store the head as previous pointer 
 * and will traverse till next pointer is not 
 * NULL.
 */ 
node_st_ *
delete_key_at_pos_linked_list(node_st_ * node,
		              int pos) {
    int temp_pos = 0;
    node_st_ * temp = node,*prev = NULL;
    //Base case , can't delete from empty node.
    if (node == NULL) {
        return node;
    }	   
    if(temp_pos == pos) {
       temp = temp->next;
       free(node);
       return temp; 
    }	   
    temp_pos++;
    prev = node;
    temp = node->next;
    while(temp != NULL) {
          if(temp_pos == pos) {
	     prev->next = temp->next;
	     free(temp);
	  }	 
	  prev = temp;
	  temp = temp->next;
	  temp_pos++; 
    }	   
    return node; 
}

/*
 * EDT : delete_linked_list
 * This API takes pointer to the 
 * head of the linked list and delete 
 * all the elements of it.
 */ 
void delete_linked_list(node_st_ * tree) {
     node_st_ * temp = NULL;
     while(tree){
           temp = tree;
	   tree= tree->next;
	   free(temp);
     }	   
}

/*
 * EDT : len_linked_list
 * This API will take the head pointer 
 * to the linked list and will return
 * the length of the list.
 */ 
int 
len_linked_list(node_st_ * node) {
    if(node == NULL)
       return 0;
    return len_linked_list(node->next) + 1 ;
}	

/*
 * EDT : key_lookup_linked_list
 * This API will take the head pointer to the 
 * linked list and the key to be found.
 * If key is found , this API will
 * return TRUE else FALSE.
 */ 
bool
key_lookup_linked_list(node_st_ * node,
		       int key) {
    if (node == NULL)
	return false;
    if(node->data == key)
       { return true; }
    else {
       return key_lookup_linked_list(node->next,key);
    }    
}

/*
 * EDT : nth_node_linked_list
 * Return the pointer to the
 * nth node of the linked list from the first.
 */ 
node_st_ * 
nth_node_linked_list(node_st_ * node,
		     int index) {
    int temp_index = 0;	
    if(node == NULL) {
       return node;
    } 	   
    while( node != NULL ) {
           if(temp_index == index) {
	      return node;
	   }	   
	   temp_index ++;
	   node = node->next;
    }	   
    return node; 
}

/*
 * EDT : nth_node_from_last_linked_list
 * This API will take the head pointer 
 * and node psn from the last. 
 */ 
node_st_ * 
nth_node_from_last_linked_list(node_st_ * node,
		               int index) {
    int temp_index = 0 ;
    node_st_ * temp = node;
    if(node == NULL) {
       return node;
    }	    
    while(temp) {
          temp_index++;
	  temp = temp->next;
    }	    
    //Nth node asked is more than the list size.
    if(index > temp_index) {
       return NULL; 
    }	    
    temp_index = temp_index - index;
    temp = node;
    while(temp_index) {
          temp++;
	  temp_index--;
    }	    
    return temp;
}	

/*
 * EDT : nth_node_from_last_linked_list_v2
 * Logic of fast and slow pointer.
 * create the difference of index between slow and fast
 * pointer.
 *
 */ 
node_st_ * 
nth_node_from_last_linked_list_v2 (node_st_ * node,
		                   int index) {
     node_st_ * prev = node,*forw = node;	
     int temp_index = index;
     //Base Case 
     if(node == NULL) 
	return NULL;
     //Create a gap of index b/w prev
     //and forw nodes.
     while(temp_index) {
	   temp_index--;  
           forw = forw->next;
	   if(!forw) {
	      return NULL;
	   }	   
     }
     while(forw->next) {
           prev =prev->next;
	   forw = forw->next;
     }	     
     return prev;
}	

/*
 * EDT : middle_linked_list
 * Approach 1 : Count the length of the linked list
 * and return the length/2 element.
 * Approach 2 : We know that double of a middle lead
 *              to the original value.   
 */
node_st_ *
middle_linked_list(node_st_ * node) {
     // Base case
     if (node == NULL) 
	 return node;
     node_st_ * single = node;
     node_st_ *doubl = node;
     /*
      * Case 1 : When single node is present , it will return
      * the head itself.
      * Case 2 : When there are 2 nodes , it will return the 
      *          second node .
      * Case 3 : When there are 3 nodes , it will return the 
      * second node. 
      */
     while (doubl != NULL && doubl->next != NULL) {
            doubl = doubl->next->next;
	    single = single->next; 
     }
     return single;     
}

/*
 * EDT : find_key_inst_linked_list
 * This API will take the head pointer 
 * as well as the key whose instances to be found
 */ 
int 
find_key_inst_linked_list(node_st_ * node, int key) {
    if (node == NULL)
	return 0;
    if (node->data == key) {
        return find_key_inst_linked_list(node->next,key) + 1;
    } else {
       return find_key_inst_linked_list(node->next,key);   
    }   
}	

/*
 * EDT : node_not_in_hash
 * Given a linked list, and 
 * hash table , this will return 
 * true or false, if node is 
 * found in hash.
 */ 
bool 
node_not_in_hash(node_st_ * node, hash_node_ * hash) {
    int temp = count;
    while (temp) {
      if (node == hash[temp].addr) {
          return false;
      }
      temp--;      
    }
    return true;
}

/*
 * EDT : Insert a node in hash
 * Given a node pointer , it 
 * will store the address in hash.
 */ 

void 
insert_in_hash(node_st_ * node, 
	       hash_node_ * hash,
	       int len) {
    hash[count].addr = node;
    count++;
}
/*
 * Detect loop in 
 * the linked list.
 * v2 : It can also be found 
 * via tortoise-hare[Floyd cycle algo.]
 */ 

bool 
is_loop_linked_list(node_st_ * node) {
    if (node == NULL) return false;

    int len = len_linked_list(node);
    hash_node_ hash[len];
    while(node) {
          if(node_not_in_hash(node,hash)) {
	     insert_in_hash(node,hash,len);
	     node = node->next;
	  }else {
	     return true;
	  }	  
    }
    return false;
}

int 
len_loop_linked_list(node_st_ * node) {
    //Use is_loop_linked_list and 
    //set a global variable to temp.
    //Return the temp as size of loop
}

bool
helper_func(node_st_ ** node , node_st_ * child) {
     bool flag ; 
     if(child == NULL)
	 return true;     
     flag = helper_func(node,child->next);
     if (flag == true) {
	 bool temp = (child->data == (*node)->data) ;   
         *node = (*node)->next;
	 return temp;
     }
     return flag;     
}

/*
 * EDT : is_linked_list_palindrome()
 * Approach 1 : Add all the elements in the stack
 *              Now Start traversing linked list again,
 *              popping and comparing at each access .
 *              If there is mismatch , terminate.
 * Approach 2 : Use the following logic ; pass the reference
 *              to head till end of linked list is found.
 *              If found , then the last container will have the
 *              reference to head as well as the last node.
 *              check for the data , and change the reference to 
 *              head->next.              
 *              https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
 * Approach 3 : From the middle , reverse the partial list 
 * 		and compare with the first half.
 * 		After comparison , reverse again and attach to the original list.   
 * 		(To Do.)          
 */ 
bool 
is_linked_list_palindrome(node_st_* node) {
    //return helper_func(&node,node);     
    node_st_ * slow_ptr = node;
    node_st_ * fast_ptr = node;
    if(slow_ptr == NULL)
       return false;
    /*
     * Logic to reach the middle of linked-list.
     * Store each element traversed by slow-ptr
     * in stack.
     */ 
    while (fast_ptr != NULL &&
	   fast_ptr->next != NULL) {
	   stack_arr[stack_index] = slow_ptr->data;
           slow_ptr = slow_ptr->next;
	   fast_ptr = fast_ptr->next->next;
	   stack_index++;
    }
    /*
     * Detect the odd-even length of the linked list.
     * If list is even-length , then fast_ptr will be null.
     * If list is odd_length, then fast_ptr will not be null,
     * shift the slow_ptr from middle to next of middle.
     */ 
    if(fast_ptr != NULL && fast_ptr->next == NULL)	    
       slow_ptr = slow_ptr->next;
    //Decreement the stack index. 
    stack_index--;	    
    while(slow_ptr != NULL && stack_index != -1){
          if(slow_ptr->data != stack_arr[stack_index])
	     return false;
          slow_ptr = slow_ptr->next;
	  stack_index--;	  
    }
    return true;    
    // start from slow ptr and pop from stack and match it.   
}

/*
 * To-do 
 * Swap nodes without exchanging 
 * the data elements.
 */ 

/*
 * EDT : last_node_to_front_linked_list
 */ 
node_st_ *
last_node_to_front_linked_list(node_st_ * node) {
    if (node == NULL)
	return node;
    if (node->next == NULL)
	return node;

    node_st_ * prev = node;
    node_st_ * next = node->next->next;
    while(next != NULL) {
          prev = prev->next;
	  next = next->next;
    }	   
    node_st_ * head = prev->next;
    prev->next = NULL;
    head->next = node;
    return head;
}

/*
 * EDT : intersection_linked_lists
 * Assumption that node indeed merges
 */ 

bool
intersection_linked_lists(node_st_ * node1,
		          node_st_ * node2) {
     int index = 0;
     if (node1 == NULL)
         return false;
     if (node2 == NULL)
	 return false;     
     int len_node1 = len_linked_list(node1);
     int len_node2 = len_linked_list(node2);
     if ((len_node1 - len_node2) > 0 ){
	 for(index; index < (len_node1- len_node2);index++) {
	     node1 = node1->next;
	 }	 
         while((node1 != node2) && 
		(node1 != NULL && node2 != NULL)) {
	       node1++;
	       node2++;
	 }
	 if (!node1 || !node2) {
	     return false;
	 }
         return true;	 
     } else if((len_node2 - len_node1) > 0){
        for(index; index < (len_node2 - len_node1);index++) {
	     node2 = node2->next;
	 }	 
         while(node1 != node2 && node1 && node2) {
	       node1++;
	       node2++;
	 }
         if(!node1 != !node2) 
	    return false;
	 return true;
     } else {
	while(node1 != node2 && node1 && node2) {
	      node1++;
	      node2++;
	}
	if(!node1 || !node2) 
	   return false;
	return true;
     }	     
}
node_st_ * 
odd_even_linked_list (node_st_ ** node) { 
      node_st_ * odd_start = NULL,*odd_end ;
      node_st_ *even_start = NULL,*even_end;
      if (*node == NULL)
	  return *node;
      while (*node != NULL) {
             if(((*node)->data % 2) == 0) {
	         if(even_start == NULL) {
		    even_start = *node;
		    even_end = *node;
		 } else {
		   even_end->next = *node;
		   even_end = even_end->next;
		 }
	     } else {
	         if (odd_start == NULL) {
		     odd_start = *node;
		     odd_end = *node;
		 } else {
		     odd_end->next = *node;
		     odd_end = odd_end->next;
		 }	 
	     }
             (*node) = (*node)->next;	     
      }	     
      if (even_start == NULL) 
          return odd_start;
      if (odd_start == NULL)
	  return even_start;
      odd_end->next = NULL;
      even_end->next = odd_start;
      return even_start;
}

/*
 * Reversal of linked list with
 * 2 temp variables only.
 */ 
node_st_ *
reverse_linked_list(node_st_ * node) {
    if (node == NULL)
	return node;
    if (node->next == NULL)
	return node;
    node_st_ *temp = NULL , *last = NULL;// *next = node->next;
    last = node;
    node = node->next;
    last->next = NULL;
    while(node != NULL) {
          temp = node->next;
	  node->next = last;
	  last = node; 
	  node = temp;
    }
    return last;    
}

static void 
print_reverse_linked_list (node_st_ * node) {
     if(node == NULL)
	return;
     print_reverse_linked_list(node->next);
     printf("%d->",node->data);
}

node_st_ *
swap_linked_list(node_st_ * head, int key1 ,int key2){
    node_st_ * ptr1 = NULL,*prev1 = NULL;
    node_st_ * ptr2 = NULL, *prev2 = NULL;
    node_st_ * temp = NULL;
    ptr1 = head;
    ptr2 = head;
    if(head == NULL )
       return head;
    if(key1 == key2)
       return head;	    
    while(ptr1 != NULL && ptr1->data != key1){
          prev1 = ptr1;
	  ptr1 = ptr1->next;
    }
    while(ptr2 != NULL && ptr2->data != key2){
          prev2 = ptr2;
	  ptr2 = ptr2->next;
    }
    if(ptr1 == NULL || ptr2 == NULL)
       return head;
    if(prev1 == NULL){
       prev2->next = ptr2->next;
       ptr2->next = head->next;
       head = ptr2;
       return head;
    }
    if(prev2 == NULL){
       prev1->next = ptr1->next;
       ptr1->next = head->next;
       head = ptr1;
       return head;
    }
    prev1->next = ptr2;
    temp = ptr2->next;
    ptr2->next = ptr1->next;
    prev2->next = ptr1;
    ptr1->next = temp;
    return head;   
}	

int main (void) {
    node_st_ * head = NULL;
    head = node_insert_at_front(head,5);
    head = node_insert_at_front(head,10);
    head = node_insert_at_front(head,15);
    head = node_insert_at_front(head,20);
    head = node_insert_at_front(head,25);
    display_linked_list(head);
    //head = delete_key_at_pos_linked_list(head,2);
    //head = delete_key_at_pos_linked_list(head,5);
    //head = delete_key_at_pos_linked_list(head,15);
    //head = delete_key_at_pos_linked_list(head,10);
    //delete_linked_list(head);
    //head = NULL;
    printf("List length is %d \n",len_linked_list(head));
    head = swap_linked_list(head,20,10);
    //node_st_ * mid = middle_linked_list(head);
   // printf("Mid element is %d\n",mid->data);
   // printf("Instances of 2 found are : %d\n",find_key_inst_linked_list(head,2));
    //printf("Loop found is %s\n",is_loop_linked_list(head) ? "TRUE":"FALSE");
    //printf("Palindrome found is %s\n",is_linked_list_palindrome(head) ? "TRUE":"FALSE");
    //head = last_node_to_front_linked_list(head);
    display_linked_list(head);
    //head = odd_even_linked_list(&head);
    //display_linked_list(head);
    //print_reverse_linked_list(head); 
    //head = reverse_linked_list(head);
    //display_linked_list(head); 
}
