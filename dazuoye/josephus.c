#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
   
    int i;
    int j=0;
    int m=atoi(argv[1]);
    int n=atoi(argv[2]);
    int str[m];
    int count=0;

    for(i=0;i<m;i++)
        str[i]=1;
       
        while(j<m){
            
            for(i=0;i<m;i++)
              { if (str[i]==1)
                 count++;
                    
                 if(n==count)
                 {
                   
                   count=0;
                   
                   j++;
                  
                  printf("%3d: %3d out",j,i+1);
                 
                 str[i]=0;

                    if(j%5==0)
                        printf("\n");
                 }
            
            
            }    }
                    
                    return 0;
} 
             
               
                        
                    
                       
                        
                        
                       
                            
                            
                          
                            
                         
                     
                      
                        
                       
                         
                         
                         
    
