//Linear Merge
#include<stdio.h>
#include<conio.h>
void main()
{
  int x[5]={2,5,10,100,112};
  int y[7]={2,15,20,35,60,65,90};
  int z[12],i=0,j=0,k=0;
  clrscr();
  while(i<5&&j<7)
  {
	 if(x[i]<y[j])
		z[k++]=x[i++];
	 else
		z[k++]=y[j++];
  }
  if(i<5)
  {
	 while(i<5)
		z[k++]=x[i++];
  }
  else
  {
	 while(j<7)
		z[k++]=y[j++];
  }
  printf("\nmearged array is:");
  for(k=0;k<12 ;k++)
	 printf("  %d",z[k]);
  getch();
}