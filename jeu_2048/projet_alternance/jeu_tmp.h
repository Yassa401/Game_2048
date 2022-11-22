
#ifndef JEU_TMP_H
#define JEU_TMP_H

#ifndef NB_MAX
#define NB_MAX 5

#endif

void matrice(int n, int mat[NB_MAX][NB_MAX]);
void initialisation(int n, int mat[NB_MAX][NB_MAX]);
void tab_copy(int t1[NB_MAX][NB_MAX], int t2[NB_MAX][NB_MAX]);
void hasard(int n, int mat[NB_MAX][NB_MAX]);
int changement_etat(int t1[NB_MAX][NB_MAX], int t2[NB_MAX][NB_MAX]);
void afficher(int n, int mat[NB_MAX][NB_MAX]);
MLV_Keyboard_button deplacement(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button sym);
void deplacement_aux(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button sym);
void score_count(int *sc, int mat[NB_MAX][NB_MAX], int i, int j);
void fusion(int n,int mat[NB_MAX][NB_MAX], MLV_Keyboard_button dep , int *score );
void victoire(int n, int mat[NB_MAX][NB_MAX]);
int defaite(int n, int mat[NB_MAX][NB_MAX]);

#endif