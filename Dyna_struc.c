//WAP TO CREATE DYNAMIC STRUCTURE 
#include<stdio.h>
#include<alloc.h>

struct student
{
int   sno,m;
char sname[20];
float per;
};
void main()
{
struct student  *p; 
p = ( struct student * ) malloc (sizeof ( struct student ));
printf("\n enter sno,m,sname of student");
scanf("%d%d%s" , &p->sno , &p->m , p->sname );
p->per=p->m/3.0;
printf("\n %d %d %s" , p->sno , p->m , p->sname , p->per );
free(p);
}

