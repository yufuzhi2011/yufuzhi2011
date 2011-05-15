#include <stdio.h>
#include <string.h>

int jiami ()
{ 
	 int i;
    char c='3';
    char str[100]={0};

    printf("input a string:");
    scanf("%s",str);

    for (i=0;str[i]!='\0';i++)
        str[i]=(str[i]^c);

    puts(str);

    for (i=0;str[i]!='\0';i++)
        str[i]=(str[i]^c);

    puts(str);

    return 0;
}
