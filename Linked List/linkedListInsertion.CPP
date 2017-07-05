#include<iostream>
#include<conio>
#include<stdio>
#include<stdlib>

struct Node
{
	int data;
   struct Node* next;
};

void push(struct Node**head, int data)
{
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
   if(!newNode)
   {
   	cout<<"Memory Error";
   }

   newNode->data=data;
   newNode->next=*head;
   *head=newNode;
}

void append(struct Node**head, int data)
{
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
   struct Node *last=*head;

   newNode->data=data;
   newNode->next=NULL;

   if(*head==NULL)
   {
   	*head=newNode;
   }

   while(last->next!=NULL)
   {
   	last=last->next;
   }

   last->next=newNode;
}

void dispList(struct Node *n)
{
	while(n!=NULL)
   {
   	cout<<n->data<<" ";
      n=n->next;
   }
}

void middle(struct Node *prevNode, int data)
{
	if(prevNode==NULL)
   {
   	cout<<"Memory Error";
   }
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->next=prevNode->next;
	prevNode->next=newNode;
}
int main(void)
{
	struct Node* head = NULL;
	push(&head, 10);
   append(&head,11);
   push(&head, 9);
   middle(head->next,20); //Can also add head->next->next as an argument
   dispList(head);
   getch();
}
