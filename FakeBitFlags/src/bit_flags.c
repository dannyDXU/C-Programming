/*
 ============================================================================
 Name        : Danny Xu
 Date        : 5/1/2019
 Effort      : Four Hours
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
	int num = 32;
	int count = 1;
	int temp = number_of_bits;
	pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	if(pBit_flags != NULL) {
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = 32;
		if(temp >= num) {
			while(temp >= num) {
				num = num + 32;
				count++;
			}
			pBit_flags->capacity = 32*count;
		}
		pBit_flags->data = (int*)malloc(sizeof(int)*count);

		if(pBit_flags->data == NULL){
				free(pBit_flags);
				return NULL;
		}

		for(int i = 0; i < count; i++) {
			pBit_flags->data[i] = 0;
		}
	}
	return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
		Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
		int index = flag_position / 32;
		int* ptemp;

		if (flag_position < 0) {
			return FAILURE;
		}

		if (index >= pBit_flags->capacity) {
			ptemp = (int*)malloc(sizeof(int)*(index + 1));

			for (int i = 0; i < (index + 1); i++) {
				ptemp[i] = 0;
			}

			if (ptemp != NULL) {

				for (int i = 0; i < pBit_flags->size; i++) {
					ptemp[i] = pBit_flags->data[i];
				}

				free(pBit_flags->data);

				pBit_flags->data = ptemp;
				pBit_flags->capacity = (index)+32;
			}

			else {
				return FAILURE;
			}

		}

		pBit_flags->data[index] |= 1 << (flag_position % 32);

		if (pBit_flags->size < (index + 1)) {
			pBit_flags->size = index + 1;
		}

		return SUCCESSFUL;

}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
		Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

		if (flag_position < 0) {
			return FAILURE;
		}

		int index = flag_position / 32;

		pBit_flags->data[index] &= ~(1 << (flag_position % 32));

		return SUCCESSFUL;

}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){

		Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
		int index;
		int result;
		int locationInBit;

		index = flag_position / 32;

		if (index<0 || index>pBit_flags->size) {
			return -999;
		}

	    locationInBit = flag_position % 32;

		result = pBit_flags->data[index] & (1 << locationInBit);

		if (result == 1) {
			return 1;
		}

		return 0;

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
