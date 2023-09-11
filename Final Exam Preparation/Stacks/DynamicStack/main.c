#include <stdio.h>
#include "DynamicStack.h"

int main() {
    tStack S;
    tItemS d = 1;
    tItemS e = 2;
    tItemS f = 3;
    createEmptyStack(&S);
    push(d,&S);
    printf("primer elemento tras introducir d: %d\n",peek(S));
    push(e,&S);
    printf("primer elemento tras introducir e: %d\n",peek(S));
    push(f,&S);
    printf("primer elemento tras introducir f: %d\n", peek(S));
    pop(&S);
    printf("primer elemento tras eliminar la cima: %d\n", peek(S));
    pop(&S);
    printf("primer elemento tras eliminar la cima: %d\n", peek(S));

    return 0;
}