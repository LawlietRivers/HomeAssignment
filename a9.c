#include<stdio.h>
#include<stdlib.h>

void readAppend(char rf[], char wt[])
{
	FILE* readfrom = fopen(rf,"r");
	FILE* writeto = fopen(wt,"a");
	if(!readfrom||!writeto)
	{
		perror("File open failure");
		
	}

	char ch=fgetc(readfrom);
	while(ch!=EOF)
	{
		 fputc(ch, writeto);
		ch = fgetc(readfrom);
	}

}

int main()
{
	int k,n1,n2;
printf("\nEnter number of characters in full pathname (pathname+extension) of input file:\n");
scanf("%d",&n1);
printf("\nEnter number of characters in full pathname (pathname+extension) of output file:\n");
scanf("%d",&n2);
char* i = (char*)calloc((n1+1),sizeof(char));
char* o = (char*)calloc((n2+1),sizeof(char));
printf("\nEnter pathname of input file: \n");

scanf("%s",i);
printf("\nEnter pathname of output file: \n");
scanf("%s",o);


readAppend(i,o);
}