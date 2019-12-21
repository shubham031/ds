#include<stdio.h>
#include<conio.h>

struct tree
{
  int no,level;
  struct tree *left,*right;
};

struct tree *root=NULL;
int dpt;
struct tree * search(int val,int *found)
{
  struct tree *p=root,*par=NULL;
  while(p!=NULL)
  {
    if(val==p->no)
    {
      *found=1;
      return par;
    }
    else if(val>p->no)
    {
      par=p;
      p=p->right;
    }
    else
    {
      par=p;
      p=p->left;
    }
  }
  return par;
}

void insert (int val)
{
  struct tree *parent,*n;
  int f=0;
  n=(struct tree *)malloc(sizeof(struct tree));
  n->no=val;
  n->left=n->right=NULL;
  if(root==NULL)
  {
    root=n;
    root->level=0;
    return;
  }
  parent=search(val,&f);
  if(f==1)
  {
    printf("\nDuplicate No");
    free(n);
    return;
  }
  n->level=parent->level+1;
  if(val>parent->no)
    parent->right=n;
  else
    parent->left=n;
}

void preorder(struct tree *p)
{
  if(p!=NULL)
  {
    printf("%d ",p->no);
    preorder(p->left);
    preorder(p->right);
  }
}

void inorder(struct tree *p)
{
  if(p!=NULL)
  {
    inorder(p->left);
    printf("%d ",p->no);
    inorder(p->right);
  }
}

void postorder(struct tree *p)
{
  if(p!=NULL)
  {
    postorder(p->left);
    postorder(p->right);
    printf("%d ",p->no);
  }
}

void disleafnode(struct tree *p)
{
if(p!=NULL)
  {
    if(p->left==NULL && p->right==NULL)
	printf("%d ",p->no);
    disleafnode(p->left);
    disleafnode(p->right);
  }

}

void samegennodes(struct tree *p,int gen)
{
if(p!=NULL)
  {
    if(p->level==gen)
	printf("%d ",p->no);
    samegennodes(p->left,gen);
    samegennodes(p->right,gen);
  }

}


void depth(struct tree *p)
{
if(p!=NULL)
  {
    if(p->level>dpt)
	dpt=p->level;
    depth(p->left);
    depth(p->right);
  }
}

void deletenode(int val)
{
  struct tree *parent,*child,*r,*p;
  int f=0,t;
  if(root==NULL)
  {
    printf("Tree is Empty");
    return;
  }
  parent=search(val,&f);
  if(f==0)
  {
     printf("\n%d not found",val);
     return;
  }
  if(parent==NULL)
    r=root;
  else
  {
    if(parent->left->no==val)
      r=parent->left;
    else
      r=parent->right;
  }
  /* node has two children */
  if(r->left!=NULL&&r->right!=NULL)
  {
    p=r->right;
    while(p->left != NULL)
	 p=p->left;
    f=0;
    parent=search(p->no,&f);
    t=r->no;
    r->no=p->no;
    p->no=t;
    r=p;
  }
  /* node has no children */
  if(r->left==NULL&&r->right==NULL)
  {
    if(parent->left==r)
      parent->left=NULL;
    else
      parent->right=NULL;
    free(r);
    printf("\n node deleted ");
    return;
  }
  /*node has exactly one children */
  if(r->right!=NULL)
    child=r->right;
  else
    child=r->left;
  if(parent->left==r)
    parent->left=child;
  else
    parent->right=child;
  printf("\n node deleted ");
  free(r);
}


void main()
{
  int  ch,n;
  do
  {
    clrscr();
    printf("\n1. Insert Node");
    printf("\n2. Preorder");
    printf("\n3. Inorder");
    printf("\n4. Postorder");
    printf("\n5. Display All Leaf Nodes");
    printf("\n6. Same Generation Nodes");
    printf("\n7. Depth");
    printf("\n8. Delete Node");
    printf("\n0. Exit");
    printf("\n\nEnter Your Choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter Number ");
	     scanf("%d",&n);
	     insert(n);
	     break;
      case 2:preorder(root);
	     break;
      case 3:inorder(root);
	     break;
      case 4:postorder(root);
	     break;
      case 5:disleafnode(root);
	     break;
      case 6:printf("\nEnter Generation ");
	     scanf("%d",&n);
	     samegennodes(root,n);
	     break;
      case 7:dpt=0;
	     depth(root);
	     printf("\n Depth Of Tree = %d ",dpt);
	     break;
      case 8:printf("\nEnter Number ");
	     scanf("%d",&n);
	     deletenode(n);
	     break;
      case 0:break;
      default:printf("\nWrong Choice...Try Again");
    }
    if(ch!=0)
    {
      printf("\n\nPress any key to continue");
      getch();
    }
  }while(ch!=0);
}