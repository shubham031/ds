//Bubble Sorting
#include<stdio.h>
#include<conio.h>
void main()
{
  int x[10],i,j,t;
  printf("\nEnter 10 number:");
  for(i=0;i<10;i++)
  scanf("%d",&x[i]);
  printf("\n before sorting");
  for(i=0;i<10;i++)
	 printf("  %d",x[i]);
  for(i=0;i<10;i++)
  {
	 for(j=0;j<9-i;j++)
	 {
		if(x[j]>x[j+1])
		{
		  t=x[j];
		  x[j]=x[j+1];
		  x[j+1]=t;
		}
	 }//end of j loop
  }//end of i loop
  printf("\n after sorting");
  for(i=0;i<10;i++)
	 printf("  %d",x[i]);
  getch();
}