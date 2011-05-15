#include <stdio.h>
#include <stdlib.h>
#include "muiti.h"
#include "d2b.h"
#include "exchange.h"
#include "encryption.h"

int main(int argc, const char *argv[])
{
    int n;

    printf("1.decimal to binary\n");
    printf("2.x*y\n");
    printf("3.low or up exchange\n");
    printf("4.encryption\n");
    printf("5.Exit\n");
    flag:    printf("Please choose [1-5]:\n");
    scanf("%d",&n);

    if(!(n>=1&&n<=5))
    {   
        printf("the wrong choose\n");
        goto flag;
    }

    switch(n){
    case 1:dtob ();goto flag;
    case 2:mul ();goto flag;
    case 3:zhuanhuan ();goto flag;
    case 4:jiami ();goto flag;
    case 5:exit(0);
    }
    return 0;
}
