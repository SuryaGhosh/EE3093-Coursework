#include "tutorial5.h"
#include <stdio.h>
#include <stdlib.h>

// linked list

typedef struct node {
	int data;			// current data
	struct node *next;	// pointer to the next node 
} node;

void print_list(node **head);
void remove_tail(node **head);
void remove_head(node **head);
node* get_node(node **head, int n);
void add_head(node **head, int data);
void delete_node(node **head, int n);
void reverse_list(node **head);
void split_list(node **head, node **front, node **back);

void run_tutorial_5() {
	node *head = NULL;
	node *current_node = NULL;

	print_list(&head);
	remove_head(&head);
	add_head(&head, 5);
	add_head(&head, 3);
	add_head(&head, 6);
	add_head(&head, 9);
	remove_head(&head);
	print_list(&head); 
	remove_head(&head);
	print_list(&head);
	get_node(&head, 3);
	get_node(&head, 10);
	get_node(&head, 0);
	remove_tail(&head);
	print_list(&head);
	remove_tail(&head);
	print_list(&head);
	remove_tail(&head);
	print_list(&head);
	remove_tail(&head);
	print_list(&head);
	add_head(&head, 7);
	add_head(&head, 2);
	print_list(&head);
	remove_tail(&head);
	print_list(&head);
	add_head(&head, 1);
	add_head(&head, 3);
	add_head(&head, 3);
	print_list(&head);
	remove_head(&head);
	print_list(&head);
	delete_node(&head, 1);
	print_list(&head);
	delete_node(&head, 0);
	print_list(&head);
	delete_node(&head, 0);
	delete_node(&head, 0);
	add_head(&head, 11);
	add_head(&head, 33);
	add_head(&head, 22);
	delete_node(&head, 1);
	print_list(&head);
	add_head(&head, 9);
	add_head(&head, 3);
	add_head(&head, 6);
	add_head(&head, 1);
	print_list(&head);
	reverse_list(&head);
	print_list(&head);

	node* front = NULL;
	node* back = NULL;
	split_list(&head, &front, &back);
	print_list(&front);
	print_list(&back);
}

void print_list(node **head) {
	node* p;
	int i = 0;
	printf("\n\nPrinting List:\n");
	for (p = *head; p != NULL; p = p->next) {
		printf("node[%d]: %d\n", i, p->data);
		i++;
	}
	if (i == 0) {
		printf("\nList is empty!\n");
	}
}
	
void remove_tail(node **head) { // the address of head is passed in, if we do node* then it is passed by reference    
	printf("\nRemoving tail.");
	node *p, *q = NULL; // creates null node pointers p and q 

	// the list is empty
	if (*head == NULL) { 
		printf("\nList is empty!");
		return;
	}

	// there is only one element in the list
	if ((*head)->next == NULL) {
		free(*head); // frees node/memory
		*head = NULL; // sets head to null to prevent dangling pointer
		return;
	}

	// iterates through list until the next node is NULL
	for (p = *head; p->next != NULL; p = p->next) { // p=p->next updates p, its actual value changes
		q = p; // in essence, q stores the 2nd to last node in the list
	}

	if (q != NULL) {
		// reassign q next to be NULL
		q->next = NULL;
	}

	// removes the last node 
	free(p);
}

void remove_head(node **head) { // the address of head is passed in
	printf("\nRemoving head");
	if (*head == NULL) { // we use *head to access the value stores at the address
		printf("\nList is empty, no head removed!\n");
		return;
	}

	//node* p = (node*)malloc(sizeof(node)); // unnecessary; we want p to refer head directly instead of storing values

	node *p = (*head); // is a placeholder for head so we can have a reference to its memory
	*head = (*head)->next; // changes head to the succeeding value
	printf("\nRemoved head storing %d.", p->data);
	free(p); // frees memory previously held by head
}

void add_head(node **head, int data) { //since head is a pointer type, defined as *head, we need to pass it as **head. ie a pointer to the head pointer
	printf("\nAdding head: %d", data);

	node *p = (node*)malloc(sizeof(node));

	p->data = data;
	p->next = *head; // **head is a pointer to a pointer, therefore *head derefernces it 

	*head = p;
}

node *get_node(node **head, int n) {
	printf("\nFetching node number: %d", n);
	node* temp = *head;

	int i;
	for (i=0; i<n; i++) {
		temp = temp->next; 

		if (temp == NULL) {
			printf("\nElement out of bounds!");
			return NULL;
		}
	}
	printf("\Node %d: %d", n, temp->data);
	return temp;
}

void delete_node(node **head, int n) { 
	// deletes the nth node 
	// we need to link the preceding node to the succeeding one 
	// the node may be at the beginning, middle, or end of the list 

	printf("\nDeleting node: %d", n);

	int node_num = 0;
	node *q = NULL;
	node *p = *head;

	if (n == 0) {
		remove_head(head);
		return;
	}
	while (p != NULL) {
		if (node_num == n) {
			q->next = p->next;
			free(p);
			return;
		}
		q = p;
		p = p->next;
		node_num++;
	}
	printf("Node %d out of bounds!", n);
}

void reverse_list(node **head) {
	printf("\nReversing list");
	node *prev = NULL;
	node *curr = *head;
	node *next = NULL;

	while (curr != NULL) {
		next = curr->next; // stores next node
		curr->next = prev; // reverses direction
		prev = curr;	   // updates prev data to store curr data, ie moves prev down the list  
		curr = next;	   // moves curr down the list 
	}

	*head = prev;
}

void split_list(node **head, node **front, node **back) {
	printf("\nSplitting list");

	// Used the "hare and tortoise" algoritm. We move one pointer 2 nodes at a time, 
	// and the other pointer 1 node at a time. When the first pointer has reached the
	// end of the list, the second one will be at the middle.
	// 
	// what tortoise is half as fast as a hare??

	node *fast, *slow;
	fast = (*head)->next; // this assures that even-length lists are split equally, otherwise fast starts too late
	slow = *head;

	while (fast != NULL && fast->next != NULL) { // we need to assert that fast->next isn't null so we can access fast->next->next
		slow = slow->next;
		fast = fast->next->next;
	} 

	*front = *head;
	*back = slow->next;
	slow->next = NULL; // this cuts the list in half, properly allocating the front, and making the back list point to NULL
}