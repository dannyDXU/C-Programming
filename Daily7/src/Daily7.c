/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/25/2018
 Purpose     : Create a function call smile that can create a smile face, then using the
 main function call smile function three times to create 3 smiles.
 Main Difference from the previous version: The main difference is that the first version
 is very messy because everything is compressed in the main function. It can get confusing, but
 this new version it looks much cleaner and is more easy to read. IT's also less work, much simplified.
Time Spent   : 20 minutes first time, revised took 1 min
 ============================================================================
 */

#include <stdio.h>

void smile (void);

int main(int argc, char*argv []) {
	smile();
    printf("\n");
    smile();
    printf("\n");
    smile();
	return 0;
}

void smile(void) {
	printf("   **** \n");
	printf("  * . .*\n");
	printf("*       *\n");
	printf("*   \\_/ *\n");
	printf(" *     *\n");
	printf("   ****\n");
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

