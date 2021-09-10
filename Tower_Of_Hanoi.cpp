//Tower of Hanoi

#include <stdio.h>
#include <string.h>
#include <iostream>
int main()
{
    int n;
   char s='A';
   char t='B';
   char d='C';
   printf("Enter No. of disks: ");
   scanf("%d",&n);
   int toh(int,char,char,char);
    toh(n,s,t,d);


       return 0;
}

int toh(int n,char s,char t,char d)
{
    if(n>0)
    {
        toh(n-1,s,d,t);
        printf("\nMove disk %d from %c to %c\n",n,s,d);
        toh(n-1,t,s,d);
    }
    return 0;
}
