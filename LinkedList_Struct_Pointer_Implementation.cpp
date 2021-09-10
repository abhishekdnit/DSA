// Linear Linked List Structure & Pointer implementation

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
        printf("\n1. Create List\n");
        printf("2. Add at beginning\n");
        printf("3. Add at between\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Add at the End\n");
        printf("7. Count\n");
        printf("8. Reverse\n");
        printf("9. Search\n");
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
            void del(int);
            printf("Enter element to be deleted: ");
            scanf("%d",&m);
            del(m);
            break;

        case 5:
             void display();
             display();
             break;

        case 6:

             printf("Enter data to be entered at the end: ");
             scanf("%d",&m);
             void AddAtEnd(int);
             AddAtEnd(m);
             break;

        case 7:

            void count();
            count();
            break;

        case 8:

            struct node* revers(struct node*);
            revers(start);
            break;

        case 9:

        printf("Enter value to be searched: ");
        scanf("%d",&m);
        void search(int);
        search(m);
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
      printf("Listgetline(cin, str); is empty...");
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

void AddAtEnd(int m)
{
    struct node *q,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;
    tmp->link=NULL;

    q=start;

    while(q->link!=NULL)
    {
        q=q->link;
    }

    q->link=tmp;
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

/*void reverse()
{
  struct node *p1,*p2,*p3;

  if(start->link==NULL)
  {getline(cin, str);
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
}*/

struct node* revers(struct node * start)
{
   if(start==NULL)
       return start;
   else
   {
    revers(start->link);
    printf("%d\n",start->info);
   }

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
