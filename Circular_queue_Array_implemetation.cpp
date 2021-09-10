//Circular Queue Program in Array implementation...

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int rear=-1;
int front=-1;
int Queue_arr[MAX];

int main()
{
    int choice;

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
    int a;
    if(rear==MAX-1 && front==0 || front==rear+1) // if rear at end & front at begin Or front is ahead of rear
    {
        printf("Queue is Overflow..\n");
        return;
    }

    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
         if(rear==MAX-1)
            rear=0;
         else
            rear=rear+1;

         printf("Enter the value to be inserted in the queue: ");
         scanf("%d",&a);
         Queue_arr[rear]=a;
}

void del()
{

    if(front==-1)
    {
        printf("Queue is Underflow..\n");
    }
    if(front==rear)     //If only one element in the queue
    {
        printf("Deleted element is : %d\n",Queue_arr[front]);
        front=-1;
        rear=-1;
    }

    else
         if(front==MAX-1)
            {
                printf("Deleted element is : %d\n",Queue_arr[front]);
                front=0;
            }

         else
            {
                printf("Deleted element is : %d\n",Queue_arr[front]);
                front=front+1;
            }
}

void display()
{
    int i=front;
    if(rear==-1 && front==-1)
    {
        printf(" Queue is empty..\n");
    }
    else
    {
        printf("Queue elements are: ");
        while(i!=rear)
        {
            printf("%d  ",Queue_arr[i]);
            if(i==MAX-1)
                i=0;
            else
                i++;

        }

        printf("%d  ",Queue_arr[i]);
    }
}
