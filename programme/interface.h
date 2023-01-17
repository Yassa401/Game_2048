#include "jeu_initiale.h"


#ifndef INTERFACE_H
#define INTERFACE_H

MLV_Color couleur(int i,int j,int mat[NB_MAX][NB_MAX]);

void afficher_grille_mlv(int n, int mat[NB_MAX][NB_MAX], MLV_Font* font);

int victoire_mlv(int n, int mat[NB_MAX][NB_MAX]);

void defaite_mlv(int n, int mat[NB_MAX][NB_MAX]);

#endif