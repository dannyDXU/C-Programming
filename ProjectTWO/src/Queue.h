#ifndef QUEUE_H_
#define QUEUE_H_
#include "Status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE hQ, int item);

Status queue_service(QUEUE hQ);

Boolean queue_empty(QUEUE hQ);

int queue_front(QUEUE hQ, Status* pStatus);

//int queue_next_front(QUEUE hQ, Status* pStatus);

void queue_destroy(QUEUE* phQueue);


#endif
