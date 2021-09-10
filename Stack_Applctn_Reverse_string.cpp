// Stack Application: Reverse the string..

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 20

int top=-1;
char stack_arr[MAX];
char pop();
void push(char);

int main()
{
    char str[20];
    printf("Enter the string = ");
    gets(str);

    for(int i=0;i<strlen(str);i++)
        push(str[i]);

    for(int i=0;i<strlen(str);i++)
        str[i]=pop();

        printf("Reversed string = ");
        puts(str);

}

void push(char item)
{

    if(top==MAX-1)
    {
        printf("Stack is Overflow..\n");
        return;
    }
    else
    {
        stack_arr[++top]=item;
    }

}

char pop()
{
    if(top==-1)
    {
        printf("Stack is Underflow..\n");
    }

    else
    return stack_arr[top--];
}
