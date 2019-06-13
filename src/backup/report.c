/* Routines for storing population data into files */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
# include "rand.h"

/* Function to print the information of a population in a file */
void report_pop (population *pop, FILE *fpt)
{
    int i, j;
    for (i=0; i<popsize; i++)
    {
        for (j=0; j<nobj; j++)
        {
            fprintf(fpt,"%lf\t",pop->ind[i].obj[j]);
        }
        if (ncon!=0)
        {
            for (j=0; j<ncon; j++)
            {
                fprintf(fpt,"%e\t",pop->ind[i].constr[j]);
            }
        }
        if(N!=0){
          //printTree(&(pop->ind[i]),fpt,"\t");
          //Print the tree if you wanna die waiting...
        }
        fprintf(fpt,"%e\t",pop->ind[i].constr_violation);
        fprintf(fpt,"%d\t",pop->ind[i].rank);
        fprintf(fpt,"%e\n",pop->ind[i].crowd_dist);
    }
    return;
}

/* Function to print the information of feasible and non-dominated population in a file */
void report_feasible (population *pop, FILE *fpt, FILE *fpt2)
{   fprintf(fpt, "#%s Gen: %d Popsize: %d Px: %lf Pm: %lf \n",instName,ngen,popsize, pcross, pmut );
    fprintf(fpt, "Crossovers: %d Mutations: %d\n",ncross,nmut);
    fprintf(fpt, "NNI: %d SPR: %d TBR: %d SWAP: %d STEP %d\n",n_nni,n_spr,n_tbr,n_ls,n_step);
    int i, j;
		//LAST COMMIT
		//HERE
    for (i=0; i<ngen; i++)
    {
        if (pop->ind[i].constr_violation == 0.0 && pop->ind[i].rank==1)
        {
            for (j=0; j<nobj; j++)
            {
                fprintf(fpt,"%lf\t",pop->ind[i].obj[j]);
            }
            if (ncon!=0)
            {
                for (j=0; j<ncon; j++)
                {
                    fprintf(fpt,"%e\t",pop->ind[i].constr[j]);
                }
            }
            //if(N!=0){
            printTree(&(pop->ind[i]),fpt2,"\n\n");
            //}
            fprintf(fpt,"%e\t",pop->ind[i].constr_violation);
            fprintf(fpt,"%d\t",pop->ind[i].rank);
            fprintf(fpt,"%e\n",pop->ind[i].crowd_dist);
        }
    }
    return;
}

void report_best (population *pop, FILE *fpt, FILE *fpt2)
{   //fprintf(fpt, "#%s Gen: %d Popsize: %d Px: %lf Pm: %lf \n",instName,ngen,popsize, pcross, pmut );
    double best=0;
    int i, selected=0;
    best = pop->ind[0].obj[0];
    for (i=0; i<popsize; i++)
    {
        if (pop->ind[i].constr_violation == 0.0 && pop->ind[i].rank==1)
        {	if(pop->ind[i].obj[0]<best){
				best = pop->ind[i].obj[0];		
                selected = i;
			}
        }
    }
		fprintf(fpt,"%lf\n",pop->ind[selected].obj[0]);
    printTree(&(pop->ind[selected]),fpt2,"\n\n\n");
    return;
}

void write_best (population *pop,int gen, FILE *fpt){
  int i, bestIndex = 0;
  double best;
  best = pop->ind[0].obj[0];
  for(i=1;i<popsize;i++){
    if(pop->ind[i].obj[0]<best){
      best = pop->ind[i].obj[0];
      bestIndex=i;
    }
  //  #ifdef printcheck_best
    if(pop->ind[i].obj[1]<lowest) { lowest = pop->ind[i].obj[1];}
    if(pop->ind[i].obj[1]>highest) { highest = pop->ind[i].obj[1];}
  //  #endif
  }
  fprintf(fpt, "%d %lf %lf\n", gen,pop->ind[bestIndex].obj[0],pop->ind[bestIndex].obj[1]);
}
