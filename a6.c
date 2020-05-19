#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float** transpose(float** arr, int n)
{
        int i,j;
        float** transpose = (float**)calloc(n,sizeof(float*));
        for(i=0;i<n;i++)
                transpose[i]=(float*)calloc(n,sizeof(float));
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        transpose[i][j]=arr[j][i];
        }
        return transpose;
}

float** getcofactor(float** arr, int n, int x, int y)
{
        int i,j,k,l=0;
        float** temp = (float**)calloc((n-1),sizeof(float*));
        for(i=0;i<n;i++)
                temp[i]=(float*)calloc((n-1),sizeof(float));
        for(i=0;i<n;i++)
        {k=0;
                for(j=0;j<n;j++)
                        if(j!=y&&x!=i){
                                temp[l][k]=arr[i][j];
                                k++;}
                if(x!=i)
                        l++;                
        }
      

        return temp;
}

float detfind(float** arr, int n)
{
        if(n==1){
           
        return arr[0][0]; }       
        if(n==2){
             
        return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];}
        else{
                float d =0;int i,p=1;
                for(i=0;i<n;i++){
                        d+=arr[0][i]*p*detfind(getcofactor(arr,n,0,i),n-1);

                        p*=-1;}
                      
                return d;
        }

}

float** findadj(float** arr, int n)
{
        int i,j;
        float** adj = (float**)calloc(n,sizeof(float*));
        for(i=0;i<n;i++)
                adj[i]=(float*)calloc(n,sizeof(float));
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        adj[i][j]=detfind(getcofactor(arr,n,i,j),n-1);
                }
        }
        adj = transpose(adj,n);
        return adj;
}
         
void inverse(float **arr, int n)
 {
        int i,j;
        float determinant = detfind(arr,n);
        if(determinant==0){
                printf("Matrix is non-invertible.\n");
                return;
        }

        float** inv = (float**)malloc(n*sizeof(float*));
        for(i=0;i<n;i++)
                inv[i] = (float*)malloc(n*sizeof(float));
        inv = findadj(arr,n);
       
        printf("\nORIGINAL MATRIX : \n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        printf("\t%f",arr[i][j]);
                printf("\n");


        }
        printf("\nINVERSE MATRIX : \n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        printf("\t%f",inv[i][j]);
                printf("\n");


        }
}

int main()
{
        int i,j,n;
        printf("ENTER THE DIMENSION OF SQUARE MATRIX: \n");
        scanf("%d",&n);
        float** arr = (float**)calloc(n,sizeof(float*));
        for(i=0;i<n;i++)
                arr[i]=(float*)calloc(n,sizeof(float));

        for(i=0;i<n;i++)
                for(j=0;j<n;j++){
                        printf("\n ENTER ARRAY ELEMENT AT ( %d , %d ) : " ,(i+1),(j+1));
                        scanf("%f",&arr[i][j]);
                }

                inverse(arr,n);

}