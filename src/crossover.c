/* Crossover routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "global.h"
# include "rand.h"

/* Function to cross two individuals */
void crossover (individual *parent1, individual *parent2, individual *child1, individual *child2)
{
    treecross(parent1,parent2,child1,child2);
    return;
}