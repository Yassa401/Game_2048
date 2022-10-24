
#ifndef JEU_TMP_H
#define JEU_TMP_H

#ifndef NB_MAX
#define NB_MAX 4

#endif

void matrice(int n, int mat[NB_MAX][NB_MAX]);
void initialisation(int n, int mat[NB_MAX][NB_MAX]);
void hasard(int n, int mat[NB_MAX][NB_MAX]);
void afficher(int n, int mat[NB_MAX][NB_MAX]);
char deplacement(int n,int mat[NB_MAX][NB_MAX], char *c);
void deplacement_aux(int n,int mat[NB_MAX][NB_MAX], char c);
void score_count(int *sc, int mat[NB_MAX][NB_MAX], int i, int j);
void fusion(int n,int mat[NB_MAX][NB_MAX], char dep , int *score );
void victoire(int n, int mat[NB_MAX][NB_MAX]);

#endif