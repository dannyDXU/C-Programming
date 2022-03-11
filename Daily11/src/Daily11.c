/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/30/2018
 Purpose     : The purpose of this program is to get the user to input a number that it between the ranges of 1 to 79, then print a certain amount of module base on that number.
 Time Spent  : 1 hour
 ============================================================================
 */

#include <stdio.h>

void draw_line(int number);
void clear_keyboard_buffer(void);
int main(int argc, char* argv[]) {
	setbuf(stdout, NULL);
	int number, numbercount;
	printf("Please enter the number of percent signs you want in your line: \n");
	numbercount = scanf("%d", &number);
		clear_keyboard_buffer ();

	while (numbercount == 0 || number <= 0 || number > 79) {
		printf("I'm sorry, that number is unrecoginized or out of range, try [1-79]: \n");
		numbercount = scanf("%d" , &number);
		clear_keyboard_buffer ();
	}

	draw_line(number);

	return 0;
}

void draw_line(int number) {
	for (int i = 0; number > i; i++) {
	printf("%%");
	}
}

void clear_keyboard_buffer (void) {
	char ch;
	scanf("%c", &ch);

	while (ch != '\n') {
		scanf("%c", &ch);
	}
}

/*
 Computing I -- COMP.1010 Honor Statement

 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation. This practice is manifested in the
 University's Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog. Violation will
 be dealt with as outlined therein.

 All programs assignments in this class are to be done by the
 student alone. No outside help is permitted except the instructor and
 approved tutors.

 I certify that the work submitted with this assignment is mine and was
 generated in a manner consistent with this document, the course
 academic policy on the course website on Blackboard, and the Umass
 Lowell academic code.

 Date: 9/30/2018
 Name: Danny Xu
 */




