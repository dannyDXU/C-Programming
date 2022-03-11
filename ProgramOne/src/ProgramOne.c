/*
 ===========================================================================
 Author      : Danny Xu
 Date        : 10/8/2018
 Purpose     : The purpose is to create a program that takes an initial value from user and a ending value from user, then calculate and print out every number that is between that initial and ending (inclusive) and the number of steps that it took to reach it. Prints maximum 7 per line.
 Time Spent  : About 5 hours
 ============================================================================
 */

#include <stdio.h>

void clear_keyboard_buffer (void);
void createTable (int initialNumber, int lastNumber);
int main(int argc, char* argv []) {
	int initialNumber;
	int lastNumber;
	setbuf(stdout, NULL);
	printf("Enter a starting point: ");
	scanf("%d", &initialNumber);
	while (initialNumber <= 1 || initialNumber >= 1000 ) {
		printf("Please enter a starting point greater than 1 and less than 1000:");
		scanf("%d", &initialNumber);
		clear_keyboard_buffer();
	}
	printf("Enter an ending point: ");
	scanf("%d", &lastNumber);
	while (lastNumber <= initialNumber || lastNumber >= 10000 ) {
			printf("Please enter a ending point greater than starting point and less than 10000:");
			scanf("%d", &lastNumber);
			clear_keyboard_buffer();
		}

	createTable(initialNumber, lastNumber);
	return 0;

}
void createTable (int initialNumber, int lastNumber) {
	int amount = 0;
	int count  = 0;
	int k = initialNumber;
	for (int i = initialNumber; i <= lastNumber; i++) {
		if(amount == 7){                           // If there are 7 numbers printed then it will start a new line //
				printf("\n");
				amount = 0;
    }
		do
		{
			if(i % 2 != 0) {
				i = 3*i+1;
				count++;
		}
			if (i % 2 == 0) {
				i = i/2;
				count++;
		}
		}while (i != 1);							// Basically while i isn't one it will keep dividing it by two if even or times it by 3 then add one if odd, then count //
				i = k;
				printf("%5d:%-5d", i, count);
				count = 0;							// Reset the count back to zero //
				k++;
				amount ++;

		}
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

 Date: 10/08/2018
 Name: Danny Xu
 */

