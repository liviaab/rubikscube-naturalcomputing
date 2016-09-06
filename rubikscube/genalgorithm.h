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
void printpopfitness(Individual *, int );
void selectElite(Individual *, Individual *);
void crossover(Individual *);
void mutation(Individual *);
void initPopulation( Individual *);
void selectElite(Individual *, Individual *);
void init(Cube *, FILE *);
void printStatsToFile(Individual *, FILE*);