// Sorted Linear Linked List Program...

/* NOTE:
1. Don't forget to add return & traverse always one position before in insertion & deletion
  */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;



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
        printf("\n1. Create List\n");
        printf("2.   Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Reverse\n");
        printf("7. Search\n");
        printf("8. Quit\n");
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
            void insert(int);
            printf("Enter node data which have to be added : ");
            scanf("%d",&m);
            insert(m);
            break;

        case 3:
            void del(int);
            printf("Enter element to be deleted: ");
            scanf("%d",&m);
            del(m);
            break;

        case 4:
             void display();
             display();
             break;

        case 5:

            void count();
            count();
            break;

        case 6:

            void reverse();
            reverse();
            break;

        case 7:

        printf("Enter value to be searched: ");
        scanf("%d",&m);
        void search(int);
        search(m);
        break;

        case 8:
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


void insert(int m)
{
    struct node *tmp,*q;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;

    if(start==NULL || m < start->info) //If item is less than 1st node element
   {
    tmp->link=start;
    start=tmp;
    return;
   }

   q=start;
   while(q!=NULL)
   {
       if(m < (q->link->info))      //if item is inserted in between
       {
          tmp->link=q->link;
          q->link=tmp;
          return;
       }

       q=q->link;

       if(q->link==NULL && q->info < m)   // if item inserted at last..
       {
           tmp->link=NULL;
           q->link=tmp;

           return;
       }

   }

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


void del(int m)
{
  struct node *q,*tmp;

  if(start->info==m)  //if first element deleted
  {
      tmp=start;
      start=start->link;
      free(tmp);
      return;
  }

  q=start;

  while(q->link->link!=NULL)   //If element deleted in between
  {
      if(q->link->info==m)
      {
          tmp=q->link;
          q->link=q->link->link;
          free(tmp);
          return;
      }

      q=q->link;
  }

    if(q->link->info==m)    //If deleted at the end
    {
        tmp=q->link;
        q->link=tmp->link;
        free(tmp);
        return;
    }

    printf("Element %d does not found\n",m);

}

void count()
{

int cnt=0;
struct node *q;
q=start;

while(q!=NULL)
{
    q=q->link;
    cnt++;
}

printf("No. of elements are: %d",cnt);
}

void reverse()
{
  struct node *p1,*p2,*p3;

  if(start->link==NULL)
  {
      printf("Only one element is present.");
      return;
  }

  p1=start;
  p2=p1->link;
  p3=p2->link;

  p1->link=NULL;
  p2->link=p1;

  while(p3!=NULL)
  {
      p1=p2;
      p2=p3;
      p3=p3->link;
      p2->link=p1;
  }

  start=p2;
}

void search(int m)
{
    struct node *q;
    int pos=1;
    q=start;
    while(q!=NULL)
    {
    if(q->info==m)
    {
        printf("Entered data is present at position %d\n",pos);
        return;
    }
    q=q->link;
    pos++;
    }
if(q==NULL)
    printf("Item not found..\n");
}
