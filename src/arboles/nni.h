#ifndef _NNI_H_
#define _NNI_H_

#include "phylip.h"

int search_nni(node *v, int mod_node, int *actual, int neib, int *res);
int result_nni();
int nni_move(int *parsi);

#endif

