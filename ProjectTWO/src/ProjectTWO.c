/*
 ============================================================================
 Program     : Program 2
 Author      : Danny Xu
 Date        : 4/25/2019
 Time Spent  : 5 Days
 Purpose     : The purpose of this is to get use to using queues in order to solve problems like this
 ============================================================================
 */

#include <stdio.h>
#include "Queue.h"

void outputTheResult(QUEUE left, QUEUE Right, int boatAmountAtATime);
void clear_keyboard_buffer (void);
int main(int argc, char*argv [])
{
	int amountOfTimes;
	int amountOfRounds;
	int boatAmountAtATime;
	int weightamount;
	char directions;
	QUEUE left;
	QUEUE Right;

	setbuf(stdout, NULL);

	left = queue_init_default();
	Right = queue_init_default();

	scanf("%d", &amountOfTimes);
	clear_keyboard_buffer ();

	while (amountOfTimes > 0) {
		scanf("%d", &boatAmountAtATime);
		boatAmountAtATime *= 100;
		scanf("%d", &amountOfRounds);
		clear_keyboard_buffer ();
		while(amountOfRounds > 0) {
			scanf("%d", &weightamount);
			scanf("%c", &directions);
			scanf("%c", &directions);
			 clear_keyboard_buffer ();
			 //printf("%d\n",weightamount);
			if(directions == 'l') {
				//printf("l\n");
				queue_enqueue(left, weightamount);
			}
			else {
				//printf("r\n");
				queue_enqueue(Right, weightamount);
			}

			//printf("Once %d\n", amountOfRounds);
			amountOfRounds --;
		}

		outputTheResult(left, Right, boatAmountAtATime);
		amountOfTimes--;
	}

	printf("works\n");
	return 0;
}

void outputTheResult(QUEUE left, QUEUE Right, int boatAmountAtATime) {
	int count = 0;
	int LeftTemp = queue_front(left, NULL);
	int RightTemp = queue_front(Right, NULL);
	while(!queue_empty(left) || !queue_empty(Right)) {
		if(!queue_empty(left) && count%2==0) {
			while(LeftTemp <= boatAmountAtATime) {
				queue_service(left);
				if(!queue_empty(left)) {
					LeftTemp += queue_front(left, NULL);
				}
				else
				{
					break;
				}

			}
			count++;
			if(!queue_empty(left)) {
				LeftTemp = queue_front(left, NULL);
			}
		}
		if(!queue_empty(Right) && count%2!=0) {
			while(RightTemp <= boatAmountAtATime) {
				queue_service(Right);
				if(!queue_empty(Right)) {
					RightTemp += queue_front(Right, NULL);
				}
				else
				{
					break;
				}
			}

		   count++;
		   if(!queue_empty(Right)) {
			   RightTemp = queue_front(Right, NULL);
		   }
	  }

		if(count%2==0 && !(queue_empty(Right)) && (queue_empty(left))) {
			count++;
		}

		else if(count%2!=0 && !(queue_empty(left)) && (queue_empty(Right))) {
			count++;
		}

	}

	printf("%d\n", count);
}

void clear_keyboard_buffer (void) {
	char ch;
	scanf("%c", &ch);

	while (ch != '\n') {
		scanf("%c", &ch);
	}
}
