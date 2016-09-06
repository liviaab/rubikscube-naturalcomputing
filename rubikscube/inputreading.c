#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputreading.h"
#include "globals.h"


void read_entry( FILE *input, Cube *cube ){
	int i, j, k;
	int dimension, faceindex, colorindex;
	char *side;
	char color1, color2, color3, 
		 color4, color5, color6,
		 color7, color8, color9;


	fscanf(input, "%d", &dimension);
	side = (char*)malloc(6*sizeof(char));

	for( i = 0; i < NUM_FACES ; i++){
		fscanf(input, "%s ", side);

	
		faceindex = getFace(side);

		for(k = 0; k < 6 ;k++) side[k] = '\0';

		fscanf(input, "%c %c %c\n%c %c %c\n%c %c %c", 
			&color1, &color2, &color3,
			&color4, &color5, &color6,
	 		&color7, &color8, &color9);	

	 	setFace(cube, faceindex, color1, color2, color3,
			color4, color5, color6,
	 		color7, color8, color9);
	}

	free(side);
	return;
}

