#ifndef _PHYLIP_H_
#define _PHYLIP_H_


typedef struct _node{
	char* name;           /* name of sequence, only for leaves */
	unsigned char* seq;   /* sequence, each position is a set of characters */
	int cost;             /* cost of this branch */
	struct _node *left;   /* left child */
	struct _node *right;  /* right child */
	struct _node *father; /* father */
} node;

typedef unsigned char pardata;


int read_phylip_file(const char* file);
int free_phylip();
int eval_seq_parsimony(const pardata *left, const pardata *right, pardata *seq, int size);
node* create_leaf(int ind);
int create_tree();
int delete_tree(node *v);
int print_tree(FILE* newick, node *v);
int delete_node(node *v);
node* create_node(node *left, node *right);
/*node* create_node2(node *left, node *right);*/
node* copy_sub_tree(const node *v);


extern int n; /* number of sequences */
extern int m; /* length of sequences */
extern char** names; /* instance names */
extern char** nucle; /* sequences */
extern node* best; /* best tree */
extern node* actual;
/*extern node* newmove;*/


#endif

