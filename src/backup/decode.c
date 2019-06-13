/* Routines to decode the population */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "global.h"
# include "rand.h"

/* Function to decode a population to find out the binary variable values based on its bit pattern */
void decode_pop (population *pop)
{
    int i;
    for(i=0;i<popsize;i++){
        propagateValues(&(pop->ind[i]));
    }
    return;
}