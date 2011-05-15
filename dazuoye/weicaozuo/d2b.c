#include <stdio.h>
int dtob ()
{  
    int i;
    int n;
    
    printf("input a number:");
    scanf("%d",&n);
            
    for (i=31;i>=0;i--)
        if((n>>i)&1)break;
                        
    for(;i>=0;i--)
        printf("%d",((n>>i)&1));
                                           
    printf("\n");
                                                
    return 0;
                                                    
}
