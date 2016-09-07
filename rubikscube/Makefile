
rubcube: rc.o inputreading.o cube.o cubemovements.o genalgorithm.o auxfunctions.o
	gcc -o rubcube rc.o inputreading.o cube.o cubemovements.o genalgorithm.o auxfunctions.o -lm

rc.o: rc.c globals.h
	gcc -c rc.c -o rc.o -lm

inputreading.o: inputreading.c globals.h
	gcc -c inputreading.c -o inputreading.o -lm

cube.o: cube.c globals.h
	gcc -c cube.c -o cube.o -lm

cubemovements.o: cubemovements.c globals.h
	gcc -c cubemovements.c -o cubemovements.o -lm 

genalgorithm.o: genalgorithm.c globals.h
	gcc -c genalgorithm.c -o genalgorithm.o -lm

auxfunctions.o: auxfunctions.c globals.h
	gcc -c auxfunctions.c -o auxfunctions.o -lm

clean:
	rm -r *.o *.txt