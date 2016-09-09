#pragma once 

#define NUM_FACES		6
#define NUM_FACELETES	9
#define	SEED			1

// Podem ser modificados:
#define POPULATION	    13500
#define NUM_GENERATIONS	100
#define NUM_TORNEIO		1

#define TAXA_MUTACAO	0.8
#define TAXA_CRUZAMENTO	0.2

#define NUM_MOVEMENTS	20

#define NUM_ELITE		1	
#define CROSSOVER_POINT	(NUM_MOVEMENTS*1/2)
#define NUM_MUTATIONS	5	
/*

Padrão:
Num_mov = 20
Pop = 100
Geracoes = 100
Torneio = 3

Tx_mut = 0.8
Tx_cruz = 0.2

COPoint = 1/2
Num_mut = 1/2*num_mov 
Elite = 1



*/
