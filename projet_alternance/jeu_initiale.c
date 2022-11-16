#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <math.h>
#include "jeu_tmp.h"
#include "sauvegarde_partie.h"
#include "interface.h"

int main(void){
    int n, mat[NB_MAX][NB_MAX],mat_tmp[NB_MAX][NB_MAX], x, y, score, meilleur_score;
    int taille_x, taille_y ; /* taille de la fenetre */
    int mouse_x, mouse_y, taille_interlinge = 9 , continuer_partie = 0;
    char* text;
    char score_str[50];
    char meilleur_score_str[50];
    char * fichier = "partie.txt";
    MLV_Keyboard_button sym;
    MLV_Event event;
    MLV_Keyboard_button dep ;
    n = NB_MAX, score = 0;
    meilleur_score = 425;

    taille_x = NB_MAX*110+10+150;
    taille_y = NB_MAX*110+10+150;
    
    sprintf(score_str,"%d",score);
    sprintf(meilleur_score_str,"%d",meilleur_score);
    
    MLV_create_window("Jeu_2048", "2048", NB_MAX*110+10+150, NB_MAX*110+10+150);

    /* demander si on veut une nouvelle partie ou continuer */
    MLV_draw_adapted_text_box(
        taille_x/4 , taille_y/4,
        "Commencer une nouvelle partie",taille_interlinge,
        MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(
        taille_x/4, taille_y/2,
        "Continuer la partie",taille_interlinge,
        MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER);
    MLV_actualise_window();
    /* Attendre que l'utilisateur clique sur le bouton de la souris */
    MLV_wait_mouse(&mouse_x,&mouse_y);

    if (taille_x/4 <= mouse_x && mouse_x <= 3*taille_x/4 && taille_y/4 <= mouse_y &&  mouse_y <= taille_y/4 + 20){
        MLV_draw_text(150,400,"Initialisation d'une partie !",
                      MLV_COLOR_MAGENTA);
    }
    if (taille_x/4 <= mouse_x && mouse_x <= taille_x/2 && taille_y/2 <= mouse_y &&  mouse_y <= taille_y/2 + 20){
        MLV_draw_text(150,400,"Récuperation de la partie !",
                      MLV_COLOR_MAGENTA);
        continuer_partie = 1;
    }
    
    MLV_actualise_window();
    MLV_wait_seconds(2);

    MLV_clear_window( MLV_COLOR_BLACK);
    
    MLV_wait_input_box(
                100, 70, 300, 150,
                MLV_COLOR_RED, MLV_COLOR_GREEN,MLV_COLOR_BLACK,
                "  Nom du joueur : ", &text
                );
    while(1){
        srand(time(NULL));
        matrice(n, mat);
        initialisation(n, mat);
        if (continuer_partie){
            recup_partie(n, fichier, mat); 
        }
        while(1){
            if (event == MLV_KEY){
                printf("event recuperé\n");

                /* déroulement de la partie en arrière plan  */
                tab_copy(mat_tmp, mat);
                victoire(n, mat);
                if (defaite(n,mat)==0){
                    printf("vous avez perdu \n ");
                }
                dep = deplacement(n, mat, sym);
                fusion(n, mat, dep, &score );
                meilleur(&meilleur_score,score);

                if (score > meilleur_score){
                sprintf(meilleur_score_str,"%d",meilleur_score);
                }
                sprintf(score_str,"%d",score);
                
                if (changement_etat(mat,mat_tmp)){
                    hasard(n,mat);
                }
                
                /* affichage du plateau de jeu et du score dans le terminal */
                fprintf(stdout, "Le score est : %d \n",score);
                afficher(n, mat);
            }

            /* effacer le contenu de la fenêtre pour afficher l'état actuel */
            MLV_clear_window( MLV_COLOR_BLACK);

            /* afficher le nom du joueur et du score dans l'interface graphique  */
            MLV_draw_text( 7* taille_x/100 , 7 * taille_y/100, "Joueur : ", MLV_COLOR_WHITE );
            MLV_draw_text( 17* taille_x/100, 7 * taille_y/100, text, MLV_COLOR_GREEN );
            
            MLV_draw_text( 42 * taille_x/100, 7 * taille_y/100, "Score : ", MLV_COLOR_WHITE );
            MLV_draw_text( 52 * taille_x/100, 7 * taille_y/100, score_str, MLV_COLOR_GREEN );

            MLV_draw_text( 62 * taille_x/100, 7 * taille_y/100, "Meilleur score : ", MLV_COLOR_WHITE );
            MLV_draw_text( 82 * taille_x/100, 7 * taille_y/100, meilleur_score_str, MLV_COLOR_GREEN );
            
            victoire_mlv(n, mat);
            defaite_mlv(n, mat);
            for (x = 10+75; x <= NB_MAX*110+150-100; x+=110){
                for (y = 10+150; y <= NB_MAX*110+150-100; y+=110){
                    MLV_draw_filled_rectangle(x,y,100,100,MLV_COLOR_GREY);
                }
            }
            afficher_mlv(n,mat);
            MLV_update_window();
            
            /* printf("arrivé ici ! \n"); */
            event =MLV_wait_keyboard_or_mouse(&sym,NULL,NULL,NULL,NULL);
        }
    }
   
    MLV_free_window();
    return 0;
}