/*
 ============================================================================
 Author      : Danny Xu
 Date        : 11/22/2018
 Purpose     : The purpose of this is to open a file on the computer and find what how many integers, sum, smallest, largest, and average of the file is.
 Time Spent  : 40 minutes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv []) {
	FILE *inputFile;
	inputFile = fopen("C:/Users/Public/example/numbers.txt", "r");

	if(inputFile == NULL) {
		printf("File can't open\n");
		exit(1);
	}
	else {
		printf("Successful\n");
	}

	int num, count=0, sum=0, smallest=0, largest=0;
	double average;
	while(fscanf(inputFile, "%d", &num)==1) {
		count ++;
		sum += num;
		average = (double)sum/(double)count;
		if(smallest > num){
			smallest = num;
		}
		if(largest < num) {
			largest = num;
		}
	}
	printf("There were %d integers in the file\n", count);
	printf("The sum of all integers in the file is %d\n", sum);
	printf("The smallest Integer in the file is %d\n", smallest);
	printf("The largest Integer in the file is %d\n", largest);
	printf("The average of all the numbers are %g", average);

	 fclose(inputFile);
	 return 0;
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

 Date: 11/22/2018
 Name: Danny Xu
 */







