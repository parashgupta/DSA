#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CAPACITY 5
void enqueue(int);
int dequeue();
int peek();
bool isEmpty();
bool isFull();
void showALL();

int Queue[CAPACITY];
int f=-1;
int r=-1;

void main()
{
	int x,c;
	do
	{
		printf("1. ENQUEUE\n");
		printf("2. DEQUEUE\n");
		printf("3. PEEK\n");
		printf("4. ISEMPTY\n");
		printf("5. ISFULL\n");
		printf("6. SHOWALL\n");
		printf("7. EXIT\n\n");
		printf("Enter Your Choice\n ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
					printf("Enter Data\n");
					scanf("%d",&x);
					enqueue(x);
					printf("\n");
					break;
			case 2:
					printf(" Element %d is deleted\n ",dequeue());
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
			// isEmpty();
			printf("%s\n",isFull()?"true":"false");
			printf("\n");
			break;
			case 6:
					showALL();
			case 7: break;
			default : printf("Invalid Choice\n");
		}
	}while(c!=7);
} 

void enqueue(int x)
{
	if(isFull())
	{
		printf("Queue is Full\n");
		return;
	}
	if(f==-1) f++;
	Queue[++r] = x;
}

int dequeue()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		exit(0);
	}
	return Queue[f++];
}

int peek()
{
	if(isEmpty())
	{
		printf("Queue is empty\n\n");
		exit(0);
	}
	return Queue[f];
}

bool isEmpty()
{
	if(f==-1 || f>r) return true;
	return false;
}

bool isFull()
{
	if(r==CAPACITY-1) return true;
	return false;
}

void showALL()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return;
	}
	for(int i=f;i<=r;i++)
	{
		printf("%d\t",Queue[i]);
	}
	printf("\n\n");
}