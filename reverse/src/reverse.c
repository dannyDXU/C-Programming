/*
 ============================================================================
 Name        : Danny Xu
 Date        : 1/23/2019
 Time Spent  : 30 minutes
 ============================================================================
 */

#include <stdio.h>

char* reverse (char word []);
char* reverse (char word []) {
	char temp;
	int i = 0, count = 0;
	while (word[i] != '\0') {
		count ++;
		i++;
	}
	for (int i = 0; i < count/2; i++) {
		temp = word[i];
		word[i] = word[(count-1)-i];
		word[(count-1)-i] = temp;
	}

	return word;
}
