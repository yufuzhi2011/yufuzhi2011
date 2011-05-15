#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int rscallback(void *p,int argc,char **argv,char **argvv)
{
    int i;
    *(int *)p=0;
    
    for(i=0;i<argc;i++)
    {
        printf("%s=%s  ",argvv[i],argv[i]?argv[i]:"NULL");
    }
        putchar('\n');
        
        return 0;
}

int main()
{
    int n;
    sqlite3 *db;
    int ret=0;
    
    ret=sqlite3_open("./tesb.db",&db);
    if(ret!=SQLITE_OK)
    {
        fputs(sqlite3_errmsg(db),stderr);
        fputs("\n",stderr);
        exit(1);
    }
   while(1){
   fputs("1.Display all records\n",stdout);
   fputs("2.Insert Record\n",stdout);
   fputs("3.Delete Record\n",stdout);
   fputs("4.Exit\n",stdout);
   fputs("Please Select[1-4]:",stdout);
   scanf ("%d",&n);
   switch(n){
       
       case 1:select1(db);break;
       case 2:insert1(db);break;
       case 3:delete1(db);break;
       case 4:exit(0);
       default:return 0;
            }  
            } 
   sqlite3_close(db);

   return 0;
}
int select1(sqlite3 *p)
{
    char *err=0;
    int empty=1;
    int ret=0;
    
    ret=sqlite3_exec(p,"select * from employee;",rscallback,&empty,&err);
    if (ret!=SQLITE_OK)
    {
        fputs(err,stderr);
        fputs("\n",stderr);
        sqlite3_close(p);
        exit(1);
    }
    if (empty)
    {
        fputs("table employee is empty\n",stderr);
     
    }
        
        return 0;
}

int insert1(sqlite3 *p )
{
    char *sql;
    char *err=0;
    int ret=0;
    char id[10];
    char name[10];
    char gender[10];
    char age[5];
    
    fputs("Please input id name gender age:\n",stdout);
    scanf("%s %s %s %s",id,name,gender,age);
    sql=sqlite3_mprintf("insert into employee values(%s,%Q,%Q,%s);",id,name,gender,age);
    
    ret=sqlite3_exec(p,sql,rscallback,NULL,&err);
    
    if (ret!=SQLITE_OK)
    {
        fputs(err,stderr);
        fputs("\n",stderr);
        sqlite3_close(p);
        exit(1);
    }
    return 0;
}
int delete1(sqlite3 *p)
{
    char *err=0;
    char *sql1=0;
    char *sql2=0;
    int ret=0;
    char str1[10];
    char str2[10];
    int n;
    int empty=1;
    
    fputs("1.Delete by ID \n",stdout);
    fputs("2.Delete by Name\n",stdout);
    fputs("Your choice:",stdout);
    scanf("%d",&n);
    if (1==n)
    {
        fputs("Please input the ID:",stdout);
        scanf("%s",str1);
        sql1=sqlite3_mprintf("delete from employee where id=%s;",str1);
        ret=sqlite3_exec(p,sql1,rscallback,&empty,&err);
        }
    if(2==n)
    {
        fputs("Please input the name:",stdout);
        scanf("%s",str2);
        sql2=sqlite3_mprintf("delete from employee where name=%Q;",str2);
        ret=sqlite3_exec(p,sql2,rscallback,&empty,&err);
    }
    
    if (ret!=SQLITE_OK)
    {
        fputs(err,stderr);
        fputs("\n",stderr);
        sqlite3_close(p);
        exit(1);
    }
    if (empty)
    {
        fputs("table employee is empty\n",stderr);
    } 

    return 0;
}
