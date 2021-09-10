#include<stdio.h>

#define MAX 50

int MIN(int[],int,int);

int main()
{
    int arr[MAX],n,i,k,loc,temp;

    printf("Enter No. of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nUnsorted list is :\n");

    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);

    for(k=0;k<=n-2;k++)   //Important to remember the condition of for loop i.e, upto k<=n-2..
    {
       loc=MIN(arr,k,n);
       temp=arr[k];
       arr[k]=arr[loc];
       arr[loc]=temp;

    }


    printf("\nSorted order is :\n ");

    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);

    return 0;
}

int MIN(int arr[],int k,int n)
{
  int MIN,j,LOC;
  MIN=arr[k];
  LOC=k;

  for(j=k+1;j<=n-1;j++)
  {
      if(MIN>arr[j])
      {
          MIN=arr[j];
          LOC=j;
      }

  }

 return LOC;
}
