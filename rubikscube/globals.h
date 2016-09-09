#pragma once 

#define NUM_FACES		6
#define NUM_FACELETES	9
#define	SEED			1

#define NUM_TORNEIO		3
#define CROSSOVER_POINT	(NUM_MOVEMENTS*1/2)
#define NUM_MUTATIONS	5

// Modificados:
#define POPULATION	    25000
#define NUM_GENERATIONS	100000
#define NUM_MOVEMENTS	20
#define NUM_ELITE		1	

#define TAXA_MUTACAO	0.85
#define TAXA_CRUZAMENTO	0.15
/*

Padrão1:
Num_mov = 20
Pop = 100
Geracoes = 100
Torneio = 3

Tx_mut = 0.7
Tx_cruz = 0.3

COPoint = 1/2
Num_mut = 1/2*num_mov 
Elite = 1

Padrão2:
Num_mov = 20
Pop = 100
Geracoes = 100
Torneio = 3

Tx_mut = 0.8
Tx_cruz = 0.2

COPoint = 1/2
Num_mut = 5
Elite = 1

Padrao3 (2a Leva):
elite : 1
Torneio = 2
Populacao = 50000
Geracoes = 100000
n movs = 20 (dps 18)

Tx_mut = 0.85
Tx_cruz = 0.15

*/
