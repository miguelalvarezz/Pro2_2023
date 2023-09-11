//
// Created by Miguel on 05/06/2023.
//

#include "DynamicStack.h"
#include <stdlib.h>

void createEmptyStack(tStack *S){
    *S = SNULL;
}

bool createNode(tPosS *p){
    *p = malloc(sizeof(struct tNodeS));
    return (*p != SNULL);
}

bool push(tItemS item, tStack *S){
    tPosS aux;
    if(!createNode(&aux)){
        return false;
    } else{
        aux->data = item;
        aux->down = *S;
        *S = aux;
        return true;
    }
}

void pop(tStack *S){
    tPosS aux;

    aux = *S;
    *S = (*S)->down;
    free(aux);
}

tItemS peek(tStack S){
    return (S -> data);
}

bool isEmptyStack(tStack S){
    return (S == SNULL);
}