#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
char stack[MAX];int top=-1;         

void  push (char  ch)
  { if (top == MAX -1)
       return ;
    stack [++top]=ch;
   }

char  pop( )
  {if(top==-1)
       return '\0';
    return stack[top--];
  }

int prece(char ch)
  { if( ch=='/' || ch=='*' )
       return 2;
    if( ch=='+' || ch=='-' )
       return 1;
     else 
        return 0;
  }

void main()
  {
  char in[50],post[50],ch;
  int i=0,j=0,len;
  clrscr();
  printf("\n Enter any expression in infix notation :");
  scanf("%s",in);
  len=strlen(in);
  push('(');
  in[len]=')';
  in[len+1]='\0';
  while(in[i] != '\0')
    {
    if( isalpha(in[i]) )
      post[j++]=in[i];
    else if(in[i]=='(')
      push('(');
    else if(in[i]==')')
     {
     while( (ch=pop()) != '(' )
	post[j++]=ch;
     }
    else if(in[i] != ' ')
     {
     while( prece(ch=pop()) >= prece(in[i]) )
	  post[j++]=ch;
     push(ch);
     push(in[i]);
     }
    i++;
    }
    post[j]='\0';
    printf("\n Postfix Expression=%s",post);
    getch();
  }
