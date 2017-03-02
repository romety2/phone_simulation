PR = main.o mini_tel.o dod_gry.o dod_kal.o obrazki.o

BIB = -lm -lGL -lGLU -lglut

prog: $(PR)
	gcc -o mini_tel $(PR) $(BIB)

main.o: mini_tel.h
mini_tel.o: mini_tel.h dod_kal.h dod_gry.h obrazki.h
dod_gry.o: dod_gry.h
dod_kal.o: dod_kal.h
obrazki.o: obrazki.h

clean :
	rm mini_tel $(PR)
