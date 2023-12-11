#include<stdio.h>
#include<stdbool.h>
#define CAPACITY 20

void push(char);
char pop();
char peek();
bool isEmpty();

char stack[CAPACITY];
int top = -1;

void main()
{
	int i=0;
	char input[CAPACITY];
	printf("Enter Any Expression\n");
	scanf("%s",input);
	
	while(input[i]!='\0')
	{
		if(input[i]=='('||input[i]=='{'||input[i]=='[')
			{
				push(input[i]);
			}
	else if(input[i]==')'||input[i]=='}'||input[i]==']')
		{
			if(isEmpty())
			{
				top=1;
				break;
			}
			if(input[i]==')')
			{
				if(peek()=='(')
				{
				pop();	
				}
				else break;
			}
			if(input[i]=='}')
			{
				if(peek()=='{')
				{
				pop();	
				}
				else break;
			}
			if(input[i]==']')
			{
				if(peek()=='[')
				{
				pop();	
				}
				else break;
			}
		}
		i++;
	}
	if(isEmpty())
	{
		printf("Correct Expression\n");
	}
	else
	{
		printf("In-Correct Expression\n");
	}
}

void push(char x)
{
	if(top==CAPACITY-1)
	{
		printf("Stack is Overflow\n");
		return;
	}
	stack[++top]=x;
}

char pop()
{
	return stack[top--];
}
char peek()
{
	return stack[top];
}

bool isEmpty()
{
	if(top==-1)return true;
	return false;
}

