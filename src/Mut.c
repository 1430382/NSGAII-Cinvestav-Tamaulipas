#include "global.h"
#include "rand.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//int N,L;
int **sideA,**sideB,
	sizeA,sizeB;
int *randlist;
//int N,L;


void listA(Node *n, int depth, int maxDepth) {
  if (!n)
    return;
  if (depth <= maxDepth) {
    sideA[sizeA][0] = n->copyIndex;
    sideA[sizeA][1] = depth;
    sizeA++;
    listA(n->left, depth + 1, maxDepth);
    listA(n->right, depth + 1, maxDepth);
  }
}

void listB(Node *n, int depth, int maxDepth) {
  if (!n)
    return;
  if (depth <= maxDepth) {
    sideB[sizeB][0] = n->copyIndex;
    sideB[sizeB][1] = depth;
    sizeB++;
    listB(n->left, depth + 1, maxDepth);
    listB(n->right, depth + 1, maxDepth);
  }
}

void listA1(Node *n){
	if(!n) return;
	sideA[sizeA][0] = n->copyIndex;
	sizeA++;
	listA1(n->left);
	listA1(n->right);
}

void listB1(Node *n){
	if(!n) return;
	sideB[sizeB][0] = n->copyIndex;
	sizeB++;
	listB1(n->left);
	listB1(n->right);
}

void listNodes(Node *node,int maxDepth){
	sizeA=0;sizeB=0;
	//memset(sideA,0,(2*N-1)*sizeof(int));
	//memset(sideB,0,(2*N-1)*sizeof(int));
	listA(node->left, 0, maxDepth);
	listB(node->right, 0, maxDepth);
}

void listInsertionSitesA(Node *n){
	sizeA=0;
	//memset(sideA,0,(2*N-1)*sizeof(int));
	listA1(n);
}

void listInsertionSitesB(Node *n){
	sizeB=0;
	//memset(sideB,0,(2*N-1)*sizeof(int));
	listB1(n);
}

void shuffle(int *randarr, int start,int end){
	auto i,aux,pos;
	for(i=start;i<end;i++){
		pos = rnd(i,end);
		aux = randarr[pos];
		randarr[pos] = randarr[i];
		randarr[i]=aux;
	}
}

double updatingParsimony(int *A, int *B) {
  double x = 0;
  auto i;
  #pragma omp parallel for shared(A,B) private(i) reduction(+:x)
  for (i = 0; i < L; i++){
    if ((A[i] & B[i]) == 0) {
      x += 1;
      A[i]|=B[i];
    } else {
      A[i]&=B[i];
    }
  }
  return x;
}

double updateNode(Node *n){
	double initialPars = n->localParsimony;
	double x = 0;
	auto i;
	Node *left=n->left, *right =n->right;
	#pragma omp parallel for private(i) reduction(+:x)
	for(i=0;i<L;i++){
		if((left->values[i]&right->values[i])==0){
			x+=1;
			n->values[i] = left->values[i]|right->values[i];
		}
		else{
			x+=0;
			n->values[i] = left->values[i]&right->values[i];
		}
	}
	n->localParsimony = x;
	n->cumulativeParsimony = left->cumulativeParsimony + right->cumulativeParsimony + n->localParsimony;
	n->subTreeSize = left->subTreeSize + right->subTreeSize + 2;
	return initialPars-n->localParsimony;
}

//Meassure the improvement of swapping two nodes
//having revious knowledge of their common ancestor
double swapImprovement(individual *ind, Node *root, Node *A, Node *B){
	auto valA[L],valB[L];
	double improvement = 0;
	memcpy(valA,A->values,L*sizeof(int));
	memcpy(valB,B->values,L*sizeof(int));
	while( A->parent != root){
		if(isRight(A)){
			improvement += A->parent->localParsimony - updatingParsimony(valA,A->parent->left->values);
		}
		else{
			improvement += A->parent->localParsimony - updatingParsimony(valA,A->parent->right->values);
		}
		A=A->parent;
	}
	//fprintf(stderr, "in a parent \n");
	while(B->parent != root){
		if(isRight(B)){
			improvement += B->parent->localParsimony - updatingParsimony(valB,B->parent->left->values);
		}
		else{
			improvement += B->parent->localParsimony - updatingParsimony(valB,B->parent->right->values);
		}
		B=B->parent;
	}
	//fprintf(stderr, "in b parent \n");
	improvement += root->localParsimony - updatingParsimony(valA,valB);
	while(root != ind->root){
		if(isRight(root)){
			improvement += root->parent->localParsimony - updatingParsimony(valA,root->parent->left->values);
		}
		else{
			improvement += root->parent->localParsimony - updatingParsimony(valA,root->parent->right->values);
		}
		root = root->parent;
	}
	return improvement;
}

void nni(individual *ind){
	auto mut_site, siteA, siteB;
	Node *A,*B,*pA,*pB;
	do{
		mut_site=rnd(N,2*N-2);
	} while(ind->nodes[mut_site].subTreeSize<4);
	//fprintf(stderr, "%d \n", ind->nodes[mut_site].subTreeSize);
	listNodes(&ind->nodes[mut_site],1);
	//fprintf(stderr, "%d %d\n", sizeA, sizeB);
	do{	
		siteA = rnd(0,sizeA-1);
		siteB = rnd(0,sizeB-1);
	}while(sideA[siteA][1]+sideB[siteB][1]==0 || sideA[siteA][1]+sideB[siteB][1]>1);
	//fprintf(stderr, "don\n");
	//Let the magic happen
	A=&(ind->nodes[sideA[siteA][0]]);
	B=&(ind->nodes[sideB[siteB][0]]);
	pA= A->parent;
	pB= B->parent;
	if(isRight(A)){pA->right = B;} else {pA->left = B;}
	if(isRight(B)){pB->right = A;} else {pB->left = A;}
	A->parent = pB; B->parent = pA;
}


void nni_search(individual *ind){	
	double currImp = 0,bestImp = 0;
	//int mut_site, siteA, siteB;
	auto bestA, bestB;
	auto i,j,k, found = 0,numComp = 0;
	Node *R, *A, *B, *pA, *pB;
	//shuffle(randlist,N,2*N-2);

	for(i = N,numComp = 0; i<2*N-1 && numComp<MAXCHECK;i++){
		R=&(ind->nodes[i]);
		if(R->subTreeSize>=4){
			listNodes(R,1);
			//fprintf(stderr, "%d %d\n", sizeA, sizeB);
			for(j=0;j<sizeA && numComp<MAXCHECK ;j++){
				//fprintf(stderr, "j: %d\n", j);
				for (k = 0; k < sizeB && numComp<MAXCHECK; k++){
					//fprintf(stderr, "k: %d\n", k);
					if(sideA[j][1]+sideB[k][1] == 1){
						currImp = swapImprovement(ind, R,&(ind->nodes[sideA[j][0]]),&(ind->nodes[sideB[k][0]]));
						if ((currImp > bestImp) || (currImp == bestImp && randomperc()<=.5)){
							found = 1;
							bestImp = currImp;
							bestA = sideA[j][0];
							bestB = sideB[k][0];
						}
					}
					numComp++;
					//fprintf(stderr, "%d\n", numComp);
				}
			}
		}
	}

	if(found==1){
		A = &(ind->nodes[bestA]);
		B = &(ind->nodes[bestB]);
		pA = A->parent;
		pB = B->parent;
		if(isRight(A)){pA->right = B;} else {pA->left = B;}
		if(isRight(B)){pB->right = A;} else {pB->left = A;}
		A->parent = pB; B->parent = pA;
	}
}


void spr(individual *ind){
	auto prune_site, insertion_site;
	Node *prune, *freeNode, *selNode, *inNode;
	do{
		prune_site=rnd(N,2*N-2);
	}while(isRoot(&ind->nodes[prune_site]));
	prune = &ind->nodes[prune_site];
	if(isRoot(prune->parent)){
		if(isRight(prune)){
			freeNode = ind->root;
			ind->root = ind->root->left;
			ind->root->parent=NULL;
			prune->parent=NULL;
			clearNode(freeNode);
		}
		else{
			freeNode = ind->root;
			ind->root = ind->root->right;
			ind->root->parent = NULL;
			prune->parent = NULL;
			clearNode(freeNode);
		}
	}
	else{
		freeNode = prune->parent;
		if(isRight(prune)){
			if(isRight(freeNode)){
				freeNode->parent->right = freeNode->left;
				freeNode->left->parent = freeNode->parent;
				prune->parent=NULL;
				clearNode(freeNode);
			}
			else{
				freeNode->parent->left = freeNode->left;
				freeNode->left->parent = freeNode->parent;
				prune->parent=NULL;
				clearNode(freeNode);
			}
		}
		else{ //isLeft(prune)
			if(isRight(freeNode)){
				freeNode->parent->right = freeNode->right;
				freeNode->right->parent = freeNode->parent;
				prune->parent = NULL;
				clearNode(freeNode);
			}
			else{
				freeNode->parent->left = freeNode->right;
				freeNode->right->parent = freeNode->parent;
				prune->parent = NULL;
				clearNode(freeNode);
			}
		}
	}
	
	listInsertionSitesA(ind->root);
	insertion_site = rnd(0,sizeA-1);
	selNode = &(ind->nodes[sideA[insertion_site][0]]);

	if(isRoot(selNode)){
		freeNode->right = selNode;
		selNode->parent	=freeNode;
		freeNode->left = prune;
		prune->parent=freeNode;
		ind->root = freeNode;
	}
	else{
		inNode = selNode->parent;
		if(isRight(selNode)){
			inNode->right = freeNode;
			freeNode->parent = inNode;
			freeNode->right = selNode;
			selNode->parent=freeNode;
			freeNode->left = prune;
			prune->parent = freeNode;
		}
		else{
			inNode->left = freeNode;
			freeNode->parent=inNode;
			freeNode->right = selNode;
			selNode->parent=freeNode;
			freeNode->left = prune;
			prune->parent = freeNode;
		}
	}
}

void spr_search(individual *ind){
	double currImp, bestImp = 0, initialImp;
	auto z, y, found = 0,
		parentIsRoot=0,
		numComp=0,
		val[L];
	Node *currPrune, *currParent, *currSibling, *currInSite, *climber,
		 *bestPrune, *bestInSite;
	for(z=N;z<2*N-1 && numComp<MAXCHECK;z++){
		if(isRoot(&(ind->nodes[z]))) continue;
		else{
			//Must record and detatch node
			//CurrParent = FreeNode
			//CurrSibling = ?? sibling
			currPrune = &(ind->nodes[z]);
			currParent = currPrune->parent;
			if(isRight(currPrune)){
				currSibling = currParent->left;
			}
			else{
				currSibling = currParent->right;
			}
			if(isRoot(currParent)){ //no updates required, only change of root
				parentIsRoot = 1;
				ind->root = currSibling;
				ind->root->parent = NULL;
				initialImp = ind->root->localParsimony;
			}
			else{ //If parent is not root then modifications must take place
				parentIsRoot=0;
				if(isRight(currParent)){
					currParent->parent->right=currSibling;// currParent->left;
					currSibling->parent=currParent->parent;
					currPrune->parent = NULL;
				}
				else{
					currParent->parent->left=currSibling;
					currSibling->parent=currParent->parent;
					currPrune->parent=NULL;	
				}
			}
			initialImp = currParent->localParsimony;
			if(parentIsRoot==0){//Apply changes and evaluate
				climber = currSibling->parent;
				while(climber!=NULL){
					int aux = climber->localParsimony;
					initialImp+= aux - updateNode(climber);
					climber=climber->parent;
				}
			}
			//Now current selection is pruned proceed to evaluate
			listInsertionSitesA(ind->root);
			//fprintf(stderr, "A: %d\n", sizeA);
			for(y=0;y<sizeA && numComp < MAXCHECK ;y++){
				//fprintf(stderr, "NC: %d\n", numComp);
				currInSite = &(ind->nodes[sideA[y][0]]);
				if(currInSite == currSibling) continue;
				else if(currInSite == ind->root){
					memcpy(val,currPrune->values,L*sizeof(int));
					currImp = initialImp + updatingParsimony(val,ind->root->values);					
				}
				else{
					currImp = initialImp;
					climber = currInSite;
					memcpy(val,currPrune->values,L*sizeof(int));
					currImp += updatingParsimony(val,climber->values);
					while(climber != ind->root){
						if(isRight(climber)){
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->left->values);
						}
						else{
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->right->values);
						}
						climber = climber->parent;
					}
				}
				if((currImp>bestImp) || (currImp==bestImp && randomperc()<=.5)){
					found = 1;
					bestImp = currImp;
					bestPrune = currPrune;
					bestInSite = currInSite;
				}
				numComp++;
			}
			//fprintf(stderr, "done with this prune\n");
			//Return to original tree in order to perform a new iteration
			if(parentIsRoot==1){
				currParent->right = currSibling;
				currParent->left = currPrune;
				currPrune->parent = currParent;
				currSibling->parent = currParent;
				currParent->parent = NULL;
				ind->root = currParent;
			}
			else{
				if(isRight(currSibling)){
					currSibling->parent->right = currParent;
					currParent->parent = currSibling->parent;
					currParent->right= currSibling;
					currSibling->parent = currParent;
					currParent->left=currPrune;
					currPrune->parent=currParent;
				}
				else{
					currSibling->parent->left = currParent;
					currParent->parent=currSibling->parent;
					currParent->right=currSibling;
					currSibling->parent=currParent;
					currParent->left=currPrune;
					currPrune->parent=currParent;
				}
			}
			climber=currParent;
			while(climber!=NULL){
				updateNode(climber);
				climber=climber->parent;
			}
			//fprintf(stderr, "connected\n");
		}
	}
	//Max comparissons done
	//All evaluated or limit reached
	if(found==1){
		currParent = bestPrune->parent;
		if(isRight(bestPrune)){
			currSibling = currParent->left;
		}
		else{
			currSibling=currParent->right;
		}

		if(currParent == ind->root){	
			ind->root = currSibling;
			currSibling->parent = NULL;
		}
		else{
			if(isRight(currParent)){
				currParent->parent->right=currSibling;
				currSibling->parent=currParent->parent;
			}
			else{
				currParent->parent->left=currSibling;
				currSibling->parent=currParent->parent;
			}	
		}
		//Parent succesfully detached from tree;
		//and root reassigned if needed
		if(bestInSite == ind->root){
			ind->root = currParent;
			currParent->parent = NULL;
			currParent->right = bestPrune;
			currParent->left = bestInSite;
			bestInSite->parent = currParent;
			bestPrune->parent = currParent;
		}
		else{
			if(isRight(bestInSite)){
				bestInSite->parent->right=currParent;
				currParent->parent=bestInSite->parent;
				currParent->right = bestPrune;
				bestPrune->parent=currParent;
				currParent->left = bestInSite;
				bestInSite->parent=currParent;
			}
			else{
				bestInSite->parent->left=currParent;
				currParent->parent=bestInSite->parent;
				currParent->right=bestPrune;
				bestPrune->parent=currParent;
				currParent->left = bestInSite;
				bestInSite->parent=currParent;
			}	
		}
		//Pruned node inserted next to insertion site
	}
}

void tbr(individual *ind){
	Node *r1, *r2, *freeNode, *inSite;
	auto prune_site,side;
	do{
		prune_site =rnd(N,2*N-2);
	}while(isRoot(&ind->nodes[prune_site]));
	r1 = &ind->nodes[prune_site];
	freeNode = r1->parent;
	if(isRoot(freeNode)){
		if(isRight(r1)){
			r2 = freeNode->left;
			//ind->root = r2;
		}
		else{
			r2 = freeNode->right;
			//ind->root = r2;
		}
		//parentIsRoot=1;
		r1->parent = NULL;
		r2->parent = NULL;
		clearNode(freeNode);
	}
	else{
		if(isRight(r1)){
			if(isRight(freeNode)){
				freeNode->parent->right = freeNode->left;
				freeNode->left->parent = freeNode->parent;
			}
			else{
				freeNode->parent->left = freeNode->left;
				freeNode->left->parent=freeNode->parent;
			}
		}
		else{
			if(isRight(freeNode)){
				freeNode->parent->right = freeNode->right;
				freeNode->right->parent = freeNode->parent;
			}
			else{
				freeNode->parent->left = freeNode->right;
				freeNode->right->parent = freeNode->parent;
			}
		}
		clearNode(freeNode);
		r2 = ind->root;
		r1->parent = NULL;
		r2->parent = NULL;
	}
	if(randomperc()<.5){
		listInsertionSitesA(r1);
		ind->root = r1;
		side = 0;
	}
	else{
		listInsertionSitesA(r2);
		ind->root = r2;
		side = 1;
	}
	inSite = &ind->nodes[sideA[rnd(0,sizeA-1)][0]];
	if(isRoot(inSite)){
		freeNode->left = ind->root;
		ind->root->parent = freeNode;
		ind->root = freeNode;
		if(side == 0){
			freeNode->right = r2;
			r2->parent = freeNode;
		}
		else{
			freeNode->right = r1;
			r1->parent = freeNode;
		}
	}
	else{
		if(isRight(inSite)){
			inSite->parent->right = freeNode;
			freeNode->parent=inSite->parent;
			freeNode->right = inSite;
			inSite->parent = freeNode;
			if(side==0){
				freeNode->left = r2;
				r2->parent = freeNode;
			}
			else{
				freeNode->left = r1;
				r1->parent = freeNode;
			}
		}
		else{
			inSite->parent->left = freeNode;
			freeNode->parent = inSite->parent;
			freeNode->left = inSite;
			inSite->parent=freeNode;
			if(side==0){
				freeNode->right = r2;
				r2->parent = freeNode;
			}
			else{
				freeNode->right = r1;
				r1->parent = freeNode;
			}
		}
	}
}

void tbr_search(individual *ind){
	double currImp, bestImp = 0, initialImp;
	auto z, y , found = 0,
		parentIsRoot, numComp = 0,
		val[L],
		bestSide = -1;
	//Reconstruction values
	Node *currBis, *currSibling, *freeNode, *climber;//*currRoot,
	Node *bestBis, *bestR1,*bestR2,*bestInSite, *currInSite;
	Node *r1,*r2; 
	for(z = N; z<2*N-1 && numComp<MAXCHECK; z++){
		if(isRoot(&ind->nodes[z])) {continue;}
		else{
			currBis = &ind->nodes[z];
			if(isRight(currBis)){
				currSibling = currBis->parent->left;
			}
			else{
				currSibling = currBis->parent->right;
			}
			freeNode = currBis->parent;
			if(isRoot(freeNode)){ 
				//set roots, update nothing
				//currRoot = freeNode;
				r1 = currSibling;
				r2 = currBis;  //Removed root is secondary
				parentIsRoot=1;
			}
			else{
				parentIsRoot=0;
				//Bisect tree, update and save info
				if(isRight(currBis)){
					currSibling = freeNode->left;
					currSibling->parent = freeNode->parent;
					if(isRight(freeNode)){
						freeNode->parent->right = currSibling;
					}
					else{
						freeNode->parent->left = currSibling;
					}
				}
				else{
					currSibling = freeNode->right;
					currSibling->parent =freeNode->parent;
					if(isRight(freeNode)){
						freeNode->parent->right = currSibling;
					}
					else{
						freeNode->parent->left = currSibling;
					}
				}
				//assign roots
				r1 = ind->root;
				r2 = currBis;
				climber = currSibling;
				initialImp = freeNode->localParsimony;
				while(climber != r1 ){
					initialImp += updateNode(climber->parent);
					climber = climber->parent;
				}
			}
			//fprintf(stderr, "detached\n");
			//Node detached , start  listings and comps
			//first side, inserting r2(bisected) into r1 [side 0]
			listInsertionSitesA(r1);
			for(y = 0; y<sizeA && numComp<MAXCHECK;y++){
				currInSite = &(ind->nodes[sideA[y][0]]);
				if(currInSite == currSibling) continue;
				else if(currInSite == r1){
					memcpy(val,r2->values,L*sizeof(int)); //Comparisson tool
					currImp+= initialImp + updatingParsimony(val,r1->values);
				}
				else{
					memcpy(val,r2->values,L*sizeof(int)); //Comparisson tool
					currImp=initialImp;
					climber = currInSite;
					currImp+= updatingParsimony(val,climber->values);
					while(climber!=r1){
						if(isRight(climber)){
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->left->values);
						}
						else{
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->right->values);
						}
						climber=climber->parent;
					}
				}
				if((currImp>bestImp) || (currImp==bestImp && randomperc()<.5)){
					found = 1;
					bestBis = currBis;
					bestImp=currImp;
					bestR1 = r1; //new root
					bestR2 = r2; //Clipping
					bestInSite = currInSite; //insertion site of r1
					bestSide = 0; //Inserting r2
				}
				numComp++;
			}
			//fprintf(stderr, "side 1 done\n");
			listInsertionSitesA(r2);
			for(y=0;y<sizeA && numComp<MAXCHECK;y++){
				currInSite = &ind->nodes[sideA[y][0]];
				//no insertion into sibling for this is the clipped tree
				if(currInSite == r2){
					memcpy(val,r1->values,L*sizeof(int)); //Comparisson tool
					currImp = initialImp + updatingParsimony(val,r1->values);
				}
				else{
					memcpy(val,r1->values,L*sizeof(int));
					currImp = initialImp;
					climber = currInSite;
					currImp+=updatingParsimony(val,climber->values);
					while(climber!=r2){
						if(isRight(climber)){
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->left->values);
						}
						else{
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->right->values);
						}
						climber = climber->parent;
					}
				}
				if((currImp>bestImp) || (currImp==bestImp && randomperc()<.5)){
					found = 1;
					bestImp = currImp;
					bestR1 = r1;
					bestR2 = r2;
					bestBis = currBis;
					bestInSite = currInSite;
					bestSide = 1;
				}
				numComp++;
			}	
			//fprintf(stderr, "side 2 done\n");
			/*RECONNECT*/		
			if(parentIsRoot == 1){
				ind->root = freeNode;
				freeNode->right = currBis;
				freeNode->left = currSibling;
				currBis->parent=freeNode;
				currSibling->parent = freeNode;
			}
			else{ //REconnect and update
				ind->root = r1;
				if(isRight(currSibling)){
					currSibling->parent->right = freeNode;
					freeNode->parent = currSibling->parent;
					freeNode->right = currSibling;
					freeNode->left = currBis;
					currBis->parent = freeNode;
					currSibling->parent = freeNode;
				}
				else{
					currSibling->parent->left=freeNode;
					freeNode->parent = currSibling->parent;
					freeNode->left = currSibling;
					freeNode->right = currBis;
					currBis->parent = freeNode;
					currSibling->parent =freeNode;
				}
				climber = currSibling;
				while(climber!=ind->root){
					updateNode(climber->parent);
					climber = climber->parent;
				}
			}
		} //end this ruond of comparisson
		//fprintf(stderr, "connected\n");
	}
	//fprintf(stderr, "for done %d\n",found);
	if(found == 1){
		//fprintf(stderr, "found %d\n",bestBis->copyIndex);
		//step 1, bisect
		freeNode = bestBis->parent;
		//fprintf(stderr, "ummmm\n");
		r1=bestR1;
		r2=bestR2;

		if(isRoot(freeNode)){
			//fprintf(stderr, "isrut\n");
			r1->parent = NULL;
			r2->parent = NULL;
			clearNode(freeNode);
		}
		else{
			//fprintf(stderr, "isnot\n");
			if(isRight(bestBis)){
				if(isRight(freeNode)){
					freeNode->parent->right =freeNode->left;
					freeNode->left->parent = freeNode->parent;
				}	
				else{
					freeNode->parent->left = freeNode->left;
					freeNode->left->parent = freeNode->parent;
				}
			}
			else{//bestbis = left
				if(isRight(freeNode)){
					freeNode->parent->right = freeNode->right;
					freeNode->right->parent = freeNode->parent;
				}
				else{
					freeNode->parent->left = freeNode->right;
					freeNode->right->parent= freeNode->parent;
				}
			}
			clearNode(freeNode);
		}
		//fprintf(stderr, "disconnected\n");
		if(bestSide == 0){
			
			//fprintf(stderr, "side 0\n");
			if(bestInSite == r1){
				ind->root = freeNode;
				freeNode->right = r1;
				freeNode->left = r2;
				r1->parent = freeNode;
				r2->parent = freeNode;	
			}
			else{
				ind->root = bestR1;
				ind->root->parent = NULL;
				freeNode->parent = bestInSite->parent;
				if(isRight(bestInSite)){
					bestInSite->parent->right = freeNode;
				}
				else{
					bestInSite->parent->left = freeNode;
				}
				freeNode->left = bestInSite;
				freeNode->right = bestR2;
				bestR2->parent=freeNode;
				bestInSite->parent=freeNode;
			}
		}
		else{
			//fprintf(stderr, "side1\n");
			if(bestInSite == r2){
				ind->root = freeNode;
				freeNode->right = r1;
				freeNode->left = r2;
				r1->parent = freeNode;
				r2->parent = freeNode;
			}
			else{
				ind->root = bestR2;
				ind->root->parent = NULL;
				freeNode->parent = bestInSite->parent;
				if(isRight(bestInSite)){bestInSite->parent->right = freeNode;}
				else{bestInSite->parent->left = freeNode;}
				freeNode->left= bestInSite;
				freeNode->right=bestR1;
				bestR1->parent = freeNode;
				bestInSite->parent = freeNode;			
			}
		}
	}
}

void step(individual *ind){
	auto prune_site, insertion_site;
	Node *prune, *freeNode, *inSite, *inNode;
	prune_site = rnd(0,N-1);
	prune = &ind->nodes[prune_site];
	freeNode = prune->parent;
	if(isRoot(freeNode)){
		if(isRight(prune)){
			ind->root = freeNode->left;
			ind->root->parent = NULL;
			clearNode(freeNode);
		}
		else{
			ind->root = freeNode->right;
			ind->root->parent = NULL;
			clearNode(freeNode);
		}
	}
	else{
		if(isRight(prune)){
			if(isRight(freeNode)){
				freeNode->parent->right = freeNode->left;
				freeNode->left->parent=freeNode->parent;
			}
			else{
				freeNode->parent->left = freeNode->left;
				freeNode->left->parent = freeNode->parent;
			}
		}
		else{
			if(isRight(freeNode)){
				freeNode->parent->right = freeNode->right;
				freeNode->right->parent = freeNode->parent;
			}
			else{
				freeNode->parent->left = freeNode->right;
				freeNode->right->parent=freeNode->parent;
			}
		}
		clearNode(freeNode);
	}
	do{
		insertion_site = rnd(0,2*N-2);
	}while(insertion_site == prune_site || insertion_site == freeNode->copyIndex);
	inSite = &ind->nodes[insertion_site];
	if(isRoot(inSite)){
		freeNode->left = inSite;
		freeNode->right = prune;
		prune->parent = freeNode;
		inSite->parent = freeNode;
		ind->root = freeNode;
	}
	else{
		inNode = inSite->parent;
		if(isRight(inSite)){
			inNode->right = freeNode;
			freeNode->parent = inNode;
			freeNode->left = prune;
			prune->parent = freeNode;
			freeNode->right = inSite;
			inSite->parent = freeNode;
		}
		else{
			inNode->left = freeNode;
			freeNode->parent = inNode;
			freeNode->left = prune;
			prune->parent = freeNode;
			freeNode->right = inSite;
			inSite->parent = freeNode;
		}
	}
}

void step_search(individual *ind){
		double currImp, bestImp = 0, initialImp;
	auto z, y, found = 0,
		parentIsRoot=0,
		numComp=0,
		val[L];
	Node *currPrune, *currParent, *currSibling, *currInSite, *climber,
		 *bestPrune, *bestInSite;
	for(z=0;z<N && numComp<MAXCHECK;z++){
		if(isRoot(&(ind->nodes[z]))) continue;
		else{
			//Must record and detatch node
			//CurrParent = FreeNode
			//CurrSibling = ?? sibling
			currPrune = &(ind->nodes[z]);
			currParent = currPrune->parent;
			if(isRight(currPrune)){
				currSibling = currParent->left;
			}
			else{
				currSibling = currParent->right;
			}
			if(isRoot(currParent)){ //no updates required, only change of root
				parentIsRoot = 1;
				ind->root = currSibling;
				ind->root->parent = NULL;
				initialImp = ind->root->localParsimony;
			}
			else{ //If parent is not root then modifications must take place
				parentIsRoot=0;
				if(isRight(currParent)){
					currParent->parent->right=currSibling;// currParent->left;
					currSibling->parent=currParent->parent;
					currPrune->parent = NULL;
				}
				else{
					currParent->parent->left=currSibling;
					currSibling->parent=currParent->parent;
					currPrune->parent=NULL;	
				}
			}
			initialImp = currParent->localParsimony;
			if(parentIsRoot==0){//Apply changes and evaluate
				climber = currSibling->parent;
				while(climber!=NULL){
					auto aux = climber->localParsimony;
					initialImp+= aux - updateNode(climber);
					climber=climber->parent;
				}
			}
			//Now current selection is pruned proceed to evaluate
			listInsertionSitesA(ind->root);
			//fprintf(stderr, "A: %d\n", sizeA);
			for(y=0;y<sizeA && numComp < MAXCHECK ;y++){
				//fprintf(stderr, "NC: %d\n", numComp);
				currInSite = &(ind->nodes[sideA[y][0]]);
				if(currInSite == currSibling) continue;
				else if(currInSite == ind->root){
					memcpy(val,currPrune->values,L*sizeof(int));
					currImp = initialImp + updatingParsimony(val,ind->root->values);					
				}
				else{
					currImp = initialImp;
					climber = currInSite;
					memcpy(val,currPrune->values,L*sizeof(int));
					currImp += updatingParsimony(val,climber->values);
					while(climber != ind->root){
						if(isRight(climber)){
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->left->values);
						}
						else{
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->right->values);
						}
						climber = climber->parent;
					}
				}
				if((currImp>bestImp) || (currImp==bestImp && randomperc()<=.5)){
					found = 1;
					bestImp = currImp;
					bestPrune = currPrune;
					bestInSite = currInSite;
				}
				numComp++;
			}
			//fprintf(stderr, "done with this prune\n");
			//Return to original tree in order to perform a new iteration
			if(parentIsRoot==1){
				currParent->right = currSibling;
				currParent->left = currPrune;
				currPrune->parent = currParent;
				currSibling->parent = currParent;
				currParent->parent = NULL;
				ind->root = currParent;
			}
			else{
				if(isRight(currSibling)){
					currSibling->parent->right = currParent;
					currParent->parent = currSibling->parent;
					currParent->right= currSibling;
					currSibling->parent = currParent;
					currParent->left=currPrune;
					currPrune->parent=currParent;
				}
				else{
					currSibling->parent->left = currParent;
					currParent->parent=currSibling->parent;
					currParent->right=currSibling;
					currSibling->parent=currParent;
					currParent->left=currPrune;
					currPrune->parent=currParent;
				}
			}
			climber=currParent;
			while(climber!=NULL){
				updateNode(climber);
				climber=climber->parent;
			}
			//fprintf(stderr, "connected\n");
		}
	}
	//Max comparissons done
	//All evaluated or limit reached
	if(found==1){
		currParent = bestPrune->parent;
		if(isRight(bestPrune)){
			currSibling = currParent->left;
		}
		else{
			currSibling=currParent->right;
		}

		if(currParent == ind->root){	
			ind->root = currSibling;
			currSibling->parent = NULL;
		}
		else{
			if(isRight(currParent)){
				currParent->parent->right=currSibling;
				currSibling->parent=currParent->parent;
			}
			else{
				currParent->parent->left=currSibling;
				currSibling->parent=currParent->parent;
			}	
		}
		//Parent succesfully detached from tree;
		//and root reassigned if needed
		if(bestInSite == ind->root){
			ind->root = currParent;
			currParent->parent = NULL;
			currParent->right = bestPrune;
			currParent->left = bestInSite;
			bestInSite->parent = currParent;
			bestPrune->parent = currParent;
		}
		else{
			if(isRight(bestInSite)){
				bestInSite->parent->right=currParent;
				currParent->parent=bestInSite->parent;
				currParent->right = bestPrune;
				bestPrune->parent=currParent;
				currParent->left = bestInSite;
				bestInSite->parent=currParent;
			}
			else{
				bestInSite->parent->left=currParent;
				currParent->parent=bestInSite->parent;
				currParent->right=bestPrune;
				bestPrune->parent=currParent;
				currParent->left = bestInSite;
				bestInSite->parent=currParent;
			}	
		}
		//Pruned node inserted next to insertion site
	}
	/*
	double currImp, bestImp = 0, initialImp;
	int z, y, found = 0,
		parentIsRoot,
		numComp=0,
		val[L];
	Node *currPrune, *currParent, *currSibling, *currInSite, *climber,
		 *bestPrune, *bestInSite;
	for(z=0;z<N && numComp<MAXCHECK;z++){
		if(isRoot(&(ind->nodes[z]))) continue;
		else{
			//Must record and detatch node
			//CurrParent = FreeNode
			//CurrSibling = ?? sibling
			currPrune = &(ind->nodes[z]);
			currParent = currPrune->parent;
			if(isRight(currPrune)){
				currSibling = currParent->left;
			}
			else{
				currSibling = currParent->right;
			}
			if(isRoot(currParent)){ //no updates required, only change of root
				parentIsRoot = 1;
				ind->root = currSibling;
				ind->root->parent = NULL;
				initialImp = ind->root->localParsimony;
			}
			else{ //If parent is not root then modifications must take place
				parentIsRoot=0;
				if(isRight(currParent)){
					currParent->parent->right=currSibling;// currParent->left;
					currSibling->parent=currParent->parent;
					currPrune->parent = NULL;
				}
				else{
					currParent->parent->left=currSibling;
					currSibling->parent=currParent->parent;
					currPrune->parent=NULL;	
				}
			}
			initialImp = currParent->localParsimony;
			if(parentIsRoot==0){//Apply changes and evaluate
				climber = currSibling->parent;
				while(climber!=NULL){
					int aux = climber->localParsimony;
					initialImp+= aux - updateNode(climber);
					climber=climber->parent;
				}
			}
			//Now current selection is pruned proceed to evaluate
			listInsertionSitesA(ind->root);
			for(y=0;y<sizeA && numComp < MAXCHECK ;y++){
				currInSite = &(ind->nodes[sideA[y][0]]);
				if(currInSite == currSibling) continue;
				else if(currInSite == ind->root){
					memcpy(val,currPrune->values,L*sizeof(int));
					currImp = initialImp + updatingParsimony(val,ind->root->values);					
				}
				else{
					currImp = initialImp;
					climber = currInSite;
					memcpy(val,currPrune->values,L*sizeof(int));
					currImp += updatingParsimony(val,climber->values);
					while(climber != ind->root){
						if(isRight(climber)){
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->left->values);
						}
						else{
							currImp += climber->parent->localParsimony - updatingParsimony(val,climber->parent->right->values);
						}
						climber = climber->parent;
					}
				}
				if((currImp>bestImp) || (currImp==bestImp && randomperc()<=.5)){
					found = 1;
					bestImp = currImp;
					bestPrune = currPrune;
					bestInSite = currInSite;
				}
				numComp++;
			}
			//Return to original tree in order to perform a new iteration
			if(isRight(currSibling)){
				currSibling->parent->right = currParent;
				currParent->parent = currSibling->parent;
				currParent->right= currSibling;
				currSibling->parent = currParent;
				currParent->left=currPrune;
				currPrune->parent=currParent;
			}
			else{
				currSibling->parent->left = currParent;
				currParent->parent=currSibling->parent;
				currParent->right=currSibling;
				currSibling->parent=currParent;
				currParent->left=currPrune;
				currPrune->parent=currParent;
			}
			climber=currParent;
			while(climber!=NULL){
				updateNode(climber);
				climber=climber->parent;
			}
		}
	}
	//Max comparissons done
	//All evaluated or limit reached
	if(found==1){
		currParent = bestPrune->parent;
		if(isRight(bestPrune)){
			currSibling = currParent->left;
		}
		else{
			currSibling=currParent->right;
		}
		if(isRight(currParent)){
			currParent->parent->right=currSibling;
			currSibling->parent=currParent->parent;
		}
		else{
			currParent->parent->left=currSibling;
			currSibling->parent=currParent->parent;
		}
		//Parent succesfully detached from tree;
		if(isRight(bestInSite)){
			bestInSite->parent->right=currParent;
			currParent->parent=bestInSite->parent;
			currParent->right = bestPrune;
			bestPrune->parent=currParent;
			currParent->left = bestInSite;
			bestInSite->parent=currParent;
		}
		else{
			bestInSite->parent->left=currParent;
			currParent->parent=bestInSite->parent;
			currParent->right=bestPrune;
			bestPrune->parent=currParent;
			currParent->left = bestInSite;
			bestInSite->parent=currParent;
		}
		//Pruned node inserted next to insertion site
	}*/
}

void lswap(individual *ind){
	Node *n1, *n2, *p1, *p2;
	auto r1,r2;
	do{
		r1 = rnd(0,N-1);
		r2 = rnd(0,N-1);
	}while(r1==r2);
	n1 = &ind->nodes[r1];
	n2 = &ind->nodes[r2];
	p1 = n1->parent;
	p2 = n2->parent;
	r1 = isRight(n1);
	r2 = isRight(n2);
	if(r1==1){
		p1->right = n2;
		n2->parent = p1;
	}
	else{
		p1->left = n2;
		n2->parent = p1;
	}
	if(r2 ==1){
		p2->right = n1;
		n1->parent = p2;
	}
	else {
		p2->left = n1;
		n1->parent = p2;
	}
}

void lswap_search(individual *ind){
	double currImp,bestImp=0;
	auto road[N][N],depth[N];
	auto z,y,c,c1,c2,found = 0, common,numComp=0,bestA,bestB;
	Node *climber,*A,*B,*pA,*pB;
	for(c=0;c<N;c++){
		climber = &ind->nodes[c];
		depth[c] = 0;
		while(climber!=NULL){
			road[c][depth[c]] = climber->copyIndex;
			depth[c]++;
			climber = climber->parent;
		}
	}
	//Arrays filled, now compare
	for(z = 0; z < N && numComp < MAXCHECK; z++){
		for(y=z+1;y<N && numComp < MAXCHECK;y++){ //dont repeat...
			c1 = depth[z]-1;
			c2 = depth[y]-1;
			while(c1!=0 && c1 !=0){
				if(road[z][c1] == road[y][c2]){
					common = road[z][c1];
					c1--;
					c2--;
				}
				else{
					break; //found last common node
				}
			}
			currImp = swapImprovement(ind,&ind->nodes[common],&ind->nodes[z],&ind->nodes[y]);
			if(currImp>bestImp || (currImp==bestImp && randomperc()<=.5)){
				found = 1;
				bestImp = currImp;
				bestA = z;
				bestB = y;
			}
			numComp++;
		}
	}
	if(found==1){
		A = &ind->nodes[bestA];
		B = &ind->nodes[bestB];
		pA = A->parent;
		pB = B->parent;
		if(isRight(A)){pA->right = B;}else{pA->left = B;}
		if(isRight(B)){pB->right = A;}else{pB->left = A;}
		A->parent = pB;
		B->parent = pA;
	}
}


void mutateTree(individual *ind) {
  double random = randomperc();
  //double search = randomperc();
  //printTree(ind,stdout,"\n");
  if(random<pmut){
    random = randomperc();
    if (random < pmut_nni) {
    	if(randomperc()<=pmut_rnd){
    		//printf("reg nni\n");
    		nni(ind);	
    	} 
    	else{
    		//printf("search nni\n");
    		nni_search(ind);
    	}
    	n_nni++;
    } 
    else if (random < pmut_nni + pmut_spr) {
      if(randomperc()<=pmut_rnd){
    		//printf("reg spr\n");
    		spr(ind);	
    	} 
    	else{
    		//printf("search spr\n");
    		spr_search(ind);
    	}
    	n_spr++;
    } 
    else if (random < pmut_nni + pmut_spr + pmut_tbr) {
      if(randomperc()<=pmut_rnd){
    		//printf("reg tbr\n");
    		tbr(ind);	
    	} 
    	else{
    		//printf("search tbr\n");
    		tbr_search(ind);
    	}
    	n_tbr++;
    }
    else if(random < pmut_nni + pmut_spr +pmut_tbr + pmut_ls){
      if(randomperc()<=pmut_rnd){
    		//printf("reg swap\n");
    		lswap(ind);	
    	} 
    	else{
    		//printf("search swap\n");
    		lswap_search(ind);
    	}
    	n_ls++;
    }
    else if(random< pmut_nni + pmut_spr + pmut_tbr + pmut_ls + pmut_step){
      if(randomperc()<=pmut_rnd){
    		//printf("reg step\n");
    		step(ind);	
    	} 
    	else{
    		//printf("search step\n");
    		step_search(ind);
    	}
    	n_step++;
    }
    propagateValues(ind);
    nmut++;
  }
}


/*
int main(int argc, char const *argv[])
{	srand (time(NULL));
  	seed = (double)rand() / (double)RAND_MAX ;
  	randomize();
	int arr[15],i;
	N=0;
	L=0;
	//arr = (int*)malloc(15*sizeof(int));
	for(i=0;i<15;i++)arr[i]=i;
	for(i=0;i<15;i++)printf("%d ", arr[i]);
		printf("\n");
	shuffle(arr,0,10);
	for(i=0;i<15;i++)printf("%d ", arr[i]);
		printf("\n");
	shuffle(arr,0,10);
	for(i=0;i<15;i++)printf("%d ", arr[i]);
		printf("\n");
	shuffle(arr,0,10);
	for(i=0;i<15;i++)printf("%d ", arr[i]);
		printf("\n");
	return 0;
}
*/
