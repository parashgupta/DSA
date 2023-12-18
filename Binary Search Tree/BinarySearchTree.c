#include<stdio.h>
#include<stdlib.h>
struct Node *insert(struct Node*,int);
void showAll(struct Node*);

struct Node
{
int data;
struct Node *left;	
struct Node *right;	
};

struct Node *root = NULL;

void main()
{
root = insert(root,10);
insert(root,5);
insert(root,15);
insert(root,2);
insert(root,1);
showAll(root);
}	

struct Node *insert(struct Node *temp,int x)
{
	if(temp==NULL)
	{
		temp = malloc(sizeof(struct Node));
		temp->data = x;
		temp->left = temp->right=NULL;
	}
	else if(x<temp->data)
	{
		temp->left  = insert(temp->left,x);
	}
	else if(x>temp->data)
	{
		temp->right  = insert(temp->right,x);
	}
	return temp;
}

void showAll(struct Node *temp)  //In Order Traversing
{
		if(temp==NULL) return;
		showAll(temp->left);
		printf("%d\n",temp->data);
		showAll(temp->right);
}

// void showAll(struct Node *temp)  //Pre Order Traversing
// {
		// if(temp==NULL) return;
		// printf("%d\n",temp->data);
		// showAll(temp->left);
		// showAll(temp->right);
// }

// void showAll(struct Node *temp)  //Post Order Traversing
// {
		// if(temp==NULL) return;
		// showAll(temp->left);
		// showAll(temp->right);
		// printf("%d\n",temp->data);
// }