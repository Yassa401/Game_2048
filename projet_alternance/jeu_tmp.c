#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "jeu_tmp.h"
#include <string.h>

#define NB_MAX 4

/*void viderbuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}
int lire(char *str, int longueur){
    if (fgets(str,longueur,stdin) != NULL){
        viderbuffer();
        return 1;
    }
    else {
        viderbuffer();
        return 0;
    }
}*/

void matrice (int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    return;
}

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

void tab_copy(int t1[NB_MAX][NB_MAX],int t2[NB_MAX][NB_MAX]){
    int i, j;
    for (i=0;i<NB_MAX;i++){
        for (j=0;j<NB_MAX;j++){
            t1[i][j] = t2[i][j];
        }
    }
    return ;
}
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

int changement_etat(int t1[NB_MAX][NB_MAX], int t2[NB_MAX][NB_MAX]){
    int i, j, tmp[NB_MAX][NB_MAX];
    for (i=0;i<NB_MAX;i++){
        for (j=0;j<NB_MAX;j++){
            if (t1[i][j] != t2[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

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
    else {}
    printf("fin d'éxécution \n");
    return sym;
}


void deplacement_aux(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button sym){
    int i,j;
    //fprintf(stdout, "\n");
    //fprintf(stdout,"-%c-\n",c);
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
    else {}
    return ;
}
void score_count(int *sc, int mat[NB_MAX][NB_MAX], int i, int j){
    *sc += mat[i][j];
    //fprintf(stdout, "Le score est : %d \n",*sc);
    return ;
}
void fusion(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button dep, int *score ){
    int i,j; 
    // fprintf(stdout, "-%c-\n",dep);
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

void meilleure(); 

void victoire(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mat[i][j] == 2048){
                afficher(n, mat);
                fprintf(stdout,"Vous avez gagné ! \n");
                exit(EXIT_SUCCESS);                
            }
        }
    }
}
/* int est_deplacer(char *c, int n){
    char strdep[4] = {'a','d','w','s'};
    int i;
    for (i=0;i<n;i++){
        if (c[0] == strdep[i]){
            return 1 ;
        }
    }
    return 0 ;
    }*/
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
 


/* tests des fonctions */ 

/* int main(void){
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
    
    } */