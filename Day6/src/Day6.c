/*
 ============================================================================
 Program: Linked list reverse
 Author: Danny Xu
 Date: 2/11/2019
 Time Spent: 2 hours
 Purpose: The purpose is to practice with Node* and linked list. To understand how linked list works and how to reverse them.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
void reverseLinkedList(Node** pHead);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node pointer).
     reverseLinkedList(&head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//Define your function here
void reverseLinkedList(Node** pHead){
	Node* previous = NULL;
	Node* current = *pHead;
	Node* next = NULL;

	while(current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*pHead = previous;
}
