/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Álvarez González    LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo         LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 17 / 02 / 23
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define LNULL -1
#define MAX 25

typedef int tPosL;

typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

void createEmptyList(tList* L);
bool insertItem(tItemL d, tPosL p, tList* L);
tPosL first(tList L);
tPosL next(tPosL p, tList L);
tPosL previous(tPosL p, tList L);
tPosL last(tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL findItem(tParticipantName a, tList L);
void updateItem(tItemL d, tPosL p, tList* L);
void deleteAtPosition(tPosL p, tList* L);

#endif
