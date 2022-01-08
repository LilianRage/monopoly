
#ifndef MONOPPLATEAU_PLATEAU_H
#define MONOPPLATEAU_PLATEAU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char* content;
}Line;

typedef struct {
    int id;
    int idCase;
    int price;
    int owner;
    int rent;
}Propriete;

typedef struct {
    int id;
    int players[4];
    char displayPlayers[50];
    Propriete proprietes[5];
}Case;

typedef struct{
    int pos;
    int idProperty;
    char* playerName;
    int argentDujoueur;
    int pion;
}Player;

// fonctions et methodes
int createCases();
int init();
int display();
void displayPlayers();
void space();
Propriete createProperty(int id, int idCase, int price, int owner, int rent);

#endif //MONOPPLATEAU_PLATEAU_H
