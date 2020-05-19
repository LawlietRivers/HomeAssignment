#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


 void find(int arr[static 1], int n)
 {
 	int i, max,min,max2,min2;
 	max=max2 = INT_MIN;
 	min=min2=INT_MAX;
 	for(i=0;i<n;i++)
 	{
 		if(arr[i]>max)
 		{
 			max2=max;
 			max=arr[i];

 		}
 		else if(arr[i]<max&&arr[i]>max2)
 		{
 			max2=arr[i];
 		}
 		if(arr[i]<min)
 		{
 			min2=min;
 			min=arr[i];
 		}
 		else if(arr[i]>min&&arr[i]<min2)
 		{
 			min2=arr[i];
 		}
 	}
 	printf("\nSecond smallest element of array = %d\n", min2);
 	printf("\nSecond largest element of array = %d\n", max2);
 	}

int main()
{
	int n;
	printf("Enter size of array:\n ");
	scanf("%d", &n);
	int arr[n];
	//int* arr = (malloc)(n*sizeof(int));
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter element: \n");
		scanf("%d", &arr[i]);
		printf("\n");

	}
	
	find(arr,n);

	

}
