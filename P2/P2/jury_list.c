/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Álvarez González LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 03 / 04 / 23
 */
#include "jury_list.h"
#include <stdbool.h>
#include "string.h"

bool isEmptyListJ(tListJ J) {
    return J.lastPos == NULLJ;
}

void createEmptyListJ(tListJ *J) {
    J->lastPos = NULLJ;
}

tPosJ buscaPosParaInsertarJ(tParticipantName nombre,tListJ J) {

    tPosJ p;

    for (p = 0; p <= J.lastPos ; p++){

        if (strcmp(nombre, J.data[p].juryName) <= 0)
            return p;
    }
    return NULLJ;
}

bool insertItemJ(tItemJ d, tListJ* J){
    tPosJ q, p = 0;

    p= buscaPosParaInsertarJ(d.juryName,*J);

    if(J->lastPos == MAX-1)         //Comprueba excepcion
        return false;
    else{
        J->lastPos++;
        if (p==(NULLJ))             //insertar al final
            J->data[J->lastPos]=d;
        else{                       //Insertar en el medio
            for(q=J->lastPos;q>p;q--){  //for(q = L->lastPos;q>=p+1;q--){
                J->data[q]=J -> data[q-1];
            }
            J->data[p]=d;
        }
        return true;
    }
}

tPosJ firstJ(tListJ J) {
    return 0;
}

tPosJ nextJ(tPosJ p, tListJ J) {
    if (p == J.lastPos)
        return NULLJ;
    else
        return ++p;
}

tPosJ previousJ(tPosJ p, tListJ J) {
    return --p;
}

tPosJ lastJ(tListJ J) {
    return J.lastPos;
}

tItemJ getItemJ(tPosJ p, tListJ J) {
    return J.data[p];
}

tPosJ findItemJ (tJuryName nombre, tListJ J) {
    tPosJ p;

    for (p = 0; p <= J.lastPos ; p++){

        if (strcmp(nombre, J.data[p].juryName) == 0)
            return p;
    }
    return NULLJ;
}

void updateItemJ(tItemJ d, tPosJ p, tListJ *J) {
    J->data[p] = d;
}

void deleteAtPositionJ(tPosJ p, tListJ *J) {
    tPosJ i;

    J->lastPos--;
    for (i = p; i <= J->lastPos; i++)
        J->data[i] = J->data[i + 1];
}
