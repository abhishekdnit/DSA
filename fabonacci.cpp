// fabonacci by using recursion..

#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int i,j,k;
    printf("Enter the starting Position:");
    scanf("%d",&i);
    printf("Enter the End Position:");
    scanf("%d",&j);
    int fact(int);
    for(k=i;k<=j;k++)
        printf("%d  ",fact(k));
    return 0;
}

int fact(int n)
{
if(n==1||n==2)
    return (1);
    return(fact(n-1)+fact(n-2));
}
