/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/13/2018
 Purpose     : My program teaches how to use placeholders to replace strings, integers, characters, and floats.
 Time Spent  : Around 20 minutes
 ============================================================================
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

 Date: 9/13/2018
 Name: Danny Xu

 */

#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("%d is an integer and should be printed using %%d.\n", 57);
	printf("\n");
	printf("The character \'%c\' can be printed using %%c.\n", '%');
	printf("\n");
	printf("Floating point numbers use %%f. %3.6f is an example.\n", 3.14159);
	printf("\n");
	printf("Using placeholder %%%3.1ff can display the value of %c\n", 5.2 , 'a');
	printf("number to an accuracy %s.", "of two decimal places");
	return 0;
}
