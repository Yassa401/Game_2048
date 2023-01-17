
jeu_initiale : jeu_initiale.o gestion_jeu.o sauvegarde_partie.o interface.o menu_principale.o 
	gcc -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` jeu_initiale.o gestion_jeu.o sauvegarde_partie.o interface.o menu_principale.o `pkg-config --libs-only-l MLV` -o jeu_initiale
	chmod +x gestion_sauvegarde.sh

jeu_initiale.o : jeu_initiale.c jeu_initiale.h gestion_jeu.h sauvegarde_partie.h interface.h menu_principale.h 
	gcc -c jeu_initiale.c

menu_principale.o : menu_principale.c menu_principale.h 
	gcc -c menu_principale.c

interface.o : interface.c interface.h jeu_initiale.h gestion_jeu.h menu_principale.h
	gcc -c interface.c

sauvegarde_partie.o : sauvegarde_partie.c sauvegarde_partie.h jeu_initiale.h
	gcc -c sauvegarde_partie.c

gestion_jeu.o : gestion_jeu.c gestion_jeu.h jeu_initiale.h
	gcc -c gestion_jeu.c

clean : 
	rm -f jeu_initiale *.o
