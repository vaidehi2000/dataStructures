#include<conio>
#include<stdio>
#include<iostream>
#include<stdlib>

struct Node
{
	int data;
   struct Node* next;
};

int push(struct Node**head, int data)
{
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
   if(!newNode)
   {
   	cout<<"Memory Error";
   }

   newNode->data=data;
   newNode->next=*head;
   *head=newNode;
   return 0;
}

void count(struct Node *head)
{
	int count=0;
   struct Node*current = head;

   while(current!=NULL)
   {
   	current=current->next;
      count++;
   }
   cout<<"The number of nodes are "<<count;
}
int main(void)
{
	struct Node* head=NULL;
   push(&head,1);
   push(&head, 1);
   push(&head, 2);
   push(&head, 1);
	count(head);
   getch();
}