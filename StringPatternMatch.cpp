//Pattern Substrings

#include <stdio.h>
#include <string.h>
#include <iostream>
int main() {

    char str1[30],str2[30];
    int a;
    printf("Enter text String= ");
    gets(str1);

    printf("Enter pattern string= ");
    gets(str2);
    int sub(char[],char[]);
    a=sub(str1,str2);

    if(a==0)
        printf("\nPattern not matched\n");
    else
        printf("Pattern matched...");

       return 0;
}

int sub(char s1[],char s2[])
{

int i,j,k,m;

if(strlen(s2)>strlen(s1))
    return 0;

for(i=0;i<strlen(s1);i++)
{
    k=0;
    for(j=i;k<strlen(s2);j++,k++)
    {

        if(s1[j]!=s2[k])

        {
            m=0;
            break;
        }
        else
            m=1;
    }
   if(m==1)
    return (i+1);

}


return 0;

}
