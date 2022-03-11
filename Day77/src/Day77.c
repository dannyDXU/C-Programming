#include <stdio.h>
#include <stdlib.h>
enum boolean {
	FALSE, TRUE};

typedef enum boolean Boolean;

enum status {
	FAILURE, SUCCESSFUL};

typedef enum status Status;

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
typedef void* STACK;

Boolean test_case_is_valid(void);
void clear_keyboard_buffer(void);
STACK stack_init_default(void);
Status stack_push(STACK hStack, char item);
Status stack_pop(STACK hStack);
Boolean stack_empty(STACK hStack);
char stack_top(STACK hStack, Status* pStatus);
void stack_destroy(STACK* phStack);
int main(int argc, char* argv[])
{
	int n;
	int i;

	scanf("%d", &n);
	clear_keyboard_buffer();
	for (i = 0; i < n; i++)
	{
		if (test_case_is_valid())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}


Boolean test_case_is_valid(void)
{
	char c;
	int noc;
	STACK hStack;
	hStack = stack_init_default();
	noc = scanf("%c", &c);
	if(noc != 1) {
		return FALSE;
	}
	while (noc == 1 && c != '\n')
	{
		if(c == '(' || c == '{' || c == '[') {
			stack_push(hStack, c);
			noc = scanf("%c", &c);
		}

		if(c == ')' ) {
			if(stack_top(hStack, NULL) == '(' ) {
				stack_pop(hStack);
				noc = scanf("%c", &c);
			}
			else {
				while(c != '\n') {
				noc = scanf("%c", &c);
			    }
				stack_destroy(&hStack);
				return FALSE;
			}
		}

		if(c == '}' ) {
			if(stack_top(hStack, NULL) == '{' ) {
				stack_pop(hStack);
				noc = scanf("%c", &c);
			}
			else {
				while(c != '\n') {
					noc = scanf("%c", &c);
				}
				stack_destroy(&hStack);
				return FALSE;
			}
		}

		if(c == ']' ) {
			if(stack_top(hStack, NULL) == '[' ) {
				stack_pop(hStack);
				noc = scanf("%c", &c);
			}
			else {
				while(c != '\n') {
					noc = scanf("%c", &c);
				}
				stack_destroy(&hStack);
				return FALSE;
			}
		}
		while(c == ' ') {
			noc = scanf("%c", &c);
		}
	}

	if(stack_empty(hStack) != TRUE) {
		stack_destroy(&hStack);
		return FALSE;
	}
	stack_destroy(&hStack);
	return TRUE;
}

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



void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
