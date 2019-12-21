//WAP to Reprent polynomials and addition
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
struct node
{
int coef,exp;
struct node *next;
};
struct node *s1=NULL,*s2=NULL,*s3=NULL;
void append(struct node *&p,int a,int b)
{
struct node *q=p,*r;
r=(struct node *)malloc(sizeof(struct node));
r->coef=a;
r->exp=b;
if(p==NULL)
  {p=r;
   p->next=NULL;
   return; }
if(r->exp > p->exp)
 { r->next=p;
   p=r;
   return; }
while(q->next != NULL)
  {if(q->exp==r->exp)
    {q->coef+=r->coef;
     free(r);
     return; }
  if(q->next!=NULL && q->exp > r->exp && r->exp > q->next->exp)
      { r->next=q->next;
	q->next=r;
	return;}
   q=q->next;
   }
  if( q->exp > r->exp && q->next==NULL )
    { r->next=q->next;
      q->next=r;
      return; }
}
void show(struct node *p)
{if(p==NULL)
  { printf("\n no polynomial");
    return; }
  while(p!=NULL)
   { printf("%dX%d ",p->coef,p->exp);
     p=p->next; }
}
void sum()
 { struct node *p=s1,*q=s2;
   while(p!=NULL)
    { append(s3,p->coef,p->exp);
      p=p->next; }
   while(q!=NULL)
    { append(s3,q->coef,q->exp);
      q=q->next; }
  printf("\n Addition of two polynomials ");
  show(s3);
}
void main()
 { int ch, e,c;
   do{
    printf("\n 1 Append (Polynommial s1 ):");
    printf("\n 2 Append (Polynommial s2 ):");
    printf("\n 3 Show ( Polynomial s1 ):");
    printf("\n 4 Show ( Polynomial s2 ):");
    printf("\n 5 Sum ( s1 + s2 ):");
    printf("\n 0 Exit ");
    printf("\n Enter Your Choice ");
    scanf("%d",&ch);
    switch(ch)
     { case 1:printf("\n enter coef and exponent ");
	      scanf("%d%d",&c,&e);
	      append(s1,c,e);
	      break;
       case 2:printf("\n enter coef and exponent ");
	      scanf("%d%d",&c,&e);
	      append(s2,c,e);
	      break;
       case 3:show(s1);
	      break;
       case 4:show(s2);
	      break;
       case 5:sum();
	      break;
       case 0:break;
       default:printf("\n Invalid Choice ");
      }
    }while(ch != 0);
   }
