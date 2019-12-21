//Selection Sorting
#include<stdio.h>
#include<conio.h>
void main()
{
  int x[10],i,j,t,s,p;
  printf("\nEnter 10 number:");
  for(i=0;i<10;i++)
	 scanf("%d",&x[i]);
  printf("\nEntered element before sorting:");
  for(i=0;i<10;i++)
	 printf("   %d",x[i]);
  for(i=0;i<9;i++)
  {
	 for(j=i+1;j<10;j++)
	 {
		if(x[i]>x[j])
		{
		  t= x[i];
		  x[i]=x[j];
		  x[j]=t;
		}
	 }//end of j loop
  }
  printf("\nEntered element after sorting:");
  for(i=0;i<10;i++)
	 printf("  %d",x[i]);
  getch();
}