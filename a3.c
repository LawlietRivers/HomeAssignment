#include<stdio.h>
#include<stdlib.h>

void multiply(int** a, int** b, int m, int n, int c)
{
	int i,j,k;
	int** res = (int**)malloc(m*sizeof(int));
	
	for(i=0;i<m;i++)
	{
		res[i]=(int*)malloc(c*sizeof(int));
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<c;j++)
		{
			res[i][j]=0;
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<c;j++)
		{
			for(k=0;k<n;k++)
			{
				res[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("Product matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%5d",res[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int m1,n1,m2,n2,i,j;
	printf("\nEnter dimensions of first matrix: ");
	scanf("%d %d",&m1,&n1);
	printf("\nEnter dimensions of second matrix: ");
	scanf("%d %d",&m2,&n2);
	if(n1!=m2){
		printf("\nMatrix multiplication not possible.\n");
		return 0;
	}
	int** a = (int**)malloc(m1*sizeof(int));
	
	for(i=0;i<m1;i++)
	{
		a[i]=(int*)malloc(n1*sizeof(int));
	}
	int** b = (int**)malloc(m2*sizeof(int));
	
	for(i=0;i<m2;i++)
	{
		b[i]=(int*)malloc(n2*sizeof(int));
	}
	printf("\nFOR FIRST MATRIX :\n");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("\nEnter integer : ");
			scanf("%d",&a[i][j]);
		}
	}
 	printf("\nFOR SECOND MATRIX :\n");
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("\nEnter integer : ");
			scanf("%d",&b[i][j]);
		}
	}
	printf("\n");
	printf("FIRST MATRIX : \n ");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	printf("SECOND MATRIX : \n ");
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			
			printf("\t%d",b[i][j]);
		}
		printf("\n");
	}
	multiply(a,b,m1,n1,n2);

}