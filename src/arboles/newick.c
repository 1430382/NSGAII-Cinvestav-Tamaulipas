#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "phylip.h"
#include <string.h>
/////////
#define MAXRAND	 0x0FFFFFFFF
#define MAXEVAL  10000
#define MARKOV   10000
#define ENFR     0.99
#define MAXCONG  15
#define TFIN     1.0E-3
#define TINI     5.0

//////
void separate(FILE* *temp);
static int create_tree_from_file(const char *file);
static node* parse(FILE* fid);


int main(int argc, char* argv[])
{
	int i, cost_ini, acc, marknum;
	FILE *itera, *resul;
	struct timeval tinitial,tfinal;
	char* ptr;
	long ttmp;
	char instname[128];
	int eval, cong, flag, cnni, cspr;
	double tempe;
	unsigned randnum;
	double delta;
	if(argc < 3){
		printf("I need two arguments (phylipfile newickfile).\n");
		return -1;
	}

	read_phylip_file(argv[1]);
	separate(argv[2]);
	//
	create_tree_from_file(argv[3]);
		if((itera = fopen(argv[4], "w")) == NULL){
		perror("fopen (main)");
		exit(EXIT_FAILURE);
	}
	////////	
	printf("\nCost: %i\n", best->cost);
	fprintf(itera, "#mark\tparsi\taccept\ttempe\ttotal\tnni\tspr\n");
	fprintf(itera, "%i\t%i\t%i\t%f\t%i\t%i\t%i\n", marknum, best->cost, acc, tempe, MARKOV, cnni, cspr);
	fflush(itera);
	//delete_tree(best);
	//free_phylip();
	delete_tree(best);
	free_phylip();
	////////////
	puts("arboles:");
//  system("/home/asura/Documents/Estadias/ExperimentalSetup/src/arboles/execute.sh");
	printf("\nCost: %i\n", best->cost);
	//////////////////	
	return 0;
}
void Print(node* head)
{
    node *current = head;
    while (current != NULL)
    {
        fprintf(stderr,"%c", &current->left);
				//printf("%s\n", current->right);
			//	printf("%s\n", current->father);
        current = current->father;
    }
}
/* parse newick file */
node* parse(FILE* fid)
{
	FILE* equis;
	equis = fopen("/home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/instancias/temp/test.txt", "w");
	int i, f, j;
	node *v, *left, *right, *coma, *rp;
	char curr;
	char array[16];
	curr = fgetc(fid);
	fprintf(stderr,"%c",curr);
	v = NULL;
	switch(curr){
		case '(':
			left = parse(fid);
			coma = parse(fid);
			right = parse(fid);
			rp = parse(fid);
			v = create_node(left, right);
			//
			fprintf(equis, "%c", '(');
			print_tree(equis, v->left);
			fprintf(equis, "%c", ',');
			print_tree(equis, v->right);
			fprintf(equis, "%c", ')');
			fclose(equis);
			/////
/*			fprintf(stderr, "%c", '(');
			fprintf(stderr,"%c", v->left);
			fprintf(stderr, "%c", ',');
			fprintf(stderr,"%c", v->right);
			fprintf(stderr, "%c", ')');*/
			break;
		case ',':
		case ')':
			v = NULL;
			break;
		default:
			i = 0;
			f = 0;
			do{//palabrascompletassinespacios
			
				array[i++] = curr;
				curr = fgetc(fid);
			
				if(curr == ',' || curr == ')'){
					f = 1;
					ungetc(curr, fid);
				}
		
			} while(!f);
			
			array[i] = 0;
			for(i = 0 ; i < n ; ++i){
				char tmp[16];
				for(j = 0 ; j < 10 ; j++){
					tmp[j] = names[i][j];
					if(isspace(tmp[j]))
						tmp[j] = 0;				
				}
				tmp[10] = 0;
				if(!strcmp(tmp, array))
					v = create_leaf(i);
			}
	}
	return v;
///	
}
void separate(FILE* *temp)
{
	//FILE *temp;
	char linebuf[2048];
	FILE* input;
	//FILE *input = fopen("/home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/instancias/rbcl55-small.tree", "r");
	input = fopen(temp, "r");
	FILE *output = fopen("/home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/instancias/temp/temp.txt","w");
  int lineno = 0, VV;
	fprintf(stderr,"LINE:\n");
	scanf("%d",&VV);
  char *line;
  while (line = fgets(linebuf, 2048, input))
  {
   ++lineno;
   if (lineno == VV)
    {
     fputs("line ", stdout);
			printf("%s", line);
      fputs( line, output );
      break;
    }
  }
	fclose(output);
  fclose(input);
}
/* creates newick tree */
int create_tree_from_file(const char *file)
{
	FILE* fid;
	char curr;
	fid = fopen(file, "r");	
	do
		curr = fgetc(fid);
	while(curr != '(');
//	fprintf(stderr,"primer parentesis");
	//fprintf(stderr,"\n%c",curr);
	ungetc(curr, fid);
	best = parse(fid);
	fclose(fid);
	return 0;
}
