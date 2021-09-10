// Stack Application for Conversion of infix into postfix & evaluation of postfix .....

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 50

int top=-1;
char stack_arr[MAX];
char pop();
void push(char);
void precedence_stack(char);
void precedence_post();
char infix[MAX];
char postfix[MAX];
static int j=0;
int eval();

int main()
{

    int i,l,value;
    printf("Enter the infix expression = ");
    fflush(stdin);
    gets(infix);
    l=strlen(infix);

    infix[l]='#';

    for(i=0;infix[i]!='#';i++)
    {
        if(infix[i]=='^'||infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-'||infix[i]=='(')
            push(infix[i]);
        else
            {
                if(infix[i]==')')
                    precedence_post();
                else
                {
                postfix[j]=infix[i];
                j++;
                }
            }
    }

    while(top!=-1)
    {
        postfix[j]=stack_arr[top];
        top--;
        j++;
    }

    printf("Postfix Expression= %s\n",postfix);

    value=eval();

    printf("Value of Postfix Expession: %d",value);

    return 0;
}


void push(char item)
{
    //0stack_arr[0]='#';

    if(top==MAX-1)
    {
        printf("Stack is Overflow..\n");
        return;
    }
    else
    {
        if(item=='^'||item=='*'||item=='/'||item=='+'||item=='-')
            precedence_stack(item);
        top=top+1;
        stack_arr[top]=item;

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

void precedence_stack(char chr)
{
    int tmp;
    tmp=top;
    char pop_chr;

    if(chr=='+')
    {
       // while(stack_arr[tmp]!='#')
        {
            if(stack_arr[tmp]=='+'||stack_arr[tmp]=='*'||stack_arr[tmp]=='/'||stack_arr[tmp]=='^')
                    {
                        pop_chr=pop();
                        postfix[j]=pop_chr;
                        j++;
                    }
                   // tmp--;
        }

    }

    if(chr=='*')
    {
        //while(stack_arr[tmp]!='#')
        {
            if(stack_arr[tmp]=='*'||stack_arr[tmp]=='/'||stack_arr[tmp]=='^')
                    {
                        pop_chr=pop();
                        postfix[j]=pop_chr;
                        j++;
                    }
                   // tmp--;
        }

    }

    if(chr=='/')
    {
       // while(stack_arr[tmp]!='#')
        {
            if(stack_arr[tmp]=='/'||stack_arr[tmp]=='^')
                    {
                        pop_chr=pop();
                        postfix[j]=pop_chr;
                        j++;
                    }
                    //tmp--;
        }

    }

    if(chr=='^')
    {
        //while(stack_arr[tmp]!='#')
        {
            if(stack_arr[tmp]=='^')
                    {
                        pop_chr=pop();
                        postfix[j]=pop_chr;
                        j++;
                    }
                    //tmp--;
        }

    }

    else
        if(chr=='-')
    {
       // while(stack_arr[tmp]!='#')
        {
            //if(stack_arr[tmp]=='-'||stack_arr[tmp]=='+'||stack_arr[tmp]=='*'||stack_arr[tmp]=='/'||stack_arr[tmp]=='^')
                    {
                        pop_chr=pop();
                        postfix[j]=pop_chr;
                        j++;
                    }
                    //tmp--;
        }

    }
}

void precedence_post()
{
    char pop_chr;
    while(stack_arr[top]!='(')
    {
      pop_chr=pop();
      postfix[j]=pop_chr;
      j++;
    }
    pop();
}

int eval()
{

int a,b,len,i,temp;
char c1,c2,result[5];
len=strlen(postfix);
postfix[len]='#';

for(i=0;postfix[i]!='#';i++)
{
    if(postfix[i]>='0' && postfix[i]<='9')
        push(postfix[i]);

    else
    {
        printf("postfix = %c\n",postfix[i]);
        c1=pop();
        a=c1-48;
        printf("c1= %c , a= %d\n",c1,a);
        c2=pop();
        b=c2-48;
        printf("c2= %c , b= %d\n",c2,b);
        switch(postfix[i])
        {
            case '+':
                temp=b+a;break;

            case '-':
                temp=b-a;break;

            case '*':
                temp=b*a;break;

            case '/':
                temp=b/a;break;

            case '^':
                temp=pow(b,a);
                break;

        }

     /*   if(temp>=10)
                result='A'+ temp-10;
        else
            result='0' + temp; */
            //sprintf(result,"%d",temp);
        //result=temp;
        printf("temp-int = %d  temp-char = %c\n",temp,result);
        push(result);

    }
}
return temp;
}
