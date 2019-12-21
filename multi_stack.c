//WAP to implement multiple stack 
#include<stdio.h>
# define MAX 10
int stack[MAX], topA = -1,topB=MAX;
void  pushA (int  val)
  {  if (topA+1 == topB)
       {
	 printf("\noverflow in StackA");
	 return ;  }
   stack [++topA]=val;
   }
int  popA( )
  {  if(topA==-1)                                                 
        {
        printf("\nunderflow in StackA");
        return -999; }
     return stack[topA--];
  }

void showA ( )
   {  int i;
      if(topA==-1)
       {
        printf ("\nstackA is empty");
        return;  }
      for (i=topA; i>=0; i--)
	  printf("   %d", stack[i]);
    }

void  pushB (int  val)
  { if (topB-1 == topA)
       {
        printf("\noverflow in StackB");
        return ; }
   stack [--topB]=val;
   }

int  popB( )
  { if(topB==MAX)
       {
       printf("\nunderflow in StackB");
       return -999; }
  return stack[topB++];
  }

void showB ( )
   { int i;
      if(topB==MAX)
        {
         printf ("\nstackB is empty");
         return; }
      for (i=topB; i<MAX; i++)
	  printf("   %d", stack[i]);
    }


void main ()
    { int no, ch;
       do
        {	printf ("\n 1 pushA");
	printf ("\n 2 popA");
	printf ("\n 3 showA");
	printf ("\n 4 pushB");
	printf ("\n 5 popB");
	printf ("\n 6 showB");
	printf ("\n 0 exit");
	printf ("\n enter your Choice:");
	scanf ("%d", &ch);
	switch (ch)
	 {case 1 : printf("\n Enter no : ");
		  scanf("%d", &no);
		  pushA(no);
		  break;
	  case 2 : no = popA( );
		  if (no != -999)
		     printf ("\n % d poped ",no);
		  break;
	  case 3 : showA();
		  break;
	  case 4 : printf("\n Enter no : ");
		  scanf("%d", &no);
		  pushB(no);
		  break;
	  case 5 : no = popB( );
		  if (no != -999)
		     printf ("\n % d poped ",no);
		  break;
	  case 6 : showB();
		  break;
	  case 0 : break;
	  default : printf("\n invalid choice");
	  }//end of switch
         }while ( ch !=  0);
      }

