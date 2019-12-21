#include<stdio.h>
#include<conio.h>                                            
#include<ctype.h>
# define MAX 50
float stack [MAX];int top = -1;

void  push (float  val)
  { if (top == MAX -1)
       return ;
     stack [++top]=val;
   }

float  pop( )
  { if(top==-1)
        return -0.0;
    return stack[top--];
  }



void main()
 {char post[50];
   int i=0;
   float A,B,C;
   clrscr();
   printf("\n Enter any expression in post notation(in Numeric Form):");
   scanf("%s",post);
   while(post[i] != '\0')
     { if( isdigit(post[i]) )
	push(post[i]-48);
     else if(post[i] != ' ')
       { A=pop();
          B=pop();
          if(post[i]=='+')
            C=B+A;
          else if(post[i]=='-')
             C=B-A;
          else if(post[i]=='*')
             C=B*A;
          else if(post[i]=='/')
             C=B/A;
          push(C);
        }
      i++;
     }//end of loop
    printf("\n Answer Of Postfix Expression=%f", pop() );
  }

