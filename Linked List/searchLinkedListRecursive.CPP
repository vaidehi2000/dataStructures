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

   if(head==NULL)
   {
   	return false;
   }

   else if(head->data==element)
   {
   	return true;
   }

   search(head->next,14);
}
int main(void)
{
	struct Node* head=NULL;
   push(&head,11);
   push(&head,12);
   push(&head,21);
   push(&head,14);
   search(head,14)? cout<<"Yes" : cout<<"No";
   getch();
}