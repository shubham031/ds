//WAP to array using shell sort method
#include<stdio.h>
#include<conio.h>
void shellsort(int *a,int size)
 {
 int temp,gap,i,swap;
 gap=size/2;
 do{
    do{
       swap=0;
       for(i=0;i<size-gap;i++)
	 { if(a[i]>a[i+gap])
	     {
	     temp=a[i];
	     a[i]=a[i+gap];
	     a[i+gap]=temp;
	     swap=1;
	     }
	 }
      }while(swap);
   }while(gap=gap/2);
 }
void main()
 {
 int x[10],i;
 printf("\n enter array ");
 for(i=0;i<10;i++)
 scanf("%d",&x[i]);
 shellsort(x,10);
 printf("\n after sorting");
 for(i=0;i<10;i++)
    printf("  %d",x[i]);
}
