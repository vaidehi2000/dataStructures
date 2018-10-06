#include<iostream>
#include<conio>
#include<stdio>
#include<stdlib>

struct Node{ // Linked List Node Structure
	int data;
	struct Node* next;
};

// Adds an element to the head of the list
void push(struct Node**head, int data)
{
	struct Node *newNode= (struct Node*)malloc(sizeof(struct Node)); // allocate memory for new Node

	 if(!newNode) // if memory was not allocated
   {
   	cout<<"Memory Error";
   }

	 // set structure variables
   newNode->data=data;
   newNode->next=*head; // put in front of previous head
   *head = newNode; //new Node is now the head
}

// Adds an element to the end (tail) of the list
void append(struct Node**head, int data)
{
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); // allocate memory for Node
  struct Node *last = *head;

	 // set node data
   newNode->data=data;
   newNode->next=NULL; // end of list -> has no next

   if(*head == NULL) // If empty list
   {
   	*head = newNode; // new node becomes the head
   }

   while(last->next!=NULL) // find last (tail node)
   {
   	last=last->next;
   }

   last->next=newNode; // add to end of list
}

// prints list
void dispList(struct Node *n)
{
	while(n!=NULL)
   {
   	cout<<n->data<<" ";
      n=n->next; // iterate through
   }
}

// add node between 2 nodes in list
void middle(struct Node *prevNode, int data)
{
	if(prevNode==NULL)
   {
   	cout<<"Memory Error";
   }
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); // allocate memory
   newNode->data=data;
   newNode->next=prevNode->next; // add before next node
	prevNode->next=newNode; // add after pervious node
}

// some testing
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
