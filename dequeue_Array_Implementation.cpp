// Dequeue Program in Array implementation...

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int left=-1;
int right=-1;
int Queue_arr[MAX];

int main()
{
    int choice;

    printf("1. Input restricted dequeue.\n");
    printf("2. Output restricted dequeue.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        void input_que();
        input_que();
        break;

    case 2:
        void output_que();
        output_que();
        break;

    }

}

void input_que()
{
    int choice;

    while(1)
    {
        printf("\n1.Insert at right\n");
        printf("2.Delete from left\n");
        printf("3.Delete from right\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            void insert_right();
            insert_right();
            break;

        case 2:
            void del_left();
            del_left();
            break;

        case 3:
            void del_right();
            del_right();
            break;

        case 4:
            void display();
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Wrong Choice");
        }
    }

    }


void output_que()
{

    int choice;
    while(1)
    {
        printf("\n1.Insert at right\n");
        printf("2.insert at left\n");
        printf("3.Delete from left\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            void insert_right();
            insert_right();
            break;

        case 2:
            void insert_left();
            insert_left();
            break;

        case 3:
            void del_left();
            del_left();
            break;

        case 4:
            void display();
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Wrong Choice");
        }
    }

    }

void insert_right()
{
int a;

    if(left==0 && right==MAX-1 || right==left-1)
    {
        printf("Queue is Overflow..\n");
        return;
    }

    if(left==-1)
    {
        right=0;
        left=0;
    }

    else
        if(right==MAX-1)
            right=0;
        else
            right=right+1;

    printf("Enter the element input at right: ");
    scanf("%d",&a);
    Queue_arr[right]=a;
}

void insert_left()
{
int a;

    if(left==0 && right==MAX-1 || left==right+1)
    {
        printf("Queue is Overflow..\n");
        return;
    }

    if(left==-1)
    {
        right=0;
        left=0;
    }

    else
        if(left==0)
            left=MAX-1;
        else
            left=left-1;

    printf("Enter the element input at left: ");
    scanf("%d",&a);
    Queue_arr[left]=a;
}

void del_left()
{

    if(left==-1)
    {
        printf("Queue is Underflow..\n");
        return;
    }
    printf("Deleted element from queue is : %d",Queue_arr[left]);

    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
        if(left==MAX-1)
            left=0;
        else
            left=left+1;
}

void del_right()
{

    if(left==-1)
    {
        printf("Queue is Underflow..\n");
        return;
    }
    printf("Deleted element from queue is : %d",Queue_arr[right]);

    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
        if(right==0)
            right=MAX-1;
        else
            right=right-1;
}

void display()
{
    int front=left, rear=right;

    if(left==-1 && right==-1)
    {
        printf("Dequeue is empty..\n");
        return;
    }
    printf("Queue elements are: ");

   if(front<=rear)
   {
        while(front<=rear)
        {
            printf("%d ",Queue_arr[front]);
            front++;

        }

    }
    else
    {
         while(front<=MAX-1)
        {
            printf("%d ",Queue_arr[front]);
            front++;

        }
        front=0;

        while(front<=rear)
        {
            printf("%d ",Queue_arr[front]);
            front++;
        }

    }
    printf("\n");
}
