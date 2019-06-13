/* Memory allocation and deallocation routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "global.h"
# include "rand.h"

/* Function to allocate memory to a population */
void allocate_memory_pop (population *pop, int size)
{
    int i;
    pop->ind = (individual *)malloc(size*sizeof(individual));
    for (i=0; i<size; i++)
    {
        allocate_memory_ind (&(pop->ind[i]));
    }
    return;
}

/* Function to allocate memory to an individual */
void allocate_memory_ind (individual *ind)
{
    int j;
    if(N!=0){
      ind->nodes = (Node*)malloc((2*N-1)*sizeof(Node));
      for(j=0;j<2*N-1;j++){
        ind->nodes[j].values = (int *)malloc(L*sizeof(int));
      }
    }
    ind->obj = (double *)malloc(nobj*sizeof(double));
    if (ncon != 0)
    {
        ind->constr = (double *)malloc(ncon*sizeof(double));
    }
    return;
}

/* Function to deallocate memory to a population */
void deallocate_memory_pop (population *pop, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        deallocate_memory_ind (&(pop->ind[i]));
    }
    free (pop->ind);
    return;
}

/* Function to deallocate memory to an individual */
void deallocate_memory_ind (individual *ind)
{
    int j;
    if(N!=0){
      for(j=0;j<2*N-1;j++){
        free(ind->nodes[j].values);
      }
        free(ind->nodes);
    }
    free(ind->obj);
    if (ncon != 0)
    {
        free(ind->constr);
    }
    return;
}
