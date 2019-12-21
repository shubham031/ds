//Insertion Sort
#include<stdio.h>
#include<conio.h>
void main()
{
	int x[10],i,j,t,no;
	printf("\nEnter 10 number:");
	for(i=0;i<10;i++)
	  scanf("%d",&x[i]);
	printf("\nEntered element before sorting:");
	for(i=0;i<10;i++)
	  printf("   %d",x[i]);
	for(i=1;i<10;i++)
	{
	  if(x[i]<x[i-1])
	  {
		 no=x[i];
		 j=i-1;
			 while(j>=0&&  x[j]>no )
		 {
			x[j+1]=x[j];
			j--;
		 }
		 x[j+1]=no;
	  }//end of if
	}//end of i loop
	printf("\nEntered element after sorting:");
	for(i=0;i<10;i++)
	  printf("   %d",x[i]);
	getch();
}