
jeu_initiale : jeu_initiale.o jeu_tmp.o sauvegarde_partie.o interface.o menu_principale.o 
	gcc -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` jeu_initiale.o jeu_tmp.o sauvegarde_partie.o interface.o menu_principale.o `pkg-config --libs-only-l MLV` -o jeu_initiale

jeu_initiale.o : jeu_initiale.c jeu_initiale.h jeu_tmp.h sauvegarde_partie.h interface.h menu_principale.h 
	gcc -W -Wall -std=c89 -pedantic -O3 -c jeu_initiale.c

menu_principale.o : menu_principale.c menu_principale.h 
	gcc -W -Wall -std=c89 -pedantic -O3 -c menu_principale.c

interface.o : interface.c interface.h jeu_initiale.h jeu_tmp.h menu_principale.h
	gcc -W -Wall -std=c89 -pedantic -O3 -c interface.c

sauvegarde_partie.o : sauvegarde_partie.c sauvegarde_partie.h jeu_initiale.h
	gcc -W -Wall -std=c89 -pedantic -O3 -c sauvegarde_partie.c

jeu_tmp.o : jeu_tmp.c jeu_tmp.h jeu_initiale.h
	gcc -W -Wall -std=c89 -pedantic -O3 -c jeu_tmp.c

clean : 
	rm -f jeu_initiale *.o
