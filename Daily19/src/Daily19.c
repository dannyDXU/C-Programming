/*
 ============================================================================
 Author      : Danny Xu
 Date        : 11/1/2018
 Purpose     : Asking the user what option they want and then calling the function that relates to their option, until 0 is called which ends the program.
 Time Spent  : 15 minutes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void convertLengths (void);
void convertWeights (void);
void exitNow (void);
int main(void) {
	setbuf(stdout, NULL);
	int choice;
	do{
	 printf("1. convert lengths\n");
	 printf("2. convert weights\n");
	 printf("0. Exit\n");
	 printf("Please choose from (1, 2, 0):\n");
	 scanf("%d", &choice);
	 if(choice == 1) {
		 convertLengths();
	 }
	 if(choice == 2) {
		 convertWeights();
	 }
	}while(choice != 0);

	exitNow();

	return 0;
}
void convertLengths (void){
	printf("The user want to convert_lengths.\n");
}
void convertWeights (void){
	printf("The user want to convert_weights.\n");
}
void exitNow (void){
	printf("User chose to exit.\n");
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

