
#include<stdio.h>
# define MAX 10
int stack [MAX], top = -1;
void  push (int  val)
  {   
   if (top == MAX -1)
       {	 
           printf("\noverflow");
	 return ;  }
   stack [++top]=val;
   }
int  pop( )
  {  
   if(top==-1)
       {  
        printf("\nunderflow");
        return -999;  }
  return stack[top--];
  }

void show ( )
   {  int i;
      if(top==-1)
        {
         printf ("\nstack is empty");
         return;  }
        for (i=top; i>=0; i--)
         printf("   %d", stack[i]);
   }




void main ()
    { int no, ch;
       do
       {	printf ("\n 1 push");
	printf ("\n 2 pop");
	printf ("\n 3 show");
	printf ("\n 0 exit");
	printf ("\n enter ur your ");
	scanf ("%d", &ch);


	switch (ch)
	 {case 1 : printf("\n Enter no : ");
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
	  }//end of switch
	  }while ( ch !=  0);//end of while
      }

