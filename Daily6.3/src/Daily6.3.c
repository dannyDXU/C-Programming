/*
 ===========================================================================
 Author      : Danny Xu
 Date        : 9/25/2018
 Purpose     : The purpose of this program is to have the user to enter a number,
 if it's positive divide it by two, if odd then make it positive by multiplying it by 3 and add 1.
 Time Spent  : About 40 minutes the first, the second time which is to revise took 1 min
 Help        : I didn't know why when I ran it it was all blank even though I had printf before scanf, so I went to Comp 1010 Piazza and someone else was
 also having this issue and to resolve this they said to put setbuf(stdout, NULL); in the beginning of code.
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char* argv []) {
	setbuf(stdout, NULL);
	int number;
	int numberCount;
	printf("Please enter a positive integer:");
	numberCount = scanf("%d", &number);
	if (number % 2 == 0) {
		number /= 2;
		printf("The next value of the number is: %d \n", number);
	}
	else {
		number = number*3 + 1;
		printf("The next value of the number is: %d \n", number);
	}
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

 Date: 9/25/2018
 Name: Danny Xu
 */
