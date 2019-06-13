/* Data initializtion routines */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "global.h"
# include "rand.h"

/* Function to initialize a population randomly */
void initialize_pop (population *pop)
{
    int i;
    if(greedIndex==-1){
    	for (i=0; i<popsize; i++)
	    {
	        initialize_ind (&(pop->ind[i]));
	    }	
    }
    else{
    	int numTrees;
    	char newicktree[6*N];
    	double estimatedScore;
    	fscanf(greedFile,"%d\n",&numTrees);
    	if(numTrees>popsize){
    		fprintf(stderr, "Number of greedy trees excedes population size\n program will exit\n");
    		exit(-1);
    	}
    	//fprintf(stderr, "starting %d\n",numTrees);
    	for(i=0;i<numTrees;i++){
    		//fprintf(stderr, "line %d\n", i);
    		fscanf(greedFile,"%lf\t%s\n",&estimatedScore,newicktree);
    		//fprintf(stderr, "%lf\t%s\n", estimatedScore,newicktree);
    		treeFromNewick(&(pop->ind[i]),taxa,newicktree);
    		//fprintf(stderr, "%lf\t%lf\n", estimatedScore,pop->ind[i].root->cumulativeParsimony);
    	}
    	for (int i = numTrees; i < popsize; ++i){
    		newRandomTree(&(pop->ind[i]),taxa);
    	}
    }
    fprintf(stderr, "trees initialized\n");
    return;
}

/* Function to initialize an individual randomly */
void initialize_ind (individual *ind)
{
    newRandomTree(ind,taxa);
    return;
}
