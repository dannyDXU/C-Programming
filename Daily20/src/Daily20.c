/*
 ============================================================================
 Author      : Danny Xu
 Date        : 11/4/2018
 purpose     : The purpose of this is to use a for loop that makes the value double the index and then reverse the values of the array.
 Time Spent  : 20 minutes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverseOrder (int array[]);
int main(void) {
	int array[40];
	int count = 0;
	for (int i = 0; i < 40; i++) {
		array[i] = i+i;
		printf("%7d", array[i]);
		count ++;
		if (count == 10) {
			printf("\n");
			count = 0;
		}
	}
	printf("*****");
	printf("\n");
	reverseOrder(array);
}

void reverseOrder (int array[]) {
	int count = 0;
	int temp;
	for (int i = 0; i < 20; i++) {
		temp = array[i];
		array[i] = array[39-i];
		array[39-i] = temp;
	}
	for (int i = 0; i < 40; i++) {
		printf("%7d", array[i]);
		count ++;
		if (count == 10) {
			printf("\n");
			count = 0;
		}
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

 Date: 11/4/2018
 Name: Danny Xu
 */






