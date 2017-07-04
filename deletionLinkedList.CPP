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

void pop(struct Node**head, int key)
{
	struct Node* temp=*head, *prev;

   //Check if the head is the key node
   if(temp!=NULL && temp->data==key)
   {
   	*head=temp->next;
      free(temp);
      return 0;
   }

   //Search for the key to be deleted
   while(temp!=NULL && temp-data!=key)
   {
   	prev=temp;
      temp=temp->next;
   }

   //If the key is not found
   if(temp==NULL)
   {
   	return 0;
   }

   //Removing the link of the node from the list
   prev->next=temp->next;
   free(temp);
}

void dispList(struct Node* n)
{
	while(n)
   {
   	cout<<n->data<<" ";
      n=n->next;
   }
}
int main(void)
{
	struct Node* head = NULL;
	push(&head, 10);
   push(&head, 20);
   push(&head, 30);
   push(&head, 40);
   cout<<"The created linked list is : ";
   dispList(head);
   push(&head,40);
   push(&head,10);
   cout<<"\nLinked list after deletion is : ";
   dispList(head);
   getch();
}
