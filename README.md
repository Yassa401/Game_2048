# jeu_2048

projet d'alternance pour l'année 2022/2023 En L2 informatique

Binôme : Yasser et Lydia


## Compilation :
commande : gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` jeu_initiale.c jeu_tmp.o `pkg-config --libs-only-l MLV` -o jeu_initiale
