//implementing Binary Tree using array and preforming Preorder traversal

#include<stdio.h>
#include<stdlib.h>

#define size 100 

int bin[size];
int i=0;

void create(int i)  //creating Binary Tree
{
  printf("enter data(-1 to stop)\n");
  int x;
  scanf(" %d",&x);
  if(x == -1)
    return;
  bin[i]=x;
  printf("Enter left child of %d:\n",x);
  create(2*i+1);
  printf("Enter right child of %d:\n",x);
  create(2*i+2);
}

void preorder(i)    //preorder traversal of Binary Tree
{
    if(bin[i]==-999 || i>size-1)
            return;
        printf("\n%d",bin[i]);
        preorder(2*i+1);
        preorder(2*i+2);
}

void main()     
{
    printf("create bintree\n");
    create(i);
    i=0;
    int c;
    
    while(1)
    {
      printf("enter the index of node(-1 to stop)");
      scanf("%d",&c);
      if(c==-1 || c > size-1)
        break;
      printf("left child-%d\nright child-%d\n",bin[2*c+1],bin[2*c+2]);
    }
}