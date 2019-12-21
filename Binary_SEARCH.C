//Binary Search
#include<stdio.h>
#include<conio.h>
void main()
{
  int x[10]={2,4,5,6,7,8,9,18,30,68};
  int lb=0,ub=9,mid=4,sno;
  clrscr();
  printf("\nEnter searching no:");
  scanf("%d",&sno);
  while(lb<=ub)
  {
	 if(x[mid]==sno)
	 {
		printf("element fount and position=%d",mid+1);
		return;
	 }
	 if(sno<x[mid])
		ub=mid-1;
	 else
		lb=mid+1;
	 mid=(lb+ub)/2;
  }
  printf("\n element not found");
  getch();
}