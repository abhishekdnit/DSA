#include<stdio.h>

#define MAX 50

void quick_sort(int[],int,int);

int main()
{
    int arr[MAX],n,i,low,up;

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

    low=0;
    up=n-1;

    quick_sort(arr,low,up);

    printf("\nSorted order is :\n ");

    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);

    return 0;
}

void quick_sort(int arr[],int low,int up)
{
    int piv,left,right,temp,flag;
    flag=0;

    left=low;
    right=up;

    piv=low;  // Take 1st element always as pivot for all sublists..

    if(low>=up)
        return;

    //Loop till pivot comes at its proper place

    while(flag==0)
    {
        // Compare from right to left
        while(arr[piv]<=arr[right] && piv!=right)
            right=right-1;

        if(piv==right)
            flag=1;

        if(arr[piv]>arr[right])
        {
            temp=arr[piv];
            arr[piv]=arr[right];
            arr[right]=temp;
            piv=right;
        }

        // Compare from left to right
        while(arr[piv]>=arr[left] && piv!=left)
            left=left+1;

        if(piv==left)
            flag=1;

        if(arr[piv]<arr[left])
        {
            temp=arr[piv];
            arr[piv]=arr[left];
            arr[left]=temp;
            piv=left;
        }


    }

quick_sort(arr,low,piv-1);
quick_sort(arr,piv+1,up);

return ;

}

