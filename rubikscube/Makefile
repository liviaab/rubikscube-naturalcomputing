all: rubcube

rubcube: rc.o inputreading.o cube.o cubemovements.o genalgorithm.o
	gcc -o rubcube rc.o inputreading.o cube.o cubemovements.o genalgorithm.o -lm

rc.o: rc.c
	gcc -c rc.c -o rc.o -lm

inputreading.o: inputreading.c
	gcc -c inputreading.c -o inputreading.o -lm

cube.o: cube.c
	gcc -c cube.c -o cube.o -lm

cubemovements.o: cubemovements.c
	gcc -c cubemovements.c -o cubemovements.o -lm

genalgorithm.o: genalgorithm.c
	gcc -c genalgorithm.c -o genalgorithm.o -lm