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
void showAll();
void showAll2(int);
struct Node
{
int data;
struct Node *next;
}; 
struct Node *start=NULL;
struct Node *end=NULL;

void revshow()
{
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct Node *temp1 = start;
	struct Node *temp2=start;
	do
	{
		do
		{
			temp1 = temp1->next;
		}while(temp1->next!=temp2);
			printf("%d\t",temp1->data);
		temp2= temp1;
		temp1 = start;
	}while(temp2!=start);
}

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
	printf("7. Show All\n");
	printf("8. Show reverse\n");
	printf("9. Count Node\n");
	printf("10. Search Node\n");
	printf("11. Show All2\n");
	printf("12. Exit\n\n");
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
		
		case 4: deleteAtB(); break;
		case 5: deleteAtE(); break;
		
		case 6: 
		printf("Enter Position\n");
		scanf("%d",&p);
		deleteAtSP(p); 
		break;
		case 7: showAll(); break;
		case 11: 
			printf("Enter Data\n");
			scanf("%d",&x);
			showAll2(x); 
			break;
		case 8: revshow(); break;
		case 9: 
		printf("Total Nodes = %d\n",CountNode()); 
		break;
		case 10:
		printf("Enter Data\n");
		scanf("%d",&x);
		printf("Node At %d position\n",SearchNode(x));
		break;
		
		case 12: break;
		default: printf("Invalid Choice\n");
	}
	
	}while(c!=12);
}

void insertAtB(int x)  //Insert At Beginning
{
	struct Node *temp = malloc(sizeof(struct Node));
	if(temp == NULL)
	{
		printf("No Space Available....");
		return;
	}
	temp->data=x;
	if(start==NULL)
	{
		start=end=temp->next=temp;
		return;
	}
	temp->next=start;
	start = end->next = temp;
}

void insertAtE(int x)  //Insert At Ending
{
	if(start == NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node *temp = malloc(sizeof(struct Node));
	if(temp == NULL)
	{
		printf("No Space Available....");
		return;
	}
	temp-> data = x;
	temp-> next = start;
	end->next = end = temp;
}

void insertAtSP(int p,int x)   //insert at specific Position
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
	if(temp == NULL)
	{
		printf("No Space Available....");
		return;
	}
	temp->data = x;
	struct Node *temp2 = start;
	for(int i=1;i<p-1;i++)
	{
	temp2 = temp2->next;	
	}
	temp->next = temp2->next;
	temp2->next = temp;
}

void deleteAtB()  //Delete At Beginning
{
if(start==NULL)
{
	printf("List is Empty");
	return;
}	
	struct Node *temp = start;
	start = start->next;
	end->next=start;
	if(start==end)
	{
		start=NULL;
		end=NULL;
	}
	free(temp);
}

void deleteAtE()   //Delete At Ending
{
	if(start==NULL || start==end)// || start->next==NULL)
	{
		deleteAtB();
		return;
	}
	struct Node *temp = start;
	struct Node *temp2=end;
	while(temp->next!=end)
	{
		temp = temp->next;
	}
	temp->next = start;
	end= temp;
	free(temp2);
}

// void deleteAtE()    //Delete at Ending
// {
	// if(start==NULL || start->next==NULL)
	// {
		// deleteAtB();
		// return;
	// }
	// struct Node *temp = start;
	// while(temp->next->next!=NULL)
	// {
		// temp = temp->next;
	// }
	// free(temp->next);
	// temp->next = NULL;

// }


int CountNode()   //Count Node
{
	int c=0;
	if(start==NULL) return c;
	struct Node *temp = start;
	do
	{
		temp = temp->next;
		c++;
	}while(temp!=start);
	return c;
}


void deleteAtSP(int p)  //Delete At Specific Position
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
		struct Node *temp2;
	for(int i=1;i<p;i++)
	{
		temp2= temp;
		temp = temp->next;	
	}
	temp2->next = temp->next;
	free(temp);
}



int SearchNode(int x)   //search node
{
	int index=-1;
	if(start==NULL) return index;
	struct Node *temp =start;
	do
	{
		index++;
		if(temp->data==x) return index;
		temp= temp->next;
	}while(temp!=start);
	return -1;
}

void showAll()    //display
{
	if(start == NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp = start;
	do
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}while(temp!=start);
	printf("\n\n");
}

void showAll2(int x)  
{
	if(start == NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp = start;
	while(temp->data!=x)
	{
		temp = temp->next;
		if(temp==start)
		{
			printf("data not found\n");
			return;
		}
	}
	struct Node *temp2= temp;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}	while(temp!=temp2);
	printf("\n\n");
}