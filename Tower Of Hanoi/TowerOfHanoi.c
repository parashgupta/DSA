#include<stdio.h>
void show(int,char,char,char);
void main()
{
	show(3,'A','C','B');
}
void show(int n,char s,char d,char t)
{
	if(n==1)
	{
		printf("Move disk %d from %c => %c\n\n",n,s,d);
	}
	else 
	{
		show(n-1,s,t,d);
		printf("Move disk %d from %c => %c\n\n",n,s,d);
		show(n-1,t,d,s);
	}
}