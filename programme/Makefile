CC=gcc
CFLAGS=-W -Wall -std=c89 -pedantic -O3
LDFLAGS=
EXEC_FILES=jeu_initiale

all : jeu_initiale


jeu_initiale : jeu_initiale.o gestion_jeu.o sauvegarde_partie.o interface.o menu_principale.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` $^ `pkg-config --libs-only-l MLV` -o $@
	chmod +x gestion_sauvegarde.sh

jeu_initiale.o : jeu_initiale.c jeu_initiale.h gestion_jeu.h sauvegarde_partie.h interface.h menu_principale.h 
	$(CC) -c $<

menu_principale.o : menu_principale.c menu_principale.h 
	$(CC) -c $<

interface.o : interface.c interface.h jeu_initiale.h gestion_jeu.h menu_principale.h
	$(CC) -c $<

sauvegarde_partie.o : sauvegarde_partie.c sauvegarde_partie.h jeu_initiale.h
	$(CC) -c $<

gestion_jeu.o : gestion_jeu.c gestion_jeu.h jeu_initiale.h
	$(CC) -c $<

clean : 
	rm -f $(EXEC_FILES) *.o
