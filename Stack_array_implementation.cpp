// Stack Program in Array implementation...

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int top=-1;
int stack_arr[MAX];

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            void push();
            push();
            break;

        case 2:
            void pop();
            pop();
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

void push()
{
    int a;
    if(top==MAX-1)
    {
        printf("Stack is Overflow..\n");
    }
    else
    {
        printf("Enter the value to be pushed: ");
        scanf("%d",&a);
        top=top+1;
        stack_arr[top]=a;
    }

}

void pop()
{
    int b;
    if(top==-1)
    {
        printf("Stack is Underflow..\n");
    }

    else
    {
        printf("Popped element is : %d",stack_arr[top]);
        top=top-1;

    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty..\n");
    }
    else
    {
        printf("Stack elemets are: ");
        for(i=top;i>=0;i--)
        {
            printf("%d , ",stack_arr[i]);
        }
    }
}
