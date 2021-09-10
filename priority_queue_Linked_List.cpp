// Priority Queue Program in Linked List implementation...

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node
{
    int info;
    int priority;
    struct node *link;
}*front=NULL;

int main()
{
    int choice;
    //struct node *front=NULL;
    //struct node *rear=NULL;

    while(1)
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            void insert();
            insert();
            break;

        case 2:
            void del();
            del();
            break;

        case 3:
            void display();
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Wrong Choice");
        }
    }

}

void insert()
{
    //int a;
    struct node *tmp,*q;
    int a,prior;
    tmp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value to be inserted in the queue: ");
        scanf("%d",&a);
        tmp->info=a;
        printf("Enter priority : ");
        scanf("%d",&prior);
        tmp->priority=prior;

        if(front==NULL || prior<front->priority)
        {
            tmp->link=front;
            front=tmp;
        }

        else
        {
            q=front;
            while(q->link!=NULL && q->link->priority<=prior)
            {
                q=q->link;
            }
            tmp->link=q->link;
            q->link=tmp;
        }

}

void del()
{
    struct node *tmp;
    //tmp=(struct node*)malloc(sizeof(struct node));

    if(front==NULL)
    {
        printf("Queue is Underflow..\n");
    }

    else
    {
        printf("Deleted element is : %d",front->info);
        tmp=front;
        front=front->link;
        free(tmp);
    }
}

void display()
{
    struct node *q;
    q=front;
    if(front==NULL)
    {
        printf(" Queue is empty..\n");
    }
    else
    {
        printf("Queue elements are: ");
        while(q!=NULL)
        {
            printf("\n%d  %d\n",q->priority,q->info);
            q=q->link;

        }
    }
}
