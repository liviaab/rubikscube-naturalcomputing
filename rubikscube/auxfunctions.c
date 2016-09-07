#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "cube.h"
#include "cubemovements.h"
#include "auxfunctions.h"
#include "genalgorithm.h"
#include <time.h>

void printpopfitness(Individual *population, int length){
	int i;
	printf("Imprimindo a Fitness de todos os individuos\n");
	for (i = 0; i < length; i++){
		printf("%d\n", population[i].Fitness);
	}
	return;
}


void printStatsToFile(Individual *population, FILE *fpout){
	/*
		1 - fitness do melhor e do pior dos individuos
		2 - fitness media da população
		3 - numero de individuos repetidos na população
		?? 4 - numero de individuos gerados por crossover melhores e piores que a fitness media dos pais
	*/
	int i,k;
	int aux1, aux2, aux3, aux4;

	aux1 = population[0].Fitness;
	aux2 = population[0].Fitness;
	aux4 = 0;
	aux3 = 0;
	for(i = 0; i < POPULATION; i++){
		//best fitness
		if(population[i].Fitness < aux1){
			aux1 = population[i].Fitness;

		}
		//worst fitness
		if(population[i].Fitness > aux2){
			aux2 = population[i].Fitness;
		}
		//average 
		aux4 += population[i].Fitness;
	//	printf("%d\n", population[i].Fitness);
	}
	//printf("%d\n",aux1 );
	//printf("%d\n", aux4);  
	aux4 = aux4/POPULATION;

	
	fprintf(fpout, "%d\n%d\n%d\n", aux1, aux2, aux4);

	//individuos iguais
	for(i = 0; i < POPULATION - 1 ; i++ ){
		for(k = i + 1; k < POPULATION ; k++ ){
			if( cmpIndv(population[i].Genotype, population[k].Genotype ) ){
				aux3++; 
				//printf("Iguais: %d %d , fitness: %d %d\n",i, k, population[i].Fitness, population[k].Fitness );
				break;
			}
		}
	}
	fprintf(fpout, "%d\n\n",aux3);

	return;
}



void swap(Individual *a, Individual *b){
    Individual temp = *a;
    *a = *b;
    *b = temp; 
}


void printArray(Individual* array, int length){
    int i, k;
    for (i = 0; i < length; i++){
    	printf("%d - Fitness: %d\t|\t", i, array[i].Fitness);
        for(k=0; k< NUM_MOVEMENTS; k++){
        	printf("%d ", array[i].Genotype[k]);
        }
    printf("\n");
    }
    //printf("\n");
    return;
}


void shuffle( Individual* array, int length){
   	srand ( time(NULL) );
 	int i, j;
 	
    for (i = length-1; i > 0; i--){
        j = rand() % (i+1);
        swap(&array[i], &array[j]);
    }
}


void teste(Individual *array, int length){
    shuffle(array, length);
    printArray(array, length); 
    return;
}

