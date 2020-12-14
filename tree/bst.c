#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} node;

void display_tree(node* node, int* list, int* index)
{
	if (node)
	{
		display_tree(node->left, list, index);
		printf("%d  ",node->data);
		list[*index] = node->data;
		*index = *index + 1;
		display_tree(node->right, list, index);
	}
}

void printInorderWOrec(node* root)
{
	int done = 0;
	node* temp = NULL;

	if(NULL == root)
	{	
		printf("Empty node received");
		return;
	}

	while(!done)
	{
		if(root)
		{
			push(stack, root);
			root = root->left;
		}
		else
		{
			if(stack)
			{
				temp = pop(stack);
				printf("%d ",temp->data);

				root = temp->right;
			}
			else
				done = 1;
		}
	}
}

void display_tree_pre(node* node)
{
	if (node)
	{
		printf("%d  ",node->data);
		display_tree_pre(node->left);
		display_tree_pre(node->right);
	}
}
void search_tree(node* root, int data)
{
	if(root == NULL)
	{
		printf("\n Node with value %d not found",data);
		return;
	}

	if(root->data == data)
	{
		printf("\n Node with value %d found",data);
		return;
	}

	if(data > root->data)
		search_tree(root->right, data);
	
	if(data < root->data)
		search_tree(root->left,data);
}

void insert_node(node** root, int data)
{
	if(*root == NULL)
	{
		node* temp = NULL;
		temp = malloc(sizeof(node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
		return;
	}

	if(data < (*root)->data)
	{
		insert_node(&((*root)->left), data);
		return;
	}
	if(data > (*root)->data)
	{
		insert_node(&((*root)->right), data);
		return;
	}

	return;
}

node* node_successor(node* root)
{
/*	node* temp =NULL;
	while(root)
	{
		temp = root;
		root = root->left;
	}
	return temp;*/
	if(root->left == NULL)
		return root;
	
	return node_successor(root->left);
}
node* delete_node(node* root, int data)
{
	if(root == NULL)
		return root;
	
	if (data > root->data)
		root->right = delete_node(root->right, data);
	else if(data < root->data)
		root->left = delete_node(root->left, data);
	else {
		node* temp_node = NULL;
		if(root->left ==NULL)
		{
			temp_node = root->right;
			free(root);
			return temp_node;
		}
		else if(root->right ==NULL)
		{
			temp_node = root->left;
			free(root);
			return temp_node;
		}
		else
		{
			temp_node = node_successor(root->right);
			root->data = temp_node->data;
			root->right = delete_node(root->right, root->data);
		}
	}
	return root;
}

int getHeight(node* root)
{
	int lheight = 0;
	int rheight = 0;

	if(root == NULL)
		return 0;
	else
	{
		lheight = getHeight(root->left);
		rheight = getHeight(root->right);

		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}

void printThisLevel(node *root, int level)
{
	if(root == NULL)
	{
		printf(" null");
		return;
	}
	
	if(level == 1)
	{
		if(root)
			printf(" %d", root->data);
		else
			printf(" null");
	}
	
	else if(level>1)
	{
		printThisLevel(root->left, level-1);
		printThisLevel(root->right, level-1);
	}
}

void printLevelOrder(node* root)
{
	int height = getHeight(root);
	int i = 0;

	for(i = 1; i<=height; i++)
	{
		printThisLevel(root, i);
	}
}

node* makeAvlTree(int* list, int start, int end)
{
	if(start>end)
		return NULL;

	node* root = NULL;
	int mid = 0;

	root = malloc(sizeof(node));

	mid = (start+end)/2;

	root->data = list[mid];
	root->left = makeAvlTree(list, start, mid-1);
	root->right = makeAvlTree(list, mid+1, end);

	return root;
}

void main()
{
	node *root = NULL;
	node* avlRoot = NULL;
	int list[10];
	int height = 0;
	int* listLen = NULL;

	listLen = malloc(sizeof(int));
	*listLen = 0;

	//display_tree(root);
	insert_node(&root, 70);
	insert_node(&root, 60);
	insert_node(&root, 50);
	insert_node(&root, 40);
	insert_node(&root, 30);
	insert_node(&root, 20);
//	insert_node(&root, 10);
	printf("\n");
	display_tree_pre(root);
	display_tree(root, list, listLen);

	printf("\nNumber of elements = %d", *listLen);

//	search_tree(root, 10);
//	search_tree(root, 1);

	printf("\n");
//	display_tree(root);
//	root = delete_node(root, 40);
//	printf("\n");
//	display_tree(root);

	height = getHeight(root);

	printf("\n Height of tree = %d\n", height);

	avlRoot = makeAvlTree(list, 0, *listLen-1);

	printf("\n Balanced tree = ");
	display_tree_pre(avlRoot);
//	insert_node(&root, 5);
	//printLevelOrder(root);
}
