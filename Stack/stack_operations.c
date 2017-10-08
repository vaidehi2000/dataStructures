#include <stdio.h> /* printf, scanf */
#include <stdlib.h> /* malloc, free */
#include <stdbool.h> /* type bool */

/* Stack Implementation in C */

/* struct that defines our stack node */
typedef struct StackNode {
	int key;
	struct StackNode* next;
} Stack;

void stack_new(Stack **top);
void stack_push(Stack **top, int key);
bool stack_pop(Stack **top, int *key);
bool stack_empty(Stack *top);

void print_stack(Stack *top);

int main() {
	int opt, k;
	
	/* Creates a stack */
	Stack *top;
	stack_new(&top);

	do {
		printf("1. Push\n2. Pop\n3. Print Stack\n0. Exit\nEnter the option: ");
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				printf("Enter the key: ");
				scanf("%d", &k);
				stack_push(&top, k);
				break;
			case 2:
				if (stack_pop(&top, &k))
					printf("Node with key %d removed.\n", k);
				else
					printf("Stack is empty.\n");

				break;
			case 3:
				print_stack(top);
				break;
		}
	} while (opt != 0);
}

void stack_new(Stack **top) {
	*top = NULL;
}

/* Insert a new node in stack */
void stack_push(Stack **top, int key) {
	Stack *elem = (Stack*) malloc(sizeof(Stack));

	if (!elem) {
		printf("Error: malloc failed.\n");
		return;
	}

	/* Substitute top by elem in stack */
	elem->key = key;
	elem->next = *top;
	*top = elem;
}

/* Remove the top of stack and assign to key* the key of removed node */
bool stack_pop(Stack **top, int *key) {
	/* If stack is empty, don't have nodes to pop */
	if (stack_empty(*top)) return false;

	Stack *elem = *top;
	*top = elem->next; /* change top of stack for the next element */
	*key = elem->key;
	free(elem); /* free memory of removed node */
	return true;
}

bool stack_empty(Stack *top) {
	return top == NULL;
}

void print_stack(Stack *top) {
	Stack *e = top;

	while (e != NULL) {
		printf("| key: %04d |\n", e->key);
		e = e->next;
	}
	printf("\n");
}
