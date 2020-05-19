#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int** getcofactor(int** arr, int n, int y)
{
        int i,j,k;
        int** temp = (int**)calloc(n,sizeof(int*));
        for(i=0;i<n;i++)
                temp[i]=(int*)calloc(n,sizeof(int));
        for(i=1;i<n;i++)
        {k=0;
                for(j=0;j<n;j++)
                        if(j!=y){
                                temp[i-1][k]=arr[i][j];
                                k++;}
        }

        return temp;
}
int detfind(int** arr, int n)
{
        if(n==1)
                return arr[0][0];
        if(n==2)
        return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
        else{
                int d =0,i,p=1;
                for(i=0;i<n;i++){
                        d+=arr[0][i]*p*detfind(getcofactor(arr,n,i),n-1);

                        p*=-1;}
                return d;
        }
}


int main()
{
        int i,j,n;
        printf("ENTER THE DIMENSION OF SQUARE MATRIX: \n");
        scanf("%d",&n);
        int** arr = (int**)calloc(n,sizeof(int*));
        for(i=0;i<n;i++)
                arr[i]=(int*)calloc(n,sizeof(int));

        for(i=0;i<n;i++)
                for(j=0;j<n;j++){
                        printf("\n ENTER ARRAY ELEMENT AT ( %d , %d ) : " ,(i+1),(j+1));
                        scanf("%d",&arr[i][j]);
                }

                printf("DETERMINANT = %d\n", detfind(arr,n));
}