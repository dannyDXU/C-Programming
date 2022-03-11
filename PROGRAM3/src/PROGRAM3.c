/*
 ============================================================================
 Program Name : Program 3
 Name        : Danny Xu
 Date        : 5/1/2019
 Effort      : 2 Hours
 purpose     : The purpose is to use bitflags toward our advantage to store 2 billion numbers
 ============================================================================
 */
#include<stdio.h>
#include<stdlib.h>

void set_flag( int flag_holder[], int flag_position);
int check_flag( int  flag_holder[], int flag_position);

int main(int argc, char *argv []) {
    setbuf(stdout, NULL);
	int* numbers;
    int temp;
    int prevNum = 0;
    int num = 32;


    numbers = (int*)malloc(sizeof(int)*62500001);


    for(int i = 0; i < 62500001; i++) {
        	numbers[i] = 0;
        }

    while(1) {

    	scanf("%d", &temp);
    	if(temp == -1) {
    		break;
    	}
    	set_flag(numbers, temp);

    }


    for(int j = 0; j < 62500001; j++) {
    	if(numbers[j] != 0) {
			for(int i = prevNum; i < num ; i++)  {
				 if(check_flag(numbers, i) == 1) {
					 printf("%d\n", i);
				 }
			 }
    	}
    	prevNum = num;
    	num += 32;
    }


    free(numbers);
    return 0;
}

void set_flag( int flag_holder[], int flag_position) {
	int i = 0;
	i = flag_position/32;
	flag_position = flag_position%32;
	flag_holder[i] = flag_holder[i] | (1 << flag_position);
}

int check_flag( int  flag_holder[], int flag_position){

	int index, locationInBit,temp;

	index = flag_position / 32;

	locationInBit = flag_position % 32;

	temp = flag_holder[index];
	temp = temp >> locationInBit;
	if((temp & 1) == 1){
		return 1;
	}
	return 0;
}
