    
#ifndef INTERFACE_H
#define INTERFACE_H

MLV_Color couleur(int i,int j,int mat[NB_MAX][NB_MAX]);

void afficher_mlv(int n, int mat[NB_MAX][NB_MAX]);

int victoire_mlv(int n, int mat[NB_MAX][NB_MAX]);

void defaite_mlv(int n, int mat[NB_MAX][NB_MAX]);

#endif