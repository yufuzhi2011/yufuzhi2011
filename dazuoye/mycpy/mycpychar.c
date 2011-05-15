#include <stdio.h>

int mycpychar (FILE *s1,FILE *s2)
{
    int n;
    
    while ((n=fgetc(s1))!=EOF)
    {
       
        fputc(n,s2);      
    }

    fclose(s1);
    fclose(s2);
    
    return 0;
}

