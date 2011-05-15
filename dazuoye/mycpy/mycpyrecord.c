#include <stdio.h>

int mycpyrecord (FILE *s1,FILE *s2)
{
    char str[2];
    while(fread(str,1,1,s1)!=0)
    {
        fwrite(str,1,1,s2);
    }

    fclose(s1);
    fclose(s2);

    return 0;
}

