#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

#define weight	100


typedef char Face[NUM_FACELETES];

/*
	cubeface[0] = Front			||		cubeface[1]	= Left
	cubeface[2] = Right			||		cubeface[3]	= Back
	cubeface[4] = Up			||		cubeface[5]	= Down

	___________
	| 0  1  2 |
	| 3  4  5 |
	| 6  7  8 |
	|_________|
*/

typedef struct{
	Face cubeface[NUM_FACES];
}Cube;

int 	getFace(char *);
void	setFace(Cube *, int, char , char , char , char, char , char , char , char , char );
void 	printCube(Cube);
void 	printFileCube(Cube, FILE *);