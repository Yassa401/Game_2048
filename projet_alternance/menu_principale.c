#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu_principale.h"

int menu_principale(int n , int taille_interligne){
    /*! 
     * variables contenant la taille de la boite du texte commencer la partie
     */
    int longueur_boite_commencer, largeur_boite_commencer ;
    
    /*!
     * variables contenant la taille de la boite du texte continuer la partie
     */
    int longueur_boite_continuer, largeur_boite_continuer ;

    int taille_x ,taille_y;
    int mouse_x = 0, mouse_y = 0;
    int continuer_partie = -1  ;

    MLV_Font* font = MLV_load_font("Starborn.ttf", 20);

    taille_x = n*110+10+150;
    taille_y = n*110+10+150;

    /*!
     * demander si le joueur veut commencer une nouvelle partie ou continuer 
     */

    MLV_get_size_of_adapted_text_box_with_font(
        "Commencer une nouvelle partie",font,
        taille_interligne,
        &largeur_boite_commencer, &longueur_boite_commencer
        );

    MLV_get_size_of_adapted_text_box_with_font(
        "Continuer la partie",font,
        taille_interligne,
        &largeur_boite_continuer, &longueur_boite_continuer
        );

    MLV_draw_adapted_text_box_with_font(
        taille_x/6 , taille_y/3,
        "Commencer une nouvelle partie",font,
        taille_interligne,
        MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box_with_font(
        taille_x/6, taille_y/2,
        "Continuer la partie",font,
        taille_interligne,
        MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER);

    font = MLV_load_font("Starborn.ttf",100);

    MLV_draw_text_with_font(taille_x/10, taille_y/12,"2048 !",font,MLV_COLOR_YELLOW);
    MLV_actualise_window();

    
    
    while(continuer_partie == - 1){
        MLV_wait_mouse(&mouse_x,&mouse_y);
    
        if (taille_x/6 <= mouse_x && mouse_x <= (taille_x/6 + largeur_boite_commencer) && taille_y/3 <= mouse_y &&  mouse_y <= (taille_y/3 + longueur_boite_commencer)){
            MLV_draw_text(taille_x/4,450,"Initialisation d'une partie !",
                          MLV_COLOR_MAGENTA);
            continuer_partie = 0;
        }
        if (taille_x/6 <= mouse_x && mouse_x <= (taille_x/6 + largeur_boite_continuer) && taille_y/2 <= mouse_y &&  mouse_y <= (taille_y/2 + longueur_boite_continuer)){
            MLV_draw_text(taille_x/4,450,"Récuperation de la partie !",
                          MLV_COLOR_MAGENTA);
            continuer_partie = 1;
        }
    }
    MLV_actualise_window();
    MLV_wait_seconds(2);

    return continuer_partie;

}


void saisie_nom_joueur(int n,int taille_interligne, char* text){

    int longueur_boite_saisie, largeur_boite_saisie;

    int taille_x, taille_y;
    char* text_tmp;
    MLV_Font* font = MLV_load_font("Starborn.ttf",20);

    taille_x = n*110+10+150;
    taille_y = n*110+10+150;
    
    MLV_get_size_of_adapted_text_box_with_font(
        "Nom du joueur :              ",font,
        taille_interligne,
        &largeur_boite_saisie, &longueur_boite_saisie
        );

    MLV_wait_input_box_with_font(
        taille_x/10, taille_y/10, (taille_x/10)+largeur_boite_saisie, (taille_y/10)+ longueur_boite_saisie,
            MLV_COLOR_RED, MLV_COLOR_GREEN,MLV_COLOR_BLACK,
            "  Nom du joueur : ", &text_tmp, font
            );

    MLV_actualise_window();

    strcpy(text,text_tmp);
    
    return ;

     

}


