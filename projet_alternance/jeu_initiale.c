#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <math.h>
#include "jeu_tmp.h"

MLV_Color couleur(int i,int j,int mat[NB_MAX][NB_MAX]){
    switch ( mat[i][j] )
    {
    case 2 :
        return MLV_COLOR_CYAN1 ;
    case 4 :
        return MLV_COLOR_LIME_GREEN ;
    case 8 :
        return MLV_COLOR_LIGHT_SALMON;
    case 16 :
        return MLV_COLOR_MAGENTA;
    case 32 :
        return MLV_COLOR_GOLD1;
    case 64 :
        return MLV_COLOR_WHITE_SMOKE;
    case 128 :
        return MLV_COLOR_ROYAL_BLUE;
    case 256 :
        return MLV_COLOR_DARK_KHAKI;
    case 512 :
        return MLV_COLOR_INDIAN_RED;
    case 1024 :
        return MLV_COLOR_GREEN;
    default :
        return MLV_COLOR_RED;      
    }
}

void afficher_mlv(int n, int mat[NB_MAX][NB_MAX]){
    int i,j, x, y;
    x = 0, y = 0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mat[i][j] != 0){
                y = i * 110 + 10 + 150; /* coordonnées Y */
                x = j * 110 + 10 + 75; /* coordonnées X */
                MLV_draw_filled_rectangle(x,y,100,100,couleur(i,j,mat));
            }
        }
    }
}

int main(void){
    int n, mat[NB_MAX][NB_MAX],mat_tmp[NB_MAX][NB_MAX], x, y, score;
    char* text; 
    MLV_Keyboard_button sym;
    MLV_Event event;
    MLV_Keyboard_button dep ;
    n = NB_MAX, score = 0;
    MLV_create_window("Jeu_2048", "2048", NB_MAX*110+10+150, NB_MAX*110+10+150);
    MLV_wait_input_box(
                100, 70, 300, 150,
                MLV_COLOR_RED, MLV_COLOR_GREEN,MLV_COLOR_BLACK,
                "  Nom du joueur : ", &text
                );
    while(1){
        srand(time(NULL));
        matrice(n, mat);
        initialisation(n, mat);
        /*MLV_create_window("Jeu_2048", "2048", NB_MAX*110+10, NB_MAX*110+10);*/
        while(1){
            if (event == MLV_KEY){
                printf("event recuperé\n");
                tab_copy(mat_tmp, mat);
                victoire(n, mat);
                dep = deplacement(n, mat, sym);
                fusion(n, mat, dep, &score );
                /* affichage dans le terminal du score */
                fprintf(stdout, "Le score est : %d \n",score);        
                if (changement_etat(mat,mat_tmp)){
                    hasard(n,mat);
                }
                /* affichage du plateau de jeu dans le terminal */
                afficher(n, mat);
            }           
            /*MLV_wait_input_box(
                10, 70, 200, 90,
                MLV_COLOR_RED, MLV_COLOR_GREEN,MLV_COLOR_BLACK,
                "Nom du joueur : ", &text
                );*/
            MLV_clear_window( MLV_COLOR_BLACK);
            MLV_draw_text( 50, 50, "Joueur : ", MLV_COLOR_GREEN );
            MLV_draw_text( 120, 50, text, MLV_COLOR_GREEN );
            /* MLV_draw_filled_rectangle(0,0,NB_MAX*110+10,NB_MAX*110+10,MLV_COLOR_BLACK); */
            for (x = 10+75; x <= NB_MAX*110+150-100; x+=110){
                for (y = 10+150; y <= NB_MAX*110+150-100; y+=110){
                    MLV_draw_filled_rectangle(x,y,100,100,MLV_COLOR_GREY);
                }
            }
            afficher_mlv(n,mat);
            MLV_update_window();
            printf("arrivé ici ! \n");
            event =MLV_wait_keyboard_or_mouse(&sym,NULL,NULL,NULL,NULL);
        }
    }
   
    MLV_free_window();
    return 0;
}