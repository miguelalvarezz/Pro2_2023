/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Álvarez González LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 03 / 04 / 23
 */

#ifndef JURY_LIST_H
#define JURY_LIST_H

#include <stdbool.h>
#include "types.h"

#define NULLJ -1
#define MAX 1000

typedef struct tItemJ{
    tJuryName juryName;
    tNumVotes totalVoters;
    tNumVotes validVotes;
    tNumVotes nullVotes;
    tListP participantList;
} tItemJ;

typedef int tPosJ;

typedef struct {
    tItemJ data[MAX];
    tPosJ lastPos;
} tListJ;

void createEmptyListJ(tListJ* J);
bool insertItemJ(tItemJ d, tListJ* J);
void updateItemJ(tItemJ d , tPosJ p, tListJ* J);
void deleteAtPositionJ(tPosJ p, tListJ* J);
void deleteListJ(tListJ* J);
tPosJ findItemJ(tJuryName j, tListJ J);
bool isEmptyListJ(tListJ J);
tItemJ getItemJ(tPosJ p, tListJ J);
tPosJ firstJ(tListJ J);
tPosJ lastJ(tListJ J);
tPosJ previousJ(tPosJ p, tListJ J);
tPosJ nextJ(tPosJ p, tListJ J);
tPosJ buscaPosParaInsertarJ(tParticipantName n,tListJ J);
bool copyListJ(tListJ L, tListJ* M);

#endif
