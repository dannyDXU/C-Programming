#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"
#include "status.h"

void print_bits(BIT_FLAGS hBit_flags);
int main(int argc, char* argv[])
{
	BIT_FLAGS hBit_flags = bit_flags_init_number_of_bits(0);
	bit_flags_set_flag(hBit_flags, 3);
	bit_flags_set_flag(hBit_flags, 16);
	bit_flags_set_flag(hBit_flags, 31);
	bit_flags_set_flag(hBit_flags, 87);

	print_bits(hBit_flags);
	printf("size = %d, capacity = %d \n", bit_flags_get_size(hBit_flags), bit_flags_get_capacity(hBit_flags));
	printf("\n\n");

	bit_flags_unset_flag(hBit_flags, 31);
	bit_flags_unset_flag(hBit_flags, 3);
	bit_flags_set_flag(hBit_flags, 99);
	bit_flags_set_flag(hBit_flags, 100);

	print_bits(hBit_flags);
	printf("size = %d, capacity = %d \n", bit_flags_get_size(hBit_flags), bit_flags_get_capacity(hBit_flags));

	bit_flags_unset_flag(hBit_flags, 200);
	print_bits(hBit_flags);
	printf("size = %d, capacity = %d \n", bit_flags_get_size(hBit_flags), bit_flags_get_capacity(hBit_flags));
	bit_flags_destroy(&hBit_flags);
	return 0;
}
void print_bits(BIT_FLAGS hBit_flags)
{
	int i, j;
	for (i = 0; i < bit_flags_get_capacity(hBit_flags)/32; i++)
	{
		for (j = 0; j < 32; j++)
		{
			printf("%d", bit_flags_check_flag(hBit_flags, j+(i*32)));
			if ((j + 1) % 4 == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
