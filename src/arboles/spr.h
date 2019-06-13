#ifndef _SPR_H_
#define _SPR_H_

#include "phylip.h"

int search_spr(node *v, int mod_node, int *actual, unsigned neib, int *res);
int undo_spr();
int spr_move();

#endif

