#include<stdio.h>
#include<stdlib.h>

int count(char s[], int n)
{
	int i, c=0;
	for(i=0;i<n;i++)
		if(s[i]==' ')
			c++;
	return c;
}
int main()
{
	int i,n;

	printf("Enter number of characters in paragraph: ");
	scanf("%d",&n);
	char para[n+1];
	printf("\nEnter paragraph: \n");
	for(i=0;i<n;i++)
		scanf("%c",&para[i]);
	printf("%s",para);
	printf("\nNumber of spaces in given paragraph = %d\n",count(para,n));
}