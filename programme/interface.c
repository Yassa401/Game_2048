#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <math.h>
#include "jeu_initiale.h"
#include "jeu_tmp.h"
#include "interface.h"
#include "menu_principale.h"


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
        return MLV_COLOR_PINK;
    default :
        return MLV_COLOR_RED;      
    }
}

void afficher_mlv(int n, int mat[NB_MAX][NB_MAX]){
    int i,j, x, y;
    char number[50];
    int taille_interlinge = 9;
    MLV_Font* font ;
    font = MLV_load_font(FONT, 20);
    x = 0, y = 0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mat[i][j] != 0){
                sprintf(number,"%d",mat[i][j]);
                y = i * 110 + 10 + 150; /* coordonnées Y */
                x = j * 110 + 10 + 75; /* coordonnées X */
                MLV_draw_text_box_with_font(
                x,y,
                100,100,
                number,font,
                taille_interlinge,
                couleur(i,j,mat), MLV_COLOR_BLACK,couleur(i,j,mat),
                MLV_TEXT_CENTER,
                MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
            }
        }
    }
}

int victoire_mlv(int n, int mat[NB_MAX][NB_MAX]){
    int i,j;
    MLV_Font* font ;
    font = MLV_load_font(FONT, 20);
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mat[i][j] == 2048){
                MLV_draw_text_with_font( 66* (NB_MAX*110+10+150)/100, 15 *(NB_MAX*110+10+150)/100, "Vous avez gagné !",font, MLV_COLOR_RED );
                return 1 ;
            }
        }
    }
    return 0  ;
}

void defaite_mlv(int n, int mat[NB_MAX][NB_MAX]){
    MLV_Font* font ;
    font = MLV_load_font(FONT, 20);
    if (defaite(n,mat)==0){
        MLV_draw_text_with_font(66* (NB_MAX*110+10+150)/100,  15 *(NB_MAX*110+10+150)/100, "Vous avez perdu !",font, MLV_COLOR_RED );
    }
}


