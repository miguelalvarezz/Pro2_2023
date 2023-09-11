/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Álvarez González LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 03 / 04 / 23
 */

#include "participant_list.h"
#include "string.h"
#include <stdbool.h>
#include <stdlib.h>

void createEmptyListP(tListP* P){ //crear una lista vacia = puntero a nulo
    *P= NULLP; //DIRECCION APUNTADA INICIALIZARLA A NULO
}

bool createNodeP(tPosP* p){ //recibe un puntero y lo inicializa
    *p = malloc(sizeof(struct tNode)); //memoria reservada de tamaño tNode
    return *p != NULLP; //si hay una memoria reservada devuelve el true
}

tPosP buscaPosParaInsertarP(tParticipantName nombre,tListP P){
    tPosP q;

    for (q = P; q != NULLP;  q = q->next) {
        if (strcmp(nombre, q->data.participantName) <= 0)
            return q;
    }

    return q; // Devuelve NULL si no hay cadena mayor
    //  porque insertItem inserta a la izquierda

}

bool insertItemP(tItemP d,tListP *P){
    tPosP p,new, last;
    p = buscaPosParaInsertarP(d.participantName, *P); //    p = buscaPosParaInsertar(d.participantName, L);


    if(!createNodeP(&new))
        return false;
    else{
        new -> data = d;
        new -> next = NULLP;
        //Caso lista vacía
        if(*P == NULLP){
            *P = new;
        }else{
            //Caso final de lista (usamos r para movernos por la lista hasta el final)
            if(p == NULLP){
                last = lastP(*P); // last = lastP(L)
                last->next = new;
            }else{
                //Caso cabeza de lista
                if(p == *P){
                    new -> next = *P;
                    *P = new;
                }else{
                    new -> data = p -> data;
                    new -> next = p -> next;
                    p -> next = new;
                    p -> data = d;
                }
            }
        }
        return true;
    }
}

tPosP firstP(tListP P){
    return P;
}

tPosP nextP(tPosP p,tListP P){
    return p -> next;
}

tPosP lastP(tListP P){
    tPosP p;
    for (p=P; p-> next != NULLP ; p=p->next);
    return p;
}

tPosP previousP(tPosP p, tListP P){
    tPosP q;
    if (p==P)
        return NULLP;
    else {
        for (q=P; q->next!=p;q=q->next);
        return q;
    }
}

bool isEmptyListP(tListP P){
    return P == NULLP;
}

tItemP getItemP(tPosP p, tListP P){
    return p->data;
}

tPosP findItemP(tParticipantName nombre, tListP P){
    tPosP p;

    if(P == NULLP)
        return NULLP;
//SI LA LISTA ESTÁ VACÍA DEVUELVO NULL
    for(p=P; p != NULLP; p = p->next ) {
        if  (strcmp(nombre, p->data.participantName) == 0){
            return p;
        }
    }
    return NULLP;
}

void updateItemP(tItemP d, tPosP p, tListP* P){
    p->data= d;
}

void deleteAtPositionP (tPosP p, tListP *P){
    tPosP q;
    if (p==*P){ //Borrar el primer elemento
        *P=(*P)->next;
    }
    else if (p->next == NULLP) { //BORRA EL ULTIMO ELEMENTO. else if(el siguiente elemento es nulo)...
        for (q = *P; q->next != p; q = q->next);
        q->next = NULLP;
    }else{                  //Borrar en medio
        q=p->next;
        p->data=q->data;
        p->next=q->next;
        p=q;
    }
    free(p);
}
