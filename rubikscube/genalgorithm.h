#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cube.h"
#include "cubemovements.h"

typedef struct{
	int Genotype[NUM_MOVEMENTS];
	int Fitness;
} Individual;


int	getOptFitness(void);
int	getWorstFitness(void);
int getFitness(Cube *);
void getFitnessPop(Individual *, Cube *);
void selectElite(Individual *, Individual *);
void crossover(Individual *, Individual *, int*);
void mutation(Individual *,  Individual *, int*);
void initPopulation( Individual *);
void nextGeneration(Individual*, Individual*);
void init(Cube *, FILE *);
