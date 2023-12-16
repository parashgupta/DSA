#include<stdio.h>
#include<stdbool.h>
#define CAPACITY 20

void push(char);
char pop();
char peek();
bool isEmpty();
int pr(char);

char stack[CAPACITY];
int top = -1;

void main()
{
	char input[CAPACITY];
	char output[CAPACITY];

	printf("Enter Any Expression\n");
	scanf("%s",input);
	
	int i=0,k=0;
	
	while(input[i]!='\0')
	{
		if(input[i]=='(')
			{
				push(input[i]);
			}
			else
			{
				if(input[i]>='A' && input[i]<='Z')
				{
					output[k++] = input[i];
				}
			
			else if(input[i]==')')
			{
			while(peek()!='(')
			{
				output[k++] = pop();
			}
				pop();
			}
			else
			{
				while(pr(peek())>=pr(input[i]))
				{
					output[k++] = pop();
				}
				push(input[i]);
			}
						
		}
		i++;
	}
	output[k++]= '\0';
	printf("%s\n",output);
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

int pr(char x)
{
	switch(x)
	{
		case '(': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
	}
}