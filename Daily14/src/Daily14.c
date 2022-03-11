/*
 ============================================================================
 Author      : Danny Xu
 Date        : 10/15/2018
 Purpose     : The purpose of this program is to take to ask the user for two integers, and then find the largest integer that can divide both of them. Also to get practice on calling functions that return.
 Time Spent  : 35 minutes
 ============================================================================
 */

#include <stdio.h>

int getPositiveNum (void);
void clear_keyboard_buffer(void);
int largestInteger(int firstNum, int secondNum);
int main(void) {
	int firstNum, secondNum, sum;
	setbuf(stdout, NULL);
	printf("Please enter a positive Integer: \n ");
	firstNum = getPositiveNum();
	printf("Please enter a second positive Integer: ");
	secondNum = getPositiveNum();
	sum = largestInteger(firstNum, secondNum);
	printf("The largest Integer that divides both %d and %d is: %d ", firstNum, secondNum, sum);
	return 0;
}

int getPositiveNum (void) {
	int number;
	int numberCount;
	numberCount = scanf("%d", &number);
	clear_keyboard_buffer();
	while (numberCount == 0 || number <= 0) {
		printf("I'm sorry that number is unrecognized or not positive. \n");
		printf("Please enter again: ");
		numberCount = scanf("%d", &number);
		clear_keyboard_buffer();
	}
	return number;
}

int largestInteger (int firstNum, int secondNum) {
	int testFirst = firstNum;
	int testSecond = secondNum;
	if(firstNum > secondNum) {
		while (firstNum % secondNum != 0 || testFirst % secondNum != 0 || testSecond % secondNum != 0) {
			firstNum--;
			secondNum--;
		}
		return secondNum;
	}
	else if (secondNum > firstNum) {
		while (secondNum % firstNum != 0 || testFirst % firstNum != 0 || testSecond % firstNum!= 0) {
			secondNum--;
			firstNum--;
		}
		return firstNum;
	}
	else {
		return firstNum;
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

 Date: 10/15/2018
 Name: Danny Xu
 */


