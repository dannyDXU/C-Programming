/*
 ============================================================================
 Name        : Danny Xu
 Date        : 4/30/2019
 Effort      : 1 hour and 30 min
 Purpose     : The purpose of this assignment is to practice more with bitwise operators, this time instead of taking only one integer, it takes an array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

const int SIZE = sizeof(int) * 8;
int main(int argc, char* argv[]) {
	unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.

	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);

	display_flags(flag_holder, 5);
	printf("\n\n");

	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);

	display_flags(flag_holder, 5);
	return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position) {
	int i = 0;
	i = flag_position/SIZE;
	flag_position = flag_position%SIZE;
	flag_holder[i] = flag_holder[i] | (1 << flag_position);
}
void unset_flag(unsigned int flag_holder[], int flag_position){
	/*int result;
	result = check_flag(*flag_holder, flag_position);
		if(result != 0) {
			*flag_holder = ~ *flag_holder;
			set_flag(flag_holder, flag_position);
			*flag_holder = ~ *flag_holder;
		}
		*/
	int i, positionInI, flag, flag_reverse;
	i = flag_position/SIZE;
	positionInI = flag_position % SIZE;
	flag = 1 << (positionInI);
	flag_reverse = ~flag;

	flag_holder[i] = flag_holder[i] & flag_reverse;


}
int check_flag(unsigned int  flag_holder[], int flag_position){
	int temp = flag_holder;
		temp = temp >> flag_position;
		if(temp & 1 == 1){
			return 1;
		}
		return 0;
}
void display_32_flags_as_array(unsigned int flag_holder){
	 for(int i = 0; i < 32 ; i++)  {
			 printf("%d", check_flag(flag_holder, i));
			 if((i+1)%4 == 0)   {
				 printf(" ");
			 }
		   }
		    printf("\n");
}
void display_flags(unsigned int flag_holder[], int size){
	for(int i = 0; i < size; i++) {
		display_32_flags_as_array(flag_holder[i]);
	}
}
