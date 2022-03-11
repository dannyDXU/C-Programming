/*
 ============================================================================
 Author      : Danny Xu
 Date        : 10/23/2018
 Purpose     : To create a function that calculates the Gravitational Force between Mass one and Mass two
 Time Spent  : 1 hour
 Gravitational force in	dynes of the moon on the earth:	1.98164e+029 dynes
 ============================================================================
 */

#include <stdio.h>

double getGravitationalForce (void);
double universal_G = 6.673e-8;
int main(void) {
	setbuf(stdout, NULL);
	char decision;
	do {
	double result = getGravitationalForce();
	printf("is %g dynes.\n", result);
	printf("Do you wish to continue (y/n)?: \n");
	scanf(" %c", &decision);
	}while (decision == 'y' || decision == 'Y');
       return 0;
}
double getGravitationalForce (void) {
	double massOne, massTwo, distance, GravitationalForce;
	printf("I need the mass of the first body in grams\n");
	scanf("%lf", &massOne);
	printf("I need the mass of the second body in grams.\n");
	scanf("%lf", &massTwo);
	printf("I need the distance between the two bodies in centimeters\n");
	scanf("%lf", &distance);
	GravitationalForce = (universal_G*massOne*massTwo) / (distance * distance);
	printf("The gravitational attractive force between a body with mass %g grams\n", massOne);
	printf("and another body with mass %g\n", massTwo);
	printf("at a distance of %g\n", distance);
	return GravitationalForce;
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

 Date: 10/23/2018
 Name: Danny Xu
 */


