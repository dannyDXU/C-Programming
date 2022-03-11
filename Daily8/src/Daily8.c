/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/25/2018
 Purpose     : The purpose of this program is to take a postive integer and keep on subtract it by one, then print. Until it reaches zero
 and then do it in reverse, take zero and add it by one, print until it reach the intial number inputted by the user.
 Time Spent  : About 40 minutes first time, revised took 5 minutes
 ============================================================================
 */

#include <stdio.h>

void loop_down_to_zero (int number);
void loop_up_to_int (int newNumber);
int main(int argc, char* argv []) {
	int number;
	int newNumber;
	printf("Please enter a postive integer\n");
	scanf("%d", &number);
	newNumber = number;
	loop_down_to_zero (number);
	loop_up_to_int (newNumber);

	return 0;

}

void loop_down_to_zero (int number) {
	while (number >= 0) {
		printf("%d\n", number);
			number --;
	}
	printf("****\n");
}
void loop_up_to_int (int newNumber) {
	int start = 0;
	while (start != newNumber) {
		printf("%d\n", start);
			start ++;
}
	printf("%d", newNumber);
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

 Date: 9/25/2018
 Name: Danny Xu
 */


