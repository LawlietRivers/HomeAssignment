#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search(char filename[], char word[])
{
	FILE* readfrom = fopen(filename,"r");
	if(!readfrom)
	{
		perror("File open failure");
		
	}
	int n = strlen(word);
	char scan[1001];
	char* pos=NULL;
	while(fgets(scan,1000,readfrom)!=NULL)
	{
		 pos=strstr(scan,word);
		 if(pos!=NULL){
		 	printf("Search successful.\n");
		 	return;
		 }
	}
	printf("Search unsuccessful.\n");


}

int main()
{
	int k,n1,n2;
printf("\nEnter number of characters in full pathname (pathname+extension) of file:\n");
scanf("%d",&n1);
printf("\nEnter number of characters in searh term:\n");
scanf("%d",&n2);
char* i = (char*)calloc((n1+1),sizeof(char));
char* sw = (char*)calloc((n2+1),sizeof(char));
printf("\nEnter name of file: \n");

scanf("%s",i);
printf("\nEnter name of search term: \n");
scanf("%s",sw);

search(i,sw);
}