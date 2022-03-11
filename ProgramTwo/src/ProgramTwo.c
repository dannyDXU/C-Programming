/*
 ============================================================================
 Author      : Danny Xu
 Date		 : 10/23/2018
 Purpose     : The purpose of this program is to find take the intial size of green curd and the number of day, then finding what the final population is. As well as using functions in order to make the program more readable.
 Time Spent  : 2 hours
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void clear_keyboard_buffer(void);
int getSizeOfGreenCurd(void);
int getNumberOfDays(void);
int getFinalPopulation(int GreenCurdSize, int Days);
int main(int argc, char* argv[]) {
	setbuf(stdout, NULL);
	int GreenCurdSize, Days, result;
	char decision;
	do{
	printf("Please enter the initial size of the green curd: \n");
	GreenCurdSize = getSizeOfGreenCurd (); //Saves size into variable GreenCurdSize
	printf("Please enter the number of days: ");
	Days = getNumberOfDays(); //Saves number of days into variable Days
	result = getFinalPopulation(GreenCurdSize, Days); //takes two arguments, then saves the final population into result
	printf("With an initial population of %d pounds of crud growing for %d days,\n", GreenCurdSize, Days);
	printf("the final population would be %d pounds\n", result);
	printf("Would you like to continue? (y/n)\n");
	scanf(" %c", &decision);
	}while(decision == 'y'|| decision == 'Y'); //Unless decision is 'y' or 'Y', it will exit
	return 0;
}
int getSizeOfGreenCurd(void) {		//This function gets the size of initial Green Curd
	int sizeOfGreenCurd;
	int amountCount;
	amountCount = scanf("%d", &sizeOfGreenCurd);
	clear_keyboard_buffer ();
	while (amountCount == 0 || 0 > sizeOfGreenCurd) {	 // Will keep on asking User to enter if the size is less than zero or unrecognized
		printf("I'm sorry that value is unrecognized or is negative.\n");
		printf("Please enter the intial size of the green curd: \n");
		amountCount = scanf("%d", &sizeOfGreenCurd);
		clear_keyboard_buffer ();
	}
	return sizeOfGreenCurd;
}

int getNumberOfDays(void) {		//This function gets the number of days
	int NumberOfDays;
	int amountCount;
	amountCount = scanf("%d", &NumberOfDays);
	clear_keyboard_buffer ();
	while (amountCount == 0 || 0 > NumberOfDays) {	 // Will keep on asking User to enter days if it is less than zero or unrecognized
		printf("I'm sorry that value is unrecognized or is negative.\n");
		printf("Please enter the number of days: \n");
		amountCount = scanf("%d", &NumberOfDays);
		clear_keyboard_buffer ();
	}
	return NumberOfDays;
}

int getFinalPopulation(int GreenCurdSize, int Days ) { 		//This function calculates the final population
	int count = 0;
	int previousSize1 = 0;
	int previousSize2 = GreenCurdSize;
	int CurrentSize = GreenCurdSize;
	for(int i = 0; i< Days; i++) {
		count++;
		if(count == 5) { //Only run if it has been 5 days
		  CurrentSize = previousSize1 + previousSize2; //Takes the two previous size and add them
		  previousSize1 = previousSize2; //Then set previousSize 2 and save it into previousSize 1
		  previousSize2 = CurrentSize; //Finally take the currentSize and save it to previousSize 2
		  count = 0; //Resets the count
		}
	}
	return CurrentSize;
}
void clear_keyboard_buffer (void) {
	char ch;
	scanf("%c", &ch);

	while (ch != '\n') {
		scanf("%c", &ch);
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

 Date: 10/23/2018
 Name: Danny Xu
 */

