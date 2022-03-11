/*
 ============================================================================
 Author      : Danny Xu
 Date        : 11/13/2018
 Purpose     : The purpose is to add more options to convertLength and convertWeight, to allow the user to select what they want to change currently into.
 Time Spent  : 20 minutes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void convertLengths (void);
void length_to_metric(void);
void length_to_us(void);
void convertWeights (void);
void weight_to_metric(void);
void weight_to_us(void);
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
	int choice;
	printf("The user want to convert_lengths.\n");
	printf("1. convert lengths from	feet/inches	to meters/centimeters\n");
	printf("2. convert from	meters/centimeters to feet/inches\n");
	printf("0, return to main program\n");
	do{
		scanf("%d", &choice);
		if(choice == 1) {
			length_to_metric();
		}
		if(choice == 2) {
			length_to_us();
		}
	}while(choice != 0);
	printf("Return to main menu\n");
}

void length_to_metric(void){
	printf("The user want to convert lengths from feet/inches to meters/centimeters\n");
}
void length_to_us(void){
	printf("The user want to convert from meters/centimeters to feet/inches\n");
}
void convertWeights (void){
	int choice;
	printf("The user want to convert_weights.\n");
	printf("1. convert weights from	pounds/ounces to kilograms/grams\n");
	printf("2. convert from	kilograms/grams to pounds/ounces\n");
	printf("0, return to main program\n");
	do{
		scanf("%d", &choice);
		if(choice == 1) {
			weight_to_metric();
		}
		if(choice == 2) {
			weight_to_us();
		}
	}while(choice != 0);
		printf("Return to main menu\n");

}
void weight_to_metric(void) {
	printf("1. The user wants to convert weights from pounds/ounces to kilograms/grams\n");
}
void weight_to_us(void){
	printf("2. The user wants to convert from kilograms/grams to pounds/ounces\n");
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

 Date: 11/13/2018
 Name: Danny Xu
 */
