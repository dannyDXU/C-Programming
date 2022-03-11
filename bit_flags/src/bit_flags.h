/*
 ============================================================================
 Name        : Danny Xu
 Date        : 2/25/2019
 Effort      : Two Hours
 purpose     : The purpose is to use your knowledge on vectors and create an array that will store the bits as 1s and 0s.
 Interface Proposal : Maybe a function that will tell you what the value of number is. Let's say the that within the ->data was 0001, you would want the function to tell you the value is 1.
 ============================================================================
 */

#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"

typedef void* BIT_FLAGS;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);

int bit_flags_get_size(BIT_FLAGS hBit_flags);

int bit_flags_get_capacity(BIT_FLAGS hBit_flags);

void bit_flags_destroy(BIT_FLAGS* phBit_flags);

 #endif
