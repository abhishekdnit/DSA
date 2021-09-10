// Doubly linked List Program...

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
    struct node *prev;
    int info;
    struct node *next;

}*start;

int main()
{
    int choice,n,m,i;
    int item,pos;
    start=NULL;
    while(1)
    {
        printf("\n1. Create List\n");
        printf("2.   Add at beginning\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Reverse\n");
        printf("7. Search\n");
        printf("8. Add at end\n");
        printf("9. Add in between\n");
        printf("10. Quit\n");
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
            printf("nexted List created\n");


            //input(n);
            break;

        case 2:
            void insert_begin(int);
            printf("Enter node data which have to be added : ");
            scanf("%d",&m);
            insert_begin(m);
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
            void insert_end(int);
            printf("Enter node data which have to be added : ");
            scanf("%d",&m);
            insert_end(m);
            break;

        case 9:
            void insert_between(int,int);
            printf("Enter node data which have to be added : ");
            scanf("%d",&m);
            printf("Enter position after which node to be added: ");
            scanf("%d",&pos);
            insert_between(pos,m);
            break;

        case 10:
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
    tmp->next=NULL;

    if(start==NULL)
    {
        tmp->prev=NULL;
        start=tmp;
        //start->prev=NULL;
    }

    else
    {
        q=start;

        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=tmp;
        tmp->prev=q;


    }
    return q;
}


void insert_begin(int m)
{
    struct node *tmp,*q;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;

    tmp->prev=NULL;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;



}

void insert_end(int m)
{
    struct node *tmp,*q;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;
    q=start;
    while(q!=NULL)
    {
        q=q->next;
        if(q->next==NULL)
        {
        tmp->next=NULL;
        tmp->prev=q;
        q->next=tmp;
        return;
        }

    }

}

void insert_between(int pos,int m)
{

    struct node *q,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;

    q=start;
    for(int i=1;i<pos-1;i++)
    {
        q=q->next;
        if(q==NULL)
        {
         printf("There are less than %d elements\n",pos);
         return;
        }

    }

    tmp->prev=q;
    tmp->next=q->next;
    q->next->prev=tmp;
    q->next=tmp;

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
        q=q->next;
        i++;
    }
}


void del(int m)
{
  struct node *q,*tmp;

  if(start->info==m)  //if first element deleted
  {
      tmp=start;
      start=start->next;
      start->next->prev=NULL;
      free(tmp);
      return;
  }

  q=start;

  while(q->next!=NULL)   //If element deleted in between
  {
      if(q->info==m)
      {
          tmp=q;
          q->prev->next=q->next;
          q->next->prev=q->prev;
          free(tmp);
          return;
      }

      q=q->next;
  }

    if(q->info==m)    //If deleted at the end
    {
        tmp=q;
        q->prev->next=NULL;
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
    q=q->next;
    cnt++;
}

printf("No. of elements are: %d",cnt);
}

void reverse()
{
  struct node *p1,*p2;

  if(start->next==NULL)
  {
      printf("Only one element is present.");
      return;
  }

  p1=start;
  p2=p1->next;
 // p3=p2->next;

  p1->next=NULL;
  p1->prev=p2;
  //p2->prev=p2->next;
  //p2->next=p1;

  //p2->prev=p3;

  while(p2!=NULL)
  {

      //p3=p3->next;
      p2->prev=p2->next;
      p2->next=p1;
      p1=p2;
      p2=p2->prev;
    //  p2->prev=p3;

  }

  start=p1;
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
    q=q->next;
    pos++;
    }
if(q==NULL)
    printf("Item not found..\n");
}
