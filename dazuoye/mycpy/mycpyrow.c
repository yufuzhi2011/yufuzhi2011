#include <stdio.h>

int  mycpyrow (FILE *s1,FILE *s2)
{
    char str[100];
    
    
    while(fgets(str,81,s1)!=0)
    {
       
        fputs(str,s2);
    }

    fclose(s1);
    fclose(s2);

    return 0;
}
