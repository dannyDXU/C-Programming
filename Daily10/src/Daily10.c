/*
 ============================================================================
 Author      : Danny Xu
 Date        : 9/29/2018
 Purpose     : The purpose is to take a two player's input, assuming that they put either p or r or c, and shows who have won or if they are tied at rock paper and scissor.
 Time Spent  : About 50 minutes, second time took 5 min
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char* argv []) {
	setbuf(stdout, NULL);
	char playerOne_Move;
	char playerTwo_Move;
	int playerOne_Time;
	int playerTwo_Time;
	printf("Player-1 it is your turn!\n ");
	printf("Please enter your choice (p)aper, (r)ock, or (s)cissors : \n");

	playerOne_Time = scanf(" %c", &playerOne_Move);

	printf("Player-2 it is your turn!\n ");
	printf("Please enter your choice (p)aper, (r)ock, or (s)cissors : \n");
	playerTwo_Time = scanf(" %c", &playerTwo_Move);


	if (playerOne_Move == 'p' || playerOne_Move == 'P') {
			if (playerTwo_Move == 'r' || playerTwo_Move == 'R') {
				printf("Player1 wins! Paper covers rock!");
				return 0;
		}
			else if (playerTwo_Move == 's' || playerTwo_Move == 'S') {
				printf("Player2 wins! Scissors cut paper");
				return 0;
		}
			else {
				printf("Draw, nobody wins");
				return 0;
		}
	}
	else if (playerOne_Move == 'r' || playerOne_Move == 'R') {
			if (playerTwo_Move == 'p' || playerTwo_Move == 'P') {
				printf("Player2 wins!, Paper covers rock!");
				return 0;
	}
			else if (playerTwo_Move == 's' || playerTwo_Move == 'S') {
				printf("Player1 wins! Rock breaks scissors");
				return 0;
	}
			else {
				printf("Draw, nobody wins");
				return 0;
	}

}
	else if (playerOne_Move == 's' || playerOne_Move == 'S') {
				if (playerTwo_Move == 'p' || playerTwo_Move == 'P') {
					printf("Player1 wins!, Scissor cuts paper!");
					return 0;
		}
				else if (playerTwo_Move == 'r' || playerTwo_Move == 'R') {
					printf("Player2 wins! Rock breaks scissors");
					return 0;
		}
				else {
					printf("Draw, nobody wins");
					return 0;
		}

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

 Date: 9/29/2018
 Name: Danny Xu
 */





