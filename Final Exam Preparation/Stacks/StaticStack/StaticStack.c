//
// Created by Miguel on 05/06/2023.
//

#include "StaticStack.h"

/*void createEmptyStack(tStack *S) { S->top = SNULL; }

bool push(tItemS d, tStack *S) {
    if (S->top == SMAX - 1) { //Full Stack
        return false;
    } else {
        S->top++;
        S->data[S->top] = d;
    }
    return true;
}

void pop(tStack *S) {
    S->top--;
}

tItemS peek(tStack S) { return S.data[S.top]; }

bool isEmptyStack(tStack S) { return (S.top == SNULL); }*/

bool createEmptyStack(tStack *S){
    return (S->top == SNULL);
}

bool push(tItemS item, tStack *S){
    if(S->top == SMAX-1){
        return false;
    } else {
        S->top++;
        S->data[S->top] = item;
    }
    return true;
}

void pop(tStack *S){
    S->top--;
}

tItemS peek(tStack S){
    return(S.data[S.top]);
}

bool isEmptyStack(tStack S){
    return (S.top == SNULL);
}