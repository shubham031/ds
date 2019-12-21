//WAP to Implement Circular Link List
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
     {struct node *p=start , *n;
      n = ( struct node * ) malloc( sizeof(struct node ));
      printf("\n enter no : ");
      scanf("%d", &n->no );
      n->next = NULL;
      if( start == NULL )
	{start = n;
	 start->next=start;
	 return ;
	}
      while( p -> next != start)
	{ p=p->next ; }
      p->next = n ;
      n->next=start;
      }
void traverse( struct node *q)
     {
       struct node *r=q;
       do
	{ printf("  %d", q->no );
	  q=q->next ;
	}while(q!=r);
     }
void tra_f_node( struct node *p)
     {int val;
      if ( p == NULL)
	{
	printf("\n empty link node ");
	return;
	}
       printf(" \n Enter No from Which you want to search :");
       scanf("%d",&val);
       do
	{ if(val==p->no)
	    {
	    traverse(p);
	    return;
	    }
	p=p->next ;
	}while(p!=start);
       printf(" %d Not Found ");
      }
void search( )
     {
     struct node *p = start ;
     int val;
     if ( p == NULL)
	{ printf("\n empty link node ");
	  return;
	}
     printf("\n enter element to be searched :");
     scanf("%d" , &val);
     do
       { if ( val == p->no )
	    { printf("\n found ");
	      return ;
	     }
	 p = p->next ;
       }while(p!=start);
      printf("\n element not found ");
      }
void del_all()
     {
     struct node *p;
     do{
	p=start;
	start=start->next;
	free(p);
	}while(p!=start);
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
	 printf("\n Remaining cases same as LINK LIST ");
	 printf("\n 0 Exit ");
	 printf("\n enter your choice :");
	 scanf("%d",&ch);
	 switch ( ch )
	    { case 1 :append();
		      break ;
	      case 2 :tra_f_node(start);
		      break ;
	      case 3 :search();
		      break ;
	      case 0  :del_all();
		       break;
	      }
	    printf("\n Press Any Key To Continue...");
	    getch();
	    }while( ch != 0 );
	  }


