#include<stdio.h>
#include<stdbool.h>
void display(int x[4][4])
{
	 for(int i=0;i<4;i++)
	 {
		 for(int j=0;j<4;j++)
		 {
			 printf("%d ",x[i][j]);
		 }
		 printf("\n");
	 }
}
 bool isvalid(int x[4][4],int r,int c)
 { 
	 int i,j;
	
	 for(i=r;i>=0;i--)
	 {
		 if(x[i][c])
		 {
			 return false;
			 
		 }
	 }
	 for(i=r,j=c;i>=0&&j>=0;i--,j--)
	 {
		 if(x[i][j])
		 {
			 return false;
		 }
	 }
	 
	 return true;
	 }

 bool show(int x[4][4],int r)
 {
	 
	 if(r>=4)return true;
	 int j;
	 for(j=0;j<4;j++)
	 if(isvalid(x,r,j))
	 {
		 x[r][j]=1;
		 if(show(x,r+1))return true;
           
		 x[r][j]=0;			 
	 }	 
		 return false;
}
 void main()
 {
	 
	 int i,j;
	 int x[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	 int n=4;
	 if(show(x,0))
	 {
		 display(x);
	 }
 }