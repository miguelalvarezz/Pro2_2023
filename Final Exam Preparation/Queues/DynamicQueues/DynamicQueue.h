//
// Created by Miguel on 05/06/2023.
//

#ifndef DYNAMICQUEUES_DYNAMICQUEUE_H
#define DYNAMICQUEUES_DYNAMICQUEUE_H

#endif //DYNAMICQUEUES_DYNAMICQUEUE_H
#include <stdbool.h>

/* Types definition */

#define QNULL NULL
typedef int tItemQ;

typedef struct tNodeQ *tPosQ;

struct tNodeQ{
    tItemQ item;
    tPosQ next;
};

typedef struct Queue{
    tPosQ front;
    tPosQ rear;

} tQueue;

/* Function prototypes */

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);
