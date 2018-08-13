# -*- Makefile -*-

tp2: main.o edit_distance.o
	gcc main.o edit_distance.o -o tp2

main.o: main.c 
	gcc -c main.c

edit_distance.o: edit_distance.c edit_distance.h
	gcc -c edit_distance.c

clean:
	rm *.o