/*
 ============================================================================
 Author     : Danny Xu
 Date       : 2/18/2019
 Effort     : 1 hour
 Purpose    : To create the function unset, so that we can go to a specific position and find out if it is a 0 or not, if it's not a 0 then we make it into a 0.
 ============================================================================
 */

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int  flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[]) {
	setbuf(stdout, NULL);
	unsigned int flag_holder = 0;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	display_32_flags(flag_holder);

	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);

	display_32_flags(flag_holder);
	return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position) {
	*flag_holder = *flag_holder | (1 << flag_position);
}

void unset_flag(unsigned int * flag_holder, int flag_position) {
	int result;
	result = check_flag(*flag_holder, flag_position);
	if(result != 0) {
		*flag_holder = ~ *flag_holder;
		set_flag(flag_holder, flag_position);
		*flag_holder = ~ *flag_holder;
	}
}

void display_32_flags(unsigned int flag_holder) {
	 for(int i= 31; i>=0; i--)  {
		 printf("%d", check_flag(flag_holder, i));
		 if(i%4 == 0)   {
			 printf(" ");
		 }
	   }
	    printf("\n");
}

int check_flag(unsigned int flag_holder, int flag_position) {
	int temp = flag_holder;
	temp = temp >> flag_position;
	if(temp & 1 == 1){
		return 1;
	}
	return 0;
}
