/* Mutation routines */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "global.h"
# include "rand.h"

/* Function to perform mutation in a population */
void mutation_pop (population *pop)
{
    auto i;
    for (i=0; i<popsize; i++)
    {   mutation_ind(&(pop->ind[i]));
    }
    return;
}

/* Function to perform mutation of an individual */
void mutation_ind (individual *ind)
{
    mutateTree(ind);
    return;
}
