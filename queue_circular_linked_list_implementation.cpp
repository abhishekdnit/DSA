// Queue Program in Circular Linked List implementation...

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *link;
}*rear=NULL;

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
    struct node *tmp;
    int a;
    tmp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value to be inserted in the queue: ");
        scanf("%d",&a);
        tmp->info=a;
        if(rear==NULL)
            {
             rear=tmp;
             tmp->link=rear;
             return;
            }
        else
        {
         tmp->link=rear->link;
         rear->link=tmp;
         rear=tmp;

        }

}

void del()
{
    struct node *tmp,*q;
    //tmp=(struct node*)malloc(sizeof(struct node));
    q=rear->link;
    if(rear==NULL)
    {
        printf("Queue is Underflow..\n");
        return;
    }
    if(q==rear)
    {
        tmp=rear;
        rear=NULL;
        free(tmp);
        return;
    }
    else
    {
        printf("Deleted element is : %d",q->info);
        tmp=q;
        rear->link=q->link;
        free(tmp);
    }
}

void display()
{
    struct node *q;

    if(rear==NULL)
    {
        printf(" Queue is empty..\n");
    }
    else
    {
        printf("Queue elements are: ");
        q=rear->link;                    //It should not be in beginning if rear=NULL...
        while(q!=rear)
        {
            printf("%d  ",q->info);
            q=q->link;

        }
    printf("%d",q->info);
    }
}
