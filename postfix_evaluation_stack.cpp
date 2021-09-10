// Postfix exp. evaluation

#include<iostream>

using namespace std;

int top=-1;
char stack[50];

int push(int c)
{
    stack[++top]=c;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[50],*e;
    int m,n,r;

    cout<<"Enter the expression : ";
    gets(exp);
    e=exp;
    //m=*e;
    while(*e!='\0')
    {
        if(*e<='9' && *e>='0')
            push(*e-'0');
        else
        {
           m=pop();
           n=pop();

           switch(*e)
           {
               case '+':r=n+m;
               break;

               case '-': r=n-m;
               break;

               case '*': r=n*m;
               break;

               case '/': r=n/m;
               break;

               case '%': r=n%m;
               break;

               case '^': r=n^m;
               break;

           }
           push(r);
        }
        e++;
    }

cout<<r;
}
