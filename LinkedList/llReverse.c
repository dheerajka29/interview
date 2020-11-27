#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	int data;
	} node;

void addNode(node** head, int data)
{
	node* temp = NULL;

	temp = malloc(sizeof(node));

	temp->data = data;
	temp->next = *head;

	*head = temp;
}

void printLL(node* head)
{
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}

	printf("\n");
}

void reverseLL(node** head)
{
	node* curr = *head;
	node* prev = NULL;;
	node* next = curr->next;

	while(next)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}




void main()
{
	node* head = NULL;

	addNode(&head, 1);
	addNode(&head, 2);
	addNode(&head, 3);
	addNode(&head, 4);
	addNode(&head, 5);
	
	printLL(head);

	reverseLL(&head);

	printLL(head);
}
