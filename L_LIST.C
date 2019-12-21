#include<stdio.h>
#include<alloc.h>
#include<conio.h>
struct  node
	  {
	   int no;
	   struct node * next;
	   };
struct node *start=NULL,*start1=NULL;

void append( )
	 {
	  struct node *p=start , *n;
	  n = ( struct node * ) malloc( sizeof(struct node ));
	  printf("\n enter no : ");
	  scanf("%d", &n->no );
	  n->next = NULL;
	  if ( start == NULL )
	      {
		start = n;
		 return ;
	       }
	  while( p -> next != NULL)
		    {
		     p=p->next ;
		     }
	    p->next = n ;
	   }
void traverse( struct node *p)
	 {
	  if ( p == NULL)
	      {
		printf("\n empty link node ");
		 return;
	      }
	printf(" \n start ");
	while ( p != NULL )
		   {
		    printf("  %d", p->no );
		    p=p->next ;
		    }
	printf("  end ");
	}

void search( )
     {
	  struct node *p = start ;
	  int val;
	  if ( p == NULL)
	      {
		printf("\n empty link node ");
		 return;
	      }
	printf("\n enter element to be searched :");
	scanf("%d" , &val);
	while ( p != NULL )
		   {
		     if ( val == p->no )
			{
			 printf("\n found ");
			 return ;
			}
		    p = p->next ;
		  }
	  printf("\n element not found ");
      }

void update( )
     {
	  struct node *p = start ;
	  int val;
	  if ( p == NULL)
	      {
		printf("\n empty link node ");
		 return;
	      }
	printf("\n enter element to be updated :");
	scanf("%d", &val);
	while ( p != NULL )
		   {
		     if ( val == p->no )
			{
			 printf("\n enter new  no : ");
			 scanf("%d",&p->no );
			 printf("\n element updated ");
			 return;
			 }
		    p = p->next ;
		  }
	  printf("\n element not found ");
      }


void insertafter()
   {
   struct node *p=start,*n;
   int  val;
   if(start==NULL)
     {
     printf("\n empty link list");
     return;
     }
   printf("\n enter no after which we insert no ");
   scanf("%d",&val);
   while(p != NULL)
       {
       if(val==p->no)
	{
	     n=(struct node*)malloc( sizeof(struct node));
	     printf("\n enter no");
	     scanf("%d",&n->no);
	    n->next=p->next;
	    p->next=n;
	    printf("\n node inserted");
	    return;
	    }
       p=p->next;
       }
    printf("\n %d not found" , val );
    }


void insertbefore()
     {
     struct node *p=start,*n;
     int  val;
     if(start==NULL)
       {
      printf("\n empty linf node");
      return;
      }
    printf("\n enter no before which we inserted no");
    scanf("%d",&val);
    if(val==start->no)
       {
       n=(struct node*)malloc( sizeof(struct node));
       printf("\n enter no");
       scanf("%d",&n->no);
       n->next=start;
       start=n;
       return;
       }
 while(p->next != NULL)
    {
    if(val==p->next->no)
      {
      n=(struct node*)malloc( sizeof(struct node));
      printf("\n enter no");
      scanf("%d",&n->no);
      n->next=p->next;
      p->next=n;
      return;
      }
    p=p->next;
    }
  printf("\n %d not found", val );
  }


void insertbypos()
   {
   struct node *p=start , *n ;
   int  pos , non=0 , i ;
   if(start== NULL)
     {
     printf("\n empty link list ");
     return;
     }
  while(p!=NULL)
    {
    non=non+1;
    p=p->next;
    }
  p=start;
  printf(" \n enter the position ");
  scanf("%d",&pos);
  if( pos<1 || pos>non+1 )
    {
    printf("\n invalid position ");
    return;
    }
  n=(struct node*)malloc( sizeof(struct node));
  printf(" \n enter no");
  scanf("%d",&n->no);
  if(pos==1)
    {
    n->next=start;
   start=n;
   return;
   }
for(i=1;i<=pos-2;i++)
    {
    p=p->next;
    }
 n->next=p->next;
 p->next=n;
 return;
 }


void deletebyval()
     {
     struct node *p=start,*d ;
     int  val;
    if(start==NULL)
      {
      printf("\n empty link node ");
      return;
      }
   printf("\n enter no before which we inserted no ");
   scanf("%d",&val);
   if(val==start->no)
     {
     start=start->next;
     free(p);
     return;
     }
  while(p->next!=NULL)
     {
     if(val==p->next->no)
	{
	 d=p->next;
	 p->next=d->next;
	 free(d);
	 return;
	 }
     p=p->next;
     }
    printf("\n %d not found ",val);
    }





void deletebypos( )
     {
     struct node *p=start,*d;
     int  pos, i,non=0;
     if(start==NULL)
       {
       printf("\n empty linf node ");
       return;
       }
    while(p!=NULL)
       {
       non=non+1;
       p=p->next;
       }
    p=start;
    printf(" \n enter the position of node to be deleted :");
    scanf("%d",&pos);
   if(pos<1||pos>non+1)
       {
       printf("\n invalid position ");
       return;
       }
   if(pos==1)
       {
       start=start->next;
       free(p);
       printf("\n node deleted ");
       return;
       }
    for(i=0;i<pos-2;i++)
          p=p->next;
    d=p->next;
    p->next=d->next;
    free(d);
    printf("\n node deleted ");
}


void sort()
    {
    struct node *p,*q;
    int  temp;
    if(start==NULL)
      {
      printf("\n empty link node");
      return;
      }
   if(start->next==NULL)
       {
       printf("\n single node only");
       return;
       }
     for(p=start; p->next!=NULL; p=p->next)
	{
	for(q=p->next;q!=NULL;q=q->next)
	     {
	     if(q->no<p->no)
		{
		temp=p->no;
		p->no=q->no;
		q->no=temp;
		}
	     }
	}
  }

void reverse()
     {
     struct node *p , *pre , *ne;
     if(start==NULL)
       {
       printf("\n empty link node");
       return;
       }
     else if(start->next==NULL)
      {
      printf("\n only single node");
      return;
      }
    pre=start;
    p=start->next;
    ne=p->next;
    pre->next=NULL;
    while(p!=NULL)
       {
	p->next=pre;
	pre=p;
	p=ne;
       if(ne!=NULL)
	 {
	 ne=ne->next;
	 }
      start=pre;
      printf("\n reverse link list is ");
     traverse(start);
      }
     }
void split()
    {
    int non=0,i;
    struct node *p=start;
    while(p != NULL)
	{
	non++;
	p=p->next;
	}
     p=start;
     for(i=1;i<non/2;i++)
	  p=p->next;
     start1=p->next;
     p->next=NULL;
     printf("\n first link list ");
     traverse(start);
     printf("\n second link list ");
     traverse(start1);
     }

void split_e_o()
       {









      }

void del_all()
     {
     struct node *p;
     while(start!=NULL)
	 {
	 p=start;
	 start=start->next;
	 free(p);
	 }
     }

void main( )
	{
	 int ch;
	 do
	 {
    clrscr();
	 printf("\n 1 append          :");
	 printf("\n 2 traverse        :");
	 printf("\n 3 search          :");
	 printf("\n 4 update          :");
	 printf("\n 5 insert after    :");
	 printf("\n 6 insert before   :");
	 printf("\n 7 insert by pos   :");
	 printf("\n 8 delete by val   :");
	 printf("\n 9 delete by pos   :");
	 printf("\n 10 sort           :");
	 printf("\n 11 reverse        :");
	 printf("\n 12 split          :");
	 printf("\n  0  exit          :");
	 printf("\n enter your choice :");
	 scanf("%d",&ch);
	 switch ( ch )
			{
			 case 1 : append (  );
				  break ;
			 case 2 : traverse( start );
				  break ;
			 case 3 : search (  );
				  break ;
			 case 4 : update (  );
				  break ;
			 case  5 :insertafter(  );
				  break ;
			 case 6 : insertbefore (  );
				  break ;
			 case 7 : insertbypos (  );
				  break ;
			 case 8 : deletebyval (  );
				  break ;
			 case 9 :  deletebypos(  );
				  break ;
			 case 10 : sort (  );
				  break ;
			 case 11 : reverse();
				  break ;
			 case 12 : split( );
					break ;
			 case 13 : split_e_o( );
						break;
			 case 0  : del_all( );
						 break;
			}
			printf("\n Press Any Key To Continue...");
         getch();
			}while( ch != 0 );
			 }


