#include <stdio.h>
#include <string.h>

int zhuanhuan ()
{
	int i;
    char str[100]={0};

    printf("input a string:");
    scanf("%s",str);

    for (i=0;str[i]!='\0';i++)
       if ((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))   str[i]=(str[i]^0x20);

    puts(str);
    
    return 0;
}

