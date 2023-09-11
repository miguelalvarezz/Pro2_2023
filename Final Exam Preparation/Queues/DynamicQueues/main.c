#include <stdio.h>
#include "DynamicQueue.h"

int main() {
    printf("Hello, World!\n");
    tQueue Q;
    createEmptyQueue(&Q);
    tItemQ d = 4;
    tItemQ e = 5;
    tItemQ f = 6;
    tItemQ g = 7;
    tItemQ h = 8;
    enqueue(d,&Q);
    enqueue(e,&Q);
    enqueue(f,&Q);
    enqueue(g,&Q);
    enqueue(h,&Q);
    printf("%d\n",front(Q));
    dequeue(&Q);
    printf("%d",front(Q));
    return 0;
}
