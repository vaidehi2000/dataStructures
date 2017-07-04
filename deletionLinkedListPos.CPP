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

int pop(struct Node**head, int pos)
{
	if(*head==NULL)
   {
   	cout<<"Memory Error";
   }

   struct Node* temp=*head;

   //If head needs to be removed
   if(pos==0)
   {
   	*head=temp->next;
   	free(temp);
      return 0;
   }

   //Find previous node of the node to be deleted
   for(int i=0; temp!=NULL && i<pos-1;i++)
   {
   	temp=temp->next;
   }

   //If pos is more than the number of nodes
   if(temp==NULL || temp->next++NULL)
   {
   	return 0;
   }

   struct Node* next=temp->next->next;
   free(temp->next);
   temp->next=next;

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
   pop(&head,4);
   pop(&head,1);
   cout<<"\nLinked list after deletion is : ";
   dispList(head);
   getch();
}
