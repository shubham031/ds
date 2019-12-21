#include<stdio.h>
#include<conio.h>
struct queue
{  int no;
   struct queue *next;
};
struct queue *front=NULL,*rear=NULL;

void insertrear(int val)                                                         
  { struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    q->no=val;
    q->next=NULL;
    if(front==NULL)
      { front=rear=q;
        return;
      }
    rear->next=q;
    rear=q;
    }
int deletefront()
 { int val;
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
 { struct queue *q=front;
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
  int  ch,n;
  do
  {
    clrscr();
    printf("\n1. Insert in Rear");
    printf("\n2. Delete from Front");
    printf("\n3. Show");
    printf("\n0. Exit");
    printf("\n\nEnter Your Choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter Number ");
	     scanf("%d",&n);
	     insertrear(n);
	     break;
      case 2:n=deletefront();
	     if(n!=-999)
	       printf("\n%d deleted",n);
	     break;
      case 3:show();
	     break;
      case 0:break;
      default:printf("\nWrong Choice ");
    }//end of switch 
  }while(ch!=0);
}

