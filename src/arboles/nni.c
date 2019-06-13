#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nni.h"
#include "genrand.h"


static int eval_nni_neighbor(int nt, node *v1, node *v2, node *v3, node *v4, int *res);

static int nt_bak;
static node *v1_bak;
static node *v2_bak;
static node *v3_bak;
static node *v4_bak;

static pardata smemtmp1[1024];
static pardata smemtmp2[1024];


/* searches tree neighborhood */
int search_nni(node *v, int mod_node, int *actual, int neib, int *res)
{
	unsigned char flag;

	flag = 0x00;
	if(v->left->name == NULL || v->right->name == NULL)
		(*actual)++;

	if(v->left->name == NULL)
		flag |= 0x01;

	if(v->right->name == NULL)
		flag |= 0x02;

	if(v->left->name == NULL){
		if(*actual != mod_node)
			search_nni(v->left, mod_node, actual, neib, res);
		else{
			/* two neighbors for this edge */
			if(flag == 0x03){
				if(neib == 1)
					eval_nni_neighbor(1, v, v->right, v->left->right, v->left->left, res);
				if(neib == 2)
					eval_nni_neighbor(2, v, v->right, v->left->left, v->left->right, res);
			}
			else{
				if(neib == 1 || neib == 3)
					eval_nni_neighbor(1, v, v->right, v->left->right, v->left->left, res);
				if(neib == 2 || neib == 4)
					eval_nni_neighbor(2, v, v->right, v->left->left, v->left->right, res);
			}
		}
	}

	if(v->right->name == NULL){
		if(*actual != mod_node)
			search_nni(v->right, mod_node, actual, neib, res);
		else{
			/* two neighbors for this edge */
			if(flag == 0x03){
				if(neib == 3)
					eval_nni_neighbor(3, v, v->left, v->right->left, v->right->right, res);
				if(neib == 4)
					eval_nni_neighbor(4, v, v->left, v->right->right, v->right->left, res);
			}
			else{
				if(neib == 1 || neib == 3)
					eval_nni_neighbor(3, v, v->left, v->right->left, v->right->right, res);
				if(neib == 2 || neib == 4)
					eval_nni_neighbor(4, v, v->left, v->right->right, v->right->left, res);
			}
		}
	}

	return 0;
}


/* evaluates a neighbor */
int eval_nni_neighbor(int nt, node *v1, node *v2, node *v3, node *v4, int *res)
{
	int parsi;
	node *tmp, *tmp2;
	pardata *seqtmp1, *seqtmp2, *seqtmpb;

	nt_bak = nt;
	v1_bak = v1;
	v2_bak = v2;
	v3_bak = v3;
	v4_bak = v4;

	seqtmp1 = smemtmp1;
	seqtmp2 = smemtmp2;

	parsi = v2->cost + v3->cost;
	parsi += eval_seq_parsimony(v2->seq, v3->seq, seqtmp1, m);

	parsi += v4->cost;
	parsi += eval_seq_parsimony(seqtmp1, v4->seq, seqtmp2, m);

	tmp = v1;
	while(tmp->father){
		if(tmp->father->left == tmp)  /* left child */
			tmp2 = tmp->father->right;
		else      /* right child */
			tmp2 = tmp->father->left;

		parsi += tmp2->cost;
		parsi += eval_seq_parsimony(seqtmp2, tmp2->seq, seqtmp1, m);

		seqtmpb = seqtmp1;
		seqtmp1 = seqtmp2;
		seqtmp2 = seqtmpb;
		tmp = tmp->father;
	}

	*res = parsi;
	return 0;
}


/* apply changes*/
int result_nni()
{
	node *tmp;

	switch(nt_bak){
		case 1:
		case 2:
			if(nt_bak == 1)
				v1_bak->left->left = v2_bak;
			else
				v1_bak->left->right = v2_bak;
			v1_bak->right = v4_bak;
			v4_bak->father = v1_bak;
			v2_bak->father = v1_bak->left;
			v1_bak->left->cost = v1_bak->left->left->cost + v1_bak->left->right->cost; /* accumulated cost */
			v1_bak->left->cost += eval_seq_parsimony(v1_bak->left->left->seq, v1_bak->left->right->seq, v1_bak->left->seq, m);
			break;
		case 3:
		case 4:
			if(nt_bak == 3)
				v1_bak->right->right = v2_bak;
			else
				v1_bak->right->left = v2_bak;
			v1_bak->left = v4_bak;
			v4_bak->father = v1_bak;
			v2_bak->father = v1_bak->right;
			v1_bak->right->cost = v1_bak->right->left->cost + v1_bak->right->right->cost; /* accumulated cost */
			v1_bak->right->cost += eval_seq_parsimony(v1_bak->right->left->seq, v1_bak->right->right->seq, v1_bak->right->seq, m);
			break;
		default:
			break;
	}

	tmp = v1_bak;
	while(tmp){
		tmp->cost = tmp->left->cost + tmp->right->cost; /* accumulated cost */
		tmp->cost += eval_seq_parsimony(tmp->left->seq, tmp->right->seq, tmp->seq, m);
		tmp = tmp->father;
	}

	return 0;
}


int nni_move(int *parsi)
{
	unsigned randnum1, randnum2;
	int node_mod;
	int noden = (n - 1) / 2;

	get_rand_number(&randnum1);
	get_rand_number(&randnum2);

	randnum1 %= noden;
	randnum1++;

	randnum2 %= 4;
	randnum2++;

	node_mod = 0;
	search_nni(actual, randnum1, &node_mod, randnum2, parsi);
	return 0;
}

