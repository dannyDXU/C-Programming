/*
 ============================================================================
 Author      : Danny Xu
 Date        : 11/12/2018
 Purpose     : The purpose is to prompt the user for 10 integers and put them into a array, then using a function to find the index of the largest integer.
 Pre-condition: If there is a argument with a data type int and a array.
 Post-condition: Once the function finds the index with largest integer it will return index.
 Time Spent  : 20 minutes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getIndex(int array [], int size);
int main(void) {
	int array[10], maximum;
	setbuf(stdout, NULL);
	printf("Please Enter 10 integer\n");
	for(int i = 0; i < 10; i++){
		printf("Value %d:", i+1);
		scanf("%d", &array[i]);
	}
	maximum = getIndex(array, 10);
	printf("The index for the maximum is: %d ", maximum);
}
int getIndex(int array [], int size) {
	int largest = 0;
	int index = 0;
	for(int i = 0; i < size; i++) {
		if(array[i] > largest) {
			largest = array[i];
			index = i;
		}
	}
	return index;
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

 Date: 11/12/2018
 Name: Danny Xu
 */







