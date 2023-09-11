/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Álvarez González    LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo         LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 17 / 02 / 23
 */

#include "static_list.h"
#include "types.h"
#include <string.h>

void createEmptyList(tList* L){
    L-> lastPos = LNULL;
}

/* createEmptyList (tList) -> tList
 *   Objetivo: crear una lista vacía
 *   Entradas:lista que queremos crear
 *   Salidas: una lista vacía.
 *   Postcondición: la lista queda inicializada y sin elementos.
 */

bool insertItem(tItemL d, tPosL p, tList* L){
    tPosL q;
    if(L->lastPos == MAX-1)         //Comprueba excepcion
        return false;
    else{
        L->lastPos++;
        if (p==(LNULL))             //insertar al final
            L->data[L->lastPos]=d;
        else{                       //Insertar en el medio
            for(q=L->lastPos;q>p;q--){  //for(q = L->lastPos;q>=p+1;q--){
                L->data[q]=L -> data[q-1];
            }
            L->data[p]=d;
        }
        return true;
    }
}

/* insertItem (tItemL, tPosL, tList) -> tList Bool
 *   Objetivo: añadir elemento a la lista.
 *   Entradas: elemento a insertar, posicion en la que lo queremos insertar y lista en la que lo queremos insertar.
 *   Salidas: true si el elemento fue insertado, sino, false.
 *   Precondición: la posicion tiene que ser válida.
 *   Postcondición: pueden variar las posiciones de los elementos anteriores al indicado.
 */

tPosL first(tList L){
    return 0;
}

/* first (tList) -> tPosL
 *   Objetivo: devolver la posicion del primer elemento de la lista
 *   Entradas: lista.
 *   Salidas: posicion del primer elemento.
 *   Precondición: la lista no puede estar vacia.
 */

tPosL next(tPosL p, tList L){
    if (p==L.lastPos)
        return LNULL;
    else
        return ++p;
}

/* next (tList) -> tPosL
 *   Objetivo: devolver la posicion del siguiente elemento de la lista
 *   Entradas: lista.
 *   Salidas: posicion del siguiente elemento.
 *   Precondición: la lista no puede estar vacia.
 */

tPosL previous (tPosL p, tList L){   // dada la posición 2 me devuelve la 1
    return --p;
    /*if (p==0)   //comprobar que no es la primera posición de la lista
        return LNULL;
    else
        return --p;*/
}

/* previous (tList) -> tPosL
 *   Objetivo: devolver la posicion del elemento anterior de la lista
 *   Entradas: lista.
 *   Salidas: posicion del elemento anterior.
 *   Precondición: la lista no puede estar vacia.
 */

tPosL last(tList L){
    return L.lastPos; //usamos el punto pq la lista esta pasada por valor, es decir, usa la lista q pasamos por parametro
}

/* last (tList) -> tPosL
 *   Objetivo: devolver la posicion del ultimo elemento de la lista
 *   Entradas: lista.
 *   Salidas: posicion del ultimo elemento.
 *   Precondición: la lista no puede estar vacia.
 */

bool isEmptyList(tList L){
    return L.lastPos == LNULL;
}

/* isEmptyList (tList) -> Bool
 *   Objetivo: comprobar si la lista esta vacia.
 *   Entradas: lista.
 *   Salidas: true si la lista esta vacia, sino, false.
 *   Precondición: que la lista esté declarada e inicializada.
 */

tItemL getItem(tPosL p, tList L){
    return L.data[p];
}

/* getItem (tPosL, tList) -> tItemL
 *   Objetivo: conseguir el elemento de la posicion indicada.
 *   Entradas: posicion deseada y la lista.
 *   Salidas: elemento que se encuetra en esa posicion
 *   Precondición: la posicion tiene que ser válida y la lista tiene que estar declarada e inicializada.
 */

tPosL findItem(tParticipantName a, tList L){
    tPosL p;
    if(L.lastPos==LNULL)        //comprobar que la lista está vacía o isEmptyList(L)
        return LNULL;
    else{
        for(p=0;(p<L.lastPos) && (strcmp(L.data[p].participantName,a)!=0);p++);   // mientras se de esta circustancia y no encuentre el elemento itero
        if(strcmp(L.data[p].participantName, a) == 0)//if (L.data[p].productId == a)       //devolver la posición del elemento
            return p;
        else
            return LNULL;
    }
}

/* findItem (tProductId, tList) -> tPosL
 *   Objetivo: devuelve la posicion del elemento indicado mediante el identificador (ID)
 *   Entradas: ID del producto  y la lista.
 *   Salidas: posicion del elemento.
 *   Precondición: que exista el producto con ese ID y que la lista esté declarada e inicializada.
 */

void updateItem(tItemL d, tPosL p, tList* L){
    L->data[p] = d; //(vamos a hacer un cambio en el array;vamos a pasarlo por referencia (pq vamos a trabajar con una copia))pasar por registro
}

/* updateItem (tItemL, tPosL, tList) -> tList
 *   Objetivo: actualizar el elemento de la posicion indicada.
 *   Entradas: el elemento a acatualizar, la posicion deseada y la lista.
 *   Salidas: la lista acatualizada.
 *   Precondición: existe el elemento, la posicion tiene que ser válida y la lista tiene que estar declarada e inicializada.
 *   Postcondición: el orden de los elementos de la lista no varia.
 */

void deleteAtPosition(tPosL p, tList* L){ //no estoy seguro de si lleva el * pero sino no va en el test.Si no lleva el *,entonces es la opcion entre corchetes
    tPosL i;
    L->lastPos--;
    for(i=p;i <= L->lastPos; i++)
        L->data[i]=L->data[i+1];
    /*L.lastPos--;
    for(i=p;i<L.lastPos;i++)
        L.data[i]=L.data[i+1];*/
}

/* getItem (tPosL, tList) -> tList
 *   Objetivo: eliminar el elemento de la posicion indicada.
 *   Entradas: posicion deseada y la lista.
 *   Salidas: la lista acatualizada.
 *   Precondición: la posicion tiene que ser válida y la lista tiene que estar declarada e inicializada.
 *   Postcondición: pueden variar las posiciones de los elementos anteriores al indicado.
 */
