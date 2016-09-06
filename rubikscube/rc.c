#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputreading.h"
#include "cube.h"
#include "cubemovements.h"
#include "globals.h"
#include <limits.h>

int main(int argc, char *argv[]){
	FILE *fpin, *fpout;
	fpin = fopen(argv[1], "r");
	fpout = fopen(OUTPUTFILE, "w");

	if(!fpin){
		printf("Erro na abertura do arquivo\nError opening file\n");
		exit(0);
	}

	Cube cube;
	read_entry( fpin, &cube);
	
	init(&cube);
	printf("k tnx bye2\n");

	fclose(fpin);
	fclose(fpout);
    return 0;
}