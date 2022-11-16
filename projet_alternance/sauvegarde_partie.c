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

void sauvegarde_score(int meilleur_score){

  FILE* fichier=NULL;

  fichier=fopen("meilleur_score.txt","w+");

  if(fichier==NULL){

    printf("impossible d'ouvrir le fichier\n");

    exit(EXIT_FAILURE);

  }

  fprintf(fichier,"%d",meilleur_score);;

  fclose(fichier);

}
void meilleur(int *meilleur_score,int score_actuelle){

  if(score_actuelle>*meilleur_score){

    *meilleur_score=score_actuelle;
    sauvegarde_score(*meilleur_score);

  }
}

