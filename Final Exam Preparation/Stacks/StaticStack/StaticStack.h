//
// Created by Miguel on 05/06/2023.
//

#ifndef STATICSTACK_STATICSTACK_H
#define STATICSTACK_STATICSTACK_H

#endif //STATICSTACK_STATICSTACK_H
#include <stdbool.h>
// stackstruct createempty push pop isempty

/* Types definition */

#define SNULL -1
#define SMAX 10

typedef int tItemS;
typedef int tPosS;

typedef struct tStack{
    tItemS data[SMAX];
    tPosS top;
}tStack;

bool createEmptyStack(tStack *S);
bool push(tItemS item, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);