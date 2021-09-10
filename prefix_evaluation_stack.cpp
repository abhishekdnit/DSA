// Prefix exp. evaluation

#include<iostream>
#include<string.h>
#include<math.h>

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
    int m,n,r,l=0,temp,a,b;

    cout<<"Enter the expression : ";
    gets(exp);
    e=exp;
    //m=*e;
   /* while(*e!='\0')
    {
        e++;
        l++;
    }
    l=strlen(e);
    cout<<endl<<l<<endl;

    while(l!=0)
    {
        e--;
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


        l--;

    }*/

    for(int i=strlen(e)-1;i>=0;i--)
	{
		if(e[i]<='9' && e[i]>='0')
			push(e[i]-'0');
		else
		{
			a=pop();
			b=pop();
			switch(e[i])
			{
			case '+':
				temp=b+a; break;
			case '-':
				temp=a-b;break;
			case '*':
				temp=b*a;break;
			case '/':
				temp=a/b;break;
			case '%':
				temp=a%b;break;
			case '^':
				temp=pow(a,b);
			}
			push(temp);
		}
	}

cout<<temp;
}
