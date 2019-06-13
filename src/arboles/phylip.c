#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "phylip.h"
#include "genrand.h"


static pardata map_nucleotide(char nuc);


int n;
int m;
node* best;
node* actual;
/*node* newmove;*/
char** names;
char** nucle;

//////
/* print newick tree */
int print_tree(FILE* newick, node *v)
{
	if(v->name){
		char *ptr;
		ptr = v->name;
		while(*ptr && !isspace(*ptr))
			fprintf(newick, "%c", *(ptr++));
			
		return 0;
	}

	fprintf(newick, "%c", '(');
	print_tree(newick, v->left);
	fprintf(newick, "%c", ',');
	print_tree(newick, v->right);
	fprintf(newick, "%c", ')');
	return 0;
}


/* read a file with phylip format */
int read_phylip_file(const char* file)
{
	char header[128];
	int i;
	FILE* arch;
	char* tmp;

	if((arch = fopen(file, "r")) == NULL){
		perror("fopen (read_phylip_file)");
		return -1;
	}

	if(fgets(header, 128, arch) == NULL){
		perror("fgets (read_phylip_file)");
		return -1;
	}

	if(sscanf(header, "%i%i", &n, &m) != 2){
		perror("sscanf (read_phylip_file)");
		return -1;
	}

	if((names = (char**)calloc(n, sizeof(char*))) == NULL){
		perror("calloc (read_phylip_file)");
		return -1;
	}

	if((nucle = (char**)calloc(n, sizeof(char*))) == NULL){
		perror("calloc (read_phylip_file)");
		return -1;
	}

	if((tmp = (char*)calloc(m + 15, sizeof(char))) == NULL){
		perror("calloc (read_phylip_file)");
		return -1;
	}

	for(i = 0 ; i < n ; ++i){
		if((fgets(tmp, m + 15, arch)) == NULL){
			perror("fgets (read_phylip_file)");
			return -1;
		}

		if((names[i] = (char*)calloc(11, sizeof(char))) == NULL){
			perror("calloc (read_phylip_file)");
			return -1;
		}

		if((nucle[i] = (char*)calloc(m + 1, sizeof(char))) == NULL){
			perror("calloc (read_phylip_file)");
			return -1;
		}

		strncpy(names[i], tmp, 10);
		if(isspace(tmp[10]))
			strncpy(nucle[i], &(tmp[11]), m);
		else
			strncpy(nucle[i], &(tmp[10]), m);
	}

	free(tmp);
	fclose(arch);
	return 0;
}

//si lo usa
/* free resources */
int free_phylip()
{
	int i;

	for(i = 0 ; i < n ; ++i){
		free(names[i]);
		free(nucle[i]);
	}

	free(names);
	free(nucle);
	node *v;

	return 0;
}

//33333333333333333333333333333333333333333333
/* evaluates a sequence of parsimony */
int eval_seq_parsimony(const pardata *left, const pardata *right, pardata *seq, int size)
{
	int i, parsi;

	parsi = 0;
	for(i = 0 ; i < size ; ++i){
		seq[i] = left[i] & right[i]; /* intersection */
		if(!seq[i]){
			seq[i] = left[i] | right[i]; /* union */
			++parsi;
		}
	}
	//fprintf(stderr,"parsimony %d ",parsi);
	return parsi;
}

//si lo usa
/* maps nucleotides to binary numbers */
pardata map_nucleotide(char nuc)
{
	switch(nuc){
		case '0': return 1;
		case '1': return 2;
		case '2': return 4;
		case '3': return 8;
		case 'A': return 1;
		case 'a': return 1;
		case 'T': return 8;
		case 't': return 8;
		case 'C': return 2;
		case 'c': return 2;
		case 'G': return 4;
		case 'g': return 4;
		case '-': return 16;
		case 'R': return 5;
		case 'r': return 5;
		case 'Y': return 10;
		case 'y': return 10;
		case 'W': return 9;
		case 'w': return 9;
		case 'S': return 6;
		case 's': return 6;
		case 'M': return 3;
		case 'm': return 3;
		case 'K': return 12;
		case 'k': return 12;
		case 'H': return 11;
		case 'h': return 11;
		case 'B': return 14;
		case 'b': return 14;
		case 'V': return 7;
		case 'v': return 7;
		case 'D': return 13;
		case 'd': return 13;
		case 'N': return 15;
		case 'n': return 5;
		case '?': return 255;
		default : return 255;
	}
}


/* creates a leaf with ind sequence */
node* create_leaf(int ind)
{
	int i;
	node *leaf;

	if((leaf = (node*)calloc(1, sizeof(node))) == NULL){
		perror("calloc (create_leaf)");
		return NULL;
	}

	if((leaf->name = strdup(names[ind])) == NULL){
		perror("strdup (create_leaf)");
		return NULL;
	}

	if((leaf->seq = (unsigned char*)malloc(m * sizeof(unsigned char))) == NULL){
		perror("malloc (create_leaf)");
		return NULL;
	}

	for(i = 0 ; i < m ; ++i)
		leaf->seq[i] = map_nucleotide(nucle[ind][i]);
		
	
	return leaf;
}


/* creates an internal node */
node* create_node(node *left, node *right)
{
	node *inter;

	if(left == NULL || right == NULL){
		fprintf(stderr, "invalid pointer (create_node)\n");
		return NULL;
	}

	if((inter = (node*)malloc(sizeof(node))) == NULL){
		perror("malloc (create_node)");
		return NULL;
	}

	if((inter->seq = (unsigned char*)malloc(m * sizeof(unsigned char))) == NULL){
		perror("malloc (create_node)");
		return NULL;
	}

	inter->left = left;
	inter->right = right;
	inter->left->father = inter;
	inter->right->father = inter;
	inter->name = NULL;

	inter->cost = inter->left->cost + inter->right->cost; /* accumulated cost */
	inter->cost += eval_seq_parsimony(inter->left->seq, inter->right->seq, inter->seq, m);

	return inter;
}

//no se usa
/* creates initial tree randomly */
int create_tree()
{
	int i;
	unsigned int rnum;
	node *left, *right;
	int *rp;

	if((rp = (int*)malloc(n * sizeof(int))) == NULL){
		perror("malloc (create_tree)");
		return -1;
	}

	for(i = 0 ; i < n ; ++i)
		rp[i] = i;

	if(get_rand_number(&rnum) == -1)
		return -1;

	rnum %= n;

	if((left = create_leaf(rp[rnum])) == NULL)
		return -1;

	rp[rnum] = rp[n-1];

	for(i = 0 ; i < n - 1 ; ++i){
		if(get_rand_number(&rnum) == -1)
			return -1;

		rnum %= n - i - 1;

		if((right = create_leaf(rp[rnum])) == NULL)
			return -1;

		rp[rnum] = rp[n-i-2];

		if((left = create_node(left, right)) == NULL)
			return -1;
	}
	left->father = NULL;

	best = left;
	free(rp);
	return 0;
}


/* free resources */
int delete_tree(node *v)
{
	if(v == NULL){
		fprintf(stderr, "invalid pointer (delete_tree)\n");
		return -1;
	}
	
	free(v->seq);
	if(v->name)
		free(v->name);
	else{
		delete_tree(v->left);
		delete_tree(v->right);
	}
	free(v);

	return 0;
}


/* deletes a node */
int delete_node(node *v)
{
	if(v == NULL){
		fprintf(stderr, "invalid pointer (delete_node)\n");
		return -1;
	}

	free(v->seq);
	free(v);

	return 0;
}


/* creates an internal node */
/*node* create_node2(node *left, node *right)
{
	node *inter;

	if(left == NULL || right == NULL){
		fprintf(stderr, "invalid pointer (create_node2)\n");
		return NULL;
	}

	if((inter = (node*)calloc(1, sizeof(node))) == NULL){
		perror("calloc (create_node2)");
		return NULL;
	}

	if((inter->seq = (unsigned char*)malloc(m * sizeof(unsigned char))) == NULL){
		perror("malloc (create_node)");
		return NULL;
	}

	inter->left = left;
	inter->right = right;

	inter->cost = inter->left->cost + inter->right->cost;
	inter->cost += eval_seq_parsimony(inter->left->seq, inter->right->seq, inter->seq, m);

	return inter;
}*/


/* copy subtree */
node* copy_sub_tree(const node *v)
{
	node *tmp;
	int alen;

	if(!v)
		return NULL;

	tmp = (node*)calloc(1, sizeof(node));
	tmp->cost = v->cost;
	if(v->name)
		tmp->name = strdup(v->name);
	alen = m * sizeof(unsigned char);
	tmp->seq = (unsigned char*)malloc(alen);
	memcpy(tmp->seq, v->seq, alen);

	tmp->left = copy_sub_tree(v->left);
	if(tmp->left)
		tmp->left->father = tmp;

	tmp->right = copy_sub_tree(v->right);
	if(tmp->right)
		tmp->right->father = tmp;
	
	return tmp;

}

