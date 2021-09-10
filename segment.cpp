// Linked List Structure & Pointer implementation

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

//#define Max 20
int arr[30];
int n;

struct node
{
    int info;
    struct node *link;

}*start;

int main()
{
    int choice,n,m,i;
    int item,pos;
    start=NULL;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Add at beginning\n");
        printf("3. Add at between\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter no. of Nodes to be entered: ");
            scanf("%d",&n);
            struct node* create_list(int);
            for(i=0;i<n;i++)
            {
                printf("\nEnter data of Node %d : ",i+1);
                scanf("%d",&m);
                create_list(m);
            }
            printf("Linked List created\n");


            //input(n);
            break;

        case 2:
            void Add_at_begin(int);
            printf("Enter node data which have to be added at beginning: ");
            scanf("%d",&m);
            Add_at_begin(m);
            break;

        case 3:
            int pos;
            printf("Enter position at which node to be added: ");
            scanf("%d",&pos);
            printf("Enter data :");
            scanf("%d",&m);

            void AddAtBetween(int,int);
            AddAtBetween(pos,m);
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


struct node *create_list(int data)
{
    struct node *q,*tmp;

    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=NULL;

    if(start==NULL)
        start=tmp;
    else
    {
        q=start;

        while(q->link!=NULL)
        {
            q=q->link;
        }
        q->link=tmp;


    }
    return q;
}


void Add_at_begin(int m)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;
    tmp->link=start;
    start=tmp;

}

void display()
{
    int i=1;
    struct node *q;
    if(start==NULL)
    {
      printf("List is empty...");
      return;
    }
    q=start;
    while(q!=NULL)
    {
        printf("Value at Node %d : %d\n",i,q->info);
        q=q->link;
        i++;
    }
}

void AddAtBetween(int pos,int m)
{
    struct node *q,*tmp;

    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;
    q=start;
    for(int i=1;i<pos-1;i++)
    {
        q=q->link;
        if(q==NULL)
        {
            printf("There are less than %d nodes.. \n",pos);
            return;
        }
    }

    tmp->link=q->link;
    q->link=tmp;
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

//    position=search(item);
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
