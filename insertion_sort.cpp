#include<stdio.h>

#define MAX 50

void insert_sort(int[],int);

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

    insert_sort(arr,n);

    printf("\nSorted order is :\n ");

    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);

    return 0;
}

void insert_sort(int arr[],int n)
{
    int i,j,k,temp;

    for(i=1;i<n;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0 && temp<arr[j];j--)    // Important to remember
            arr[j+1]=arr[j];

        arr[j+1]=temp;

        printf("\nPass %d, Element inserted in proper place: %d\n",i,temp);
        for(k=0;k<n;k++)
            printf("%d  ",arr[k]);
        printf("\n");
    }

}

