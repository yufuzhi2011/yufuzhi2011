#include <stdio.h>
#include <stdlib.h>

int my_shell(char * str);

int main(int argc, const char *argv[])
{
   while(1){
           char a[101]={0};
 
           printf("mysh%%  ");
           fgets(a,100,stdin);
           if(a[0]=='Q')break;
           printf("\n");

           my_shell(a);

            }
             
  
   return 0;

}

int my_shell(char * str)
{
    int i;
    int m=0;
    int n=0;
    int b[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int j=0; 

    printf("show the comand:\n");
    printf("comand:");
    
    for(i=0;str[i]==' '&&str[i]!='\n';i++);
        for(;str[i]!=' '&&str[i]!='>'&&str[i]!='<'&&str[i]!='\n';i++)
            printf("%c",str[i]);

            printf ("\n");
    
    while(1){
        for(;str[i]==' '&&str[i]!='>'&&str[i]!='<'&&str[i]!='\n';i++); 
            if (str[i]=='>'||str[i]=='<')
                break;
            if (str[i]=='\n')
                {
                    printf("\n");
                    return 0;
                }

        printf(",argument:");

        for (;str[i]!=' '&&str[i]!='>'&&str[i]!='<'&&str[i]!='\n';i++)
        printf("%c",str[i]);
        }    

        printf("\n"); 
    for (i=0;str[i]!='\n';i++)
        if('>'==str[i]) 
            m=i;
     for (i=0;str[i]!='\n';i++)
        if('<'==str[i])
            n=i;

            if(m&&(!n)){
            printf("in-file:NULL, ");
            printf("out-file:");

            for(i=m+1;str[i]==' ';i++);
            for(;str[i]!=' '&&str[i]!='\n';i++)
                printf("%c",str[i]);
                printf("\n");
                 }

            if(n&&(!m)){
            printf("in-file:");
            
            for(i=n+1;str[i]==' ';i++);
            for(;str[i]!=' '&&str[i]!='\n'&&str[i]!='>'&&str[i]!='<';i++)
                printf("%c",str[i]);
                printf(" out-file:NULL");
                printf("\n");
                printf("\n");
                  }
            if(m&&n){
            printf (",in-file:");
            
            for(i=n+1;str[i]==' ';i++);
            for(;str[i]!=' '&&str[i]!='\n'&&str[i]!='>'&&str[i]!='<';i++)
                printf("%c",str[i]);
           
            printf(" out-file:");
            
            for(i=m+1;str[i]==' ';i++);
            for(;str[i]!=' '&&str[i]!='\n'&&str[i]!='<'&&str[i]!='>';i++)
                printf("%c",str[i]);
                printf ("\n");

            }

           
     return 0;

    }

