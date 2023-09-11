/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Álvarez González LOGIN 1: miguel.alvarez.gonzalez
 * AUTHOR 2: Pablo Naya Antelo LOGIN 2: pablo.naya1
 * GROUP: 1.4
 * DATE: 03 / 04 / 23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "jury_list.h"
#include "participant_list.h"

#define MAX_BUFFER 255

char* booltoString(tEUParticipant booleano){
    if(booleano)    //si booleano es true imprimimos "eu", sino "non-eu"
        return "eu";
    else return "non-eu";
}
/* booltoString (participanteEuropeo) -> String (eu si es europeo non-eu si no lo es)
 *   Tipo: generadora
 *   Objetivo: convertir la entrada booleana en un string.
 *   Entradas: nacionalidad europea o no del participante.
 *   Salidas: string que contiene la nacionalidad del participante.
 *   Precondición: que exista el participante
 */

bool euParticipantConverter(char * location) {
    return (strcmp(location,"eu")==0);  //si la entrada es igual a "eu" devolvemos true, sino false
}
/* euParticipant (lista) -> bool
 *   Objetivo: averiguar si es europeo o no
 *   Entradas: localización del participante
 *   Salidas: true si es europeo, false si no lo es
 *   Precondición: que exista el participante
 */

int calculateTotalVotes (tListP P){
    tPosP pos;
    tItemP part;
    int totalvotes = 0;

    if (!isEmptyListP(P)) { //si la lista no esta vacia entra en el bucle
        pos = firstP(P);    //asignamos a pos la primera posicion de la lista de participantes
        while (pos != NULLP) {  //usamos este bucle para recorrer la lista
            part = getItemP(pos, P);    //obtenemos el item de la posicion actual
            totalvotes += part.numVotes;    //numero total de votos es igual a numero total de votos más los votos de dicho participante
            pos = nextP(pos,P); //pasamos a la siguiente posicion
        }
    }
    return totalvotes;
}
/* calculateTotalVotes (listaParticipantes) -> int (numeroTotalVotos)
 *   Tipo: generadora
 *   Objetivo: calcular el numero total de votos
 *   Entradas: la lista de participantes
 *   Salidas: el numeor total de votos
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void printJuryParticipants(int nullVotes, int totalVoters, tListP P){
    float percent;
    int votosValidos=0;

    if (isEmptyListP(P)){//si la lista esta vacia, imprimimos el mensaje de error
        printf("No participants\n");
    }
    else {
        votosValidos = calculateTotalVotes(P);  //calculamos el numero de votos validos de dicho participante
        for (tPosP pos = firstP(P); pos != NULLP; pos = nextP(pos, P)) {    //recorremos la lista de participantes
            tItemP part = getItemP(pos, P);    //obtenemos el participante situado en la posicion actual
            percent = ((float) part.numVotes / (float) votosValidos) * 100; //calculamos el porcentaje individual de cada participante
            if (votosValidos == 0)  //si el numero de votos validos es 0, el porcentaje pasa a ser 0%
                percent = 0.0f;
            printf("Participant %s location %s numvotes %d (%.2f%%)\n", part.participantName,
                   booltoString(part.EUParticipant), part.numVotes, percent);
        }
    }

    int votosTotales = votosValidos + nullVotes;    //el numero de votos totales es igual al numero de votos validos mas el numero de votos nullos
    percent = ((float) votosTotales * 100) / (float)totalVoters;    //calculamos el porcentaje de participacion general
    printf("Nullvotes %d\n", nullVotes);
    if(votosTotales == 0)   //si el numero de votos totales es 0, el porcentaje sera 0%
        percent = 0.0f;

    printf("Participation: %d votes from %d voters (%.2f%%)\n\n", votosTotales, totalVoters, percent);
}
/* PrintList (votosNulos, numeroTotalVotantes, listaParticipantes) -> ListaParticipantes
 *   Objetivo: imprimir la lista
 *   Entradas: votosNulos del jurado, numeroTotalVotantes del jurado, la lista de participantes de ese jurado
 *   Salidas: lista completa de participacion y votos para un jurado
 *   Precondición: que exista el participante y que la lista no esté vacía
 */

void create (char* juryName, char* totalVoters, tListJ *J) {
    tItemJ jurado;

    if(findItemJ(juryName, *J) != NULLJ) {  //si se encuentra el nombre del jurado que queremos crear, lanzamos un error
        printf("+ Error: Create not possible\n");
    } else{
        printf("* Create: jury %s totalvoters %s\n", juryName, totalVoters);
        jurado.participantList = NULLP; //inicializamos la lista de participantes de dicho jurado a NULLP
        strcpy(jurado.juryName, juryName);  //copiamos el nombre del jurado en el campo jury.juryName
        jurado.nullVotes = 0;   //inicializamos los votos nulos a 0
        jurado.totalVoters = strtol(totalVoters, NULL, 10); //inicializamos el campo de total de votantes a NULL
        jurado.validVotes = 0;  //inicializamos los votos validos a 0
        if (!insertItemJ(jurado, J)) {  //lo insertamos en la lista de jurados (si no se puede insertar, lanzamos el mensaje de error
            printf("+ Error: Create not possible\n");
        }
    }
}
/* Create (nombreJurado, votantesTotales, lista) -> ListaJurados
 *   Tipo: generadora
 *   Objetivo: Añadir un nuevo jurado al final de la lista.
 *   Entradas: nombre del jurado, cantidad de votantes por jurado, lista en la que se añade.
 *   Salidas: la lista de jurados actualizada.
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void new (char* juryName, char* participantName, char* euParticipant, tListJ* J) {
    tItemP participante;
    tPosJ pos = findItemJ(juryName, *J);    //inicializamos pos a la posicion del jurado en el que queremos crear el participante

    if(pos == NULLJ) {  //si pos es nulo lanzamos el mensaje de error
        printf("+ Error: New not possible\n");
        return;
    }
    tItemJ jury = getItemJ(pos,*J); //obtenemos el jurado que obtenemos por parametro
    tPosP participant = findItemP(participantName, jury.participantList);   //buscamos al participante indicado
    if (participant != NULLP) { //si pos es nulo lanzamos el mensaje de error
        printf("+ Error: New not possible\n");
        return;
    }
    strcpy(participante.participantName,participantName);   //copiamos el nombre del participante en el campo participante.participantName
    participante.EUParticipant = euParticipantConverter(euParticipant); //llamamos a la funcion euParticipantConverter que nos devuelve true (en caso de ser europeo) y false (si no lo es)
    participante.numVotes = 0;  //inicializamos el numero de votos del participante a 0

    if (insertItemP(participante, &jury.participantList)) { //insertamos al participante en la lista de participantes del jurado, en caso de fallo, lanzamos el mensaje de error
        printf("* New: jury %s participant %s location %s\n", juryName, participantName, euParticipant);
        updateItemJ(jury, pos, J);  //actualizamos para que la lista tenga al participante creado
    }
    else
        printf("+ Error: New not possible\n");
}
/* New (nombreJurado, nombreParticipante, participanteEuropeo, listaJurados) -> Lista
 *   Tipo: generadora
 *   Objetivo: Añadir un nuevo participante al final de la lista del jurado.
 *   Entradas: nombre del jurado, nombre del participante, nacionalidad europea o no del participante, lista en la que se añade.
 *   Salidas: la lista de jurados actualizada.
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void stats (tListJ J) {
    if (isEmptyListJ(J)){   //si la lista esta vacia lanzamos el mensaje de error
        printf("+ Error: Stats not possible\n");
        return;
    }

    for (tPosJ posJurado = firstJ(J); posJurado <= lastJ(J); posJurado++) { //recorremos la lista de jurados
        tItemJ jurado = getItemJ(posJurado, J); //obtenemos el jurado de la posicion actual
        printf("Jury %s\n", jurado.juryName);
        printJuryParticipants(jurado.nullVotes, jurado.totalVoters, jurado.participantList);    //llamamos a la funcion que nos imprimira las estadisticas de este jurado
    }
}
/* Stats (listaJurados) -> String
 *   Tipo: observadora
 *   Objetivo: mostrar las estadisticas de las votaciones
 *   Entradas: lista de jurados.
 *   Salidas: las estadisticas de las votaciones.
 *   Precondición: que la lista mencionada esté declarada e inicializada
 */

void vote (char* juryName, char* participantName, tListJ *J) {

    tPosJ posicionJurado = findItemJ(juryName, *J); //obtenemos la posicion del jurado
    if (posicionJurado == NULLJ){   //si la posicion es nula, lanzamos el mensaje de error
        printf("+ Error: Vote not possible\n");
        return;
    }

    tItemJ itemJ = getItemJ(posicionJurado, *J);    //obtenemos el jurado situado en dicha posicion
    tPosP participanteJurado = findItemP(participantName, itemJ.participantList);   //obtenemos la posicion del participante deseado

    if (participanteJurado == NULLP) {  //si la posicion del participante es nula lanzamos el mensaje de error
        printf("+ Error: Vote not possible. Participant %s not found in jury %s. NULLVOTE\n", participantName, juryName);
        itemJ.nullVotes++;  //incrementamos el numero de votos nulos del jurado
        updateItemJ(itemJ, posicionJurado, J); //actualizamos el jurado
        return;
    }

    tItemP participante = getItemP(participanteJurado, itemJ.participantList);  //obtenemos el participante deseado

    participante.numVotes++; //incrementamos el numero de votos del participante
    itemJ.validVotes++; //incrementamos el numero de votos validos
    updateItemP(participante, participanteJurado, &itemJ.participantList);
    updateItemJ(itemJ, posicionJurado, J);  //actualizamos el producto para tener la lista actualizada
    printf("* Vote: jury %s participant %s location %s numvotes %d\n", juryName, participantName, booltoString(participante.EUParticipant), participante.numVotes);
}
/* Vote (nombreJurado, nombreParticipante, votosNulos, listaJurados, listaParticipantes) -> lista
 *  Tipo: modificadora
 *  Objetivo: Contabilizar los votos de cada participante
 *  Entradas: el nombre del participante, la cantidad de votos nulos y la lista
 *  Salidas: los votos realizados
 *  Precondición: que la lista esté declarada e inicializada
 */

void disqualify (char* participantName,tListJ *J) {
    tItemP participant;
    tPosP pos;
    tPosJ juryAux;
    tItemJ  itemJury;

    if (isEmptyListJ(*J)) { //si la lista esta vacia lanzamos el mensaje de error
        puts("+ Error: Disqualify not possible\n");
    }
    else {
        for (juryAux = firstJ(*J); juryAux <= lastJ(*J) ; juryAux++) {  //recorremos la lista de jurados
            itemJury = getItemJ(juryAux, *J);   //obtenemos el jurado de la posicion actual
            pos = findItemP(participantName, itemJury.participantList); //obtenemos la posicion del participante que queremos descalificar
            printf("Jury %s\n", itemJury.juryName);
            if(pos == NULLP){   //si la posicion es nula, lanzamos el mensaje de error
                printf("No participant %s\n", participantName);
            }
            else{
                participant = getItemP(pos, itemJury.participantList);  //obtenemos el participante  de la posicion actual
                itemJury.nullVotes += participant.numVotes; //incrementamos el numero de votos nulos
                printf("Participant %s disqualified\n", participantName);
                deleteAtPositionP(pos, &itemJury.participantList);  //eliminamos al participante de la lista
                updateItemJ(itemJury, juryAux, J);  //actualizamos el jurado
            }
            printf("\n");
        }
    }
}
/* Disqualify (nombreParticipante, listaJurados) -> lista
 *  Tipo: destructora
 *  Objetivo: eliminar a un participante de todas las listas de jurados.
 *  Entradas: el nombre del participante y la lista de jurados.
 *  Salidas: la lista actualizada.
 *  Precondición: que la lista de jurados esté declarada e inicializada
 */

void removeJury (tListJ *J) {
    tItemJ juryAux;
    tPosJ prev;
    int counter = 0;

    if (isEmptyListJ(*J)){  //si la lista esta vacía lanzamos el mensaje de error
        printf("+ Error: Remove not possible\n");
        return;
    }

    for (tPosJ pos = firstJ(*J); pos != NULLJ; pos = nextJ(pos, *J)){   //recorremos la lista de jurados
        juryAux = getItemJ(pos,*J); //obtenemos el jurado de la posicion actual
        if (juryAux.validVotes == 0){   //si el numero de votos validos es igual a 0 eliminamos el jurado
            printf("* Remove: jury %s\n", juryAux.juryName);
            prev = previousJ(pos, *J); //asignamos a prev la posición anterior a pos
            deleteAtPositionJ(pos, J);  //eliminamos el jurado
            pos = prev;
            counter++;  //incrementamos el contador que nos servirá de detector de fallos
        }
    }
    if(counter == 0)    //si el contador es 0 (es decir, no se ha eliminado ningun jurado, imprimimos el mensaje de error
        printf("+ Error: Remove not possible\n");
}
/* RemoveJury (listaJurados) -> lista
 *  Tipo: destructora
 *  Objetivo: eliminar todos los jurados con 0 votos válidos.
 *  Entradas: la lista de jurados.
 *  Salidas: la lista actualizada.
 *  Precondición: que la lista de jurados esté declarada e inicializada
 */

void winners (tListJ J) {
    tPosJ pos = firstJ(J);

    if(isEmptyListJ(J)){    //si la lista esta vacia lanzamos el mensaje de error
        printf("+ Error: Winners not possible\n");
    } else{
        while (pos != NULLJ){   //este bucle nos sirve para recorrer la lista de jurados
            int exception = 0;  //contador que nos servira para detectar errores
            int empateEu = 0, empateNonEu = 0;
            int contadorParticipantesEu = 0, contadorParticipantesNonEu = 0;
            tItemJ jury = getItemJ(pos, J); //obtenemos el jurado de la posicion actual
            tPosP participantPos = firstP(jury.participantList);    //obtenemos el primer elemento de la lista de participantes del jurado
            tItemP auxEu = {"", -1, true}, auxNonEu = {"", -1, false};  //creamos dos itemP auxiliares que
            // nos serviran despues para comprobar la nacionalidad y la validez de un partipante

            printf("Jury %s\n", jury.juryName);
            if (isEmptyListP(jury.participantList)){    //si la lista esta vacia lanzamos el mensaje de error
                printf("Location eu: No winner\n");
                printf("Location non-eu: No winner\n\n");
            } else{
                while(participantPos != NULLP) { //este buble nos permite recorrer la lista de participantes
                    tItemP participant = getItemP(participantPos,jury.participantList);    //obtenemos el participante situado en la posicion actual

                    if ((participant.EUParticipant == true) && (participant.numVotes > auxEu.numVotes)) {    //si el participante es europeo y el numero de votos es superior al auxiliar entramos al bucle
                        auxEu = participant;    //actualizamos a auxiliar
                    } else if ((participant.EUParticipant == false) && (participant.numVotes > auxNonEu.numVotes)) { // si no es europeo y es superior al auxiliar entramos al bucle
                        auxNonEu = participant; //actualizamos auxiliar no europeo
                    } else if ((participant.EUParticipant == true) && (participant.numVotes == auxEu.numVotes)) {
                        empateEu++;
                    } else if ((participant.EUParticipant == false) && (participant.numVotes == auxNonEu.numVotes)) {
                        empateNonEu++;
                    } else
                        exception++;    //si no se da ninguna de las circunstancias anteriores, se incrementa el contador (en caso de empate, en caso de que sea igual...)


                    if (participant.EUParticipant == true)
                        contadorParticipantesEu++;
                    else if (participant.EUParticipant == false)
                        contadorParticipantesNonEu++;

                    participantPos = nextP(participantPos, jury.participantList);   //pasamos a la siguiente posicion
                }

                if(auxEu.numVotes < 0)  //si el numero de votos de auxiliar es menor a 0 (es decir, ningun elemento lo ha superado) imprimimos el mensaje de error
                    printf("Location eu: No winner\n");
                else{
                    if ((((auxEu.numVotes == 0) && (exception > 0)) || (empateEu > 0)) && (contadorParticipantesEu != 1))   //si el numero de votos es igual a 0 y el contador es mayor a 0, o, si hay empate, se lanza el mensaje de error
                        printf("Location eu: No winner\n");
                    else
                        printf("Location eu: Participant %s numvotes %d\n", auxEu.participantName, auxEu.numVotes);
                }

                if(auxNonEu.numVotes < 0)  //si el numero de votos de auxiliar es menor a 0 (es decir, ningun elemento lo ha superado) imprimimos el mensaje de error
                    printf("Location non-eu: No winner\n");
                else{
                    if ((((auxNonEu.numVotes == 0) && (exception > 0)) || (empateNonEu > 0)) && (contadorParticipantesNonEu != 1))   //si el numero de votos es igual a 0 y el contador es mayor a 0, o, si hay empate, se lanza el mensaje de error
                        printf("Location non-eu: No winner\n");
                    else
                        printf("Location non-eu: Participant %s numvotes %d\n\n", auxNonEu.participantName, auxNonEu.numVotes);
                }
            }
            pos = nextJ(pos, J);    //pasamos a la siguiente posicion
        }
    }
}
/* Winners (listaJurados) -> lista
 *  Tipo: observadora
 *  Objetivo: mostrar al ganador de cada jurado.
 *  Entradas: la lista de jurados.
 *  Salidas: la lista actualizada.
 *  Precondición: que la lista de jurados, y la lista de participantes de un jurado, estén declaradas e inicializadas.
 */

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *J) {
    printf("********************\n");
    switch (command) {
        case 'C':
            printf("%s %c: jury %s totalvoters %s\n", commandNumber, command, param1, param2);
            create(param1, param2, J);
            break;
        case 'N':
            printf("%s %c: jury %s participant %s location %s\n", commandNumber, command, param1, param2, param3);
            new(param1, param2, param3, J);
            break;
        case 'V':
            printf("%s %c: jury %s participant %s\n", commandNumber, command, param1, param2);
            vote(param1, param2, J);
            break;
        case 'D':
            printf("%s %c: participant %s\n", commandNumber, command, param1);
            disqualify(param1, J);
            break;
        case 'S':
            printf("%s %c:\n", commandNumber, command);
            stats(*J);
            break;
        case 'R':
            printf("%s %c:\n", commandNumber, command);
            removeJury(J);
            break;
        case 'W':
            printf("%s %c:\n", commandNumber, command);
            winners(*J);
            break;
        default:
            break;
    }
}

void readTasks(char *filename)  {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    tListJ J;
    tListP P;
    createEmptyListJ(&J);
    createEmptyListP(&P);
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &J);
        }
        fclose(f);
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {

    char *file_name = "create.txt";

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