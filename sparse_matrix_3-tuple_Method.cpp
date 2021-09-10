// 3-tuple method sparse matrix in array implementation...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mat[50][50];
int spar[30][3];

int main()
{
    int i,j,mr,mc,nzero=0,s=1;


 printf("Enter the No. of rows of matrix : ");
 scanf("%d",&mr);

 printf("Enter the No. of columns of matrix : ");
 scanf("%d",&mc);

  for(i=0;i<mr;i++)
    for(j=0;j<mc;j++)
       {
        printf("Enter the element of %d row & %d column: ",i+1,j+1);
        scanf("%d",&mat[i][j]);
       }

    printf("Entered matrix : \n");
    for(i=0;i<mr;i++)
    for(j=0;j<mc;j++)
       {
           printf("%6d",mat[i][j]);
           if(mat[i][j]!=0)
            nzero++;
            if(j==mc-1)
                printf("\n");
       }

    spar[0][0]=mr;
    spar[0][1]=mc;
    spar[0][2]=nzero;

    for(i=0;i<mr;i++)
        for(j=0;j<mc;j++)
       {
            if(mat[i][j]!=0)
            {
                spar[s][0]=i+1;
                spar[s][1]=j+1;
                spar[s][2]=mat[i][j];
                s++;
            }

       }

       printf("3-tuple Sparse matrix : \n");
    for(i=0;i<s;i++)
    for(j=0;j<3;j++)
       {
           printf("%6d",spar[i][j]);
            if(j==2)
                printf("\n");
       }

}
