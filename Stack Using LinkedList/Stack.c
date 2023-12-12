#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void push(int);
int pop();
int peek();
bool isEmpty();
void showALL();

struct Node
{
	int data;
	struct Node *next;
};
	struct Node *top=NULL;

void main()
{
	int x,c;
	do
	{
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEK\n");
		printf("4. ISEMPTY\n");
		printf("5. SHOWALL\n");
		printf("6. EXIT\n\n");
		printf("Enter Your Choice\n ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
					printf("Enter Data\n");
					scanf("%d",&x);
					push(x);
					printf("\n");
					break;
			case 2:
					printf(" Element %d is deleted\n ",pop());
					printf("\n");
					break;
			case 3:
					printf("%d\n",peek());
					printf("\n");
					break;
			case 4:
					// isEmpty();
					printf("%s\n",isEmpty()?"true":"false");
					printf("\n");
					break;
			case 5:
					showALL();
			case 6: break;
			default : printf("Invalid Choice\n");
		}
	}while(c!=6);
}

void push(int x)
{
	struct Node *temp = malloc(sizeof(struct Node));
	if(temp == NULL)
	{
		printf("No Space Available....");
	}
	else
	{
		temp->data = x;
		temp->next=top;
		top = temp;
	}
}

int pop()
{
	if(isEmpty())
{
	printf("Stack is Empty");
	exit(0);
}
	struct Node *temp = top;
	int a = temp->data;
	top = top->next;
	free(temp);
	return a;
}

int peek()
{
	if(isEmpty())
{
	printf("Stack is Empty");
	exit(0);
}
	return top->data;
}

bool isEmpty()
{
	if(top==NULL) return true;
	return false;
}

void showALL()
{
	if(isEmpty())
	{
		printf("Stack is Empty\n");
		return;
	}
	struct Node *temp = top;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp= temp->next;
	}
	printf("\n\n");
}