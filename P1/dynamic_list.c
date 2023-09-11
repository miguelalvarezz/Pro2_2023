/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Álvarez González    LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya  Antelo         LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 17 / 02 / 23
 */

#include "dynamic_list.h"

#include "stdlib.h"
#include <stdbool.h>
#include <string.h>

void createEmptyList(tList* L){ //crear una lista vacia = puntero a nulo
    *L= LNULL; //DIRECCION APUNTADA INICIALIZARLA A NULO
}

/* createEmptyList (tList) -> tList
 *   Objetivo: crear una lista vacía
 *   Entradas:lista que queremos crear
 *   Salidas: una lista vacía.
 *   Postcondición: la lista queda inicializada y sin elementos.
 */

bool createNode(tPosL* p){ //recibe un puntero y lo inicializa
    *p=malloc(sizeof(struct tNode)); //memoria reservada de tamaño tNode
    return *p != LNULL; //si hay una memoria reservada devuelve el true
}

bool insertItem(tItemL d,tPosL p,tList *L){
    tPosL q,r;

    if(!createNode(&q))
        return false;
    else{
        q -> data = d;
        q -> next = LNULL;
        //Caso lista vacía
        if(*L == LNULL){
            *L = q;
        }else{
            //Caso final de lista (usamos r para movernos por la lista hasta el final)
            if(p == LNULL){
                for(r = *L ; r -> next != LNULL; r = r -> next);
                r -> next = q;
            }else{
                //Caso cabeza de lista
                if(p == *L){
                    q -> next = *L;
                    *L = q;
                }else{
                    q -> data = p -> data;
                    q -> next = p -> next;
                    p -> next = q;
                    p -> data = d;
                }
            }
        }
        return true;
    }
}

/* insertItem (tItemL, tPosL, tList) -> tList Bool
 *   Objetivo: añadir producto a la lista.
 *   Entradas: producto a insertar, posicion en la que lo queremos insertar y lista en la que lo queremos insertar.
 *   Salidas: true si el elemento fue insertado, sino, false.
 *   Precondición: la posicion tiene que ser válida.
 *   Postcondición: pueden variar las posiciones de los elementos anteriores al indicado.
 */

tPosL first(tList L){
    return L;
}

/* first (tList) -> tPosL
 *   Objetivo: devolver la posicion del primer elemento de la lista
 *   Entradas: lista.
 *   Salidas: posicion del primer elemento.
 *   Precondición: la lista no puede estar vacia.
 */

tPosL next(tPosL p,tList L){
    return p -> next;
}

/* next (tList) -> tPosL
 *   Objetivo: devolver la posicion del siguiente elemento de la lista
 *   Entradas: lista.
 *   Salidas: posicion del siguiente elemento.
 *   Precondición: la lista no puede estar vacia.
 */


tPosL last(tList L){
    tPosL p;
    for (p=L; p-> next !=LNULL ; p=p->next);
    return p;
}

/* last (tList) -> tPosL
 *   Objetivo: devolver la posicion del ultimo elemento de la lista
 *   Entradas: lista.
 *   Salidas: posicion del ultimo elemento.
 *   Precondición: la lista no puede estar vacia.
 */

tPosL previous(tPosL p, tList L){
    tPosL q;
    if (p==L)
        return LNULL;
    else {
        for (q=L; q->next!=p;q=q->next);
        return q;
    }
}

/* previous (tList) -> tPosL
 *   Objetivo: devolver la posicion del elemento anterior de la lista
 *   Entradas: lista.
 *   Salidas: posicion del elemento anterior.
 *   Precondición: la lista no puede estar vacia.
 */

bool isEmptyList(tList L){
    return L==LNULL;
}

/* isEmptyList (tList) -> Bool
 *   Objetivo: comprobar si la lista esta vacia.
 *   Entradas: lista.
 *   Salidas: true si la lista esta vacia, sino, false.
 *   Precondición: que la lista esté declarada e inicializada.
 */

tItemL getItem(tPosL p, tList L){
    return p->data;
}

/* getItem (tPosL, tList) -> tItemL
 *   Objetivo: conseguir el elemento de la posicion indicada.
 *   Entradas: posicion deseada y la lista.
 *   Salidas: elemento que se encuetra en esa posicion
 *   Precondición: la posicion tiene que ser válida y la lista tiene que estar declarada e inicializada.
 */

tPosL findItem(tParticipantName a, tList L){
    tPosL p;
    for(p=L; (p != LNULL) && (strcmp(p->data.participantName, a)!= 0); p = p->next);
    return p;
}

/* findItem (tProductId, tList) -> tPosL
 *   Objetivo: devuelve la posicion del elemento indicado mediante el identificador (ID)
 *   Entradas: ID del producto  y la lista.
 *   Salidas: posicion del elemento.
 *   Precondición: que exista el producto con ese ID y que la lista esté declarada e inicializada.
 */

void updateItem(tItemL d, tPosL p, tList* L){
    p->data= d;
}

/* updateItem (tItemL, tPosL, tList) -> tList
 *   Objetivo: actualizar el elemento de la posicion indicada.
 *   Entradas: el elemento a acatualizar, la posicion deseada y la lista.
 *   Salidas: la lista acatualizada.
 *   Precondición: existe el elemento, la posicion tiene que ser válida y la lista tiene que estar declarada e inicializada.
 *   Postcondición: el orden de los elementos de la lista no varia.
 */

void deleteAtPosition (tPosL p, tList *L){
    tPosL q;
    if (p==*L){ //Borrar el primer elemento
        *L=(*L)->next;
    }
    else if (p->next==LNULL) { //BORRA EL ULTIMO ELEMENTO. else if(el siguiente elemento es nulo)...
        for (q = *L; q->next != p; q = q->next);
        q->next = LNULL;
    }else{                  //Borrar en medio
        q=p->next;
        p->data=q->data;
        p->next=q->next;
        p=q;
    }
    free(p);
}

/* getItem (tPosL, tList) -> tList
 *   Objetivo: eliminar el elemento de la posicion indicada.
 *   Entradas: posicion deseada y la lista.
 *   Salidas: la lista acatualizada.
 *   Precondición: la posicion tiene que ser válida y la lista tiene que estar declarada e inicializada.
 *   Postcondición: pueden variar las posiciones de los elementos anteriores al indicado.
 */