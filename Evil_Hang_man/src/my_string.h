#ifndef LAB_MY_STRING_H
#define LAB_MY_STRING_H

#include<stdio.h>
#include "generic.h"
typedef void* MY_STRING;


Status continue_key(MY_STRING key);

MY_STRING my_string_init_default(void);

MY_STRING my_string_init_c_string(char*);

Status my_string_extraction(MY_STRING,FILE*);

Status my_string_insertion(MY_STRING,FILE*);

int my_string_get_capacity(MY_STRING);

int my_string_get_size(MY_STRING);

int my_string_compare(MY_STRING,MY_STRING);

void my_string_unsertion(MY_STRING);

void my_string_destroy(Item* phMy_string);

Status my_string_push_back(MY_STRING hMy_string, char item);

Status my_string_pop_back(MY_STRING hMy_string);

Status my_string_isempty(MY_STRING hMy_string);

char* my_string_at(MY_STRING hMy_string, int index);

char* my_string_c_str(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

void my_string_assignment(Item* pLeft, Item Right);

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);

Status is_key(MY_STRING,MY_STRING);
