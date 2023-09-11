/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Álvarez González    LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya  Antelo         LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 17 / 02 / 23
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include "stdbool.h"

#define LNULL NULL
typedef struct tNode* tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};

typedef tPosL tList;



//CABECERAS
void createEmptyList(tList* L);
bool createNode(tPosL* p);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL next(tPosL p,tList L);
tPosL previous(tPosL p, tList L);
bool insertItem(tItemL d,tPosL p,tList *L);
void deleteAtPosition (tPosL p, tList *L);
tItemL getItem(tPosL p, tList L);
void updateItem(tItemL d, tPosL p, tList* L);
tPosL findItem(tParticipantName a, tList L);

#endif
