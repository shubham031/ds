#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int f=-1,r=-1;



void insertrear(int no)
  { if((f==0&&r==MAX-1)||(r+1==f))
     {
     printf("\nQueue is Full");
     return;  }
   else
     {  if(r==-1)
           f=r=0;
        else if(r==MAX-1)
           r=0;
        else
          r++;
        queue[r]=no;
      }
   }
int deletefront()
 { int val;
   if(f==-1)
     { printf("\nQueue is Empty");
       return -999;
      }
   else
    { val=queue[f];
       if(f==r)
          f=r=-1;
       else if(f==MAX-1)
          f=0;
       else
          f++;
     }
  return val;
  }
void show()
  {  int i=f;
    if(f==-1)
     {  printf("\nQueue is Empty");
        return; }
   while(i!=MAX)
     {  printf("%d  ",queue[i]);
        if(i==r)
          break;
        else if(i==MAX-1)
          i=0;
        else
          i++;
      }
}
void main()
{  int  ch,n;
   do
    {  printf("\n1. Insert in Rear");
       printf("\n2. Delete from Front");
       printf("\n3. Show");
       printf("\n0. Exit");
       printf("\n\nEnter Your Choice");
       scanf("%d",&ch);
       switch(ch)
         {
         case 1 : printf("\nEnter Number ");
	          scanf("%d",&n);
	          insertrear(n);
	          break;
         case 2 : n=deletefront();
	          if(n!=-999)
	             printf("\n%d deleted",n);
	          break;
         case 3 : show();
	           break;
         case  0 :break;
         default : printf("\nWrong Choice...Try Again");
       }
    }while(ch!=0);
}


