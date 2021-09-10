// factorial by using recursion & tail recursion..

#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int x,f,r;
    cout<<"x= ";
    cin>>x;

    int fact(int);
    int rfact(int,int);
    f=fact(x);
    r=rfact(x,1);
    cout<<"f by recursion= "<<f;
    cout<<"\nf by Tail recursion= "<<r;
    return 0;
}

int fact(int n)
{

    int a=1;
    if(n>1)
    a=(n*fact(n-1));
    return a;
}

int rfact(int x,int f1)
{
    if(x==1)
        return f1;
    else
        rfact(x-1,x*f1);
}
