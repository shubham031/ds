//WAP to demostrate the initialization of variable of structure 
#include<stdio.h>
struct student
{
int   sno,m;
char sname[20];
float per;
};
void main()
{
struct student  s1={101,709,"amit",70.9},s2={202,806,"rohit",80.6};
printf("\n %d %d %s %f " , s1.sno , s1.m , s1.sname , s1.per );
printf("\n %d %d %s %f ", s2.sno , s2.m , s2.sname , s2.per );
}

