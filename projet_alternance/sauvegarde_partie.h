#include "jeu_initiale.h"

#ifndef SAUVEGARDE_PARTIE_H
#define SAUVEGARDE_PARTIE_H

void recup_partie(int n, char * str ,int mat[NB_MAX][NB_MAX],int *score, char* nom_joueur);

void sauvegarde_score(int meilleur_score);

void meilleur(int *meilleur_score,int score_actuelle);

void recup_meilleure_score(int *meilleur_score);

void sauvegarde_partie(int n, int mat[NB_MAX][NB_MAX], int score,char* nom_joueur);


#endif