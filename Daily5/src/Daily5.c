/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/16/2018
 Purpose     : The purpose of the program is to create variables and to use the variable to do math.
 Time Spent  : About 20 minutes
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
	int num1 = 100;
	int num2 = 10;
	int num3 = 16;
	int num4 = 4;
	printf("The first number is: %d\n", num1);
	printf("The second number is: %d\n", num2);
	printf("The third number is: %d\n", num3);
	printf("The fourth number is: %d\n", num4);

	printf("\n");
	printf("\n");

	int sum = num1 + num2;
	int result = num1 * num3;
	int quotient = num2 / num4;
	int remainder = num2 % num4;

	printf("The sum of 100 and 10 is: %d\n", sum);
	printf("The product of 100 and 16 is: %d\n", result);
	printf("The quotient of 10 divide by 4 is: %d\n", quotient);
	printf("The remainder of 10 divide by 4 is: %d\n", remainder);

	return 0;
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

 Date: 9/16/2018
 Name: Danny Xu
 */

