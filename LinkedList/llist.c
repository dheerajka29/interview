#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node* next;
	} node;


void display_list(node* head)
{
	if (NULL==head)
	{
		printf("List is empty");
		return;
	}
	while (head)
	{
		printf(" data is %d\n",head->data);
		head = head->next;
	}
}

void append_node(node** head, int data)
{
	node* temp = NULL;
	node* temp_head = NULL;

	temp = malloc(sizeof(node));
	temp_head = *head;

	temp->data = data;
	temp->next = NULL;

	if(NULL == temp_head)
	{
		*head = temp;
		return;
	}

	while(temp_head->next)
	{
		temp_head = temp_head->next;
	}

	temp_head->next = temp;
}
	
void ll_rev(node** head)
{
	if(((*head) == NULL) && ((*head)->next == NULL))
		return;

	node* curr = NULL;
	node* prev = NULL;
	node* next = NULL;

	curr = *head;
	prev = NULL;
	next = curr->next;

	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;

}

bool recursive_loop(node** node_ref, node* node)
{
	if(NULL == node)
	{
		return true;
	}

	bool flag = recursive_loop(node_ref, node->next);

	if(flag ==true)
	{
		if(node->data ==(*node_ref)->data)
		{
			*node_ref = (*node_ref)->next;
			return true;
		}
	}
	return false;
}
			

bool isPalindrome(node* head)
{
	if (head == NULL)
	{
		return false;
	}

	return recursive_loop(&head, head);
}

void removeLoop(node** head, node* slow)
{
	int count = 1;
	node* ptr1 = NULL;
	node* ptr2 = NULL;

	ptr1 = slow;
	ptr2 = slow;

	while(ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		count++;
	}

	printf("\n Length of Loop = %d", count);
	ptr1 = *head;
	ptr2 = *head;

	while(count)
	{
		ptr2 = ptr2->next;
		count--;
	}

	printf(" here");
	while(ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	while(ptr2->next != ptr1)
	{
		ptr2 = ptr2->next;
	}

	ptr2->next = NULL;

	printf("\n Loop removed successfully");
}
void detectAndRemoveLoop(node** head)
{
	node* fast = NULL;
	node* slow = NULL;

        fast = *head;
	slow = *head;
	while(slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			printf("\n Loop found, proceeding to removal");
			removeLoop(head, slow);
			return;
		}
	}

	printf("\n Loop not found");
}
void main()
{
	node* temp = NULL;

	append_node( &temp, 5);
	append_node( &temp, 10);
	append_node( &temp, 15);
	append_node( &temp, 20);
	append_node( &temp, 25);
	append_node( &temp, 20);
	append_node( &temp, 15);
	append_node( &temp, 10);
	append_node( &temp, 5);

	display_list(temp);

	ll_rev(&temp);

	printf("Reversed List is\n");
	display_list(temp);

	if(isPalindrome(temp))
		printf("\n List is Palindrome");
	else
		printf("\n List is not palindrome");

	temp->next->next->next->next->next = temp->next->next;

	detectAndRemoveLoop(&temp);
	display_list(temp);
}

 	
