// Linked List Array implementation

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define Max 20
int arr[Max];
int n;
int main()
{
    int choice,item,pos;
    while(1)
    {
        printf("1. Input \n");
        printf("2. Insert\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter no. of elements to be entered: ");
            scanf("%d",&n);
            void input(int);
            input(n);
            break;

        case 2:
            void insert();
            insert();
            break;

        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d",&item);
            int search(int);
            pos=search(item);
            if(pos>=1)
                printf("%d item found at position %d\n",item,pos);
            else
                printf("Element not found\n");
            break;

        case 4:
              void del();
              del();
            break;

        case 5:
             void display();
             display();
             break;

        case 6:
            exit(0);
            break;

        default:
            printf("Wrong Choice\n");
        }
    }
}


void input(int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("Input value for element %d: ",i+1);
            scanf("%d",&arr[i]);
    }
}

void insert()
{
    int position,item,temp;
    if(n==Max)
    {
        printf("List is Overflow\n");
        return;
    }

    printf("Enter position of insertion: ");
    scanf("%d",&position);
    printf("Enter the item to be entered :");
    scanf("%d",&item);

    if(position>n+1)
    {
        printf("Enter position less than or equal to %d\n",n+1);
    return;
    }

    if(position==n+1)
    {
        arr[position-1]=item;
        n=n+1;
        return;
    }

    temp=n-1;
    while(temp>=position-1)
    {
    arr[temp+1]=arr[temp];
    temp--;
    }

    arr[position-1]=item;
    n=n+1;
}

void display()
{
    int i;
    if(n==0)
    {
      printf("List is empty...");
      return;
    }

    for(i=0;i<n;i++)
        printf("Value at position %d : %d\n",i+1,arr[i]);
}

int search(int item)
{

    int i;

    for(i=0;i<n;i++)
    {
        if(arr[i]==item)
        return i+1;
    }
        return 0;
}

void del()
{
    int item,position;

    if(n==0)
    {
        printf("List is underflow");
        return;
    }

    printf("Enter the item to be deleted:");
    scanf("%d",&item);

    if(item==arr[n-1])
    {
        n=n-1;
        return;
    }

    position=search(item);
    if(position==0)
    {
        printf("Element not present in array");
        return;
    }

    while(position!=n)
    {
    arr[position-1]=arr[position];
    position++;
    }
    n=n-1;
}
