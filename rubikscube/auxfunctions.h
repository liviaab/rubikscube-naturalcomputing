#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cube.h"
#include "cubemovements.h"
#include "genalgorithm.h"
#include <time.h>


void printpopfitness(Individual *, int );
void printStatsToFile(Individual *, FILE*);

void swap(Individual*, Individual*);
void printArray(Individual*, int);
void shuffle(Individual*, int);