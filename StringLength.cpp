//Length of string without sizeof function

#include <stdio.h>
#include <iostream>
int main() {

    char str[20];
    int l;
    printf("Enter String= ");
    gets(str);
    //printf("\n%c",str[20]);

    int Length(char *);
    l=Length(str);

    printf("\nLength= %d",l);

    if(str[20]=='\0')
    {
        printf("\nHII");
    }

    return 0;
}

int Length(char *s)
{
    int i=0;
    while(*s!='\0')
    {
       i++;
       s++;
    }
    return i;
}
