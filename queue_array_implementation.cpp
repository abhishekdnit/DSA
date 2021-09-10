// Queue Program in Array implementation...

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
    front=0;
    if(rear==MAX-1)
    {
        printf("Queue is Overflow..\n");
    }
    else
    {
        printf("Enter the value to be inserted in the queue: ");
        scanf("%d",&a);
        rear=rear+1;
        Queue_arr[rear]=a;
    }

}

void del()
{
    int b;
    if(front==-1 || front>rear)
    {
        printf("Queue is Underflow..\n");
    }

    else
    {
        printf("Popped element is : %d",Queue_arr[front]);
        front=front+1;

    }
}

void display()
{
    int i;
    if(rear==-1 && front==-1)
    {
        printf(" is empty..\n");
    }
    else
    {
        printf("Queue elements are: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d , ",Queue_arr[i]);
        }
        printf("\b\b ");
    }
}
