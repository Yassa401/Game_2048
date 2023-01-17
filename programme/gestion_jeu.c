#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "gestion_jeu.h"
#include "jeu_initiale.h"


/*!
 * initialise les valeurs de la matrice à 0 
 */
void matrice (int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    return;
}

/*
 * initialise deux indices aléatoires de la matrice à 2,2 ou 2.4
 */
void initialisation(int n,int mat[NB_MAX][NB_MAX]){
    int i,j;
    i = rand()%n;
    j = rand()%n;
    mat[i][j] = 2;
    while (mat[i][j] != 0){
        i = rand()%n;
        j = rand()%n;
    }
    mat[i][j] = (rand()%(2)+1)*2;
    return;    
}

/*!
 * copie les valeurs de la matrice t2 dans t1
 */
void tab_copy(int t1[NB_MAX][NB_MAX],int t2[NB_MAX][NB_MAX]){
    int i, j;
    for (i=0;i<NB_MAX;i++){
        for (j=0;j<NB_MAX;j++){
            t1[i][j] = t2[i][j];
        }
    }
    return ;
}

/*!
 * affiche la matrice dans le terminal
 */ 
void afficher(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        printf("|");
        for (j=0;j<n;j++){
            if (mat[i][j] == 0){
                printf("    |");
            }
            else
            {
                printf("%4d|",mat[i][j]);
            }
        }
        printf("\n");
    }
}

/*!
 * génère aléatoirement 2 ou 4 dans une case de la matrice ayant la valeur 0
 * l'argument n est la taille de la matrice
 */
void hasard(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    i = rand()%n;
    j = rand()%n; 
    while (mat[i][j] != 0){
        i = rand()%n;
        j = rand()%n;
    }
    mat[i][j] = (rand()%(2)+1)*2;
    return;
}

/*!
 * vérifie s'il y a une différence entre les deux matrices en argument
 */ 
int changement_etat(int t1[NB_MAX][NB_MAX], int t2[NB_MAX][NB_MAX]){
    int i, j;
    for (i=0;i<NB_MAX;i++){
        for (j=0;j<NB_MAX;j++){
            if (t1[i][j] != t2[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

/*!
 * effectue les déplacements des touches du clavier
 * la fonction retourne la touche du clavier pressé 
 */
MLV_Keyboard_button deplacement(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button sym){
    int i,j;
    const char* sym_string;
    sym_string = MLV_convert_keyboard_button_to_string( sym );
    printf("sym -----%s------ \n ",sym_string);
    if ( sym == MLV_KEYBOARD_LEFT){
        int g ,tmp;
        for (i=0;i<n;i++){
            g = 0, tmp = 0;
            for (j=0;j<n;j++){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[i][g] = tmp;
                    g += 1;
                }
            }
        }
    }
    if ( sym == MLV_KEYBOARD_RIGHT){
        int d ,tmp;
        for (i=n-1; i>=0; i--){
            d = n-1, tmp = 0;
            for (j=n-1; j>=0; j--){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[i][d] = tmp;
                    d -= 1;
                }
            }
        }
    }
    if ( sym == MLV_KEYBOARD_DOWN){
        int b, tmp;
        for (j=n-1; j>= 0; j--){
            b=n-1, tmp = 0;
            for (i=n-1; i>=0; i--){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[b][j] = tmp;
                    b -= 1;
                }
             }
        }
    }
    if ( sym  == MLV_KEYBOARD_UP){
        int h, tmp;
        for (j=0; j<n; j++){
            h = 0, tmp = 0;
            for (i=0; i<n; i++){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[h][j] = tmp;
                    h += 1;
                }
             }
        }
    }
    return sym;
}

/*!
 * effectue les déplacements des touches du clavier 
 * la fonction ne retourne rien
 */
void deplacement_aux(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button sym){
    int i,j;
    if ( sym == MLV_KEYBOARD_LEFT){
        int g ,tmp;
        for (i=0;i<n;i++){
            g = 0, tmp = 0;
            for (j=0;j<n;j++){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[i][g] = tmp;
                    g += 1;
                }
            }
        }
    }
    if ( sym == MLV_KEYBOARD_RIGHT){
        int d ,tmp;
        for (i=n-1; i>=0; i--){
            d = n-1, tmp = 0;
            for (j=n-1; j>=0; j--){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[i][d] = tmp;
                    d -= 1;
                }
            }
        }
    }
    if ( sym == MLV_KEYBOARD_DOWN){
        int b, tmp;
        for (j=n-1; j>= 0; j--){
            b=n-1, tmp = 0;
            for (i=n-1; i>=0; i--){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[b][j] = tmp;
                    b -= 1;
                }
            }
        }
    }
    if ( sym == MLV_KEYBOARD_UP){
        int h, tmp;
        for (j=0; j<n; j++){
            h = 0, tmp = 0;
            for (i=0; i<n; i++){
                if (mat[i][j] != 0){
                    tmp = mat[i][j];
                    mat[i][j] = 0;
                    mat[h][j] = tmp;
                    h += 1;
                }
            }
        }
    }
    return ;
}
/*!
 * calcule le score après chaque fusion effectué
 */
void score_count(int *sc, int mat[NB_MAX][NB_MAX], int i, int j){
    *sc += mat[i][j];
    return ;
}
/*!
 * gère les fusions à effectuer selon le sens choisi
 */
void fusion(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button dep, int *score ){
    int i,j;
    
    if (dep == MLV_KEYBOARD_LEFT){
        i = 0;
        while(i<n){
            j = 0;
            while(j<n-1){
                if (mat[i][j] == mat[i][j+1]){
                    mat[i][j] += mat[i][j+1];
                    score_count(score,mat,i,j);
                    mat[i][j+1] = 0;
                }
                j += 1;
            }
            i += 1;
        }
    }
    if (dep == MLV_KEYBOARD_RIGHT){
        i = 0;
        while(i<n){
            j = n-1;
            while(j>0){
                if (mat[i][j] == mat[i][j-1]){
                    mat[i][j] += mat[i][j-1];
                    score_count(score,mat,i,j);
                    mat[i][j-1] = 0;
                }
                j -= 1;
            }
            i += 1;
        }
    }
    if (dep == MLV_KEYBOARD_UP){
        j = 0;
        while(j<n){
            i = 0;
            while(i<n-1){
                if (mat[i][j] == mat[i+1][j]){
                    mat[i][j] += mat[i+1][j];
                    score_count(score,mat,i,j);
                    mat[i+1][j] = 0;
                }
                i += 1;
            }
            j += 1;
        }
    }
    if (dep == MLV_KEYBOARD_DOWN){
        j = 0;
        while(j<n){
            i = n-1;
            while(i>0){
                if (mat[i][j] == mat[i-1][j]){
                    mat[i][j] += mat[i-1][j];
                    score_count(score,mat,i,j);
                    mat[i-1][j] = 0;
                }
                i -= 1;
            }
            j += 1;
        }
    }
    deplacement_aux(n,mat,dep);
}

/*!
 * vérifie si le joueur a gagné
 */
void victoire(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mat[i][j] == 2048){
                afficher(n, mat);
                fprintf(stdout,"Vous avez gagné ! \n");
                return ;                
            }
        }
    }
}

int d_ligne(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(mat[i][j]==mat[i][j+1]){
                return 1;
            }
        }
    }
    return 0;
}
int d_colonne(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]==mat[i+1][j]){
                return 1;
            }
        }
    }
    return 0;
}
/*
 * vérifie si le joueur a perdu
 * retourne 1 si oui sinon 0
 */
int defaite(int n, int mat[NB_MAX][NB_MAX]){
    int i,j ,cmp=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]==0){
                cmp++;
            }
        }
    }
    if(cmp==0 && d_ligne(n,mat)==0 && d_colonne(n,mat)==0){
        return 0;
    }  
    return 1;
}
 
