//Substrings

#include <stdio.h>
#include <iostream>
int main() {

    char str1[30],str2[30];
    int a,b;
    printf("Enter 1 String= ");
    gets(str1);

    printf("Enter 1 index= ");
    scanf("%d",&a);

    printf("Enter 2 index= ");
    scanf("%d",&b);

//    gets(str2);

    int sub(char*,int,int);
    sub(str1,a,b);



       return 0;
}

int sub(char *s1,int a,int b)
{

for(int i=1;i<=b;i++)
{
    s1++;
    if(i==a-1)
    {
    for(int i=1;i<=b;i++)
    {
    printf("%c",*s1);
    s1++;
    }

    }
}
return 0;
}
