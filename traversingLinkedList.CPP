#include<iostream>
#include<conio>
#include<stdio>
#include<stdlib>

struct Node
{
	int data;
   struct Node*next;
};

/*Function to traverse the linked list*/
void printList(struct Node *n)
{
	while(n != NULL)
   {
   	cout<<n->data<<" ";
      n = n->next;
   }
}

int main(void)
{
	struct Node* head = NULL;
   struct Node* second = NULL;
   struct Node* third = NULL;

   /* Allocate three nodes in the heap */
   head = (struct Node*)malloc(sizeof(struct Node));
   second = (struct Node*)malloc(sizeof(struct Node));
   third = (struct Node*)malloc(sizeof(struct Node));

   head->data = 1;
   head->next = second;

	second->data = 2;
   second->next = third;

   third->data = 3;
   third->next = NULL;

   printList(head);
   getch();

}
