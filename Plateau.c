
#include "Plateau.h"
#define NB_LINES 33
#define NB_CASES 32
#define NB_PROPRIETE 50
#define NB_PLAYERS 4


// Variables globales
Case cases[NB_CASES];
Line lignesDuPlateau[NB_LINES];
Player player[NB_PLAYERS];


int createCases(){
    // File opening in read mode

    FILE* fp = fopen("../NomPropriete.txt", "r");
    if (fp == NULL) { perror("Error opening file"); return(-1); }
    for (int i = 0; i < NB_PROPRIETE; i++) {
        // Chiffre a changer au bon nombre de caractère d'une ligne (le max)
        Case c;
        c.id = i;
        for (int id = 0; id < 2; id++){
            char nom[100];
            char prix[3];
            fgets(nom, 100, fp);
            fgets(prix, 3, fp);
            Propriete prop = createProperty(id, i, strtol(prix, NULL, 10), 0, 10);
            c.proprietes[id] = prop;
        }
        cases[i] = c;
    }
    fclose(fp);

    return 0;
}

int init() {
    // File opening in read mode
    Case newPosition;
    Case oldPosition;
    FILE* fp = fopen("../Monopoly.txt", "r");
    if (fp == NULL) { perror("Error opening file"); return(-1); }
    for (int i = 0; i < NB_LINES; i++) {
        char line[60];
        // Chiffre a changer au bon nombre de caractère d'une ligne
        fgets(line, 60, fp);
        //printf(line);
        lignesDuPlateau[i].content = line;
        //printf("%d %s", i, lignesDuPlateau[i].content);
        strcpy(line, "");
    }
    fclose(fp);

    Player leo;
    Player kevin;
    Player lilian;
    Player antoine;
    leo.pos = 0;
    kevin.pos = 0;
    lilian.pos = 0;
    antoine.pos = 0;

    leo.pion = 1;
    kevin.pion = 2;
    lilian.pion = 3;
    antoine.pion = 4;

    srand(time(NULL));
    int dice1 = 3;//(rand() %6) + 1;
    int dice2 = 4;//(rand() %6) + 1;
    printf("\n\nResultat de 1 : %d \nResultat de 2 : %d\n", dice1, dice2);
    leo.pos = leo.pos + dice2 + dice1;
    newPosition = cases[leo.pos];

    newPosition.id = leo.pion;
    // dans la case 7 mettre le pion
    printf("%d \n",leo.pos);

    printf("\n\n%d\n\n", newPosition.id);



    // ajouter les sous de base + ajouter chacun a players

    return 0;
}

void displayPlayers() {
    for (int i = 0; i < 4; i++){
        printf(cases[i].displayPlayers + '|');
    }
}

int display(Player leo) {


    int numeroDelaRange;
    int nbColonne;
    /*for (int i = 0; i < NB_LINES; i++){
        fprintf(stdout, (char *) lignesDuPlateau[i].content);
        printf("\n");
   }*/
    // File opening in read mode


    FILE* fp = fopen("../Monopoly.txt", "r");
    if (fp == NULL) { perror("Error opening file"); return(-1); }
    for (int i = 0; i < NB_LINES; i++) {
        for (int j = 0; j < nbColonne; i++) {

            // pour afficher ou sont les joueurs
            if ((i % 4 == 0) && i != 0) {
                
                cases[i].players;

                


                printf("|       %s       |       %s      |      %s       |       %s      |\n",cases->displayPlayers); // changer num && rendre dynamique
            }

            char line[60];
            // Chiffre a changer au bon nombre de caractère d'une ligne
            fgets(line, 60, fp);
            printf(line);
            strcpy(line, "");
        }
    }
    fclose(fp);

    return 0;
}

Propriete createProperty(int id, int idCase, int price, int owner, int rent){
    Propriete p;
    p.id = id;
    p.idCase = idCase;
    p.price = price;
    p.owner = owner;
    p.rent = rent;

    return p;
};
