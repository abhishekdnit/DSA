//Copy of strings

#include <stdio.h>
#include <iostream>
int main()
{

    char str1[30],str2[30];

    printf("Enter 1 String= ");
    gets(str1);

    printf("Enter 2 String= ");
    gets(str2);

    int cop(char*,char*);

    cop(str1,str2);
    printf("Copied string= %s",str1);

       return 0;
}

int cop(char *s1,char *s2)
{

    while(*s2!='\0')
    {
        *s1=*s2;
        s1++;
        s2++;

    }

    *s1='\0';

return 0;
}
