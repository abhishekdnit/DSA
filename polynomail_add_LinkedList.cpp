// Polynomial Addition using Linear Linked List Program...

#include <stdio.h>
#include <malloc.h>

struct node
{
    int coef;
    int expo;
    struct node *link;

};

struct node *enter(struct node*);
struct node *insert(struct node*,int,int);
struct node *poly_add(struct node*,struct node*);
void display(struct node*);

int main()
{

    struct node *p1_start,*p2_start,*p3_start;
    p1_start=NULL;
    p2_start=NULL;
    p3_start=NULL;

    printf("Polynomial 1 :\n");
    p1_start=enter(p1_start);

    printf("Polynomial 2: \n");
    p2_start=enter(p2_start);

    p3_start=poly_add(p1_start,p2_start);

    printf("Polynomial 1 = ");
    display(p1_start);

     printf("Polynomial 2 = ");
    display(p2_start);

    printf("Addition of Both the polynomails are: ");
    display(p3_start);


}


struct node* enter(struct node* start)
{
    int n,i,co,ex;

    printf("Enter the number of terms :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the coefficient of term %d =",i+1);
        scanf("%d",&co);

        printf("Enter the exponent of term %d =",i+1);
        scanf("%d",&ex);

        start=insert(start,co,ex);
    }

    return start;
}

struct node* insert(struct node* start,int co,int ex)
{
  struct node *tmp,*q;
  tmp=(struct node*)malloc(sizeof(struct node));
  tmp->coef=co;
  tmp->expo=ex;


  if(start==NULL||ex>start->expo)
  {
      tmp->link=start;
      start=tmp;
      //return start;
  }
  else
  {
    q=start;
    while(q->link!=NULL && q->link->expo>ex)
     q=q->link;

        tmp->link=q->link;
        q->link=tmp;
        if(q->link==NULL)
            tmp->link=NULL;

  }

  return start;
}

void display(struct node* p)
{

    while(p!=NULL)
    {
        printf("(%dx^%d) + ",p->coef,p->expo);

        p=p->link;
    }

printf("\b\b \n");
}

struct node* poly_add(struct node* p1,struct node* p2)
{

    struct node *tmp,*p3,*p3_start;
    p3_start=NULL;

    while(p1!=NULL && p2!=NULL)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        //tmp->link=NULL;

        if(p3_start==NULL)    // for setting start pointer
        {
            p3_start=tmp;
            p3=p3_start;
        }
        else                   // for linking previous node to next node.. & traversing LL by p3
        {
           p3->link=tmp;
           p3=p3->link;
        }

        if(p1->expo > p2->expo)
        {
            tmp->coef=p1->coef;
            tmp->expo=p1->expo;
            p1=p1->link;

        }
        else
                if(p2->expo > p1->expo)
                {
                    tmp->coef=p2->coef;
                    tmp->expo=p2->expo;
                    p2=p2->link;

                }
                else
                        if(p1->expo==p2->expo)
                {
                        tmp->coef=p1->coef+p2->coef;
                        tmp->expo=p1->expo;
                        p2=p2->link;
                        p1=p1->link;

                }
    }

    while(p1!=NULL)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        //tmp->link=NULL;
        tmp->coef=p1->coef;
        tmp->expo=p1->expo;
        if(p3_start==NULL)    // for setting start pointer
        {
            p3_start=tmp;
            p3=p3_start;
        }
        else                   // for linking previous node to next node.. & traversing LL by p3
        {
           p3->link=tmp;
           p3=p3->link;
        }
        p1=p1->link;
    }

    while(p2!=NULL)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        //tmp->link=NULL;
        tmp->coef=p2->coef;
        tmp->expo=p2->expo;
        if(p3_start==NULL)    // for setting start pointer
        {
            p3_start=tmp;
            p3=p3_start;
        }
        else                   // for linking previous node to next node.. & traversing LL by p3
        {
           p3->link=tmp;
           p3=p3->link;
        }
        p2=p2->link;
    }
p3->link=NULL;
return p3_start;
}
