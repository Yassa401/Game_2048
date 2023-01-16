

#ifndef MENU_PRINCIPALE_H
#define MENU_PRINCIPALE_H

#ifndef FONT
#define FONT "font/origin.ttf"

#endif

int menu_principale(int n , int taille_interligne);

void saisie_nom_joueur(int n,int taille_interligne, char* text);

void menu_sauvegarde(char * parties, int n, int taille_interligne, char * nom_sauvegarde);
    
#endif