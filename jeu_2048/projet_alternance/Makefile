
jeu_initiale : jeu_initiale.o interface.o sauvegarde_partie.o jeu_tmp.o
	gcc -o jeu_initiale -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` jeu_initiale.o interface.o jeu_tmp.o sauvegarde_partie.o `pkg-config --libs-only-l MLV`
jeu_initiale.o : jeu_initiale.c interface.h jeu_tmp.h sauvegarde_partie.h
	gcc -c -O3 jeu_initiale.c
interface.o : interface.c interface.h jeu_tmp.h
	gcc -c -O3 interface.c
sauvegarde_partie.o : sauvegarde_partie.c sauvegarde_partie.h jeu_tmp.h
	gcc -c -O3 sauvegarde_partie.c
jeu_tmp.o : jeu_tmp.c jeu_tmp.h
	gcc -c -O3 jeu_tmp.c
clean : 
	rm -f jeu_initiale *.o
