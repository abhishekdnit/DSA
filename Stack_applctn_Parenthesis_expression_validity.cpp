// Stack Application for validity of Expression containing parenthesis...

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 20
#define true 1
#define false 0


int top=-1,valid;
char stack_arr[MAX];
char pop();
void push(char);

int main()
{
    char str[20],temp;
    valid=false;
    printf("Enter the string = ");
    gets(str);

    for(int i=0;i<strlen(str);i++)
    {
        //printf("Under for= %d\n",i);
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            push(str[i]);

        if(str[i]==')'||str[i]=='}'||str[i]==']')
         {
            //printf("Under 2nd if\n");
            if(top==-1)
                valid=false;

            else
            {
            temp=pop();
            //printf("Under else- %d\n",i);
            if(str[i]==')' && temp=='(' )
            valid=true;
            if(str[i]=='}' && temp=='{')
            valid=true;
            if(str[i]==']' && temp=='[')
            valid=true;

            }
         }
    }

    if(valid==true)
        printf("Expression is True...\n");
    else
        printf("Expession is False...\n");
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
        top=top+1;
        stack_arr[top]=item;
        //printf("Under push\n");
    }

}

char pop()
{
    //printf("Under pop\n");
    if(top==-1)
    {
        printf("Stack is Underflow..\n");
    }

    else
    return stack_arr[top--];
}
