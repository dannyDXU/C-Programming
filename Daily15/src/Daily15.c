/*
 ============================================================================
 Author      : Danny Xu
 Date        : 10/17/2018
 Purpose     : Using functions to write the rock paper and scissor game
 Time Spent  : 2 hours
 Difference  : The difference is that it looks neater and not as confusing as writing everything in the main function. Plus you can reuse the function over and over, so use the same function to get player one's choice and player two's choice
 ============================================================================
 */

#include <stdio.h>

enum choice {PAP, ROC, SCI};
typedef enum choice Choice;
char getChoice (void);
void checkWinner (int playerOne, int playerTwo);
void clear_keyboard_buffer (void);
int main(int argc, char*argv []) {
	char playerOne;
	char playerTwo;
	char decision;
	do{
	setbuf(stdout, NULL);
	printf("Player-1, it's your turn!\n");
	playerOne = getChoice ();
	printf("Player-2, it's your turn!\n");
	playerTwo = getChoice ();
	checkWinner (playerOne, playerTwo);
	printf("Do you wish to continue? (y/n):\n ");
	scanf(" %c", &decision);
	}while(decision == 'y' || decision == 'Y');
	return 0;
}
char getChoice () {
	char decision;
	printf("Please enter your choice (p)aper, (r)ock, (s)cissors: ");
	scanf(" %c", &decision);
	clear_keyboard_buffer ();
	while ((decision != 'p')&& (decision != 'P')&&( decision != 's') &&( decision != 'S') &&( decision != 'r' )&&( decision != 'R')) {
		printf("I'm sorry, I do not understand\n");
		printf("Please enter your choice (p)aper, (r)ock, (s)cissors:\n ");
		scanf(" %c", &decision);
		clear_keyboard_buffer ();
	}
	if(decision == 'p') {
			 return PAP;
					}
	else if (decision == 'P') {
			return PAP;
	}
	else if (decision == 'r') {
			 return ROC;
					}
	else if (decision == 'R') {
			return ROC;
	}
	else {
			 return SCI;
	}
}
void checkWinner(int playerOne, int playerTwo) {
	switch (playerOne) {
	case PAP:
		if(playerTwo == PAP) {
		printf("No one wins, tie!\n");
		break;
		}
		if(playerTwo == SCI) {
		printf("Player-2 Wins, Scissors cut paper!\n");
		break;
		}
		if(playerTwo == ROC) {
		printf("Player-1 Wins, Paper covers rock!\n");
		break;
		}
		break;
	case ROC:
		if(playerTwo == PAP) {
			printf("Player-2 Wins, Paper covers Rock\n");
			break;
			}
			if(playerTwo == ROC) {
			printf("No one wins, tie!\n");
			break;
			}
			if(playerTwo == SCI) {
			printf("Player-1 Wins, Rock breaks Scissors!\n");
			break;
			}
			break;
	case SCI:
		if(playerTwo == PAP) {
			printf("Player-1 Wins, Scissor cuts Paper!\n");
			break;
			}
			if(playerTwo == ROC) {
			printf("Player-2 wins, Rock breaks Scissor !\n");
			break;
			}
			if(playerTwo == SCI) {
			printf("No one wins, tie!\n");
			break;
			}
			break;
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

 Date: 10/17/2018
 Name: Danny Xu
 */
