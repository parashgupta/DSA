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
void reverseList();
struct Node *reverse (struct Node *start, int k);
struct Node
{
int data;
struct Node *next;
};
struct Node *start=NULL;

// void revshow(struct Node *temp) //reverse print by using recursion
// {
	// if(temp==NULL) return;
	// revshow(temp->next);
	// printf("%d\t",temp->data);
// }

void revshow()  //reverse print by using Loops
{
struct Node *temp1 = start;
struct Node *temp2 = NULL;	
while(temp1!=NULL)
{
	while(temp1->next!=temp2)
	{
		temp1 = temp1->next;
	}
	printf("%d\t",temp1->data);
	temp2=temp1;
	temp1=start;
	if(temp2==start)break;
}
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
	printf("11. Reverse List\n");
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
		case 8: revshow(start); break;
		case 9: 
		CountNode(); 
		break;
		case 10:
		printf("Enter Data\n");
		scanf("%d",&x);
		printf("Node At %d position\n",SearchNode(x));
		break;
		
		case 11:  reverseList();
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
	else
	{
		temp->data = x;
		temp->next=start;
		start = temp;
	}
}

void insertAtE(int x)  //Insert At Ending
{
	if(start == NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node *temp = malloc(sizeof(struct Node));
	temp-> data = x;
	temp-> next = NULL;
	struct Node *temp2 = start;
	while(temp2->next!=NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next =temp;
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
	free(temp);
}

void deleteAtE()   //Delete At Ending
{
	if(start==NULL || start->next==NULL)
	{
		deleteAtB();
		return;
	}
	struct Node *temp = start;
	struct Node *temp2;
	while(temp->next!=NULL)
	{
		temp2 =temp;
		temp = temp->next;
	}
	temp2->next = NULL;
	free(temp);
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
	struct Node *temp = start;
	while(temp!=NULL)
	{
		temp = temp->next;
		c++;
	}
	printf("%d\n\n",c);
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

void showAll()
{
	if(start == NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp = reverse(start,4);
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

void reverseList()
{
		struct Node *temp1 = start;
		struct Node *temp2 = NULL;
		struct Node *temp3;
		while(temp1!=NULL)
		{
			temp3 = temp1->next;
			temp1->next = temp2;
			temp2 = temp1;
			temp1 = temp3;
		}
		start = temp2;
}
struct Node *reverse (struct Node *start, int k)
    { 
        // Complete this method
        if(k==1 || start==NULL) return start;
        struct Node *head=start;
		int c=1;
		int p=CountNode()/k;
		struct Node *temp1 = start;
		struct Node *temp2 = NULL;
		struct Node *temp3;
		struct Node *temp5;
		struct Node *temp6=NULL;
		struct Node *prev=NULL;
	    int t=1;
	    printf("%d\n",p);
	   while(p--)
	   {
		   c=1;
		   prev=temp1;
		while(c<=k && temp1!=NULL)
		{
			temp3 = temp1->next;
			temp1->next = temp2;
			temp2 = temp1;
			temp1 = temp3; 
			c++;
		}
			temp5=temp3;
		if(t)
		{
		    start = temp2;
		    t=0;
		}
		else
		{
			temp6->next = temp2;
		}
			temp1=temp3;
			temp2=NULL;
			temp3=NULL;
			temp6=prev;
	   }
	    	temp1 = temp5;
		    temp2 = NULL;
		    struct Node *temp4;
		    while(temp1!=NULL)
		    {
		    temp4 = temp1->next;
			temp1->next = temp2;
			temp2 = temp1;
			temp1 = temp4;
		    }
		    temp6->next=temp2;
		return start;
    }
	
	