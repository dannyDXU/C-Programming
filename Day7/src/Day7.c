/*
 ============================================================================
 Program	  : 673 Problem solver program
 Author       : Danny Xu
 Date         :4/29/2019
 Time Spent   : 3 days
 Purpose      :	The purpose of this program is to practice with stacks. To do that we had to practice with pushing char into the stack and how to pop the things out of stack. By learning these fundamentals, we can solve the 673 problem.
 ============================================================================
 */

#include <stdio.h>
#include "stack.h"
#include "status.h"
#include "boolean.h"

Boolean test_case_is_valid(void);

void clear_keyboard_buffer(void);

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

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
