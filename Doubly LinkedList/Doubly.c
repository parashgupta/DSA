#include<stdio.h>
#include<stdlib.h>
void insertAtB(int);
void insertAtE(int);
void insertAtSP(int ,int);
void deleteAtB();
void deleteAtE();
void deleteAtSP(int);
int CountNode();
int SearchNode(int);
void revshow();
void showAll();

struct Node
{
int data;
struct Node *next;
struct Node *prev;
};
struct Node *start=NULL;

void main()
{
	int c,x,p;
	do
	{
	printf("\n1. Insert At Beginning\n");	
	printf("2. Insert At Ending\n");	
	printf("3. Insert At Specific Position\n");
	printf("4. delete At Beginning\n");	
	printf("5. delete At Ending\n");	
	printf("6. delete At Specific Position\n");	
	printf("7. Count Node\n");
	printf("8. Search Node\n");
	printf("9. Show All\n");
	printf("10. Show reverse\n");
	printf("11. Exit\n\n");
	printf("Enter Your Choice\n");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:
		printf("Enter Data\n");
		scanf("%d",&x);
		insertAtB(x);
		printf("\n");
		break;
		case 2:
		printf("Enter Data\n");
		scanf("%d",&x);
		insertAtE(x);
		printf("\n");
		break;
		case 3: 
		printf("Enter Position\n");
		scanf("%d",&p);
		printf("Enter Data\n");
		scanf("%d",&x);
		insertAtSP(p,x); 
		break;
		case 4: 
			   deleteAtB(); 
			   break;
		case 5: 
			deleteAtE(); 
			break;
		case 6: 
		printf("Enter Position\n");
		scanf("%d",&p);
		deleteAtSP(p); 
		break;
		case 7:  
		printf("Total Nodes %d\n",CountNode());
		  break;
		case 8: 
		printf("Enter Data\n");
		scanf("%d",&x);
		printf("Node At %d position\n",SearchNode(x));
		break;		
		case 9: showAll(); break;
		case 10:  revshow(); break;
		case 11: break;
		default: printf("Invalid Choice\n");
	}
	}while(c!=11);
}

void insertAtB(int x)
{
	struct Node *temp = malloc(sizeof(struct Node));
	if(temp== NULL)
	{
		printf("No Space");
		return;
	}
	temp->data = x;
	temp->next = start;
	temp->prev = NULL;
	if(start!=NULL) start->prev = temp;
	start = temp;
}

void insertAtE(int x)
{
	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	
	struct Node *temp = malloc(sizeof(struct Node));
	if(temp == NULL)
	{
		printf("No Space");
		return;
	}
	temp->data = x;
	temp->next = NULL;
	struct Node *temp2 =start;
	while(temp2->next!=NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
	temp->prev = temp2;
}

void insertAtSP(int p,int x)
{
	if(p<=1)
	{
		insertAtB(x);
		return;
	}
	if(p>CountNode())
	{
		insertAtE(x);
		return;
	}
	struct Node *temp = malloc(sizeof(struct Node));
	struct Node *temp2 = start;
	
	for(int i=1;i<p-1;i++)
	{
		temp2 = temp2->next;
	}
	temp->data =x;
	temp->next = temp2->next;
	temp2->next->prev = temp;
	temp->prev = temp2;
	temp2->next = temp;
}

void deleteAtB()
{
	if(start == NULL)
	{
		printf("List is Empty\n");
		return;
	}
		struct Node *temp =start;
		if(start->next!=NULL) start->next->prev = NULL;
		start = start->next;
		free(temp);
}
		

void deleteAtE()
{
	if(start==NULL || start->next==NULL)
	{
		deleteAtB();
		return;
	}
	struct Node *temp = start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
	printf("Node Deleted Successfully\n");
}

void deleteAtSP(int p)
{
	if(p<=1)
	{
		deleteAtB();
		return;
	}
	if(p>CountNode())
	{
		deleteAtE();
		return;
	}
		struct Node *temp = start;
		for(int i=1;i<p;i++)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);

}

int CountNode()   //Count Node
{
	int c=0;
	struct Node *temp = start;
	while(temp!=NULL)
	{
		temp = temp->next;
		c++;
	}
	return c;
}

void showAll()
{
	if(start == NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp = start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

void revshow()
{
	if(start == NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp = start;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->prev;
	}
	printf("\n\n");
}

int SearchNode(int x)
{
	int index=-1;
	if(start==NULL) return index;
	struct Node *temp =start;
	while(temp!=NULL)
	{
		index++;
		if(temp->data==x) return index;
		temp= temp->next;
	}
	return -1;
}