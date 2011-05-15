#include <stdio.h>
#include <stdlib.h>
#include "mycpychar.h"
#include "mycpyrecord.h"
#include "mycpyrow.h"

int main(int argc, const char *argv[])
{
    FILE *p1;
    FILE *p2;
    int m;
    
    if( (p1=fopen(argv[1],"r"))==NULL)
    {
        printf("can not open the file \n");
        exit(1);
    }
        p2=fopen(argv[2],"w");

    printf("Please select\n");
    printf("1.cp by char\n");
    printf("2.cp by record\n");
    printf("3.cp by row\n");
    scanf("%d",&m);

    switch(m){
    
        case 1:mycpychar(p1,p2);break;
        case 2:mycpyrecord(p1,p2);break;
        case 3:mycpyrow(p1,p2); break;
        default:break;
                                   }
    return 0;
}


