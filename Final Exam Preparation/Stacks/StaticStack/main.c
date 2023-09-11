#include <stdio.h>
#include "StaticStack.h"

int main() {
    printf("Hello, World!\n");
    tStack S;
    tItemS d = 1;
    tItemS e = 7;
    tItemS f = 3;
    createEmptyStack(&S);
    push(d,&S);
    printf("primer elemento de la pila: %d\n",S.data[S.top]);
    push(e,&S);
    printf("primer elemento de la pila: %d\n",S.data[S.top]);
    push(f,&S);
    printf("primer elemento de la pila: %d\n",S.data[S.top]);
    pop(&S);
    printf("la cima es %d", peek(S));
    return 0;
}
