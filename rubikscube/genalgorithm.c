#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include "cube.h"
#include "cubemovements.h"
#include "genalgorithm.h"
#include "auxfunctions.h"
#include "globals.h"


int	getOptFitness(void){ 
	return 0; 
};

int getWorstFitness(void){
	return ( 6*8 + 6*4*8 + 6*4*16);
}


/*
	Fitness:
	edge  = + 4
	corner = + 6

	v1 + 1 p/ cada facelete que ta com a cor diferente à do centro
	v2 + 8 p/ cada facelete da borda posicionado corretamente
	v6 + 16 p/ cada quina errada

*/
int getFitness(Cube *cube){
	int i, k;
	int sum1, sum2, sum3;
	sum1 = 0; sum2 = 0; sum3 =0;

	// faceletes individualmente
	for ( i = 0; i < NUM_FACES ; i++){
		for(k = 0; k < NUM_FACELETES; k++){
			if(k == 4) continue;
			if(cube->cubeface[i][k] != cube->cubeface[i][4]){
				sum1++;
			}
		}
	}

	//bordas -- se tem 1 ou 2 faces diferentes
	for (i = 0; i < NUM_FACES; i++)	{
		if(cube->cubeface[i][0] != cube->cubeface[i][4] || cube->cubeface[i][1] != cube->cubeface[i][4] || cube->cubeface[i][2] != cube->cubeface[i][4]){
			sum2 += 8;
		}
		if(cube->cubeface[i][2] != cube->cubeface[i][4] || cube->cubeface[i][5] != cube->cubeface[i][4] || cube->cubeface[i][8] != cube->cubeface[i][4]){
			sum2 += 8;
		}
		if(cube->cubeface[i][6] != cube->cubeface[i][4] || cube->cubeface[i][7] != cube->cubeface[i][4] || cube->cubeface[i][8] != cube->cubeface[i][4]){
			sum2 += 8;
		}
		if(cube->cubeface[i][0] != cube->cubeface[i][4] || cube->cubeface[i][3] != cube->cubeface[i][4] || cube->cubeface[i][6] != cube->cubeface[i][4]){
			sum2 += 8;
		}		
	}

	// quinas
	for ( i = 0; i < NUM_FACES; i++){
		if( cube->cubeface[i][0] != cube->cubeface[i][4]){
			sum3 += 16;
		}	
		if( cube->cubeface[i][2] != cube->cubeface[i][4]){
			sum3 += 16;
		}	
		if( cube->cubeface[i][6] != cube->cubeface[i][4]){
			sum3 += 16;
		}	
		if( cube->cubeface[i][8] != cube->cubeface[i][4]){
			sum3 += 16;
		}	
	}

	return sum1 + sum2 + sum3;
}


void initPopulation(Individual *pop){
	//inicializando os fenótipos, iguais à configuração recebida
	int i, k ;
	for(i = 0; i < POPULATION ; i++){
		genMoves(pop[i].Genotype);
	}
	return;
}

void getFitnessPop(Individual *population, Cube *cube){
	int i, k;
	Cube aux;

	for(i = 0; i < POPULATION; i++)	{
		aux = *(cube);
		resolveCube(&aux, population[i].Genotype);
		population[i].Fitness = getFitness(&aux);
	}
	return;
}

int cmpfunc (const void * a, const void * b){
   return ( (*(Individual*)a).Fitness - (*(Individual*)b).Fitness );
}

void selectElite(Individual *population, Individual *children){
	//ordenar pela melhor fitness
	qsort(population, POPULATION, sizeof(Individual), cmpfunc);

	int i;
	for (i = 0; i < NUM_ELITE; i++){
		children[i] = population[i];
	}
	return;
}

void tournament(Individual *contestants, int length, Individual *winner ){
	int i;	
	Individual aux[NUM_TORNEIO];

	for(i = 0 ; i < NUM_TORNEIO ; i++){
		int a = ( rand()%length );
		//printf("a do torneio: %d\n", a);
		aux[i] = contestants[ a ];
	}
	
	qsort(aux, NUM_TORNEIO, sizeof(Individual), cmpfunc);
	*(winner) = aux[0];
	return;
}

void crossover(Individual *population, Individual *children, int *nextIndex){

	int i, j, k;		
	int limit = (int)POPULATION*TAXA_CRUZAMENTO / 2;
	Individual father1, father2;
	
	j = *nextIndex;
	for( i = 0; i < limit ; i++){
		//selecionar os individuos por torneio
		tournament(population, POPULATION, &father1);
		tournament(population, POPULATION, &father2); 

		for(k = 0; k < NUM_MOVEMENTS ; k++){
			if( k < CROSSOVER_POINT){
				children[j].Genotype[k] =  father1.Genotype[k];	
				children[j+1].Genotype[k] =  father2.Genotype[k];	
			}else{
				children[j].Genotype[k] =  father2.Genotype[k];	
				children[j+1].Genotype[k] =  father1.Genotype[k];
			}
		}
		j += 2;
	}
	*nextIndex = j;
	return;
}

void mutation(Individual *population, Individual *children, int *nextIndex){
	int i, j, k, limit;
	Individual aux;

	limit = (int)POPULATION*TAXA_MUTACAO;
	j=*nextIndex;

	for(i = 0; i < limit ; i++){ 
		if( j < POPULATION){
			tournament(population, POPULATION, &aux);

			for(k = 0; k < NUM_MOVEMENTS; k++){
				children[j].Genotype[k]	= aux.Genotype[k];	
			}

			// mutacao
			for(k = 0; k< NUM_MUTATIONS; k++){
				int a = (rand()%NUM_MOVEMENTS);
				int b = rand()% 18  + 1 ;
				//printf("Indice %d  mutado para %d\n", a, b);
				children[j].Genotype[ a ] = b;
			}			
		}
		else{
			for(k = 0; k< NUM_MUTATIONS; k++){
				int a = (rand()%NUM_MOVEMENTS);
				int b = rand()% 18  + 1 ;
				int c = (rand()%POPULATION);
				//printf("Indice %d  mutado para %d\n", a, b);
				if( c == 0 ) c++;
				children[c].Genotype[ a ] = b;
			}	
		}

		j++;
	}
	*nextIndex = i;
	return;
}

// true -> iguais 
bool cmpIndv(int* indv1, int* indv2){
	int i, j;

	for (i = 0; i < NUM_MOVEMENTS; i++){
		if(indv1[i] != indv2[i]){
			return false;
		}
	}
	return true;	
}

void nextGeneration(Individual *population, Individual *children){
	int i;
	for(i = 0; i < POPULATION; i++){
		population[i] = children[i];
	}
	return;
}


void init(Cube *cube, FILE *fpout){

	Individual population[POPULATION];
	Individual children[POPULATION];
	Individual aux;
	
	initPopulation( population );	
	getFitnessPop( population, cube );
	//printf("População inicial:\n");
	//printArray(population, POPULATION);
	
	int i, k, j, nextIndex;
	bool stop;
	stop = false; 
	
	srand ( (unsigned)time(NULL) );
	for(i = 0; i < NUM_GENERATIONS; i++){
		for(k = 0; k < POPULATION; k++ ){
			if(population[k].Fitness == getOptFitness() ){
				printf("Cubo resolvido na %d geracao", (i+1));
			}	
		}		

		selectElite(population, children);	
		//aqui, o vetor population está ordenado com base na fitness	
		nextIndex = NUM_ELITE;
		crossover(population, children, &nextIndex);
		//printf("Elite + Crossover:\n");	
		//printArray(children, nextIndex);
		mutation(population, children, &nextIndex);
		//printf("Elite + Crossover + Mutacao + possiveis adicoes complementares:\n");	
		
		while(nextIndex < POPULATION){
			tournament(population, POPULATION, &aux);
			for(j=0; j<NUM_MOVEMENTS; j++){
				children[nextIndex].Genotype[j] = aux.Genotype[j];
			}
			nextIndex++;
		}

		getFitnessPop(children, cube);
		printStatsToFile(children, population, fpout);
		nextGeneration(population, children);
		//printf("\nGeracao %d\n",i );
		//printArray(children, POPULATION);

		//printf("\n");

	}
	//printf("Last generation:\n");
	//printArray(children, POPULATION);
	
	return;
}
