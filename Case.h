
#ifndef MONOPPLATEAU_CASES_H
#define MONOPPLATEAU_CASES_H
#include "Propriete.h"

typedef struct {
    int id;
    int players[4];
    char displayPlayers[50];
    Propriete proprietes[5];
}Case;

#endif //MONOPPLATEAU_CASES_H
