#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "cube.h"


int getFace( char *strface){
	if( strcmp(strface, "Front") == 0 ){
		return 0;
	}else if(strcmp(strface, "Left") == 0 ){
		return 1;
	}else if(strcmp(strface, "Right") == 0 ){
		return 2;
	}else if(strcmp(strface, "Back") == 0 ){
		return 3;
	}else if(strcmp(strface, "Up") == 0 ){
		return 4;
	}else if(strcmp(strface, "Down") == 0 ){
		return 5;
	}
	return -1;
};

void setFace(Cube *cube, int face, char a, char b, char c, char d, char e, char f, char g, char h, char i ){
	cube->cubeface[face][0] = a;
	cube->cubeface[face][1] = b;
	cube->cubeface[face][2] = c;
	cube->cubeface[face][3] = d;
	cube->cubeface[face][4] = e;
	cube->cubeface[face][5] = f;
	cube->cubeface[face][6] = g;
	cube->cubeface[face][7] = h;
	cube->cubeface[face][8] = i;
};

void printCube( Cube cube){
	int i;
	printf("Printing cube --- Faces:\n");

	for(i = 0 ; i < NUM_FACES ; i++){
		if(i==0){
			printf("Front:");
		}else if(i == 1){
			printf("Left:");
		}else if(i == 2){
			printf("Right:");
		}else if(i == 3){
			printf("Back:");
		}else if(i == 4){
			printf("Up:");
		}else if(i == 5){
			printf("Down:");
		}

		printf( "\n%c %c %c\n%c %c %c\n%c %c %c\n",
			cube.cubeface[i][0],cube.cubeface[i][1],cube.cubeface[i][2],
			cube.cubeface[i][3],cube.cubeface[i][4],cube.cubeface[i][5],
			cube.cubeface[i][6],cube.cubeface[i][7],cube.cubeface[i][8] );
	}
};

void printFileCube(Cube cube, FILE *fpout){
	int i;
	fprintf(fpout,"Printing cube --- Faces:\n");

	for(i = 0 ; i < NUM_FACES ; i++){
		if(i==0){
			fprintf(fpout, "Front:");
		}else if(i == 1){
			fprintf(fpout, "Left:");
		}else if(i == 2){
			fprintf(fpout, "Right:");
		}else if(i == 3){
			fprintf(fpout, "Back:");
		}else if(i == 4){
			fprintf(fpout, "Up:");
		}else if(i == 5){
			fprintf(fpout, "Down:");
		}

		fprintf(fpout,"\n%c %c %c\n%c %c %c\n%c %c %c\n",
			cube.cubeface[i][0],cube.cubeface[i][1],cube.cubeface[i][2],
			cube.cubeface[i][3],cube.cubeface[i][4],cube.cubeface[i][5],
			cube.cubeface[i][6],cube.cubeface[i][7],cube.cubeface[i][8]);
	}
};

