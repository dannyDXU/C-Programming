/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/24/2018
 Purpose     : The purpose of this program is to try to get the user to type in a negative number, if they fail it wil; prompt them over and over again
 Time Spent  : About 40 minutes
 ============================================================================
 */

#include <stdio.h>

void clear_keyboard_buffer (void);
int main(int argc,  char* argv []) {
	int number, numberTimes;
	printf("Please enter a negative integer: \n");
	numberTimes = scanf("%d", &number);
	clear_keyboard_buffer ();

	while (number >= 0 || numberTimes == 0) {
		printf("I'm sorry, you must enter a negative number integer less than zero: \n");
		numberTimes = scanf("%d", &number);
		clear_keyboard_buffer ();
	}

	printf("The negative number was: %d\n", number);
	return 0;
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

 Date: 9/24/2018
 Name: Danny Xu
 */



