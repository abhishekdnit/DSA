



#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int x,f;
    cout<<"x= ";
    cin>>x;

    int fact(int);
    f=fact(x);
    cout<<"f= "<<f;
    return 0;
}

int fact(int n)
{

    int a;
    if(n>1);
    a=n*fact(n-1);
    return a;
}









