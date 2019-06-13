/* This file contains the variable and function declarations */
#include <stdio.h>
# ifndef _GLOBAL_H_
# define _GLOBAL_H_

# define MAXCHECK 1000
# define INF 1.0e14
# define EPS 1.0e-14
# define E  2.71828182845905
# define PI 3.14159265358979
# define GNUPLOT_COMMAND "gnuplot -persist"
# define NUM_FUNCT 15

typedef double (*FNC)(int *a, int *b);


/*Definition of trees*/
typedef struct{
  char name[50];
  char *symbols;
  int *values;
}Taxon;

typedef struct myNode
{ char name[50];
  int *values;
  int copyIndex,
      depth,
      subTreeSize;
  double localParsimony,
         cumulativeParsimony;
  struct myNode * left, * right, * parent;
}Node;

/*End definition of trees*/

typedef struct
{   Node *root;
    Node *nodes;
    int rank;
    double constr_violation;
    double *xreal;
    int **gene;
    double *xbin;
    double *obj;
    double *constr;
    double crowd_dist;
}
individual;

typedef struct
{
    individual *ind;
}
population;

typedef struct lists
{
    int index;
    struct lists *parent;
    struct lists *child;
}
list;
extern FILE *greedFile;
extern int greedIndex;
extern char *GreedPath;
/*Variables for trees*/
extern FNC *Eval;
extern int N;
extern int L;
extern char Name;
extern double calc;
extern double calc1;
extern double estimatedScore;
extern Taxon *taxa;
extern double pcross;
extern double pmut;
extern double pmut_nni;
extern double pmut_tbr;
extern double pmut_spr;
extern double pmut_ls;
extern double pmut_step;
extern double pmut_rnd;
extern double pmut_fi;
extern double pmut_bi;
extern int nmut;
extern int ncross;
extern int n_nni;
extern int n_spr;
extern int n_tbr;
extern int n_ls;
extern int n_step;
extern int **sideA;
extern int **sideB;
extern int *sl;
extern int *fn;
extern int *is;
extern int nsl;
extern int nfn;
extern int nun;
extern int nis;
extern int altobj;
extern int *randarr;
extern char *instName;
////////////////////////////////////
//////////////////////////////////
// #ifdef printcheck_best
extern double highest;
extern double lowest;
// #endif
/*En variables for trees*/
extern int nreal;
extern int nbin;
extern int nobj;
extern int ncon;
extern int popsize;
extern double pcross_real;
extern double pcross_bin;
extern double pmut_real;
extern double pmut_bin;
extern double eta_c;
extern double eta_m;
extern int ngen;
extern int nbinmut;
extern int nrealmut;
extern int nbincross;
extern int nrealcross;
extern int *nbits;
extern double *min_realvar;
extern double *max_realvar;
extern double *min_binvar;
extern double *max_binvar;
extern int bitlength;
extern int choice;
extern int obj1;
extern int obj2;
extern int obj3;
extern int angle1;
extern int angle2;

/*Prototypes for trees*/
int isLeaf(Node *n);
int isRoot(Node *n);
int isRight(Node *n);
void printTree(individual *ind,FILE *stream,char *end);

void treeFromNewick(individual *T, Taxon *Taxa,char *newick);
void clearNode(Node *n);
void newNode(Node *temp,Taxon *T);
void newInnerNode(Node *temp,Node *a, Node *b);
void newRandomTree(individual *ind, Taxon *taxa);
void propagateValues(individual *ind);
void copyTree(individual *from, individual *to);
void DeleteTree(Node *N);
void treecross (individual *parent1, individual *parent2, individual *child1, individual *child2);
void mutateTree(individual *ind);
void evaluateTree(individual *ind);
double evaluateTreeAs(Node *n, int M);

double parsimony(int *a,int *b);
double jaccard(int *a,int *b);
  double brayCurtis(int *a, int *b);      //1 done
  double canberra(int *a, int *b);        //2 done
  double chebyshev(int *a, int *b);       //3 done
  double manhattan(int *a, int *b);       //4 done
  double euclidean(int *a, int *b);       //5 done
  double kulsinski (int *a, int *b);      //7 done
  double wagner (int *a, int *b);         //8 done
  double weighted (int *a, int *b);       //9 done
  double brown (int *a, int *b);          //10 done
  double bitj(int *a, int *b);            //11 done
  double jcdist(int *a, int *b);          //12 done
  double k80(int *a, int *b);             //13 done
  double k80M(int *a, int *b);

  void shuffle();
void write_best(population *pop, int gen, FILE *fpt);
/*end prototypes for trees*/

void allocate_memory_pop (population *pop, int size);
void allocate_memory_ind (individual *ind);
void deallocate_memory_pop (population *pop, int size);
void deallocate_memory_ind (individual *ind);

double maximum (double a, double b);
double minimum (double a, double b);

void crossover (individual *parent1, individual *parent2, individual *child1, individual *child2);
void realcross (individual *parent1, individual *parent2, individual *child1, individual *child2);
void bincross (individual *parent1, individual *parent2, individual *child1, individual *child2);

void assign_crowding_distance_list (population *pop, list *lst, int front_size);
void assign_crowding_distance_indices (population *pop, int c1, int c2);
void assign_crowding_distance (population *pop, int *dist, int **obj_array, int front_size);

void decode_pop (population *pop);
void decode_ind (individual *ind);

void onthefly_display (population *pop, FILE *gp, int ii);

int check_dominance (individual *a, individual *b);

void evaluate_pop (population *pop);
void evaluate_ind (individual *ind);

void fill_nondominated_sort (population *mixed_pop, population *new_pop);
void crowding_fill (population *mixed_pop, population *new_pop, int count, int front_size, list *cur);

void initialize_pop (population *pop);
void initialize_ind (individual *ind);

void insert (list *node, int x);
list* del (list *node);

void merge(population *pop1, population *pop2, population *pop3);
void copy_ind (individual *ind1, individual *ind2);

void mutation_pop (population *pop);
void mutation_ind (individual *ind);
void bin_mutate_ind (individual *ind);
void real_mutate_ind (individual *ind);

void test_problem (double *xreal, double *xbin, int **gene, double *obj, double *constr);

void assign_rank_and_crowding_distance (population *new_pop);

void report_pop (population *pop, FILE *fpt);
void report_feasible (population *pop, FILE *fpt, FILE *fpt2);
void report_best (population *pop, FILE *fpt,FILE *fpt2);
void report_ind (individual *ind, FILE *fpt);

void quicksort_front_obj(population *pop, int objcount, int obj_array[], int obj_array_size);
void q_sort_front_obj(population *pop, int objcount, int obj_array[], int left, int right);
void quicksort_dist(population *pop, int *dist, int front_size);
void q_sort_dist(population *pop, int *dist, int left, int right);

void selection (population *old_pop, population *new_pop);
individual* tournament (individual *ind1, individual *ind2);

# endif
