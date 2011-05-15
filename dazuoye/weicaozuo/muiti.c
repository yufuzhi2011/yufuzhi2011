#include <stdio.h>
int mul ()
{
	int x;
    int y;
    int ax;
    int by;
    int flag=0;
    int i;
    int num=0;

    tag:printf("input 2 number:");
    if(2!=scanf("%d %d",&x,&y))
        goto tag;
        
    if(x>>31&1)ax=~(x-1);
        else ax=x;

    if(y>>31)by=~(y-1);
        else by=y;

    if(((x>>31)&1)^((y>>31)&1))flag=1;

    for(i=0;i<31;i++)
        if((by>>(i))&1)num=num+(ax<<i);

    if (flag)num=~num+1;
       
    printf("%d*%d=%d\n",x,y,num);
    
    return 0;
}

