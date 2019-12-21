//WAP to demonstarte of STRUCTURE WITH POINTER
#include<stdio.h>
struct student
{
int   sno,m;
char sname[20];
float per;
};
void main()
{
struct student s1 , *p;
p = &s1;
printf("\n enter sno,m,sname of student");
scanf("%d%d%s" , &p->sno , &p->m , p->sname );
p->per=p->m/3.0;
printf("\n %d %d %s" , p->sno , p->m , p->sname , p->per );
}


