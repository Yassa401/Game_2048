#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "jeu_tmp.h"
#include "sauvegarde_partie.h"

void recup_partie (int n,char *  str,int mat[NB_MAX][NB_MAX]){
    FILE* fichier = NULL;
    int i,j, valeur;
    fichier = fopen(str, "r");
    if( fichier == NULL){
        fprintf(stderr,"Erreur dans l'ouverture du fichier !\n");
        exit(EXIT_FAILURE);
    }
    valeur = 0;
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++){
            if (fscanf(fichier,"%d", &valeur) != 1){
                fprintf(stderr,"Erreur dans l'ouverture du fichier !\n");
                return ;
            };
            mat[i][j] = valeur ;
        }
    }    
}
