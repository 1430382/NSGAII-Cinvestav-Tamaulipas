#include "debug.h"
#include "global.h"
#include "rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

//int **sideA, **sideB;
//int sizeA, sizeB;
int *sl;
int *fn;
int *is;
int nsl;
int nfn;
int nun;
int nis;

/*
void shuffle(){
  int i,aux,pos;
  for(i=0;i<2*N-1;i++){
    pos = rnd(0,2*N-2);
    aux = randarr[pos];
    randarr[pos] = randarr[i];
    randarr[i]=aux;
  }
}
*/
/*...*/
int isLeaf(Node *n) {
  if (!n)
    return 0;
  if ((!(n->left) && !(n->right)) || n->copyIndex<N)
    return 1;
  return 0;
}

int isRoot(Node *n) {
  if (!n)
    return 0;
  if (!n->parent)
    return 1;
  return 0;
}

int isRight(Node *n) {
  if (!n)
    return 0;
  if (!n->parent)
    return -1;
  if (n->parent->right == n)
    return 1;
  return 0;
}

/*Visualisation functions*/
void printNode(Node *root, int side, FILE *stream) {
  if (!root)
    return;
  if (!root->left && !root->right) {
    //fprintf(stream, "%s%s", root->name, (side == 1) ? "," : "");
    fprintf(stream, "%d%s", root->copyIndex+1, (side == 1) ? "," : "");
  } else {
    fprintf(stream, "(");
    printNode(root->left, 1, stream);
    printNode(root->right, 2, stream);
    fprintf(stream, ")%s", (side == 1) ? "," : "");
  }
}

void printTree(individual *ind, FILE *stream, char *end) {
  if (!ind->root) {
    printf("Invalid root\n");
    return;
  }
  printNode(ind->root, 0, stream);
  fprintf(stream, ";%s", end);
}

/*Construction and destruction functions*/

void newNode(Node *temp, Taxon *T) {
  int z;
  strcpy(temp->name, T->name);
  temp->depth = temp->subTreeSize = 0;
  temp->localParsimony = temp->cumulativeParsimony = 0.0;
  temp->left = temp->right = temp->parent = NULL;
  for (z = 0; z < L; z++) {
    temp->values[z] = T->values[z];
  }
}
/*
void updateNode(Node *n){
  int i;
  n->localParsimony=0;
  for (i = 0; i < L; i++) {
    if ((n->left->values[i] & n->right->values[i]) == 0) {
      n->localParsimony++;
      n->values[i] = n->left->values[i] | n->right->values[i];
    } else {
      n->values[i] = n->left->values[i] & n->right->values[i];
    }
  }
  n->cumulativeParsimony = n->left->cumulativeParsimony +
                           n->right->cumulativeParsimony + n->localParsimony;
  n->subTreeSize = n->left->subTreeSize + n->right->subTreeSize + 2;
}
*/
void newInnerNode(Node *temp, Node *a, Node *b) {
  int z;
  strcpy(temp->name, "");
  temp->depth = temp->subTreeSize = 0;
  temp->localParsimony = 0.0;
  temp->parent = NULL;
  for (z = 0; z < L; z++) {
    if ((a->values[z] & b->values[z]) == 0) {
      temp->localParsimony++;
      temp->values[z] = a->values[z] | b->values[z];
    } else {
      temp->values[z] = a->values[z] & b->values[z];
    }
  }
  temp->left = a;
  temp->right = b;
  a->parent = temp;
  b->parent = temp;
}

void copyTree(individual *from, individual *to) {
  int z;
  #pragma omp parallel for
  for (z = 0; z < 2 * N - 1; z++) {
    strcpy(to->nodes[z].name, from->nodes[z].name);
    memcpy(to->nodes[z].values, from->nodes[z].values, L * sizeof(int));
    to->nodes[z].copyIndex = z;
    to->nodes[z].depth = from->nodes[z].depth;
    to->nodes[z].subTreeSize = from->nodes[z].subTreeSize;
    to->nodes[z].localParsimony = from->nodes[z].localParsimony;
    to->nodes[z].cumulativeParsimony = from->nodes[z].cumulativeParsimony;
    if (isLeaf(&(from->nodes[z])) == 0) {
      to->nodes[z].left = &(to->nodes[from->nodes[z].left->copyIndex]);
      to->nodes[z].right = &(to->nodes[from->nodes[z].right->copyIndex]);
    } else { // I THINK I WAS MISSING THIS KIND OF ASSIGNATION!
      to->nodes[z].left = NULL;
      to->nodes[z].right = NULL;
    }
    if (from->nodes[z].parent) {
      to->nodes[z].parent = &(to->nodes[from->nodes[z].parent->copyIndex]);
    } else {
      to->nodes[z].parent = NULL;
    }
  }
  to->root = &(to->nodes[from->root->copyIndex]);
}

void propagateInNodes(Node *n) {
  int i = 0;
  //fprintf(stderr, "entering %d\n", n->copyIndex);
  // Base values of a node
  n->localParsimony = 0;
  n->cumulativeParsimony = 0;
  n->subTreeSize = 0;
  if (isLeaf(n)){
    //fprintf(stderr, "%d\n", n->copyIndex);
    return;
  }

  //fprintf(stderr, "evaluating %d\n", n->copyIndex);
  propagateInNodes(n->left);
  propagateInNodes(n->right);
  int aux = 0;
  // values under you are ok, so lets collect data
  #pragma omp parallel for reduction(+:aux)
  for (i = 0; i < L; i++) {
    if ((n->left->values[i] & n->right->values[i]) == 0) {
      //n->localParsimony++;
      aux+=1;
      n->values[i] = n->left->values[i] | n->right->values[i];
    } else {
      aux+=0;
      n->values[i] = n->left->values[i] & n->right->values[i];
    }
  }
  n->localParsimony = aux;
  n->cumulativeParsimony = n->left->cumulativeParsimony +
                           n->right->cumulativeParsimony + n->localParsimony;
  n->subTreeSize = n->left->subTreeSize + n->right->subTreeSize + 2;
}

void propagateValues(individual *ind) { propagateInNodes(ind->root); }

double evaluateTreeAs(Node *n, int M) {
  double aux = 0;
  // printf("evaluating %d\n", n->copyIndex);
  if (isLeaf(n))
    return 0.0;
  aux += evaluateTreeAs(n->right, M);
  aux += evaluateTreeAs(n->left, M);
  // aux+= Eval[M](n->left->values,n->right->values);
  if (M == 0) {
    aux += parsimony(n->left->values, n->right->values);
  } else if (M == 1) {
    aux += (-1) * bitj(n->left->values, n->right->values);
  }
  else if(M == 2){
    aux+=brayCurtis(n->left->values, n->right->values);
  }
  else if (M==3) {
    aux+= canberra(n->left->values, n->right->values);
  }
  else if(M==4){
    aux+= (-1)*chebyshev(n->left->values, n->right->values);
  }
  else if(M==5){
    aux+=euclidean(n->left->values, n->right->values);
  }
  else if(M==6){
    aux+=weighted(n->left->values, n->right->values);
  }
  else if (M==7) {
    aux+=brown(n->left->values, n->right->values);
  }
  else if(M==8){
    aux+=jcdist(n->left->values, n->right->values);
  }
  else if(M==9){
    aux+= (-1)*k80(n->left->values, n->right->values);
  }
  else if (M==10){
    aux+= (-1)*k80M(n->left->values, n->right->values);
  }
  return aux;
}

void evaluateTree(individual *ind) {
  ind->obj[0] = evaluateTreeAs(ind->root, 0);
  ind->obj[1] = evaluateTreeAs(ind->root, altobj);
}

void DeleteNode(Node *a) {
  free(a->values);
  // free(a);
}

void DeleteTree(Node *root) {
  if (root) {
    DeleteTree(root->left);
    DeleteTree(root->right);
    DeleteNode(root);
  }
}

/*Building Functions*/
void newRandomTree(individual *ind, Taxon *taxa) {
  int z, n1, n2, cN = N;
  int *existingNodes = (int *)malloc(N * sizeof(int));
  for (z = 0; z < N; z++) {
    newNode(&(ind->nodes[z]), &(taxa[z]));
    existingNodes[z] = z;
  }
  while (cN > 1) {
    n1 = rnd(0, cN - 1);
    do {
      n2 = rnd(0, cN - 1);
    } while (n1 == n2);
    newInnerNode(&(ind->nodes[N + (N - cN)]), &(ind->nodes[existingNodes[n1]]),
                 &(ind->nodes[existingNodes[n2]]));
    existingNodes[MIN(n1, n2)] = N + (N - cN);
    existingNodes[MAX(n1, n2)] = existingNodes[cN - 1];
    cN--;
  }
  ind->root = &(ind->nodes[2 * N - 2]);
  for (z = 0; z < 2 * N - 1; z++)
    ind->nodes[z].copyIndex = z;
  // printf("tree created\n");
  free(existingNodes);
}

/*
Newick Builder for greedy initialization
*/
void treeFromNewick(individual *T, Taxon *Taxa, char *newick){
  char *reader = newick;
  long val;
  int currentNode = N, nextNode = N+1, i,z;
  //fprintf(stderr, "Starting taxa\n");
  for (z = 0; z < N; z++) {
    newNode(&(T->nodes[z]), &(taxa[z]));
  }  
  for(z=0;z<2*N-1;z++) {
    T->nodes[z].copyIndex = z;
    T->nodes[z].parent = T->nodes[z].left = T->nodes[z].right = NULL;
  }

  T->root = &T->nodes[N];
  //fprintf(stderr, "ending taxa, selecting root\n");
  //fprintf(stderr, "%s\n", newick);
  while(*reader){
    //fprintf(stderr, "%c %d %d\n", reader[0],currentNode,nextNode);
    if (reader[0] =='(') {
      reader++;
      if (isdigit(*reader)) {
        val = strtol(reader, &reader, 10);
        //fprintf(stderr, "%ld\n", val);
        //T->nodes[currentNode].left = &T->nodes[val-1];
        T->nodes[currentNode].left = &T->nodes[val];
        //T->nodes[val-1].parent = &T->nodes[currentNode];
        T->nodes[val].parent = &T->nodes[currentNode];
      } else {
        T->nodes[currentNode].left = &T->nodes[nextNode];
        T->nodes[nextNode].parent = &T->nodes[currentNode];
        currentNode = nextNode;
        nextNode++;
      }
    } 
    else if (reader[0] == ',') {
      reader++;
      if(isdigit(*reader)){
        val = strtol(reader,&reader,10);
        //fprintf(stderr, "%ld\n", val);
        //T->nodes[currentNode].right=&T->nodes[val-1];
        T->nodes[currentNode].right=&T->nodes[val];
        //T->nodes[val-1].parent = &T->nodes[currentNode];
        T->nodes[val].parent = &T->nodes[currentNode];
      }
      else{
        T->nodes[currentNode].right=&T->nodes[nextNode];
        T->nodes[nextNode].parent= &T->nodes[currentNode];
        currentNode = nextNode;
        nextNode++;
      }
    } 
    else if(reader[0] == ')'){
      reader++;
      if(!(T->nodes[currentNode].parent))break;
      currentNode = T->nodes[currentNode].parent->copyIndex;
      //fprintf(stderr, "%s\n", );
    }
    else if(reader[0] == ';'){
      break;
    }
    else{
      printf("Unknown symbol %c,\nConstruction terminated.\n",reader[0]);
      exit(-1);
    }
  }
  //fprintf(stderr, "built\n");
  //fprintf(stderr, "rooted\n");
  //printTree(T,stdout,"\n");
  //fprintf(stderr, "%d\n",T->root->copyIndex);
  propagateValues(T);
}

/*Search and selection functions*/
void dfls(Node *n) {
  if (isLeaf(n)) {
    sl[nsl] = n->copyIndex;
  #ifdef printcheck_search
      printf("%d\n", sl[nsl]);
  #endif
    nsl++;
  } else {
    dfls(n->left);
    dfls(n->right);
  }
}

void findLeaves(individual *T, int subtree) {
  memset(sl, 0, sizeof(int) * N);
  nsl = 0;
  dfls(&(T->nodes[subtree]));
  #ifdef printcheck_search
    printf("%d leaves found\n", nsl);
  #endif
}

void clearNode(Node *n) { // just to be sure...
  memset(n->values, 0, L * sizeof(int));
  n->right = n->left = n->parent = NULL;
  n->subTreeSize = 0;
  n->localParsimony = n->cumulativeParsimony = 0.0;
}

void detachLeaf(individual *T, Node *n) {
  #ifdef printcheck_release
    printf("releasing node %d\n", n->copyIndex);
  #endif
  fn[nfn] = n->parent->copyIndex;
  nfn++;
  if (isRoot(n->parent)) { // Change root of tree accordingly
    if (isRight(n)) {      // Right leaf, left subtree = root;
      T->root = T->root->left;
      T->root->parent = NULL;
    } else { // Left leaf, right subtree = root;
      T->root = T->root->right;
      T->root->parent = NULL;
    }
  } else if (isRight(n->parent)) {
    if (isRight(n)) { // left subtree becomes right of n->p->p
      n->parent->parent->right = n->parent->left;
      n->parent->left->parent = n->parent->parent;
    } else {
      n->parent->parent->right = n->parent->right;
      n->parent->right->parent = n->parent->parent;
    }
  } else {            // parent is left
    if (isRight(n)) { // left subtree becomes left of n->p->p
      n->parent->parent->left = n->parent->left;
      n->parent->left->parent = n->parent->parent;
    } else {
      n->parent->parent->left = n->parent->right;
      n->parent->right->parent = n->parent->parent;
    }
  }
  clearNode(n->parent);
  n->parent = NULL;
}

void releaseLeaves(individual *T) {
  int i;
  memset(fn, 0, N * sizeof(int));
  nfn = 0;
  for (i = 0; i < nsl; i++) {
    detachLeaf(T, &(T->nodes[sl[i]]));
  }
  #ifdef printcheck_release
    for (i = 0; i < nsl; i++)
      printf("%d\t", sl[i]);
    printf("%d leaves detached, %d free nodes\n", nsl, nfn);
  #endif
}

void copySubtree(individual *child, Node *n) {
  Node *self =
      &(child->nodes[fn[nun]]); // self + index in the unused nodes array
  memcpy(self->values, n->values, L * sizeof(int));
  self->localParsimony = n->localParsimony;
  self->cumulativeParsimony = n->cumulativeParsimony;
  self->subTreeSize = n->subTreeSize;

  // Right side
  if (isLeaf(n->right)) {
    self->right = &(child->nodes[n->right->copyIndex]);
    self->right->parent = self;
  } else { // Connect next node and apply the copy process to its subtree...
    nun++;
    self->right = &(child->nodes[fn[nun]]);
    child->nodes[fn[nun]].parent = self;
    copySubtree(child, n->right);
  }
  // Left side
  if (isLeaf(n->left)) {
    self->left = &(child->nodes[n->left->copyIndex]);
    self->left->parent = self;
  } else {
    nun++;
    self->left = &(child->nodes[fn[nun]]);
    child->nodes[fn[nun]].parent = self;
    copySubtree(child, n->left);
  }
  return;
}

void dfis(Node *n) {
  if (!n) {
    return;
  }
  is[nis] = n->copyIndex;
  nis++;
  dfis(n->left);
  dfis(n->right);
}

void listInsertionNodes(Node *n){
  nis = 0;
  memset(is, 0, (2 * N - 1) * sizeof(int));
  dfis(n);
  #ifdef printcheck_search
    int i;
    for (i = 0; i < nis; i++)
      fprintf(stderr, "%d  ", is[i]);
    fprintf(stderr, "\ninsertion sites found %d\n", nis);
  #endif
}

void listInsertionSites(individual *child) {
  nis = 0;
  memset(is, 0, (2 * N - 1) * sizeof(int));
  dfis(child->root);
  #ifdef printcheck_search
    int i;
    for (i = 0; i < nis; i++)
      fprintf(stderr, "%d  ", is[i]);
    fprintf(stderr, "\ninsertion sites found %d\n", nis);
  #endif
}

void insertSubtree(individual *child, individual *parent, int mating_site) {
  int ins;
  nun = 0; // next unused node (in free nodes array)
  copySubtree(child, &(parent->nodes[mating_site]));
  nun++; // Adjust to point at the last node that will be the joining site
  Node *joint = &(child->nodes[fn[nun]]);
  Node *subroot = &(child->nodes[fn[0]]);
  #ifdef printcheck_insert
    printTree(child, stderr, "\n");
    fprintf(stderr, "copied ind \n");
    printNode(&(child->nodes[fn[0]]), 0, stderr);
    fprintf(stderr, "\n");
  #endif
  listInsertionSites(child);
  /*
  ?==================================================
  Potential to aply a local search
  ==================================================?
  */
  ins = rnd(0, nis - 1); // one of the nodes yay
  Node *site = &(child->nodes[is[ins]]);
  if (isRoot(site)) { // insertion at the top
  #ifdef printcheck_conection
      fprintf(stderr, "insertion in root\n");
  #endif
    joint->left = subroot;
    joint->right = site;
    site->parent = joint;
    subroot->parent = joint;
    joint->parent = NULL;
    child->root = joint;
  } else { // its an inner node or a leaf
    if (isRight(site)) {
  #ifdef printcheck_conection
        fprintf(stderr, "insertion in right\n");
  #endif
      site->parent->right = joint;
      joint->parent = site->parent;
      joint->right = site;
      site->parent = joint;
      joint->left = subroot;
      subroot->parent = joint;
    } else {
  #ifdef printcheck_conection
        fprintf(stderr, "insertion in left\n");
  #endif
      site->parent->left = joint;
      joint->parent = site->parent;
      joint->right = site;
      site->parent = joint;
      joint->left = subroot;
      subroot->parent = joint;
    }
  }
}

/*Modification functions*/
void treecross(individual *parent1, individual *parent2, individual *child1,
               individual *child2) {
  double random;
  int mating_site;
  random = randomperc();
  if (random <= pcross) {
    ncross++;
    /*Copy individuals*/
    copyTree(parent1, child1);
    copyTree(parent2, child2);
    /*First child*/
    do {
      do {
        mating_site = rnd(N, 2 * N - 2); //
      } while (
          mating_site ==
          parent1->root
              ->copyIndex); //|| parent1->nodes[mating_site].subTreeSize>=2*N-2
      findLeaves(parent1, mating_site);
    } while (nsl == N - 1); // all but one
  #ifdef printcheck_release
      fprintf(stderr, "pre release\n");
      printTree(child2, stderr, "\n");
  #endif
    releaseLeaves(child2);
  #ifdef printcheck_release
      fprintf(stderr, "post release\n");
      printTree(child2, stderr, "\n");
  #endif
    insertSubtree(child2, parent1, mating_site);
  #ifdef printcheck_insert
      printTree(child2, stderr, "\n");
  #endif
    propagateValues(child2);
    /*Second child*/
    do {
      do {
        mating_site = rnd(N, 2 * N - 2);
      } while (mating_site == parent2->root->copyIndex);
      findLeaves(parent2, mating_site);
    } while (nsl == N - 1);
  #ifdef printcheck_release
      fprintf(stderr, "pre release\n");
      printTree(child1, stderr, "\n");
  #endif
    releaseLeaves(child1);

  #ifdef printcheck_release
      fprintf(stderr, "post release\n");
      printTree(child1, stderr, "\n");
  #endif
    insertSubtree(child1, parent2, mating_site);
  #ifdef printcheck_insert
      printTree(child1, stderr, "\n");
  #endif
    propagateValues(child1);
  } else {
    copyTree(parent1, child1);
    copyTree(parent2, child2);
  }

}
