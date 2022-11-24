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
    int mouse_x, mouse_y, taille_interligne = 9;
    int continuer_partie = 0, commencer_partie = 0;

    /*! 
     * variables contenant la taille de la boite du texte commencer la partie
     */
    int longueur_boite_commencer, largeur_boite_commencer ;
    
    /*!
     * variables contenant la taille de la boite du texte continuer la partie
     */
    int longueur_boite_continuer, largeur_boite_continuer ;

    /*!
     * variables contenant la taille de la boite de la sauvegarde d'une partie
     */
    int longueur_boite_sauvergarde, largeur_boite_sauvegarde ;
    
    int etat_victoire = 0;
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

    /*!
     * taille de la boite du bouton sauvegarde 
     */
    MLV_get_size_of_adapted_text_box(
                "Sauvegarde",
                taille_interligne,
                &largeur_boite_sauvegarde, &longueur_boite_sauvergarde
        );
    
    /*!
     * demander si le joueur veut commencer une nouvelle partie ou continuer 
     */

    MLV_get_size_of_adapted_text_box(
                "Commencer une nouvelle partie",
                taille_interligne,
                &largeur_boite_commencer, &longueur_boite_commencer
        );

    MLV_get_size_of_adapted_text_box(
                "Continuer la partie",
                taille_interligne,
                &largeur_boite_continuer, &longueur_boite_continuer
        );

    MLV_draw_adapted_text_box(
        taille_x/4 , taille_y/4,
        "Commencer une nouvelle partie",taille_interligne,
        MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(
        taille_x/4, taille_y/2,
        "Continuer la partie",taille_interligne,
        MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER);
    MLV_actualise_window();
    

    /*!
     * Attendre que l'utilisateur clique sur le bouton de la souris 
    */

    while(continuer_partie != 1 && commencer_partie != 1){
        MLV_wait_mouse(&mouse_x,&mouse_y);
    
        if (taille_x/4 <= mouse_x && mouse_x <= (taille_x/4 + largeur_boite_commencer) && taille_y/4 <= mouse_y &&  mouse_y <= (taille_y/4 + longueur_boite_commencer)){
            MLV_draw_text(taille_x/4,450,"Initialisation d'une partie !",
                          MLV_COLOR_MAGENTA);
            commencer_partie = 1;
        }
        if (taille_x/4 <= mouse_x && mouse_x <= (taille_x/4 + largeur_boite_continuer) && taille_y/2 <= mouse_y &&  mouse_y <= (taille_y/2 + longueur_boite_continuer)){
            MLV_draw_text(taille_x/4,450,"Récuperation de la partie !",
                          MLV_COLOR_MAGENTA);
            continuer_partie = 1;
        }
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
            recup_partie(n, fichier, mat, &score);
            sprintf(score_str,"%d",score);
        }
        while(1){
            if (event == MLV_KEY){
                printf("event recuperé\n");


                /*!
                 * déroulement de la partie en arrière plan  
                 */
                tab_copy(mat_tmp, mat);
                victoire(n, mat);
                if (defaite(n,mat)==0){
                    printf("vous avez perdu \n ");
                }
                dep = deplacement(n, mat, sym);
                fusion(n, mat, dep, &score );
                meilleur(&meilleur_score,score);

                if (score >= meilleur_score){
                sprintf(meilleur_score_str,"%d",meilleur_score);
                }
                sprintf(score_str,"%d",score);
                
                if (changement_etat(mat,mat_tmp)){
                    hasard(n,mat);
                }
                
                /*! 
                 * affichage du plateau de jeu et du score dans le terminal 
                 */
                fprintf(stdout, "Le score est : %d \n",score);
                afficher(n, mat);

            }
            if (event == MLV_MOUSE_BUTTON ){
                
                if ((7 *taille_x/100) <= mouse_x && mouse_x <= (7* taille_x/100 + largeur_boite_sauvegarde) && (15 *taille_y/100) <= mouse_y &&  mouse_y <= (15 *taille_y/100 + longueur_boite_sauvergarde) ){
                    
                    MLV_draw_text(8* taille_x/100 + largeur_boite_sauvegarde,16 *taille_y/100,"sauvegarde effectué !",
                          MLV_COLOR_MAGENTA);
                    MLV_actualise_window();
                    MLV_wait_seconds(1);
                /*!
                 * Sauvegarde de la partie dans un fichier "nom_joueur.txt"
                 */
                    sauvegarde_partie(n,mat,score,text);
                }

            }

            
            /*! 
             * effacer le contenu de la fenêtre pour afficher l'état actuel 
             */
            MLV_clear_window( MLV_COLOR_BLACK);

            
            /*!
             * afficher le nom du joueur , le score et le meilleur score dans la fenêtre de jeu
             * afficher le bouton de sauvegarde 
             */
            MLV_draw_text( 7* taille_x/100 , 7 * taille_y/100,
                           "Joueur : ",
                           MLV_COLOR_WHITE );
            MLV_draw_text( 17* taille_x/100, 7 * taille_y/100,
                           text,
                           MLV_COLOR_GREEN );
            
            MLV_draw_text( 42 * taille_x/100, 7 * taille_y/100,
                           "Score : ",
                           MLV_COLOR_WHITE );
            MLV_draw_text( 52 * taille_x/100, 7 * taille_y/100,
                           score_str,
                           MLV_COLOR_GREEN );

            MLV_draw_text( 62 * taille_x/100, 7 * taille_y/100,
                           "Meilleur score : ",
                           MLV_COLOR_WHITE );
            MLV_draw_text( 82 * taille_x/100, 7 * taille_y/100,
                           meilleur_score_str,
                           MLV_COLOR_GREEN );

            MLV_draw_adapted_text_box(
                    7 * taille_x/100 , 15 *taille_y/100,
                    "Sauvegarde",taille_interligne,
                    MLV_COLOR_RED,MLV_COLOR_GREEN, MLV_COLOR_BLACK,
                    MLV_TEXT_CENTER);


            /*! 
             * afficher le cas de victoire et le cas de défaite 
             * si etat_victoire = 0 alors on teste la fonction 
             * sinon on a déja atteint la victoire et continue le jeu
             * on teste la fonction défaite à chaque fois pour que le jeu arrête si atteint
             */
            if (!etat_victoire){
                etat_victoire = victoire_mlv(n, mat);
            }
            defaite_mlv(n, mat);

            
            for (x = 10+75; x <= NB_MAX*110+150-100; x+=110){
                for (y = 10+150; y <= NB_MAX*110+150-100; y+=110){
                    MLV_draw_filled_rectangle(x,y,100,100,MLV_COLOR_GREY);
                }
            }
            afficher_mlv(n,mat);
            MLV_update_window();

            /*!
             * On récupère l'événement pour l'itération suivante 
             */
            event =MLV_wait_keyboard_or_mouse(&sym,NULL,NULL,&mouse_x,&mouse_y);
        }
    }
   
    MLV_free_window();
    return 0;
}