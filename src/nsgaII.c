#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "global.h"
#include "rand.h"
#include "sys/time.h"
#include <time.h>
double elapsedTime, timeLimit = -1;
struct timeval start, end;
///////
const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}



/////////
float tock(){
   gettimeofday( &end, (struct timezone *)0 );
   return ((float)(end.tv_sec-start.tv_sec)*1000000 + (float)(end.tv_usec-start.tv_usec)) / 1000000 ;
}

void tick(){
	gettimeofday( &start, (struct timezone *) 0 );
}
//input phylip
void filename(FILE *input)
{
char aux;
	fscanf(input, "%d %d", &N, &L);
	taxa = (Taxon *)malloc(N * sizeof(Taxon));
	for (auto i = 0; i < N; i++) {
	    taxa[i].symbols = (char *)malloc(L * sizeof(char));
	    taxa[i].values = (int *)malloc(L * sizeof(int));
	    fscanf(input, "%s ", taxa[i].name);
	    for (auto j = 0; j < L; j++) {
	    	fscanf(input, "%c", &aux);
	    	taxa[i].symbols[j] = aux;
	      	if (aux == 'A' || aux == 'a') {
	        	taxa[i].values[j] = 1;
	        	continue;
	      	} else if (aux == 'C' || aux == 'c') {
		        taxa[i].values[j] = 2;
		        continue;
	    	} else if (aux == 'G' || aux == 'g') {
	        	taxa[i].values[j] = 4;
	        	continue;
	      	} else if (aux == 'T' || aux == 't') {
	        	taxa[i].values[j] = 8;
	        	continue;
	      	} else if (aux == 'R' || aux == 'r') {
		        taxa[i].values[j] = 5;
	        	continue;
	      	} else if (aux == 'Y' || aux == 'y') {
	        	taxa[i].values[j] = 10;
	        	continue;
	      	} else if (aux == 'W' || aux == 'w') {
	        	taxa[i].values[j] = 9;
	        	continue;
	      	} else if (aux == 'S' || aux == 's') {
		        taxa[i].values[j] = 6;
		        continue;
	    	} else if (aux == 'M' || aux == 'm') {
	        	taxa[i].values[j] = 3;
	        	continue;
	      	} else if (aux == 'K' || aux == 'k') {
		        taxa[i].values[j] = 12;
		        continue;
	    	} else if (aux == 'H' || aux == 'h') {
	        	taxa[i].values[j] = 11;
	        	continue;
	      	} else if (aux == 'B' || aux == 'b') {
		        taxa[i].values[j] = 14;
		        continue;
	      	} else if (aux == 'V' || aux == 'v') {
	        	taxa[i].values[j] = 7;
	        	continue;
	      	} else if (aux == 'D' || aux == 'd') {
	        	taxa[i].values[j] = 13;
	        	continue;
	      	} else if (aux == 'N' || aux == 'n') {
	        	taxa[i].values[j] = 15;
	        	continue;
	      	} else if (aux == '0') {
	        	taxa[i].values[j] = 1;
	        	continue;
	      	} else if (aux == '1') {
	        	taxa[i].values[j] = 2;
	        	continue;
	      	} else if (aux == '2') {
	        	taxa[i].values[j] = 4;
	        	continue;
	      	} else if (aux == '3') {
		        taxa[i].values[j] = 8;
		        continue;
	      	} else if (aux == '-') {
	        	taxa[i].values[j] = 16;
	        	continue;
	      	} else if (aux == '?') {
	        	taxa[i].values[j] = 255;
	        	continue;
	      	} else {
	        	fprintf(stderr, "Unknown symbol: %c \n", aux);
	        	exit(-1);
	      	}
	    }
	}
	fclose(input);
	
}
//
//input fasta
/*
void filename1(FILE *input)
{
char aux;
	fscanf(input, "%d %d" ,&N, &L);
	taxa = (Taxon *)malloc(N * sizeof(Taxon));
	for (auto i = 0; i < N; i++) {
	    taxa[i].symbols = (char *)malloc(L * sizeof(char));
	    taxa[i].values = (int *)malloc(L * sizeof(int));
	    fscanf(input, "%s ", taxa[i].name);
	    for (auto j = 0; j < L; j++) {
	    	fscanf(input, "%c", &aux);
	    	taxa[i].symbols[j] = aux;
	      	if (aux == 'A'|| aux == 'a') {
	        	taxa[i].values[j] = 1;
	        	continue;
	      	} else if (aux == 'C'|| aux == 'c') {
		        taxa[i].values[j] = 2;
		        continue;
	    	} else if (aux == 'G'|| aux == 'g') {
	        	taxa[i].values[j] = 4;
	        	continue;
	      	} else if (aux == 'T'|| aux == 't') {
	        	taxa[i].values[j] = 8;
	        	continue;
	      	}else if (aux == 'U' || aux== 'u') {
	        	taxa[i].values[j] = 8;
	        	continue;
	      	}	else if (aux == 'R'|| aux == 'r') {
		        taxa[i].values[j] = 5;
	        	continue;
	      	} else if (aux == 'Y'|| aux == 'y') {
	        	taxa[i].values[j] = 10;
	        	continue;
	      	} else if (aux == 'W'|| aux == 'w') {
	        	taxa[i].values[j] = 9;
	        	continue;
	      	} else if (aux == 'S'|| aux == 's') {
		        taxa[i].values[j] = 6;
		        continue;
	    		} else if (aux == 'M'|| aux == 'm') {
	        	taxa[i].values[j] = 3;
	        	continue;
	      	} else if (aux == 'K'|| aux == 'k') {
		        taxa[i].values[j] = 12;
		        continue;
	    		} else if (aux == 'H'|| aux == 'h') {
	        	taxa[i].values[j] = 11;
	        	continue;
	      	} else if (aux == 'B'|| aux == 'b') {
		        taxa[i].values[j] = 14;
		        continue;
	      	} else if (aux == 'V'|| aux == 'v') {
	        	taxa[i].values[j] = 7;
	        	continue;
	      	} else if (aux == 'D'|| aux == 'd') {
	        	taxa[i].values[j] = 13;
	        	continue;
	      	} else if (aux == 'N' || aux == 'n') {
	        	taxa[i].values[j] = 15;
	        	continue;
	      	} else if (aux == 'X' || aux=='x' || aux=='>') {
	        	taxa[i].values[j] = 0;
	        	continue;
	      	} else if (aux == '0') {
	        	taxa[i].values[j] = 1;
	        	continue;
	      	} else if (aux == '1') {
	        	taxa[i].values[j] = 2;
	        	continue;
	      	} else if (aux == '2') {
	        	taxa[i].values[j] = 4;
	        	continue;
	      	} else if (aux == '3') {
		        taxa[i].values[j] = 8;
		        continue;
	      	} else if (aux == '-') {
	        	taxa[i].values[j] = 16;
	        	continue;
	      	} else if (aux == '?') {
	        	taxa[i].values[j] = 255;
	        	continue;
	      	}
						 else {
	        	fprintf(stderr, "Unknown symbol: %c \n", aux);
	        	exit(-1);
	      	}
	    }
	}
	fclose(input);
	
}*/
//
char *equisde;
FNC *Eval;
int N;
int L;
char Name;
double calc;
double calc1;
//int testId;
double pcross;
double pmut;
double pmut_nni;
double pmut_tbr;
double pmut_spr;
double pmut_ls;
double pmut_step;
double pmut_rnd;
double pmut_fi;
double pmut_bi;
int altobj;
int *randarr;
char *instName;
/*---*/
Taxon *taxa;
int nreal;
int nbin;
int nobj;
int ncon;
int popsize;
double eta_c;
double eta_m;
int ngen;
int nmut;
int ncross;
int n_nni;
int n_spr;
int n_tbr;
int n_ls;
int n_step;
// #ifdef printcheck_best
double highest;
double lowest;
// #endif

int fileindex=-1,greedIndex=-1,param;
char *GreedPath;
FILE *greedFile;
FILE *reporte,*arboles;
int hayreporte=0;

void deallocate_taxa();

double bestKnown=-1, bestTime=-1;
char reportfile[100],treefile[100],genfile[100],gentree[100],
	 foundfile[100],foundtree[100];

int main(int argc, char **argv) {
	clock_t startclock = clock();
  // Execuatable code
 	int i,j;
 	popsize = 100;
	ngen = 100;
	ncon = 0;
	pcross = .818;
	pmut = .270;
	pmut_nni = 0.255;
	pmut_spr = 0.337;
	pmut_tbr = 0.079;
	pmut_ls = 0.295;
	pmut_step = 0.135;
	pmut_rnd = 0.863;//.877;
	altobj= 1;
	nobj=2;
	FILE *input;
   	population *parent_pop;
  	population *child_pop;
  	population *mixed_pop;
  	srand(time(NULL));
  	seed = (double)rand() / (double)RAND_MAX ;

	if(argc%2==0 || argc<3)
		{
        fprintf(stderr,"Missing parameter or Misplaced flag\n");
        fprintf(stderr,"Usage: %s -Input <path_to_instance>\n Optional Flags:\n"
        "\t-Output <Path to output files> (without extention, .tre and .res files created)\n"
        "\t-SIZEP <size_of_population> (multiples of 4, default: 100)\n"
        "\t-GEN	<number_of_generations, (default: 500)\n"
        "\t-PC <crossover_probability> (default: 0.818)\n"
        "\t-PM <mutation_probability> (default: 0.270)\n"
        "\t-NNI <probability_of_NNI_operator> (default: 0.255)\n"
        "\t-SPR <probability_of_SPR_operator> (default: 0.337)\n"
        "\t-TBR <probability_of_TBR_operator> (default: 0.079)\n"
        "\t-LFS <probability_of_LeafSwap_Operator> (default:0.295)\n"
        "\t-STP <probability_of_STEP_operator> (default: 0.135)\n"
        "\t-LS <probability_of_local_search> (default: 0.137)\n"
        "\t-OBJ <secondary_objective> (default: 1)\n"
        "\t\t 0 Single Objective Parsimony\n"
        "\t\t 1 D_1\n"
        "\t\t 2 D_2\n"
        "\t\t 3 D_3\n"
        ,argv[0]);
        exit(-1);
    }
	fprintf(stdout, "parameter reading\n");
	for(param=1;param<argc;param+=2){
		if  (strcmp(argv[param],"-Input")==0){
            instName = argv[param+1];
            fileindex=param+1;

            if (!(input = fopen(argv[param+1], "r"))) {
		    	printf("Failed to load file %s\nProgram will now exit\n", argv[param+1]);
		    	exit(-1);
		    }
        }
        else if(strcmp(argv[param],"-SIZEP")==0){
            popsize = atoi(argv[param+1]);
            if(popsize%4!=0){
            	printf("Invalid population size\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-GEN")==0){
            ngen = atoi(argv[param+1]);
            if(ngen<1){
            	printf("Invalid generation number\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-PC")==0){
            pcross = atof(argv[param+1]);
            if(pcross<0 || pcross>1){
            	printf("Invalid crossover probability\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-PM")==0){
        	pmut=atof(argv[param+1]);
        	if(pmut<0||pmut>1){
        		printf("Invalid mutation probability\nProgram will now exit\n");
        		exit(-1);
        	}
        }
        else if(strcmp(argv[param],"-NNI")==0){
            pmut_nni = atof(argv[param+1]);
            if(pmut_nni<0 || pmut_nni >1){
            	printf("Invalid NNI probability\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-SPR")==0){
        	pmut_spr = atof(argv[param+1]);
        	if(pmut_spr<0 || pmut_spr >1){
        		printf("Invalid SPR probability\nProgram will now exit\n");
        		exit(-1);
        	}
        }
        else if(strcmp(argv[param],"-TBR")==0){
            pmut_tbr = atof(argv[param+1]);
            if(pmut_tbr<0 || pmut_tbr >1){
            	printf("Invalid TBR probability\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-LFS")==0){
         	pmut_ls = atof(argv[param+1]);
         	if(pmut_ls<0 || pmut_ls>1){
         		printf("Invalid LFS probability\nProgram will now exit\n");
         		exit(-1);
         	}
        }
        else if(strcmp(argv[param],"-STP")==0){
            pmut_step = atof(argv[param+1]);
            if(pmut_step < 0 || pmut_step>1){
            	printf("Invalid STEP probability\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-LS")==0){
            pmut_rnd = atof(argv[param+1]);
            if(pmut_rnd<0 || pmut_rnd>1){
            	printf("Invalid local search probability\nProgram will now exit\n");
            	exit(-1);
            }
        }
        else if(strcmp(argv[param],"-OBJ")==0){
            altobj = atoi(argv[param+1]);
            if(altobj==0) {
						nobj = 1;
						}
            else {
						 nobj = 2;
						}
        }
        else if(strcmp(argv[param],"-Output")==0){
	  		hayreporte=1;
	  		strcpy(reportfile,argv[param+1]);
	  		strcat(reportfile,".res");
	  		strcpy(treefile,argv[param+1]);
	  		strcat(treefile,".tre");
	  		strcpy(genfile,argv[param+1]);
	  		strcat(genfile,".gen");
	  		strcpy(gentree,argv[param+1]);
	  		strcat(gentree,".gtre");
	  		strcpy(foundfile,argv[param+1]);
	  		strcat(foundfile,".fnd");
	  		strcpy(foundtree,argv[param+1]);
	  		strcat(foundtree,".ftre");
        }
       	else if(strcmp(argv[param],"-Greed")==0){
       		GreedPath = argv[param+1];
       		greedIndex = param+1;
				//	create_tree_from_file(GreedPath);
       		if (!(greedFile = fopen(argv[param+1], "r"))) {
		    	printf("Failed to load file %s\nProgram will now exit\n", argv[param+1]);
		    	exit(-1);
		    }
       	}
	}
	fprintf(stderr, "parameters ready\n");
	if(fileindex==-1){
		printf("No input file detected\nProgram will now exit\n");
		exit(-1);
	}
	filename(input);
	sl = (int*)malloc((N) *sizeof(int));
	fn = (int*)malloc((N) *sizeof(int));;
	is = (int*)malloc((2*N-1) *sizeof(int));
	sideA = (int**)malloc((2*N-1) * sizeof(int*));
	sideB = (int**)malloc((2*N-1) * sizeof(int*));
	randarr = (int*)malloc((2*N-1) * sizeof(int));
	for(i=0;i<2*N-1;i++){
	    randarr[i] = i;
	    sideA[i] = (int*)malloc(2*sizeof(int));
	    sideB[i] = (int*)malloc(2*sizeof(int));
	}
	ncross = 0;
	nmut = 0;
	n_nni = 0;
	n_spr = 0;
	n_tbr = 0;
	n_ls = 0;
	n_step = 0;
	parent_pop = (population *)malloc(sizeof(population));
 	child_pop = (population *)malloc(sizeof(population));
 	mixed_pop = (population *)malloc(sizeof(population));
 	allocate_memory_pop(parent_pop, popsize);
 	allocate_memory_pop(child_pop, popsize);
 	allocate_memory_pop(mixed_pop, 2 * popsize);
 	randomize();
 	initialize_pop(parent_pop);
  	//exit(-1);
  	/*fprintf(stderr, "initialized\n");
  	int algo=0;
  	for(algo=0;algo<2*N-1;algo++){
  		int leftie=-1,rightie=-1,daddy=-1;
  		if(parent_pop->ind[1].nodes[algo].right) rightie = parent_pop->ind[1].nodes[algo].right->copyIndex;
  		if(parent_pop->ind[1].nodes[algo].left) leftie = parent_pop->ind[1].nodes[algo].left->copyIndex;
  		if(parent_pop->ind[1].nodes[algo].parent) daddy = parent_pop->ind[1].nodes[algo].parent->copyIndex;
  		fprintf(stderr, "%d %d %d %d\n", parent_pop->ind[1].nodes[algo].copyIndex,leftie,rightie,daddy);
  	}
  	fprintf(stderr, "%d\n",parent_pop->ind[0].root->copyIndex);
  	printTree(&parent_pop->ind[0],stdout,";");
  	exit(-1);
  	*/
  decode_pop(parent_pop);
  //fprintf(stderr, "decoded\n");
 	evaluate_pop(parent_pop);
 	//fprintf(stderr, "evaluated\n");
 	highest = parent_pop->ind[0].obj[1];
  lowest = parent_pop->ind[0].obj[1];
  assign_rank_and_crowding_distance(parent_pop);
 	elapsedTime = 0;
 	tick();
 	//for( i = 2;i<=ngen; i++){
 	i=2;
 	FILE *GenRep,*GenTre,*Rep,*Tre, *Frep,*Ftree;
 	double start,end,recover=0;
 	double best1 = parent_pop->ind[0].obj[0],best2=parent_pop->ind[0].obj[1];
 	int stagcounter, improved=0;
 	int stagnated = 0;
 	for(stagcounter=0;stagcounter<popsize;stagcounter++){
 		if(parent_pop->ind[stagcounter].obj[0]<best1){
 			best1=parent_pop->ind[stagcounter].obj[0];
 			stagnated = 0;
 			improved=1;
 		}
 		if(nobj==2)
 		if(parent_pop->ind[stagcounter].obj[1]<best2){
 			best2=parent_pop->ind[stagcounter].obj[1];
 			stagnated = 0;
 			improved=1;
 		}
 	}
 	int found=0;
 	int keepGoing=1;
 	while(stagnated<50){
 		//fprintf(stderr, "%d %d\n", i, stagnated);
 		selection(parent_pop,child_pop);
 		// fprintf(stderr, "selected\n");
 		mutation_pop(child_pop);
 		// fprintf(stderr, "mutated\n");
 		evaluate_pop(child_pop);
 		// fprintf(stderr, "evaluated\n");
 		merge(parent_pop,child_pop,mixed_pop);
 		// fprintf(stderr, "merged\n");
 		fill_nondominated_sort(mixed_pop,parent_pop);
 		// fprintf(stderr, "filled\n");
 		//elapsedTime = tock();
 		i++;
 		improved = 0;
 		for(stagcounter=0;stagcounter<popsize;stagcounter++){
	 		if(parent_pop->ind[stagcounter].obj[0]<best1){
	 			best1=parent_pop->ind[stagcounter].obj[0];
	 			stagnated = 0;
	 			improved=1;
	 		}
	 		if(nobj==2)
	 		if(parent_pop->ind[stagcounter].obj[1]<best2){
	 			best2=parent_pop->ind[stagcounter].obj[1];
	 			stagnated = 0;
	 			improved=1;
	 		}
 		}
 		if(improved==0)stagnated++;
 		/*if(elapsedTime-recover>=bestTime && timeLimit==1) break;
 		if(i==ngen){
 			if(timeLimit==-1) break;
 			else{
 				start = tock();
 				GenRep = fopen(genfile,"w");
 				GenTre = fopen(gentree,"w");
 				fprintf(GenRep, "%lf\n", elapsedTime-recover);
 				report_best(parent_pop,GenRep,GenTre);
 				report_feasible(parent_pop,GenRep,GenTre);
 				fclose(GenRep);
 				fclose(GenTre);
 				end = tock();
 				recover = end-start; //recover time lost reporting this?
 			//First report	
 			}
 		}
 		if(found == 0 && i>ngen)
 		for(j=0;j<popsize;j++){
 			if(parent_pop->ind[j].obj[0] <= bestKnown){
 				Frep = fopen(foundfile,"a");
 				fprintf(Frep, "%d\t%lf\t%lf\t%lf\t",i,elapsedTime-recover,parent_pop->ind[j].obj[0],parent_pop->ind[j].obj[1]);
 				fflush(Frep);
 				fclose(Frep);
 				Ftree = fopen(foundtree,"a");
				printTree(&(parent_pop->ind[j]),Ftree,"\n");
				fflush(Ftree);
				fclose(Ftree);
				found =1;
 			}
 		}
 		if(found==1) {break;}
 		*/
 	}
 	elapsedTime = tock();
 	if(hayreporte==1){
 		Rep = fopen(reportfile,"w");
 		Tre = fopen(treefile,"w");
 	}
 	else{
 		Rep = stdout;
 		Tre = stderr;
 	}
 	fprintf(Rep, "%lf\n", elapsedTime-recover);
 	report_best(parent_pop,Rep,Tre);
 	report_feasible(parent_pop,Rep,Tre);
 	if(hayreporte==1){
 		fclose(Rep);
 		fclose(Tre);
 	}
	//report_best(parent_pop, stdout);
 	deallocate_taxa();
 	deallocate_memory_pop(parent_pop,popsize);
 	deallocate_memory_pop(child_pop,popsize);
 	deallocate_memory_pop(mixed_pop,2 * popsize);
 	free(parent_pop);
 	free(child_pop);
 	free(mixed_pop);
 	free(sl);
 	free(fn);
 	free(is);
 	free(randarr);
	clock_t stopclock = clock();
  double elapsed = (double)(stopclock - startclock)  / CLOCKS_PER_SEC;
	fprintf(stderr,"Time elapsed in seconds: %f\n", elapsed);
	fprintf(stderr,"Secondary Objective =: %d\n",altobj);
	//system("/home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/execute.sh");
 	return(0);
}
void deallocate_taxa()
{
  auto i;
  for(i=0;i<N;i++)
  { free(taxa[i].values);
    free(taxa[i].symbols);
  }
  free(taxa);
}
