/*
 ============================================================================
 Author      : Danny Xu
 Date        : 11/1/2018
 Purpose     : The purpose of this is to take two integers, call the function biggerGoesToA, if a is less than b, then a will equal b and b will equal the value of a.
 Time spent  : 20 minutes.
 Explanation for your function:	It works because it scans two integers, then it sends the address of a and b into the functionbiggerGoesToA, then if b is greater than a, it will take the value of b by doing *b and put it into a (*a). By doing this it goes to the address of a and changes the value of it to the value of b.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void biggerGoesToA (int *a, int *b);
int main(int argc, char* argv[]) {
	int a, b;

	setbuf(stdout, NULL);
	printf("Please enter two integers: ");
	scanf("%d, %d", &a, &b);

	printf("a is: %d\n", a);
	printf("b is: %d\n", b);

	biggerGoesToA(&a, &b);

	printf("a now becomes the bigger one and the value is: %d\n", a);
	printf("b now becomes the smaller one and the value is: %d\n", b);
	return 0;
}

void biggerGoesToA (int *a, int *b) {
	int c;
	if (*a < *b) {
		c = *a;
	   *a = *b;
	   *b = c;
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

 Date: 11/1/2018
 Name: Danny Xu
 */






