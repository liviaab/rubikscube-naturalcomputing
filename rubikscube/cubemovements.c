#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "cube.h"
#include "cubemovements.h"


void genMoves(int *moves){
	int i;

	for(i = 0; i < NUM_MOVEMENTS ; i++){
		moves[i] = (rand() % 18) + 1;
		
	}
	return;
}

/*
		Horario 			| 	Clockwise
		1	90º Frente 		|	Front 
		2	90º Fundo 		|	Back	
		3	90º Cima 		|	Up 
		5	90º Baixo 		|	Down
		5	90º Esquerda 	|	Left
		6	90º Direita 	|	Right

		Anti-horario 		|	Counterclockwise
		7	90º Frente 		|	Front 
		8	90º Fundo 		|	Back	
		9	90º Cima 		|	Up 
		10	90º Baixo 		|	Down
		11	90º Esquerda 	|	Left
		12	90º Direita 	|	Right

		180º
		13	Frente 		|	Front
		14	Fundo 		|	Back	
		15	Cima 		|	Up 
		16	Baixo 		|	Down
		17	Esquerda 	|	Left
		18	Direita 	|	Right

*/

void executeMove(Cube *cube, int move){
	char aux1, aux2, aux3, 
		 aux4, aux5, aux6,
		 aux7, aux8;

	switch(move){
		case 1: //      frente 90 H
			//laterais
			aux1 =	cube->cubeface[1][2];
			aux2 =	cube->cubeface[1][5];
			aux3 =	cube->cubeface[1][8];
			cube->cubeface[1][2] = cube->cubeface[5][2];
			cube->cubeface[1][5] = cube->cubeface[5][5];
			cube->cubeface[1][8] = cube->cubeface[5][8];
			cube->cubeface[5][2] = cube->cubeface[2][0];
			cube->cubeface[5][5] = cube->cubeface[2][3];
			cube->cubeface[5][8] = cube->cubeface[2][6];
			cube->cubeface[2][0] = cube->cubeface[4][0];
			cube->cubeface[2][3] = cube->cubeface[4][3];
			cube->cubeface[2][6] = cube->cubeface[4][6];
			cube->cubeface[4][0] = aux3;
			cube->cubeface[4][3] = aux2;
			cube->cubeface[4][6] = aux1;
			
			// salvando face temporariamente
			aux1 =  cube->cubeface[0][0];
			aux2 =	cube->cubeface[0][1];
			aux3 =	cube->cubeface[0][2];
			aux4 =	cube->cubeface[0][5];
			aux5 =	cube->cubeface[0][8]; 
			aux6 =	cube->cubeface[0][7];
		 	aux7 =	cube->cubeface[0][6];
		 	aux8 =	cube->cubeface[0][3];
		 	//mudando orientacao da face da frente
		 	cube->cubeface[0][0] = aux7;
			cube->cubeface[0][1] = aux8;
			cube->cubeface[0][2] = aux1;
			cube->cubeface[0][5] = aux2;
			cube->cubeface[0][8] = aux3; 
			cube->cubeface[0][7] = aux4;
		 	cube->cubeface[0][6] = aux5;
		 	cube->cubeface[0][3] = aux6;
			break;
		case 2: //		90º Fundo 		|	Back	
			aux1 =	cube->cubeface[2][2];
			aux2 =	cube->cubeface[2][5];
			aux3 =	cube->cubeface[2][8];
			cube->cubeface[2][2] = cube->cubeface[5][6]; 
			cube->cubeface[2][5] = cube->cubeface[5][3]; 
			cube->cubeface[2][8] = cube->cubeface[5][0]; 
			cube->cubeface[5][6] = cube->cubeface[1][6]; 
			cube->cubeface[5][3] = cube->cubeface[1][3]; 
			cube->cubeface[5][0] = cube->cubeface[1][0]; 
			cube->cubeface[1][6] = cube->cubeface[4][2];
			cube->cubeface[1][3] = cube->cubeface[4][5];
			cube->cubeface[1][0] = cube->cubeface[4][8];
			cube->cubeface[4][2] = aux1;
			cube->cubeface[4][5] = aux2;
			cube->cubeface[4][8] = aux3;
			
			// salvando face temporariamente
			aux1 =  cube->cubeface[3][0];
			aux2 =	cube->cubeface[3][1];
			aux3 =	cube->cubeface[3][2];
			aux4 =	cube->cubeface[3][5];
			aux5 =	cube->cubeface[3][8]; 
			aux6 =	cube->cubeface[3][7];
		 	aux7 =	cube->cubeface[3][6];
		 	aux8 =	cube->cubeface[3][3];
		 	//mudando orientacao da face da frente
		 	cube->cubeface[3][0] = aux7;
			cube->cubeface[3][1] = aux8;
			cube->cubeface[3][2] = aux1;
			cube->cubeface[3][5] = aux2;
			cube->cubeface[3][8] = aux3; 
			cube->cubeface[3][7] = aux4;
		 	cube->cubeface[3][6] = aux5;
		 	cube->cubeface[3][3] = aux6;
			break;
		case 3:	//		90º Cima 		|	Up 
			aux1 = cube->cubeface[1][0];
			aux2 = cube->cubeface[1][1];
			aux3 = cube->cubeface[1][2];
			cube->cubeface[1][0] = cube->cubeface[0][0];
			cube->cubeface[1][1] = cube->cubeface[0][1];
			cube->cubeface[1][2] = cube->cubeface[0][2];
			cube->cubeface[0][0] = cube->cubeface[2][0];
			cube->cubeface[0][1] = cube->cubeface[2][1];
			cube->cubeface[0][2] = cube->cubeface[2][2];
			cube->cubeface[2][0] = cube->cubeface[3][0];
			cube->cubeface[2][1] = cube->cubeface[3][1];	
			cube->cubeface[2][2] = cube->cubeface[3][2];
			cube->cubeface[3][0] = aux1;
			cube->cubeface[3][1] = aux2;
			cube->cubeface[3][2] = aux3;

			// salvando face temporariamente
			aux1 =  cube->cubeface[4][0];
			aux2 =	cube->cubeface[4][1];
			aux3 =	cube->cubeface[4][2];
			aux4 =	cube->cubeface[4][5];
			aux5 =	cube->cubeface[4][8]; 
			aux6 =	cube->cubeface[4][7];
		 	aux7 =	cube->cubeface[4][6];
		 	aux8 =	cube->cubeface[4][3];
		 	//mudando orientacao da face da frente
		 	cube->cubeface[4][0] = aux7;
			cube->cubeface[4][1] = aux8;
			cube->cubeface[4][2] = aux1;
			cube->cubeface[4][5] = aux2;
			cube->cubeface[4][8] = aux3; 
			cube->cubeface[4][7] = aux4;
		 	cube->cubeface[4][6] = aux5;
		 	cube->cubeface[4][3] = aux6;		
			break;
		case 4: //		90º Baixo 		|	Down
			aux1 = cube->cubeface[3][8];
			aux2 = cube->cubeface[3][7];
			aux3 = cube->cubeface[3][6];
			cube->cubeface[3][8] = cube->cubeface[2][8];
			cube->cubeface[3][8] = cube->cubeface[2][7];
			cube->cubeface[3][8] = cube->cubeface[2][6];
			cube->cubeface[2][8] = cube->cubeface[0][8];
			cube->cubeface[2][7] = cube->cubeface[0][7];
			cube->cubeface[2][6] = cube->cubeface[0][6];
			cube->cubeface[0][8] = cube->cubeface[1][8];
			cube->cubeface[0][7] = cube->cubeface[1][7];
			cube->cubeface[0][6] = cube->cubeface[1][6];
			cube->cubeface[1][8] = aux1;
			cube->cubeface[1][7] = aux2;
			cube->cubeface[1][6] = aux3;

			// salvando face temporariamente
			aux1 =  cube->cubeface[5][0];
			aux2 =	cube->cubeface[5][1];
			aux3 =	cube->cubeface[5][2];
			aux4 =	cube->cubeface[5][5];
			aux5 =	cube->cubeface[5][8]; 
			aux6 =	cube->cubeface[5][7];
		 	aux7 =	cube->cubeface[5][6];
		 	aux8 =	cube->cubeface[5][3];
		 	//mudando orientacao da face da frente
		 	cube->cubeface[5][0] = aux7;
			cube->cubeface[5][1] = aux8;
			cube->cubeface[5][2] = aux1;
			cube->cubeface[5][5] = aux2;
			cube->cubeface[5][8] = aux3; 
			cube->cubeface[5][7] = aux4;
		 	cube->cubeface[5][6] = aux5;
		 	cube->cubeface[5][3] = aux6;
			break;
		case 5:	//		90º Esquerda 	|	Left
			aux1 = cube->cubeface[3][2];
			aux2 = cube->cubeface[3][5];
			aux3 = cube->cubeface[3][8];
			cube->cubeface[3][2] = cube->cubeface[5][0]; 
			cube->cubeface[3][5] = cube->cubeface[5][1];
			cube->cubeface[3][8] = cube->cubeface[5][2];
			cube->cubeface[5][0] = cube->cubeface[0][6];
			cube->cubeface[5][1] = cube->cubeface[0][3];
			cube->cubeface[5][2] = cube->cubeface[0][0];
			cube->cubeface[0][6] = cube->cubeface[4][0];
			cube->cubeface[0][3] = cube->cubeface[4][1];
			cube->cubeface[0][0] = cube->cubeface[4][2];
			cube->cubeface[4][0] = aux1;
			cube->cubeface[4][1] = aux2;
			cube->cubeface[4][2] = aux3;

			// salvando face temporariamente
			aux1 =  cube->cubeface[1][0];
			aux2 =	cube->cubeface[1][1];
			aux3 =	cube->cubeface[1][2];
			aux4 =	cube->cubeface[1][5];
			aux5 =	cube->cubeface[1][8]; 
			aux6 =	cube->cubeface[1][7];
		 	aux7 =	cube->cubeface[1][6];
		 	aux8 =	cube->cubeface[1][3];
		 	//mudando orientacao da face da frente
		 	cube->cubeface[1][0] = aux7;
			cube->cubeface[1][1] = aux8;
			cube->cubeface[1][2] = aux1;
			cube->cubeface[1][5] = aux2;
			cube->cubeface[1][8] = aux3; 
			cube->cubeface[1][7] = aux4;
		 	cube->cubeface[1][6] = aux5;
		 	cube->cubeface[1][3] = aux6;		
			break;
		case 6: //		90º Direita 	|	Right
			aux1 = cube->cubeface[0][2];
			aux2 = cube->cubeface[0][5];
			aux3 = cube->cubeface[0][8];
			cube->cubeface[0][2] = cube->cubeface[5][8];
			cube->cubeface[0][5] = cube->cubeface[5][7];
			cube->cubeface[0][8] = cube->cubeface[5][6];
			cube->cubeface[5][8] = cube->cubeface[3][6];
			cube->cubeface[5][7] = cube->cubeface[3][3];
			cube->cubeface[5][6] = cube->cubeface[3][0];
			cube->cubeface[3][6] = cube->cubeface[4][8];
			cube->cubeface[3][3] = cube->cubeface[4][7];
			cube->cubeface[3][0] = cube->cubeface[4][6];
			cube->cubeface[4][8] = aux1; 
			cube->cubeface[4][7] = aux2;
			cube->cubeface[4][6] = aux3;

			// salvando face temporariamente
			aux1 =  cube->cubeface[2][0];
			aux2 =	cube->cubeface[2][1];
			aux3 =	cube->cubeface[2][2];
			aux4 =	cube->cubeface[2][5];
			aux5 =	cube->cubeface[2][8]; 
			aux6 =	cube->cubeface[2][7];
		 	aux7 =	cube->cubeface[2][6];
		 	aux8 =	cube->cubeface[2][3];
		 	//mudando orientacao da face da frente
		 	cube->cubeface[2][0] = aux7;
			cube->cubeface[2][1] = aux8;
			cube->cubeface[2][2] = aux1;
			cube->cubeface[2][5] = aux2;
			cube->cubeface[2][8] = aux3; 
			cube->cubeface[2][7] = aux4;
		 	cube->cubeface[2][6] = aux5;
		 	cube->cubeface[2][3] = aux6;	
		
			break;
		case 7: // AH  	90º Frente
			aux1 = cube->cubeface[5][2];
			aux2 = cube->cubeface[5][5];
			aux3 = cube->cubeface[5][8];
			cube->cubeface[5][2] = cube->cubeface[1][2];
			cube->cubeface[5][5] = cube->cubeface[1][5];
			cube->cubeface[5][8] = cube->cubeface[1][8];
			cube->cubeface[1][2] = cube->cubeface[4][6];
			cube->cubeface[1][5] = cube->cubeface[4][3];
			cube->cubeface[1][8] = cube->cubeface[4][0];
			cube->cubeface[4][6] = cube->cubeface[2][6];
			cube->cubeface[4][3] = cube->cubeface[2][3];
			cube->cubeface[4][0] = cube->cubeface[2][0];
			cube->cubeface[2][0] = aux3;
			cube->cubeface[2][3] = aux2;
			cube->cubeface[2][6] = aux1;

			//salvando face temporariamente
			aux1 =  cube->cubeface[0][0];
			aux2 =	cube->cubeface[0][1];
			aux3 =	cube->cubeface[0][2];
			aux4 =	cube->cubeface[0][5];
			aux5 =	cube->cubeface[0][8];
			aux6 =	cube->cubeface[0][7];
		 	aux7 =	cube->cubeface[0][6];
		 	aux8 =	cube->cubeface[0][3];
			//rotacionando
			cube->cubeface[0][0] = aux3;
			cube->cubeface[0][1] = aux4;
			cube->cubeface[0][2] = aux5;
			cube->cubeface[0][5] = aux6;
			cube->cubeface[0][8] = aux7;
			cube->cubeface[0][7] = aux8;
			cube->cubeface[0][6] = aux1;
			cube->cubeface[0][3] = aux2;
			break;
		case 8: // AH   90º Fundo
			aux1 = cube->cubeface[2][2];
			aux2 = cube->cubeface[2][5];
			aux3 = cube->cubeface[2][8];
			cube->cubeface[2][2] = cube->cubeface[4][2];
			cube->cubeface[2][5] = cube->cubeface[4][5];
			cube->cubeface[2][8] = cube->cubeface[4][8];
			cube->cubeface[4][2] = cube->cubeface[1][6];
			cube->cubeface[4][5] = cube->cubeface[1][3];
			cube->cubeface[4][8] = cube->cubeface[1][0];
			cube->cubeface[1][6] = cube->cubeface[5][0];
			cube->cubeface[1][3] = cube->cubeface[5][3];
			cube->cubeface[1][0] = cube->cubeface[5][6];
			cube->cubeface[5][0] = aux3;
			cube->cubeface[5][3] = aux2;
			cube->cubeface[5][6] = aux1;
			
			//salvando face temporariamente
			aux1 =  cube->cubeface[3][0];
			aux2 =	cube->cubeface[3][1];
			aux3 =	cube->cubeface[3][2];
			aux4 =	cube->cubeface[3][5];
			aux5 =	cube->cubeface[3][8];
			aux6 =	cube->cubeface[3][7];
		 	aux7 =	cube->cubeface[3][6];
		 	aux8 =	cube->cubeface[3][3];
			//rotacionando
			cube->cubeface[3][0] = aux3;
			cube->cubeface[3][1] = aux4;
			cube->cubeface[3][2] = aux5;
			cube->cubeface[3][5] = aux6;
			cube->cubeface[3][8] = aux7;
			cube->cubeface[3][7] = aux8;
			cube->cubeface[3][6] = aux1;
			cube->cubeface[3][3] = aux2;
			break;
		case 9: // AH   90º Cima		
			aux1 = cube->cubeface[0][0];
			aux2 = cube->cubeface[0][1];
			aux3 = cube->cubeface[0][2];
			cube->cubeface[0][0] = cube->cubeface[1][0];
			cube->cubeface[0][1] = cube->cubeface[1][1];
			cube->cubeface[0][2] = cube->cubeface[1][2];
			cube->cubeface[1][0] = cube->cubeface[3][0];
			cube->cubeface[1][1] = cube->cubeface[3][1];
			cube->cubeface[1][2] = cube->cubeface[3][2];
			cube->cubeface[3][0] = cube->cubeface[2][0];
			cube->cubeface[3][1] = cube->cubeface[2][1];
			cube->cubeface[3][2] = cube->cubeface[2][2];
			cube->cubeface[2][0] = aux1;
			cube->cubeface[2][1] = aux2;
			cube->cubeface[2][2] = aux3;
						
			//salvando face temporariamente
			aux1 =  cube->cubeface[4][0];
			aux2 =	cube->cubeface[4][1];
			aux3 =	cube->cubeface[4][2];
			aux4 =	cube->cubeface[4][5];
			aux5 =	cube->cubeface[4][8];
			aux6 =	cube->cubeface[4][7];
		 	aux7 =	cube->cubeface[4][6];
		 	aux8 =	cube->cubeface[4][3];
			//rotacionando
			cube->cubeface[4][0] = aux3;
			cube->cubeface[4][1] = aux4;
			cube->cubeface[4][2] = aux5;
			cube->cubeface[4][5] = aux6;
			cube->cubeface[4][8] = aux7;
			cube->cubeface[4][7] = aux8;
			cube->cubeface[4][6] = aux1;
			cube->cubeface[4][3] = aux2;
			break;
		case 10: // AH  90º Baixo	
			aux1 = cube->cubeface[3][8];
			aux2 = cube->cubeface[3][7];
			aux3 = cube->cubeface[3][6];
			cube->cubeface[3][8] = cube->cubeface[1][8];
			cube->cubeface[3][7] = cube->cubeface[1][7];
			cube->cubeface[3][6] = cube->cubeface[1][6];
			cube->cubeface[1][8] = cube->cubeface[0][8];
			cube->cubeface[1][7] = cube->cubeface[0][7];
			cube->cubeface[1][6] = cube->cubeface[0][6];
			cube->cubeface[0][8] = cube->cubeface[2][8];
			cube->cubeface[0][7] = cube->cubeface[2][7];
			cube->cubeface[0][6] = cube->cubeface[2][6];
			cube->cubeface[2][8] = aux1;
			cube->cubeface[2][7] = aux2;
			cube->cubeface[2][6] = aux3;
								
			aux1 =  cube->cubeface[5][0];
			aux2 =	cube->cubeface[5][1];
			aux3 =	cube->cubeface[5][2];
			aux4 =	cube->cubeface[5][5];
			aux5 =	cube->cubeface[5][8];
			aux6 =	cube->cubeface[5][7];
		 	aux7 =	cube->cubeface[5][6];
		 	aux8 =	cube->cubeface[5][3];
			//rotacionando
			cube->cubeface[5][0] = aux3;
			cube->cubeface[5][1] = aux4;
			cube->cubeface[5][2] = aux5;
			cube->cubeface[5][5] = aux6;
			cube->cubeface[5][8] = aux7;
			cube->cubeface[5][7] = aux8;
			cube->cubeface[5][6] = aux1;
			cube->cubeface[5][3] = aux2;
			break;
		case 11: // AH 90º Esquerda
			aux1 = cube->cubeface[3][2];
			aux2 = cube->cubeface[3][5];
			aux3 = cube->cubeface[3][8];
			cube->cubeface[3][2] = cube->cubeface[4][0];
			cube->cubeface[3][5] = cube->cubeface[4][1];
			cube->cubeface[3][8] = cube->cubeface[4][2];
			cube->cubeface[4][0] = cube->cubeface[0][6];
			cube->cubeface[4][1] = cube->cubeface[0][3];
			cube->cubeface[4][2] = cube->cubeface[0][0];
			cube->cubeface[0][6] = cube->cubeface[5][0];
			cube->cubeface[0][3] = cube->cubeface[5][1];
			cube->cubeface[0][0] = cube->cubeface[5][2];
			cube->cubeface[5][0] = aux1;
			cube->cubeface[5][1] = aux2;
			cube->cubeface[5][2] = aux3;
						
			//salvando face temporariamente
			aux1 =  cube->cubeface[1][0];
			aux2 =	cube->cubeface[1][1];
			aux3 =	cube->cubeface[1][2];
			aux4 =	cube->cubeface[1][5];
			aux5 =	cube->cubeface[1][8];
			aux6 =	cube->cubeface[1][7];
		 	aux7 =	cube->cubeface[1][6];
		 	aux8 =	cube->cubeface[1][3];
			//rotacionando
			cube->cubeface[1][0] = aux3;
			cube->cubeface[1][1] = aux4;
			cube->cubeface[1][2] = aux5;
			cube->cubeface[1][5] = aux6;
			cube->cubeface[1][8] = aux7;
			cube->cubeface[1][7] = aux8;
			cube->cubeface[1][6] = aux1;
			cube->cubeface[1][3] = aux2;
			break;
		case 12: // AH 90º Direita 	
			aux1 = cube->cubeface[0][2];
			aux2 = cube->cubeface[0][5];
			aux3 = cube->cubeface[0][8];
			cube->cubeface[0][2] = cube->cubeface[4][8];
			cube->cubeface[0][5] = cube->cubeface[4][7];
			cube->cubeface[0][8] = cube->cubeface[4][6];
			cube->cubeface[4][8] = cube->cubeface[3][6];
			cube->cubeface[4][7] = cube->cubeface[3][3];
			cube->cubeface[4][6] = cube->cubeface[3][0];
			cube->cubeface[3][6] = cube->cubeface[5][8];
			cube->cubeface[3][3] = cube->cubeface[5][7];
			cube->cubeface[3][0] = cube->cubeface[5][6];
			cube->cubeface[5][8] = aux1;
			cube->cubeface[5][7] = aux2;
			cube->cubeface[5][6] = aux3;
						
			//salvando face temporariamente
			aux1 =  cube->cubeface[2][0];
			aux2 =	cube->cubeface[2][1];
			aux3 =	cube->cubeface[2][2];
			aux4 =	cube->cubeface[2][5];
			aux5 =	cube->cubeface[2][8];
			aux6 =	cube->cubeface[2][7];
		 	aux7 =	cube->cubeface[2][6];
		 	aux8 =	cube->cubeface[2][3];
			//rotacionando
			cube->cubeface[2][0] = aux3;
			cube->cubeface[2][1] = aux4;
			cube->cubeface[2][2] = aux5;
			cube->cubeface[2][5] = aux6;
			cube->cubeface[2][8] = aux7;
			cube->cubeface[2][7] = aux8;
			cube->cubeface[2][6] = aux1;
			cube->cubeface[2][3] = aux2;
			break;
		case 13: // 	180º Frente
			executeMove(cube, 1);
			executeMove(cube, 1);
			break;
		case 14: // 	180º Fundo
			executeMove(cube, 2);
			executeMove(cube, 2);		
			break;
		case 15: // 	180º Cima
			executeMove(cube, 3);
			executeMove(cube, 3);		
			break;
		case 16: // 	180º Baixo
			executeMove(cube, 4);
			executeMove(cube, 4);		
			break;
		case 17: // 	180º Esquerda
			executeMove(cube, 5);
			executeMove(cube, 5);		
			break;
		case 18: // 	180º Direita
			executeMove(cube, 6);
			executeMove(cube, 6);		
			break;
		default:
			printf("Movimento inválido.\nInvalid move\n");
			break;
	}
}

void resolveCube(Cube *cube, int *moves){
	int i;

	for(i = 0; i < NUM_MOVEMENTS ;i++){
		executeMove(cube, moves[i]);
	}
	return;
}

