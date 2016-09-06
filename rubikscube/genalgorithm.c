#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "cube.h"
#include "cubemovements.h"
#include "genalgorithm.h"


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

void printpopfitness(Individual *population, int length){
	int i;
	printf("Imprimindo a Fitness de todos os individuos\n");
	for (i = 0; i < length; i++){
		printf("%d\n", population[i].Fitness);
	}
	return;
}

int cmpfunc (const void * a, const void * b){
   return ( (*(Individual*)a).Fitness - (*(Individual*)b).Fitness );
}

void selectElite(Individual *population, Individual *elite){
	//ordenar pela melhor fitness
	qsort(population, POPULATION, sizeof(Individual), cmpfunc);

	int i;
	for (i = 0; i < ELITE; i++){
		elite[i] = population[i];
	}
	return;
}

void crossover(Individual *population){
	

	return;
}

void mutation(Individual *population){

	return;
}

void printStatsToFile(Individual *population, FILE *fpout){
	/*
		1 - fitness do melhor e do pior dos individuos
		2 - fitness media da população
		3 - numero de individuos repetidos na população
		4 - numero de individuos gerados por crossover melhores e piores que a fitness media dos pais
	*/
}

void init(Cube *cube, FILE *fpout){

	Individual population[POPULATION];
	Individual elite[ELITE];

	initPopulation( population );	
	getFitnessPop( population, cube );
	
	int i, k;
	bool stop;
	stop = false;
	for(i = 0; i < NUM_GENERATIONS; i++){
		selectElite(population, elite);
		crossover(population);
		mutation(population);
		getFitnessPop(population, cube);

		//criterio de parada: se tiver algum cubo solucionado
		for(k = 0; k < POPULATION; k++){
			if(population[k].Fitness == getOptFitness()){
				stop = true;
				break;
			}
		}

		printStatsToFile(population, fpout);
		if(stop) break;
	}
	
	return;
}
