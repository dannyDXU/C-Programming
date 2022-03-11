/*
 ============================================================================
 Name        : Danny Xu
 Date        : 2/25/2019
 Effort      : Two Hours
 purpose     : The purpose is to use your knowledge on vectors and create an array that will store the bits as 1s and 0s.
 Interface Proposal : Maybe a function that will tell you what the value of number is. Let's say the that within the ->data was 0001, you would want the function to tell you the value is 1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"
#include "status.h"

struct bit_flags {
	int size;
	int capacity;
	int* data;
};

typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {
	Bit_flags *pBit_flags;
	pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	if(pBit_flags != NULL) {
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = pBit_flags->size + 1;
		pBit_flags->data = (int*)malloc(sizeof(int)*pBit_flags->capacity);

		if(pBit_flags->data == NULL){
				free(pBit_flags);
				return NULL;
		}

		for(int i = 0; i < pBit_flags->size; i++) {
			pBit_flags->data[i] = 0;
		}
	}
	return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
	int i;
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	int temp[pBit_flags->size];
	if(flag_position < 0){
		return FAILURE;
	}
	if(flag_position > pBit_flags->size) {
		for(i = 0; i < pBit_flags->size; i++) {
			temp[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->capacity = pBit_flags->capacity*2;
		pBit_flags->data = (int*)malloc(sizeof(int)*pBit_flags->capacity);
		if(pBit_flags->data == NULL) {
			free(pBit_flags);
			return FAILURE;
		}
		for(i = 0; i < pBit_flags->size; i++) {
			pBit_flags->data[i] = temp[i];
		}

		for(int j = i; j < pBit_flags->capacity; j++){
			pBit_flags->data[j] = 0;
		}
	}
		pBit_flags->data[flag_position] = 1;
		return SUCCESSFUL;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
	int i;
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	int temp[pBit_flags->size];
	if(flag_position < 0){
			return FAILURE;
	}
	if(flag_position > pBit_flags->size) {
		for(i = 0; i < pBit_flags->size; i++) {
			temp[i] = pBit_flags->data[i];
	}
		free(pBit_flags->data);
		pBit_flags->capacity = pBit_flags->capacity*2;
		pBit_flags->data = (int*)malloc(sizeof(int)*pBit_flags->capacity);
		if(pBit_flags->data == NULL) {
			free(pBit_flags);
			return FAILURE;
		}
	for(i = 0; i < pBit_flags->size; i++) {
		pBit_flags->data[i] = temp[i];
		}

	for(int j = i; j < pBit_flags->capacity; j++){
		pBit_flags->data[j] = 0;
		}
	}
		pBit_flags->data[flag_position] = 0;
		return SUCCESSFUL;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	return pBit_flags->data[flag_position];
}

int bit_flags_get_size(BIT_FLAGS hBit_flags){
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags){
	Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}
