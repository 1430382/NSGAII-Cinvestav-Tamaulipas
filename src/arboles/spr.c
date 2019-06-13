#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spr.h"
#include "genrand.h"

#define LEFT   0
#define RIGHT  1


static int count_int_nodes(node *tree, int *count);
static int regraft(node *v, int neib, int *na, int dir);


static node *backt;
static int back_dir;
static node *back_orig;
static node *back_dest;
static int back_child_side;


/* searches tree neighborhood */
int search_spr(node *v, int mod_node, int *curr, unsigned neib, int *res)
{
	int dir, na;
	if(!(v->name)){ /* for internal nodes */
		(*curr)++;
		if(*curr != mod_node){
			search_spr(v->left, mod_node, curr, neib, res);
			search_spr(v->right, mod_node, curr, neib, res);
		}
		else{
			if(v->father){ /* root is fixed */
				node *tmp;
				int count;
				if(neib % 2)
					dir = LEFT;
				else
					dir = RIGHT;
				back_dir = dir;

				/* prune */
				tmp = v->father;
				back_orig = tmp;
				if(tmp->left == v){
					if(dir == LEFT)
						tmp->left = v->left;
					else
						tmp->left = v->right;
					tmp->left->father = tmp;
					back_child_side = LEFT;
				}
				else{
					if(dir == LEFT)
						tmp->right = v->left;
					else
						tmp->right = v->right;
					tmp->right->father = tmp;
					back_child_side = RIGHT;
				}

				if(dir == LEFT)
					backt = v->right;
				else
					backt = v->left;

				delete_node(v);
				while(tmp){
					tmp->cost = tmp->left->cost + tmp->right->cost; /* accumulated cost */
					tmp->cost += eval_seq_parsimony(tmp->left->seq, tmp->right->seq, tmp->seq, m);
					tmp = tmp->father;
				}

				/* regraft */
				count = 0;
				count_int_nodes(actual, &count);
				neib %= count;
				neib++;
				na = 0;
				regraft(actual, neib, &na, dir);
				count = 0;

				*res = actual->cost;
			}
		}
	}

	return 0;
}


int count_int_nodes(node *tree, int *count)
{
	if(tree->name)
		return 0;

	(*count)++;
	count_int_nodes(tree->left, count);
	count_int_nodes(tree->right, count);

	return 0;
}


int regraft(node *v, int neib, int *na, int dir)
{
	node *a, *b;

	if(!(v->name)){ /* for internal nodes */
		(*na)++;
		if(*na != neib){
			regraft(v->left, neib, na, dir);
			regraft(v->right, neib, na, dir);
		}
		else{
			back_dest = v;
			if(dir == LEFT){
				a = create_node(v->left, backt);
				v->left = a;
			}
			else{
				a = create_node(backt, v->right);
				v->right = a;
			}
			a->father = v;

			b = v;
			while(b){
				b->cost = b->left->cost + b->right->cost; /* accumulated cost */
				b->cost += eval_seq_parsimony(b->left->seq, b->right->seq, b->seq, m);
				b = b->father;
			}
		}
	}

	return 0;
}


/* undo changes in current tree */
int undo_spr()
{
	node *a, *b;

	/* prune */
	if(back_dir == LEFT){
		a = back_dest->left;
		back_dest->left = a->left;
		a->left->father = back_dest;
	}
	else{
		a = back_dest->right;
		back_dest->right = a->right;
		a->right->father = back_dest;
	}
	delete_node(a);

	b = back_dest;
	while(b){
		b->cost = b->left->cost + b->right->cost; /* accumulated cost */
		b->cost += eval_seq_parsimony(b->left->seq, b->right->seq, b->seq, m);
		b = b->father;
	}

	/* regraft */
	if(back_child_side == LEFT){
		if(back_dir == LEFT)
			a = create_node(back_orig->left, backt);
		else
			a = create_node(backt, back_orig->left);
		back_orig->left = a;
	}
	else{
		if(back_dir == LEFT)
			a = create_node(back_orig->right, backt);
		else
			a = create_node(backt, back_orig->right);
		back_orig->right = a;
	}
	a->father = back_orig;

	b = back_orig;
	while(b){
		b->cost = b->left->cost + b->right->cost; /* accumulated cost */
		b->cost += eval_seq_parsimony(b->left->seq, b->right->seq, b->seq, m);
		b = b->father;
	}

	return 0;
}


int spr_move(int *parsi)
{
	unsigned randnum1, randnum2;
	int node_mod;
	int noden = n - 2; /* root is fixed */
/*	int noden = (n - 1) / 2 - 1; *//* root is fixed */

	get_rand_number(&randnum1);
	get_rand_number(&randnum2);

	randnum1 %= noden;
	randnum1 += 2;

	node_mod = 0;
	search_spr(actual, randnum1, &node_mod, randnum2, parsi);
	return 0;
}


