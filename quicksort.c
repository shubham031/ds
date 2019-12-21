#include<stdio.h>
#include<conio.h>
int quick(int *p,int l, int u)
   { int pos=l,t;
     while(1)
      {
      while(p[u]>p[pos] && pos != u)
	  u--;
      if(pos==u)
	return pos;
      else
        {
          t=p[pos];
          p[pos]=p[u];
          p[u]=t;
          pos=u;   }
      while(p[l]<=p[pos] && pos != l)
	  l++;
       if(pos==l)
	 return pos;
       else
         {
          t=p[pos];
          p[pos]=p[l];
          p[l]=t;
          pos=l;  
         }  
      }   
   }
void quicksort(int *p,int n)
   {
   int lb=0,ub=n-1,pos;
   int lower[10],upper[10],top=-1;
   lower[++top]=lb;
   upper[top]=ub;
   while(top != -1)
      {
      lb=lower[top];
      ub=upper[top--];
      pos=quick(p,lb,ub);
      if(pos+1<ub)
        {
        lower[++top]=pos+1;
        upper[top]=ub;
        }
      if(pos-1>lb)
        {
        lower[++top]=lb;
        upper[top]=pos-1;
        }
      }
   }

 void main()
   {  int x[10],i;
      clrscr();
      printf("\n Enter Array X ");
      for(i=0;i<10;i++)
           scanf("%d",&x[i]);
       quicksort(x,10); //calling fn 
       printf("\n After Sortig ");
       for(i=0;i<10;i++)
            printf("  %d",x[i]);
   }
