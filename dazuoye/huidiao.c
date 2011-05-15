#include <stdio.h>

typedef int (*cmp_t)(void *,void *);
void *max(void *aa[],int n,cmp_t cmp)
{
    int i;
    void *p=aa[0];
    for(i=1;i<n;i++)
        if(cmp(p,aa[i])<0)
            p=aa[i];

    return p;
    }

typedef struct
{
    char name[20];
    int score;
}struct_t;

int cmp1(void *p1,void *p2)
{
    struct_t *a;
    struct_t *b;
    a=(struct_t *)p1;
    b=(struct_t *)p2;
    if (a->score>b->score)
        return 1;
    if (a->score<b->score)
        return -1;
    if (a->score==b->score)
        return 0;
}

        

int main(int argc, const char *argv[])
{
    struct_t *p;
    struct_t ss[3]={{"yu",67},{"fu",98},{"zhi",65}};
    struct_t *kk[3]={&ss[0],&ss[1],&ss[2]};
    p= max ((void*)kk,3,cmp1);
    printf("%s\n",p->name);
    printf("%d\n",p->score);

    return 0;
}
