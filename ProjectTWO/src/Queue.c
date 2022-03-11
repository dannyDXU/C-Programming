#include <stdio.h>
#include "Queue.h"

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

/*int queue_next_front(QUEUE hQ, Status* pStatus) {
	Queue* pQueue = (Queue*)hQ;
	if (pQueue->head == NULL) {
		if(pStatus != NULL) {
		*pStatus = FAILURE;
		}
		return -1;
	}
		if(pStatus != NULL) {
		*pStatus = SUCCESSFUL;
		}
	return pQueue->head->next->data;
}
*/
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
