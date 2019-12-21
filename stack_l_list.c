//WAP to implement stack using link list 
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct stack
   {  int no;
      struct stack *next;
   };
struct stack *top=NULL;

void push(int val)
  { struct stack *n;
     n=(struct stack *)malloc(sizeof(struct stack));            
     if(n==NULL)
       {
         printf("\n Stack is overflow ");
         return;  }
    n->no=val;
    if(top==NULL)
      {
       top=n;
       top->next=NULL;
       printf("\n Node Pushed");
       return; }
     n->next=top;
     top=n;
     printf("\n Node Pushed");
    }

int pop( )
    { int val;
      struct stack *d=top;
      if(top==NULL)
       {
        printf("\n Stack is underflow ");
        return -999; }
      val=top->no;
      top=top->next;
      free(d);
      return val;
     }


void show( )
    { struct stack *p=top;
    if(top==NULL)
      {
      printf("\n Stack is empty ");
      return;  }
    while( p != NULL)
      { printf("   %d",p->no);
         p=p->next;
      }
    }

void main ( )
    { int no, ch;
       do
	{
	printf ("\n 1 push");
	printf ("\n 2 pop");
	printf ("\n 3 show");
	printf ("\n 0 exit");
	printf ("\n enter ur your ");
	scanf ("%d", &ch);
	switch (ch)
	  {
	  case 1 : printf("\n Enter no : ");
		  scanf("%d", &no);
		  push(no);
		  break;
	  case 2 : no = pop( );
		  if (no != -999)
		     printf ("\n % d poped ",no);
		  break;
	  case 3 : show();
		  break;
	  case 0 : break;
	  default : printf("\n invalid choice");
	  }
	  }while ( ch !=  0);
      }

