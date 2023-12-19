#include<stdio.h>
#include<stdbool.h>
#define max 99
#define size 5
void algo();
void showAll();
int min_index();
void main()
{
	int x[size][size]={ {0,6,0,1,0},
					  {6,0,5,2,2},
					  {0,5,0,0,5},
					  {1,2,0,0,1},
					  {0,2,5,1,0}
				   	};
	algo(x,0);
}
void algo(int x[size][size],int s)
{
	int output[size];
	bool b[size]; 
	int i,j,m;
	
	for(i=0;i<size;i++)
	{
		output[i]=max;
		b[i]=false;
	}
	output[s] = 0;
	printf("A\tB\tC\tD\tE\n\n");
	
	for(i=0;i<size;i++)
	{
		showAll(output,s);
		m=min_index(output,b);
		b[m]=true;
		
		for(j=0;j<size;j++)
		{
			if(x[m][j]!=0 && b[j]!=true && output[j] > output[m]+x[m][j])
			{
				output[j] = output[m]+x[m][j];
			}
		}
	}
			showAll(output,s);
}

void showAll(int output[size])
{
	int i;
	for(i=0;i<size;i++)
	{
		// printf("%d\t%d\n",i,output[i]);
		printf("%d\t",output[i]);
	}
	printf("\n\n");
}


int min_index(int output[],bool b[])
{
	int min_i=-1;
	int min_v=max;
	int i;
	for(i=0;i<size;i++)
	{
		if(b[i]==false && min_v>output[i]  )
		{
			min_v = output[i];
			min_i = i;
		}
	}
	return min_i;
}