#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node;
typedef struct node Node;

struct node
{
	char data;
	Node* next;
};

struct stack
{
	Node* head;
};
typedef struct stack Stack;

STACK stack_init_default(void) {
	Stack* pStack;
		pStack = (Stack*) malloc(sizeof(Stack));
		if (pStack != NULL)
		{
			pStack->head = NULL;
		}
		return pStack;
}

Status stack_push(STACK hStack, char item) {
	Stack* pStack = (Stack*)hStack;
		Node* pTemp;
		pTemp = (Node*) malloc(sizeof(Node));
		if (pTemp == NULL)
		{
			return FAILURE;
		}
		pTemp->data = item;
		pTemp->next = pStack->head;
		pStack->head = pTemp;
		return SUCCESSFUL;
}
Status stack_pop(STACK hStack) {
	Stack* pStack = (Stack*)hStack;
	Node* pTemp;

	if(pStack->head == NULL) {
		return FAILURE;
	}
	pTemp = pStack->head->next;

	free(pStack->head);

	pStack->head = pTemp;

	return SUCCESSFUL;
}
Boolean stack_empty(STACK hStack){
	Stack* pStack = (Stack*)hStack;
	if(pStack->head != NULL) {
		return FALSE;
	}
	return TRUE;
}

char stack_top(STACK hStack, Status* pStatus){
	Stack* pStack = (Stack*)hStack;
	if(pStack->head == NULL) {
		return NULL;
	}
	return pStack->head->data;
}

void stack_destroy(STACK* phStack){
	Node* temp;
	Stack* pStack = (Stack*)*phStack;

	while(pStack->head != NULL) {
		temp = pStack->head->next;
		free(pStack->head);
		pStack->head = temp;
	}
	free(pStack);
	*phStack = NULL;
}

