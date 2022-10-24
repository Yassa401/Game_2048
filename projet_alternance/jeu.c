#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NB_MAX 4 

void matrice (int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
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
    mat[i][j] = 2;
    
}

void afficher(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mat[i][j] == 0){
                printf("  |");
            }
            else
            {
                printf("%d |",mat[i][j]);
            }
        }
        printf("\n");
    }
}


void fusion();
void score();
void victoire();
void defaite();
void deplacement(int n,int mat[NB_MAX][NB_MAX], char c){
    int i,j;
    printf("choisis un sens : ");
    scanf("%c",&c);
    if ( c == "a"){
        int g , tmp;
        for (i=0;i<n;i++){
            g = 0;
            for (j=0;j<n;j++){
                if (mat[i][j] != 0){
                    mat[i][g] = mat[i][j];
                    g = j;
                }
            }
        }
    }
    if ( c == "d"){}
    if ( c == "s"){}
    if ( c == "w"){}
    else {}
    
}
void limite();
/* tests des fonctions */ 
int main(void){
    int n, mat[NB_MAX][NB_MAX];
    srand(time(NULL));
    n = NB_MAX;
    matrice(n, mat);
    initialisation(n, mat);
    afficher(n, mat);
    
}