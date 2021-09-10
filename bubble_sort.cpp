#include<stdio.h>

#define MAX 50

void bubble_sort(int[],int);

int main()
{
    int arr[MAX],n,i;

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

    bubble_sort(arr,n);

    printf("\nSorted order is :\n ");

    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);

    return 0;
}

void bubble_sort(int arr[],int n)
{
  int round,i,temp,xchange;

  for(round=0;round<n-1;round++)
  {
      xchange=0;
      for(i=0;i<n-1-round;i++)    // Important to remember the condition of for loop.
      {
          if(arr[i]>arr[i+1])
          {
          xchange=1;
          temp=arr[i];
          arr[i]=arr[i+1];
          arr[i+1]=temp;
          }

      }

      if(xchange==0)
      {
          printf("\nRounds : %d",round);
          return;
      }

  }

    return;
}
