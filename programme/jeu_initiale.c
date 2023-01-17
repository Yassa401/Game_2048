#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "jeu_initiale.h"
#include "gestion_jeu.h"
#include "sauvegarde_partie.h"
#include "interface.h"
#include "menu_principale.h"

int main(void){
    int n, mat[NB_MAX][NB_MAX],mat_tmp[NB_MAX][NB_MAX], x, y, score, meilleur_score;
    int taille_x, taille_y ; /* taille de la fenetre */
    int mouse_x, mouse_y, taille_interligne = 9;
    int continuer_partie = 0;

    
    /*!
     * variables contenant la taille de la boite de la sauvegarde d'une partie
     */
    int longueur_boite_sauvergarde, largeur_boite_sauvegarde ;
    
    int etat_victoire = 0;
    char nom_joueur[50] ;
    char score_str[50];
    char meilleur_score_str[50];
    char fichier[30] = "partie.txt";
    MLV_Keyboard_button sym = MLV_KEYBOARD_NONE;
    MLV_Event event = MLV_NONE;
    MLV_Keyboard_button dep = MLV_KEYBOARD_NONE;
    MLV_Font* font ;
    MLV_Font* font_cases;
    
    n = NB_MAX, score = 0;
    meilleur_score = 0;

    strcpy(nom_joueur,"Unknown");
    taille_x = NB_MAX*110+10+150;
    taille_y = NB_MAX*110+10+150;
    
    sprintf(score_str,"%d",score);
    sprintf(meilleur_score_str,"%d",meilleur_score);
    
    MLV_create_window("Jeu_2048", "2048", NB_MAX*110+10+150, NB_MAX*110+10+150);
    font = MLV_load_font(FONT, 15);
    font_cases = MLV_load_font(FONT, 20);
    
    /*!
     * taille de la boite du bouton sauvegarde 
     */
    MLV_get_size_of_adapted_text_box_with_font(
        "Sauvegarde",font,
                taille_interligne,
                &largeur_boite_sauvegarde, &longueur_boite_sauvergarde
        );
    
    

    /*!
     * affichage du menu principale 
    */

    continuer_partie = menu_principale(n, taille_interligne);

    
    MLV_clear_window( MLV_COLOR_BLACK);
    
    if (continuer_partie){
        menu_sauvegarde("parties.txt", n, taille_interligne, fichier);
        printf("Nom de la sauvegarde choisi est : %s \n ",fichier);
        if (strcmp(fichier,"null.txt") == 0){
            continuer_partie = 0;
        }
        
    }
    if (! continuer_partie){
        saisie_nom_joueur(n,taille_interligne,nom_joueur);
    }
    while(1){
        srand(time(NULL));
        matrice(n, mat);
        initialisation(n, mat);
        recup_meilleure_score( &meilleur_score );
        sprintf(meilleur_score_str,"%d",meilleur_score);
        if (continuer_partie){
            recup_partie(n, fichier, mat, &score, nom_joueur);
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
                    
                    MLV_draw_text_with_font(8* taille_x/100 + largeur_boite_sauvegarde,16 *taille_y/100,"sauvegarde effectué !",font,
                          MLV_COLOR_MAGENTA);
                    MLV_actualise_window();
                    MLV_wait_seconds(1);
                /*!
                 * Sauvegarde de la partie dans un fichier "nom_joueur.txt"
                 */
                    sauvegarde_partie(n,mat,score,nom_joueur);
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
            MLV_draw_text_with_font( 7* taille_x/100 , 7 * taille_y/100,
                                     "Joueur : ",font,
                                     MLV_COLOR_WHITE );
            MLV_draw_text_with_font( 17* taille_x/100, 7 * taille_y/100,
                                     nom_joueur,font,
                                     MLV_COLOR_GREEN );
            
            MLV_draw_text_with_font( 42 * taille_x/100, 7 * taille_y/100,
                                     "Score : ",font,
                                     MLV_COLOR_WHITE );
            MLV_draw_text_with_font( 52 * taille_x/100, 7 * taille_y/100,
                                     score_str,font,
                                     MLV_COLOR_GREEN );

            MLV_draw_text_with_font( 62 * taille_x/100, 7 * taille_y/100,
                                     "Meilleur score : ",font,
                                     MLV_COLOR_WHITE );
            MLV_draw_text_with_font( 82 * taille_x/100, 7 * taille_y/100,
                                     meilleur_score_str,font,
                                     MLV_COLOR_GREEN );

            MLV_draw_adapted_text_box_with_font(
                    7 * taille_x/100 , 15 *taille_y/100,
                    "Sauvegarde",font,
                    taille_interligne,
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
            afficher_grille_mlv(n,mat,font_cases);
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