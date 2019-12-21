//Linear Search
#include<stdio.h>
#include<conio.h>
void main()
{
  int x[10],i,sno;
  clrscr();
  printf("\nEnte 10 Number:");
  for(i=0;i<10;i++)
	 scanf("%d",&x[i]);
  printf("\nEnter searching no:");
  scanf("%d",&sno);
  for(i=0;i<10;i++)
  {
	 if(sno==x[i])
	 {
		printf("\n element is found and position=%d",i+1);
		getch();
		return;
	 }
  }
  printf("\n element not found");
  getch();
}