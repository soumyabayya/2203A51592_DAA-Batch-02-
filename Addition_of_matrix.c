#include<stdio.h>
int main()
{
	int i,j,a[i][j],b[i][j],c[i][j],row,col;
	printf("enter no.of rows:");
	scanf("%d",&row);
	printf("enter no.of columns:");
	scanf("%d",&col);
	
	printf("enter the first matrix elements:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the second matrix elements:\n");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
		   {
			  scanf("%d",&b[i][j]);
		   }
		}
		printf("\nThe addition of matrix is:\n");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
		   {
		   	
		   	c[i][j]=a[i][j]+b[i][j];
			printf("%d\t",c[i][j]);
		   }
		   printf("\n");
		}
		
	
}
