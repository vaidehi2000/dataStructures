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

bool search(struct Node *head, int element)
{
   struct Node*current = head;

   while(current!=NULL)
   {
   	if(current->data==element)
      {
      	return true;
      }
   	current=current->next;
   }
   return false;
}
int main(void)
{
	struct Node* head=NULL;
   push(&head,11);
   push(&head,12);
   push(&head,21);
   push(&head,14);
   search(head,2)? cout<<"Yes" : cout<<"No";
   getch();
}