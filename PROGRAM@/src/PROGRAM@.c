/*
 ============================================================================
 ============================================================================
 */

#include <stdio.h>
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

typedef struct node Node;

struct queue
{
	Node* head;
	Node* tail;
};
typedef struct queue Queue;
enum boolean {
	FALSE, TRUE};

typedef enum boolean Boolean;

enum status {
	SUCCESSFUL, FAILURE};

typedef enum status Status;

typedef void* QUEUE;

QUEUE queue_init_default(void);
Status queue_enqueue(QUEUE hQ, int item);
Status queue_service(QUEUE hQ);
Boolean queue_empty(QUEUE hQ);
int queue_front(QUEUE hQ, Status* pStatus);
void queue_destroy(QUEUE* phQueue);
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
			if(directions == 'l') {
				queue_enqueue(left, weightamount);
			}
			else {
				queue_enqueue(Right, weightamount);
			}

			amountOfRounds --;
		}

		outputTheResult(left, Right, boatAmountAtATime);
		amountOfTimes--;
	}

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

QUEUE queue_init_default(void)   {
	Queue* pQueue;
		pQueue = (Queue*)malloc(sizeof(Queue));
		if (pQueue != NULL)
		{
			pQueue->head = NULL;
			pQueue->tail = NULL;
		}
		return pQueue;
}

Status queue_enqueue(QUEUE hQ, int item){
	Queue* pQueue = (Queue*)hQ;
	    Node* pTemp;
	    if(hQ==NULL) {
	    	return FAILURE;
	    }
	    pTemp = (Node*)malloc(sizeof(Node));
	    if(pTemp == NULL) {
	    	return FAILURE;
	    }
	    pTemp->data = item;
	    pTemp->next = NULL;
	    if(pQueue->head == NULL) {
	    	pQueue->head = pTemp;
	    	pQueue->tail = pTemp;
	    }
	    else {
	    	pQueue->tail->next = pTemp;
	    	pQueue->tail = pQueue->tail->next;
	    }
	    return SUCCESSFUL;
}

Status queue_service(QUEUE hQ){
	Queue* pQueue = (Queue*)hQ;
	Node* pTemp;

	if(queue_empty(hQ)) {
		return FAILURE;
	}
	pTemp = pQueue->head->next;
	free(pQueue->head);

	pQueue->head = pTemp;

	if(pQueue->head == NULL) {
		pQueue->tail = NULL;
	}
	return SUCCESSFUL;
}

Boolean queue_empty(QUEUE hQ) {
	Queue* pQueue = (Queue*)hQ;

	if(pQueue->head != NULL) {
		return FALSE;
	}
	return TRUE;
}

int queue_front(QUEUE hQ, Status* pStatus) {
	Queue* pQueue = (Queue*)hQ;
	if (pQueue->head == NULL) {
		if(pStatus != NULL) {
		*pStatus = FAILURE;
		}
		return -5765;
	}
		if(pStatus != NULL) {
		*pStatus = SUCCESSFUL;
		}
	return pQueue->head->data;
}

void queue_destroy(QUEUE* phQueue) {
	Node* temp;
		Queue* pQueue = (Queue*)*phQueue;
		while(pQueue->head != NULL) {
			temp = pQueue->head->next;
			free(pQueue->head);
			pQueue->head = temp;
		}
		free(pQueue);
		*phQueue = NULL;
}

