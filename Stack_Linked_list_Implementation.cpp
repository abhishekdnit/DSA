// Stack Program by Linked list implementation...

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node
{
    int info;
    struct node* link;
}*top=NULL;

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
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value to be pushed: ");
        scanf("%d",&a);
        tmp->info=a;
        tmp->link=top;
        top=tmp;

}

void pop()
{
    struct node* q;
    q=top;
    if(top==NULL)
    {
        printf("Stack is Underflow..\n");
    }

    else
    {
        printf("Popped element is : %d",q->info);
        top=top->link;
        free(q);



    }
}

void display()
{
    struct node* q;
    q=top;
    if(top==NULL)
    {
        printf("Stack is empty..\n");
    }
    else
    {
        printf("Stack elemets are: ");
        while(q!=NULL)
        {
            printf("%d , ",q->info);
            q=q->link;
        }
        printf("\b\b \n");
    }

}

