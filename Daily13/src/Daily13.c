/*
 ===========================================================================
 Author      : Danny Xu
 Date        : 10/16/2018
 Purpose     : To rewrite Rock Paper Scissor game but replace the if else statements with switch case
 Time Spent  : 1 hour
 ============================================================================
 */

#include <stdio.h>
enum choice {PAP, ROC, SCI};
typedef enum choice Choice;
int main(int argc, char* argv []) {
	char playerOne;
	char playerTwo;
	setbuf(stdout, NULL);
	printf("Player-1 it is your turn!\n ");
		printf("Please enter your choice (p)aper, (r)ock, or (s)cissors : \n");
		scanf(" %c", &playerOne);
		if(playerOne == 'p') {
			playerOne = PAP;
		}
		else if(playerOne == 'P') {
			playerOne = PAP;
		}
		else if (playerOne == 'r') {
			playerOne = ROC;
		}
		else if (playerOne == 'R') {
			playerOne = ROC;
		}
		else {
			playerOne = SCI;
		}

	printf("Player-2 it is your turn!\n ");
			printf("Please enter your choice (p)aper, (r)ock, or (s)cissors : \n");
			scanf(" %c", &playerTwo);
			if(playerTwo == 'p') {
					playerTwo = PAP;
				}
			else if (playerTwo == 'P') {
					playerTwo = PAP;
			}
			else if (playerTwo == 'R') {
					playerTwo = ROC;
			}
			else if (playerTwo == 'r') {
					playerTwo = ROC;
				}
			else {
					playerTwo = SCI;
				}
switch (playerOne) {
case PAP:
	if(playerTwo == PAP) {
	printf("No one wins, tie!");
	break;
	}
	if(playerTwo == SCI) {
	printf("Player-2 Wins, Scissors cut paper!");
	break;
	}
	if(playerTwo == ROC) {
	printf("Player-1 Wins, Paper covers rock!");
	break;
	}
	break;
case ROC:
	if(playerTwo == PAP) {
		printf("Player-2 Wins, Paper covers Rock");
		break;
		}
		if(playerTwo == ROC) {
		printf("No one wins, tie!");
		break;
		}
		if(playerTwo == SCI) {
		printf("Player-1 Wins, Rock breaks Scissors!");
		break;
		}
		break;
case SCI:
	if(playerTwo == PAP) {
		printf("Player-1 Wins, Scissor cuts Paper!");
		break;
		}
		if(playerTwo == ROC) {
		printf("Player-2 wins, Rock breaks Scissor !");
		break;
		}
		if(playerTwo == SCI) {
		printf("No one wins, tie!");
		break;
		}
		break;
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

 Date: 10/16/2018
 Name: Danny Xu
 */






