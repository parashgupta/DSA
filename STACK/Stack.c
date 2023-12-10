#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CAPACITY 5
void push(int);
int pop();
int peek();
bool isEmpty();
void showALL();
int stack[CAPACITY];
int top=-1;
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
	if(top==CAPACITY-1)
	{
		printf("Stack is Overflow\n");
		return;
	}
	stack[++top] = x;
}

int pop()
{
	if(isEmpty())
	{
		printf("Stack is Empty\n");
		exit(0);
	}
	return stack[top--];
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n\n");
		exit(0);
	}
	return stack[top];
}

bool isEmpty()
{
	if(top==-1) return true;
	return false;
}

void showALL()
{
	if(isEmpty())
	{
		printf("Stack is Empty\n");
		return;
	}
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
	printf("\n\n");
}