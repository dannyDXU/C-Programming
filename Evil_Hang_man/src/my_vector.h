#ifndef LAB_MY_VECTOR_H
#define LAB_MY_VECTOR_H

#include<stdio.h>
#include "generic.h"
#include "my_string.h"
typedef void*VECTOR;

VECTOR my_vector_init_default(void);

Status my_vector_push(VECTOR,Item);

Status my_vector_pop(VECTOR);

Item* my_vector_at(VECTOR hVector, int index);

int my_vector_get_size(VECTOR);

int my_vector_get_capcity(VECTOR);

void my_vector_destory(VECTOR*);

VECTOR my_vector_copy_key(VECTOR,MY_STRING);

void my_vector_toString(VECTOR);

#endif //LAB_MY_VECTOR_H
