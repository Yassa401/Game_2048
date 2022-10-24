#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "jeu_tmp.h"


int main(void){
    int n, mat[NB_MAX][NB_MAX] , score = 0;
    char c[2] = " ";
    char dep = ' ';
    srand(time(NULL));
    n = NB_MAX;
    matrice(n, mat);
    initialisation(n, mat);
    while(1){
        victoire(n, mat);
        afficher(n, mat);
        dep = deplacement(n, mat, c);
        fusion(n, mat, dep, &score );
        fprintf(stdout, "Le score est : %d \n",score);        
        //hasard(n, mat);
    }
    
}