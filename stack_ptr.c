#include<stdio.h>
#define MAX 10

void push(int *stack , int *top ,int val)            
     { if(*top==MAX-1)
         {
          printf("\n stack is overflow ");
         return ; }
     stack[++(*top)]=val;
     }

int pop(int *stack , int *top)
    { if(*top==-1)
        {
         printf("\n stack is underflow ");
         return -999;  }
      return stack[(*top)--];
    }

void show(int *stack , int *top)
    { int i;
      if(*top==-1)
        {
        printf("\n stack is empty ");
        return;  }
      for(i=*top;i>=0;i--)
            printf("   %d",stack[i]);
     }

void reverse(int *stack,int *top)
   { int s2[MAX],t2=-1,s3[MAX],t3=-1;
      while( (*top) != -1)
	push( s2,&t2,pop(stack,top) );
   while( t2 != -1)
        push( s3,&t3,pop(s2,&t2) );
   while( t3 != -1)
	push( stack,top,pop(s3,&t3) );
   }

void cnt_occ_ele(int *stack,int *top,int val)
   {  int s2[MAX] ,t2=-1,p_ele,c=0;
      while( (*top) != -1)
	{p_ele=pop(stack,top);
	  if(val==p_ele)
	     c++;
	  push( s2,&t2,p_ele); 
          }
      while( t2 != -1)
	push( stack,top,pop(s2,&t2) );
      printf("\n\n Occurences of %d=%d",val,c);
   }

void del_occ_ele(int *stack,int *top,int val)
   {  int s2[MAX] ,t2=-1,p_ele;
      while( (*top) != -1)
	{ p_ele=pop(stack,top);
	   if(val!=p_ele)
	        push( s2,&t2,p_ele);
	}
       while( t2 != -1)
           push( stack,top,pop(s2,&t2) );
     }


void bottam_ele(int *stack,int *top)
   {  int s2[MAX] ,t2=-1,b_ele;
      while( (*top) != -1)
	 push( s2,&t2,pop(stack,top) );
      b_ele=pop(s2,&t2);
      while( t2 != -1)
 	push( stack,top,pop(s2,&t2) );
      printf("\n Botttam Element :%d",b_ele);
   }

void main ( )
    { 
        int s1[MAX],t1=-1;
        int no, ch;
        do
	{printf ("\n 1 push");
	  printf ("\n 2 pop");
	  printf ("\n 3 show");
	  printf ("\n 4 reverse ");
	  printf ("\n 5 bottam element ");
	  printf ("\n 6 occurences of ele ");
	  printf ("\n 7 delete occurences of ele ");
	  printf ("\n 0 exit");
	  printf ("\n enter ur your ");
	  scanf ("%d", &ch);
	  switch (ch)
	    {case 1 : printf("\n Enter no : ");
		        scanf("%d", &no);
		        push(s1,&t1,no);
		        break;
	      case 2 : no = pop(s1,&t1);
		         if (no != -999)
		             printf ("\n % d poped ",no);
		         break;
	      case 3 : show(s1,&t1);
		         break;
	      case 4 : reverse(s1,&t1);
		         break;
	      case 5 : bottam_ele(s1,&t1);
		         break;
	      case 6 : printf("\n Enter Ele to count occurences ");
		         scanf("%d",&no);
		         cnt_occ_ele(s1,&t1,no);
		         break;
	      case 7 : printf("\n Enter Ele to delete all occurences ");
		          scanf("%d",&no);
		          del_occ_ele(s1,&t1,no);
		          break;
	      case 0  : break;
	      default : printf("\n invalid choice");
	  }//end of switch 
         }while ( ch !=  0);//end of loop
      }
