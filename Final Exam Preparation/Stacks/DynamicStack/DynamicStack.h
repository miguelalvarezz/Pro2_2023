//
// Created by Miguel on 05/06/2023.
//

#ifndef STACKS_DYNAMICSTACK_H
#define STACKS_DYNAMICSTACK_H

#endif //STACKS_DYNAMICSTACK_H
#include <stdbool.h>
#include <stdlib.h>

#define SNULL NULL

typedef int tItemS;
typedef struct tNodeS *tPosS;

struct tNodeS{
    tItemS data;
    tPosS down;
};

typedef tPosS tStack;

void createEmptyStack(tStack *S);
bool createNode(tPosS *p);
bool push(tItemS item, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);