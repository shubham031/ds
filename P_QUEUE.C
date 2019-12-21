#include<stdio.h>
#include<conio.h>
struct queue
 {   int no , pri ;
    struct queue *next;
 };
struct queue *front=NULL,*rear=NULL;

void insert(int val,int pr)
{  struct queue *p,*q;
  q=(struct queue *)malloc(sizeof(struct queue));
  q->no=val;
  q->pri=pr;
  if(front==NULL)
   {  q->next=NULL;
      front=rear=q;
      return;  }
  p=front;
  while((p->next->pri<=q->pri)&&(p->next!=NULL))
    {   p=p->next;
        if(p==NULL)
            break;  }
  if(q->pri<p->pri)
    { q->next=p;
      front=q;  }
  else
    { q->next=p->next;
       p->next=q; }
  }
int deletefront()
 {
int val;
   struct queue *q;
   if(front==NULL)
     { printf("\nQueue is Empty");
       return -999;
     }
   q=front;
   val=front->no;
   if(front==rear)
      front=rear=NULL;
   else
     front=front->next;
   free(q);
   return val;
}
void show()
{
  struct queue *q=front;
   if(front==NULL)
    { printf("\nQueue is Empty");
      return; }
  q=front;
  while(q!=NULL)
   { printf("%d\t",q->no);
     q=q->next;
   }
}

void main()
{
  int  ch,n,pr;
  do
  {
    clrscr();
    printf("\n1. Insert");
    printf("\n2. Delete from Front");
    printf("\n3. Show");
    printf("\n0. Exit");
    printf("\n\nEnter Your Choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter Number ");
	     scanf("%d",&n);
	     printf("\nEnter Priority");
	     scanf("%d",&pr);
	     insert(n,pr);
	     break;
      case 2:n=deletefront();
	     if(n!=-999)
	       printf("\n%d deleted",n);
	     break;
      case 3:show();
	     break;
      case 0:break;
      default:printf("\nWrong Choice");
    }
    if(ch!=0)
    {
      printf("\n\nPress any key to continue");
      getch();
    }
  }while(ch!=0);
}

