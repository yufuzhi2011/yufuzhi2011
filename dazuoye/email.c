#include <stdio.h>

int zimu1(char c);
int zimu2(char c);

int main(int argc, const char *argv[])
{   
    FILE *p;
    char str[185];
    
    if((p=fopen(argv[1],"r"))==NULL)
        {
            printf("can not open the file\n");
            
        
        }

    while(fgets(str,181,p)!=NULL){
    
         manpage(str);
         
                     }

    fclose(p);
    
    return 0;
}
int manpage (char * str)
{
    int i;
    int j=0;
    int k;
    int m;
    int b[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    for(i=0;str[i]!='\n';i++)
        if('@'==str[i])
            b[j++]=i;
    
    for(j=0;b[j]!=-1;j++)
    {
        if(0==b[j])
            continue;
        
        for(i=b[j]-1;zimu1(str[i])&&i!=-1;i--);
            if((b[j]-i)>1&&(b[j]-i)<34)
            {
                for(m=b[j]+1;zimu2(str[m])&&str[m]!='\n';m++);
                    if((m-b[j])>1&&(m-b[j]<=65))
                    {
                      
                        for(k=i+1;k<m;k++)
                            printf("%c",str[k]);
                            printf("\n");
                    }
                    if (str[m]=='@')j++;
            }
    }
 
    return 0;
}

int zimu1(char c)
{
  if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))||(c=='.')||(c=='_')||((c>='1')&&(c<='9')))
        return 1;
    
    else return 0;
}

int zimu2(char c)
{
    if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))||(c=='.')||(c=='-')||((c>='1')&&(c<='9')))
        return 1;

    else return 0;
}
