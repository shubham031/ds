#include<stdio.h>
#include<conio.h>
struct node
    {
    int no;
    struct node *next,*pre;
    };
struct node *start=NULL,*last=NULL;
void append()
     { 
     struct node *n;
     n=(struct node *)malloc(sizeof(struct node));
     printf("\n Enter No :");
     scanf("%d",&n->no);
     n->next=NULL;
     if(start==NULL)
       {
       start=last=n;
       start->pre=NULL;
       printf("\n Node Appended ");
       return;
       }
     last->next=n;
     n->pre=last;
     last=n;
     printf("\n Node Appended ");
     }
void ftraverse()
     {
     struct node *p=start;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return;
       }
     printf("\n START ");
     while(p!=NULL)
       {
       printf("  %d",p->no);
       p=p->next;
       }
     printf("  END  \n");
     }
void btraverse()
     {
     struct node *p=last;
     if(last==NULL)
       {
       printf("\n Empty Link List ");
       return;
       }
     printf("\n LAST ");
     while(p!=NULL)
       {
       printf("  %d",p->no);
       p=p->pre;
       }
     printf("  START  \n");
     }
void search(struct node *p)
     {
     int val;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return;
       }
     printf("\n Enter Element to be search :");
     scanf("%d",&val);
     if(p==start)
       while(p!=NULL)
	 {
	 if(val==p->no)
	   {
	   printf(" \n Found " );
	   return;
	   }
	 p=p->next;
	 }
     else
       while(p!=NULL)
	 {
	 if(val==p->no)
	   {
	   printf(" \n Found " );
	   return;
	   }
	 p=p->pre;
	 }
     printf("\n Not Found ");
     }
void update(struct node *p)
     {
     int val;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return;
       }
     printf("\n Enter Element to be updated :");
     scanf("%d",&val);
     if(p==start)
       while(p!=NULL)
	 {
	 if(val==p->no)
	   {
	   printf(" \n Enter New No :" );
	   scanf("%d",&p->no);
	   printf("\n Node Updated ");
	   return;
	   }
	 p=p->next;
	 }
     else
       while(p!=NULL)
	 {
	 if(val==p->no)
	   {
	   printf(" \n Enter New No :" );
	   scanf("%d",&p->no);
	   printf("\n Node Updated ");
	   return;
	   }
	 p=p->pre;
	 }
     printf("\n Not Found ");
     }
void insert_after()
     {
     struct node *p=start , *n;
     int val;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return ;
       }
     printf("\n Enter Value After Which You Want To Insert New Node :");
     scanf("%d",&val);
     while(p != NULL)
       {
       if(val==p->no)
	 {
	 n=(struct node*)malloc(sizeof(struct node));
	 printf("\n Enter No :");
	 scanf("%d",&n->no);
	 n->next=p->next;
	 p->next=n;
	 n->pre=p;
	 n->next->pre=n;
	 if(p==last)
	    last=n;
	 printf("\nNode Inserted ");
	 return;
	 }
       p=p->next;
       }
     printf("\n %d Not Found ",val);
     }
void insert_before()
     {
     struct node *p=start , *n;
     int val;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return ;
       }
     printf("\n Enter Value Before Which You Want To Insert New Node :");
     scanf("%d",&val);
     while(p != NULL)
       {
       if(val==p->no)
	 {
	 n=(struct node*)malloc(sizeof(struct node));
	 printf("\n Enter No :");
	 scanf("%d",&n->no);
	 n->pre=p->pre;
	 p->pre=n;
	 n->next=p;
	 n->pre->next=n;
	 if(p==start)
	    start=n;
	 printf("\nNode Inserted ");
	 return;
	 }
       p=p->next;
       }
     printf("\n %d Not Found ",val);
     }
void insert_by_pos()
     {
     struct node *p=start , *n;
     int pos,non=0,i;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return ;
       }
     while(p!=NULL)
	 {
	 non++;
	 p=p->next;
	 }
     p=start;
     printf("\n Enter Position of node to be Insert :");
     scanf("%d",&pos);
     if(pos<1 || pos>non+1)
       {
       printf("\n Invalid Position ");
       return;
       }
     n=(struct node*)malloc(sizeof(struct node));
     printf("\n Enter No :");
     scanf("%d",&n->no);
     if(pos==1)
       {
       n->next=start;
       start->pre=n;
       start=n;
       start->pre=NULL;
       printf("\n Node Inserted ");
       return;
       }
     else if(pos==non+1)
       {
       n->pre=last;
       last->next=n;
       last=n;
       last->next=NULL;
       printf("\n Node Inserted ");
       return;
       }
     else
       {
       for(i=1;i<=pos-2;i++)
	  p=p->next;
       n->next=p->next;
       n->pre=p;
       p->next=n;
       n->next->pre=n;
       printf("\n Node Inserted ");
       }
     }
void del_by_val()
     {
     struct node *p=start,*d;
     int val;
     if(start==NULL)
       {
       printf("\n Empty Link List ");
       return;
       }
     printf("\n Enter value which you want to delete from link list :");
     scanf("%d",&val);
     if(val==start->no)
       {
       start=start->next;
       start->pre=NULL;
       free(p);
       printf("\n Node Deleted ");
       return;
       }
     if(val==last->no)
       {
       p=last;
       last=last->pre;
       last->next=NULL;
       free(p);
       printf("\n Node Deleted ");
       return;
       }
     while(p->next != NULL)
	{
	if(val==p->no)
	  {
	  d=p;
	  p->pre->next=p->next;
	  p->next->pre=p->pre;
	  free(d);
	  printf("\n Node Deleted ");
	  return;
	  }
	p=p->next;
	}
     printf("\n %d Not found ",val);
     }
void del_by_pos()
     {
     //assignment
     }
void del_all()
     {
     struct node *p=start;
     while(start!=NULL)
       {
       p=start;
       start=start->next;
       free(p);
       }
     last=NULL;
     }
void main()
     {
     int ch;
     do
      {
      clrscr();
      printf("\n 1 Append ");
      printf("\n 2 Forword Traversing ");
      printf("\n 3 Backword Traversing ");
      printf("\n 4 Search ");
      printf("\n 5 Update ");
      printf("\n 6 Insert After ");
      printf("\n 7 Insert Before ");
      printf("\n 8 Insert By Pos ");
      printf("\n 9 Delete By Val ");
      printf("\n10 Delete By Pos ");
      printf("\n 0 Exit ");
      printf("\n Enter Your Choice :");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1 : append();
		 break;
	case 2 : ftraverse();
		 break;
	case 3 : btraverse();
		 break;
	case 4 : search(start);//or//search(last);
		 break;
	case 5 : update(start);//or//update(last);
		 break;
	case 6 : insert_after();
		 break;
	case 7 : insert_before();
		 break;
	case 8 : insert_by_pos();
		 break;
	case 9 : del_by_val();
		 break;
	case 10: del_by_pos();//assignment
		 break;
	case 0 : del_all();
		 break;
	default: printf("\n Invalid Choice ....");
	}//end of switch
      printf("\n Press any key to continue...");
      getch();
      }while(ch!=0);//end of loop
     }//end of main
