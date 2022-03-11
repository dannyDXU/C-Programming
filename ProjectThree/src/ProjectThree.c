/*
 ============================================================================
 Author      : Danny Xu
 Date        : 12/5/2018
 Purpose     : The purpose is to make use of functions, to call other functions inside a function. Using that idea in order to convert either weights or heights to what you want.
 Time Spent  : 5 Hours.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void convertLengths (void);
void length_to_metric(void);
void displayLength_to_metric(int feet, double inches);
void conversionLength_to_metric(int *feet, double *inches);
void displayResultLength_to_metric(int feet, double inches);
void length_to_us(void);
void displayLength_to_us(int meters, double centimeters);
void conversionLength_to_us(int* meters, double *centimeters);
void displayResultLength_to_us(int meters, double centimeters);
void convertWeights (void);
void weight_to_metric(void);
void displayWeight_to_metric(int pounds, double ounces);
void conversionWeight_to_metric(int *pounds, double *ounces);
void displayResultWeight_to_metric(int pounds, double ounces);
void weight_to_us(void);
void displayWeight_to_us(int kilograms, double grams);
void conversionWeight_to_us(int *kilograms, double *grams);
void displayResultWeight_to_us(int kilograms, double grams);
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
	}while(choice != 0); //Allows User to choose to convert lengths or weights unless they enter zero

	exitNow();

	return 0;
}
void convertLengths (void){
	int choice;
	printf("The user want to convert_lengths.\n");
	printf("1. convert lengths from	feet/inches	to meters/centimeters\n");
	printf("2. convert from	meters/centimeters to feet/inches\n");
	printf("0, return to main program\n");
	do{							// Allows the User to select what length they want to convert
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
	int feet;
	double inches;
	printf("The user want to convert lengths from feet/inches to meters/centimeters\n");
	printf("Please enter the length you want to convert in feet/inches\n");
	printf("Enter feet: \n");
	scanf("%d", &feet);		  // Asks for feet and inches
	printf("Enter inches: \n");
	scanf("%lf", &inches);
	displayLength_to_metric(feet, inches);
	conversionLength_to_metric(&feet, &inches);
	displayResultLength_to_metric(feet, inches);  // displays the result
}

void displayLength_to_metric(int feet, double inches){
	printf("The length that you want to convert is %d feet and %g inches\n", feet, inches);
}

void conversionLength_to_metric(int *feet, double *inches) { // Converts from feet/inch to meters/centimeters
	int meters;
	double centimeters;
	centimeters = ((((*inches + (*feet*12))/12)*0.3048))*100;
	meters = centimeters/100;
	centimeters = centimeters - (meters*100);
	*feet = meters;
	*inches = centimeters;
}

void displayResultLength_to_metric(int feet, double inches) {
	printf("The result after conversion is %d meters and %g centimeters\n", feet, inches);
	printf("\n");
	convertLengths ();
}


void length_to_us(void){
	int meters;
	double centimeters;
	printf("The user want to convert from meters/centimeters to feet/inches\n");
	printf("Please enter the length you want to convert in meters/centimeters\n");
	printf("Enter meters: \n");
	scanf("%d", &meters);
	printf("Enter centimeters: \n");
	scanf("%lf", &centimeters);
	displayLength_to_us(meters, centimeters);
	conversionLength_to_us(&meters, &centimeters);
	displayResultLength_to_us(meters, centimeters);
}

void displayLength_to_us(int meters, double centimeters){
	printf("The length that you want to convert is %d meters and %g centimeters\n", meters, centimeters);
}
void conversionLength_to_us(int * meters, double *centimeters){  //Converts meters/centimeters to feet/inch
	int feet;
	double inches;

	inches = ((*meters/0.3048) + (((*centimeters/100)/0.3048)))*12;
	feet = inches/12;

	inches = inches - (feet*12);

	*meters = feet;
	*centimeters = inches;

}
void displayResultLength_to_us(int meters, double centimeters){
	printf("The result after conversion is %d feet and %g inches\n", meters, centimeters);
	printf("\n");
	convertLengths ();
}
void convertWeights (void){
	int choice;
	printf("The user want to convert_weights.\n");
	printf("1. convert weights from	pounds/ounces to kilograms/grams\n");
	printf("2. convert from	kilograms/grams to pounds/ounces\n");
	printf("0, return to main program\n");
	do{
		scanf("%d", &choice);    // Allows the user to select what weight they want to convert
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
	int pounds;
	double ounces;
	printf("1. The user wants to convert weights from pounds/ounces to kilograms/grams\n");
	printf("Please enter the weight you want to convert in pounds/ounces\n");
	printf("Enter pounds: \n");
	scanf("%d", &pounds);
	printf("Enter ounces: \n");
	scanf("%lf", &ounces);
	displayWeight_to_metric(pounds, ounces);
	conversionWeight_to_metric(&pounds, &ounces);
	displayResultWeight_to_metric(pounds, ounces);
}

void displayWeight_to_metric(int pounds, double ounces){
	printf("The weight that you want to convert is %d pounds and %g ounces\n", pounds, ounces);
}
void conversionWeight_to_metric(int *pounds, double *ounces){ // Converts pounds/ounce to kilograms/grams
	int kilograms;
	double grams;

	grams = ((*pounds/2.2046)*1000) + (((*ounces/16)/2.2046)*1000);
	kilograms = grams/1000;
	grams = grams - (kilograms*1000);
	*pounds = kilograms;
	*ounces = grams;
}
void displayResultWeight_to_metric(int pounds, double ounces){
	printf("The result after conversion is %d kilograms and %g grams\n", pounds, ounces);
	printf("\n");
	convertWeights ();
}
void weight_to_us(void){
	int kilograms;
	double grams;
	printf("2. The user wants to convert from kilograms/grams to pounds/ounces\n");
	printf("Please enter the weight you want to convert in kilograms/grams\n");
	printf("Enter kilograms: \n");
	scanf("%d", &kilograms);
	printf("Enter grams: \n");
	scanf("%lf", &grams);
	displayWeight_to_us(kilograms, grams);
	conversionWeight_to_us(&kilograms, &grams);
	displayResultWeight_to_us(kilograms, grams);
}

void displayWeight_to_us(int kilograms, double grams){
	printf("The weight that you want to convert is %d kilograms and %g grams\n", kilograms, grams);
}
void conversionWeight_to_us(int *kilograms, double *grams){ // Converts kilograms/grams to pounds/ounces
	int pounds;
	double ounces;

	ounces = ((*kilograms*2.2046)*16) + (((*grams/1000)*2.2046)*16);
	pounds = ounces/16;
	ounces = ounces - (pounds*16);

	*kilograms = pounds;
	*grams = ounces;
}
void displayResultWeight_to_us(int kilograms, double grams){
	printf("The result after conversion is %d pounds and %g ounces\n", kilograms, grams);
	printf("\n");
	convertWeights ();
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

 Date: 12/5/2018
 Name: Danny Xu
 */
