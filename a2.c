#include<stdio.h>
#include<stdlib.h>

void transpose(int** arr, int m, int n)
{
	int transpose[n][m];
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			transpose[i][j]=arr[j][i];
	}
	printf("Transpose of given matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%5d",transpose[i][j]);
		printf("\n");
	}
}
int main()
{
	int m,n;
	printf("Enter no. of rows of array: ");
	scanf("%d",&m);
	printf("\nEnter no. of columns of array: ");
	scanf("%d",&n);
	
	int** arr=(int**)malloc(m*sizeof(int* ));
	int i,j,k;
	for(k=0;k<m;k++)
		arr[k]=(int *)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nEnter a number: ");
			scanf("%d",&arr[i][j]);

		}
	}
	printf("Original matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			
			printf("%5d",arr[i][j]);

		}
		printf("\n");
	}
	printf("\n");
	transpose(arr,m,n);

}