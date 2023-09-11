/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Álvarez González LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 03 / 04 / 23
 */

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include "types.h"
#include <stdbool.h>

#define NULLP NULL

typedef struct tItemP {

    tParticipantName participantName;
    tNumVotes numVotes;
    tEUParticipant EUParticipant;

}tItemP;

//typedef struct tNode* tPosP;
struct tNode {
    tItemP data;
    tPosP next;
};

//typedef tPosP tListP;

tPosP findItemP(tParticipantName d,tListP P);
tPosP buscaPosParaInsertarP(tParticipantName n,tListP P);
void createEmptyListP(tListP *P);
bool createNodeP(tPosP* p);
bool isEmptyListP(tListP P);
tPosP firstP(tListP P);
tPosP lastP(tListP P);
tPosP nextP(tPosP p,tListP P);
tPosP previousP(tPosP p, tListP P);
bool insertItemP(tItemP d,tListP *P);
void deleteAtPositionP(tPosP p , tListP *P);
void updateItemP(tItemP d, tPosP p, tListP* P);
tItemP getItemP(tPosP p, tListP P);

#endif