//Concatenate 2 strings

#include <stdio.h>
#include <iostream>
int main() {

    char str1[30],str2[30];
    //int l;
    printf("Enter 1 String= ");
    gets(str1);

    printf("Enter 2 String= ");
    gets(str2);

    char concate(char*,char*);
    concate(str1,str2);

    printf("Concatenated String= %s",str1);
    return 0;
}

char concate(char *s1,char *s2)
{
    while(*s1!='\0')
    {
        s1++;
    }

    while(*s2!='\0')
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
}
