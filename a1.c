#include<stdio.h>
#include<stdlib.h>

 void find(int arr[static 1], int n)
 {
 	int max,min,temp,temp2;
 	
 	int x = 2<=n?2:n;
 	for(int i=0;i<x;i++)
 	{
 		max=min=i;
 		
 		for(int j=i+1;j<n-i;j++)
 		{
 			if(arr[j]>arr[max])
 				max=j;
 			if(arr[min]>arr[j])
 				min=j;
 		}
 		temp=arr[i];
 		temp2=arr[n-i-1];
 		arr[n-i-1]=arr[max];
 		arr[max]=temp2;
 		arr[i]=arr[min];
 		arr[min]=temp;


 	}
 	if(x>=2){
 	printf("Second largest element of array: %d\n",arr[n-2]);
 	printf("Second smallest element of array: %d\n",arr[1]);
 	}
 	else{
 		printf("Second largest element of array: %d\n",arr[0]);
 	printf("Second smallest element of array: %d\n",arr[0]);
 	}
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
