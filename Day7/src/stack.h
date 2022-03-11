#include "status.h"
#ifndef STACK_H
#define STACK_H


typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, char item);

Status stack_pop(STACK hStack);

Boolean stack_empty(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

void stack_destroy(STACK* phStack);

#endif
