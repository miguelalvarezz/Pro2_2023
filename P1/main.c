/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Álvarez González    LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya  Antelo         LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 17 / 02 / 23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

char* booltoString(tEUParticipant booleano){
    if(booleano)
        return "eu";
    else return "non-eu";
}
/* booltoString (participanteEuropeo) -> String (eu si es europeo non-eu si no lo es
 *   Tipo: generadora
 *   Objetivo: Añadir un nuevo participante al final de la lista.
 *   Entradas: nacionalidad europea o no del participante
 *   Salidas: string que contiene la nacionalidad del participante
 *   Precondición: que exista el participante
 */

int calculateTotalVotes (tList L){
    tPosL pos;
    tItemL part;
    int totalvotes = 0;

    if (!isEmptyList(L)) {
        pos= first(L);

        while (pos !=LNULL) {
            part = getItem(pos, L);
            totalvotes += part.numVotes;

            pos= next(pos,L);
        }

    }
    return totalvotes;
}
/* calculateTotalVotes (lista) -> Lista
 *   Tipo: generadora
 *   Objetivo: calcular el numero total de votos
 *   Entradas: la lista
 *   Salidas: el numeor total de votos
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void printList(tList L){
    tPosL pos;
    tItemL part;
    float percent;
    int totalVotes  = calculateTotalVotes(L);

    if (!isEmptyList(L)){ //si la lista no esta vacia, continúa
        pos=first(L);   //asigna la primera posicion de la lista a "pos"
        while (pos!=LNULL){ //mientras "pos" esté dentro de la lista, el bucle continúa
            part = getItem(pos,L);    //asignamos el elemento situado en "pos" a "part"
            percent = ((float)part.numVotes / (float)totalVotes)*100;
            if (totalVotes == 0)
                percent = 0.0f; // si el total de votos es 0 tenemos que devolver el porcentaje como 0
            printf("Participant %s location %s numvotes %d (%.2f%%)\n", part.participantName, booltoString(part.EUParticipant), part.numVotes, percent);
            pos=next(pos,L);    //asignamos a "pos" la siguiente posicion
        }
    }
}
/* PrintList (lista) -> Lista
 *   Objetivo: imprimir la lista
 *   Entradas: la lista
 *   Salidas: lista completa de participacion y votos
 *   Precondición: que exista el participante y que la lista no esté vacía
 */

bool euParticipant(char * location) {
    return (strcmp(location,"eu")==0);
}
/* euParticipant (lista) -> bool
 *   Objetivo: averiguar si es europeo o no
 *   Entradas: localización del participante
 *   Salidas: true si es europeo, false si no lo es
 *   Precondición: que exista el participante
 */

void new(char* param1, char* param2, tList *L){
    tItemL participante;

    if(findItem(param1,*L) != LNULL)
        printf("+ Error: New not possible\n");
    else{
        printf("* New: participant %s location %s\n", param1, param2);
        strcpy(participante.participantName,param1);
        participante.EUParticipant = euParticipant(param2);
        participante.numVotes = 0;
        insertItem(participante, LNULL, L);
    }
}
/* New (nombreParticipante, participanteEuropeo, lista) -> Lista
 *   Tipo: generadora
 *   Objetivo: Añadir un nuevo participante al final de la lista.
 *   Entradas: nombre del participante, nacionalidad europea o no del participante, lista en la que se añade.
 *   Salidas: la lista actualizada.
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void vote(char* param1, tList *L, int *voteNulls){
    tItemL participante;
    tPosL  pos;

    if(isEmptyList(*L) || (findItem(param1, *L) == LNULL)){
        printf("+ Error: Vote not possible. Participant %s not found. NULLVOTE\n", param1);
        *voteNulls = *voteNulls + 1;
    }
    else{
        pos = findItem(param1, *L);
        participante = getItem(pos, *L);
        participante.numVotes++;
        updateItem(participante, pos, L);
        printf("* Vote: participant %s location %s numvotes %d\n", param1, booltoString(participante.EUParticipant), participante.numVotes);
    }
}
/* Vote (nombreParticipante,votosNulos, lista) -> lista
 *  Tipo: modificadora
 *  Objetivo: Contabilizar los votos de cada participante
 *  Entradas: el nombre del participante, la cantidad de votos nulos y la lista
 *  Salidas: los votos realizados
 *  Precondición: que la lista esté declarada e inicializada
 */

void disqualifyFunction(tParticipantName param1, tList *L, int *voteNulls){
    tItemL part;
    tPosL pos;

    if  (isEmptyList(*L)) {
        puts("+ Error: Disqualify not possible\n");
    }
    else {
        pos = findItem(param1, *L);
        part = getItem(pos,*L);
        if (pos == LNULL) {
            puts("+ Error: Disqualify not possible\n");
        } else {
            *voteNulls = *voteNulls + part.numVotes;
            printf("* Disqualify: participant %s location %s\n", param1, booltoString(part.EUParticipant));
            deleteAtPosition(pos, L);

        }
    }
}
/* disqualifyFunction (nombreParticipante, lista, votosNulos) -> Lista
 *   Tipo: destructora
 *   Objetivo: Descalificar al participante introducido y pasar su numero de votos a votosNulos
 *   Entradas: nombre del participante, la lista y el numero total de votos nulos
 *   Salidas: la lista actualizada.
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void stats(int numVotes, tList L, int voteNulls) {
    int totalUtilVotes = calculateTotalVotes(L);
    int totalVotes;
    double porcentaje;

    if (isEmptyList(L)){
        puts("+ Error: Stats not possible");
    }
    else{
        printList(L);
        totalVotes = totalUtilVotes + voteNulls;
        porcentaje = (totalVotes * 100 ) / numVotes;
        printf("Null votes %d\n", voteNulls);
        printf("Participation: %d votes from %d voters (%.2f%%)\n", totalVotes, numVotes, porcentaje);
    }
}
/* Stats (numeroVotos, lista, numeroVotosNulos) ->
 *   Tipo: observadora
 *   Objetivo: mostrar las estadisticas de las votaciones
 *   Entradas: numero de votos, la lista y el numero de votos nulos totales.
 *   Salidas: las estadisticas de las votaciones.
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *L, int* voteNulls) {
    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s %c: participant %s location %s\n", commandNumber, command, param1, param2);
            new(param1, param2, L);
            break;
        case 'V':
            printf("%s %c: participant %s\n", commandNumber, command, param1);
            vote(param1, L, voteNulls);
            break;
        case 'D':
            printf("%s %c: participant %s\n",commandNumber, command, param1);
            disqualifyFunction(param1, L, voteNulls);
            break;
        case 'S':
            printf("%s %c: totalvoters %s\n", commandNumber, command, param1);
            stats(strtol(param1, NULL, 10), *L, *voteNulls);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    tList L;
    createEmptyList(&L);
    int voteNulls = 0;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, &L, &voteNulls);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}