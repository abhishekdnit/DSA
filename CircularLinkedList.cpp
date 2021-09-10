// Circular Linked List Structure & Pointer implementation..

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

}*last;

int main()
{
    int choice,n,m,i;
    int item,pos;
    last=NULL;
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

            void reverse();
            reverse();
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
    //tmp->link=NULL;

    if(last==NULL)
    {
        last=tmp;           //this statement should always be before 2nd statement
        last->link=last;

    }
//Each added node will add at last...
    else
    {
      tmp->link=last->link;   //This will point added node to 1st node..
      last->link=tmp;         //This will point previous node to added node
      last=tmp;                //This will point added node to last..
    }

}


void Add_at_begin(int m)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;
    tmp->link=last->link;
    last->link=tmp;

}

void display()
{
    int i=1;
    struct node *q;
    if(last==NULL)
    {
      printf("List is empty...\n");
      return;
    }
    q=last->link;
    while(q!=last)
    {
        printf("Value at Node %d : %d\n",i,q->info);
        q=q->link;
        i++;
    }
    printf("Value at Node %d : %d\n",i,last->info);  //This statement have to be added to access last element as while loop end after pointing to last...
}

void AddAtBetween(int pos,int m)
{
    struct node *q,*tmp;

    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;
    q=last->link;
    for(int i=1;i<pos-1;i++)
    {
        q=q->link;
        if(q==last->link)
        {
            printf("There are less than %d elements\n",pos);
        }

    }
    tmp->link=q->link;
    q->link=tmp;

    if(q==last)   // element inserted at the end & position comes the end.
        last=tmp;
}

void del(int m)
{

  struct node *q,*tmp;

  if(last->link==last && last->info==m) //if only one node in the list
  {
    tmp=last;
    last=NULL;
    free(tmp);
    return;

  }

  if(last->link->info==m)  //if first element deleted
  {
      tmp=last->link;
      last->link=last->link->link;
      free(tmp);
      return;
  }

  q=last->link;

  while(q->link!=last)   //If element deleted in between
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

    if(last->info==m)    //If deleted at the end
    {
        tmp=last;
        q->link=last->link;
        free(tmp);
        last=q;
        return;
    }

    printf("Element %d does not found\n",m);

}

void AddAtEnd(int m)
{
    struct node *q,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=m;

    q=last;

    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
}

void count()
{

int cnt=1;
struct node *q;
q=last->link;

while(q!=last)
{
    q=q->link;
    cnt++;
}

printf("No. of elements are: %d",cnt);
}

void reverse()
{
  struct node *p1,*p2,*p3;

  if(last->link==last)
  {
      printf("Only one element is present.");
      return;
  }

  p1=last->link;
  p2=p1->link;
  p3=p2->link;

  p1->link=last;
  p2->link=p1;

  while(p3!=last->link)
  {
      p1=p2;
      p2=p3;
      p3=p3->link;
      if(p3!=last->link) // important to add to come out of loop as otherwise link of last will change...
      p2->link=p1;
  }
  p2->link=p1; // adding to change the link of last to previous node of last node..
  last=p3; // now last will point to 1st node of LL.
}

void search(int m)
{
    struct node *q;
    int pos=1;
    q=last->link;
    while(q!=last)
    {
    if(q->info==m)
    {
        printf("Entered data is present at position %d\n",pos);
        return;
    }
    q=q->link;
    pos++;
    }
        if(last->info==m)
        {
        printf("Entered data is present at position %d\n",pos);
        return;
    }


if(q==last)
    printf("Item not found..\n");
}
