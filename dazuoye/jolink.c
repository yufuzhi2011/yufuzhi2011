#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}Node,*Pnode;

int main(int argc, const char *argv[])
{
    Pnode p;
    Pnode head=NULL;
    int k=0;
    int i;
    int m;
    int n;
    Pnode parent;
   
    if (3!=argc)
    {
        fputs("too few arguments for inputing\n",stdout);
        exit(1);
    }
    m=atoi(argv[1]);
    n=atoi(argv[2]);
   
    
    head=(struct node *)malloc(m*sizeof(struct node));
    
    p=head;
    for(i=0;i<m;i++)
    {
        p->val=i+1;
        if(m-1==i)
        {
            p->next=head;
        }
        else p->next=p+1;
        p++;
       
    }
    p=head;

    while(k<m)
    {
        for(i=1;i<n;i++)
                     {
            parent=p; 
            p=p->next;
                     }
        
        k++;
        
        printf("%3d  %3d  out",k,p->val);
        
        if (0==k%5)
            printf ("\n");
       
        parent->next=p->next;

        p=parent->next;}

        free(head);

    return 0;
}
