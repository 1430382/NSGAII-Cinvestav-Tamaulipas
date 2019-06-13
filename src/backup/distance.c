#include "global.h"
#include <math.h>
#include <stdlib.h>
#include <omp.h>
double parsimony(int *a, int *b) {
  double x = 0;
  int i;
  #pragma omp parallel for reduction(+:x)
  for (i = 0; i < L; i++)
    if ((a[i] & b[i]) == 0)
      x += 1; 
	/*for (i = 0; i < L; i++)
		{
		L=a[i] & b[i];
    if( (!L=0)
			{
				x= a[i] | b [i];
				x += 1;
			}
      
		}*/
  return x;
}

int mutationType(int a,int b){
  if (a&b) {    //No mutation, one of them is 255, cases like that
    return 0;
  }
  else if(((a&5)&&(b&5))||((a&10)&&(b&10))){ //transition
    return 1;
  }
  else if(((a&5)&&(b&10))||((a&10)&&(b&5))){ //transversion
    return 2;
  }
  else //if ((a&16) || (b&16))  deletion or insertion
      return 3;
}

int firstBitIn(int a){
  if(a&1) return 0;
  else if (a&2) return 1;
  else if (a&4) return 2;
  else if (a&8) return 3;
  else //if (a&16)
    return 4;
}


int bitsIn(int a) {
  int x = 0;
  while (a != 0) {
    a &= (a - 1);
    x++;
  }
  return x;
}


//assumes insertion as a fifth state and treats it accordingly
//change "count<4", and add "if(!(x1 && x2)) return 1;" to treat as single move
int closestBitDistIn(int a,int b){
  int x1 = 0,x2 = 0,count=0;
  for(count = 0; count<5;count++){
      if((a>>count)&1) x1 = count;
      if((b>>count)&1) x2 = count;
      if(x1 && x2) break; //if both have assigned values
  }
  return abs(x1-x2);
}


double jaccard (int *a, int *b){
  double x=0;
  int i;
  for(i=0;i<L;i++){
    if((a[i]==255)||(b[i]==255)) {x+=1; continue;}
    x+= (double)(a[i]&b[i])/(double)(a[i]|b[i]);
  }
  return x;
}

double wagner (int *a, int *b){
  double x=0;
  int i;
  for(i=0;i<L;i++){
    if((a[i]&b[i]) ==0)
      x += closestBitDistIn(a[i],b[i]);
  }
  return x;
}

double brayCurtis(int *a, int *b){
  double x1 = 0, x2 = 0;
  int i;
  for (i = 0; i<L; i++){
    if((a[i]==255)||(b[i]==255)) continue;
    x1 += abs(a[i] - b[i]);
    x2 += abs(a[i] + b[i]);
  }
  return (double)x1/(double)x2;
}

double canberra(int *a, int *b){
  double x = 0;
  int i;
  for (i = 0; i<L; i++){
    x += (double) abs(a[i] - b[i])/(double)abs(a[i] + b[i]);
  }
  return x;
}

double chebyshev(int *a, int *b){
  double x = 0, y = 0;
  int i;
  x = abs(a[0]-b[0]);
  for(i = 1; i < L; i++){
    y = abs(a[i]-b[i]);
    if (y>=x) x=y;
  }
  return x;
}

double manhattan(int *a, int *b){
  double x=0;
  int i;
  for(i=0; i<L; i++){
    if((a[i] == 255)||(b[i]==255)) continue;
    x+= (double)abs(a[i]-b[i]);
  }
  return x;
}

double euclidean(int *a, int *b){
  double x;
  int i;
  for(i=0;i<L;i++){
    if((a[i] == 255)||(b[i]==255)) continue;
    x+= (double) pow(a[i]-b[i],2);
  }
  return sqrt(x);
}

double weighted (int *a, int *b){
  double x = 0;
  int i,y;
  for (i=0; i<L; i++){
    if((a[i]&b[i])==0){
      y = mutationType(a[i],b[i]);
      if(y == 1) x += 1;  //transitions
      else x += 5;  //transversion & insertions?
    }
  }
  return x;
}

double brown (int *a, int *b){
  double x = 0;
  int i,y;
  for (i=0; i<L; i++){
    if((a[i]&b[i])==0){
      y = mutationType(a[i],b[i]);
      if(y == 1) x += 1;  //transitions
      else x += 2;  //transversion & insertions?
    }
  }
  return x;
}

double bitj(int *a, int *b){
  double x = 0 ;
  int i, y,z;
  #pragma omp parallel for reduction(+:x)  private(y,z)
  for (i = 0; i<L; i++){
    if(a[i]==255 || b[i] == 255){x+=1; continue;}
    y = a[i]&b[i];
    z = a[i]|b[i];
    x+= (double)(bitsIn(y)/bitsIn(z));
  }
  return x;
}

double jcdist(int *a, int *b){
  double x = 0;
  int i;
  for (i = 0; i< L;i++){
    if((a[i] & b[i])==0) x++;
  }
  return (-.75 * log(1 - (.75 * x/L)));
}

double k80(int *a, int *b){
  int x = 0, p = 0, q = 0, i, t;
  double P,Q;
  for(i=0; i<L; i++){
    if( (t = mutationType(a[i], b[i])) ){
      if(t == 1) p++;
      else q++;
    }
  }
  P = (double)p/(double)(p+q);
  Q = (double)q/(double)(p+q);
  // printf("%d %d %lf %lf\n",p,q,P,Q);
  x = -0.5 * (double)log((1-2*(P-Q))*(double)(sqrt(1-2*Q)));
  return x;
}


double k80M(int *a, int *b){
  int x = 0, p = 0, q = 0, i, t;
  double P,Q;
  for(i=0; i<L; i++){
    if( (t = mutationType(a[i], b[i])) ){
      if(t == 1) p++;
      else q++;
    }
  }
  P = (double)p/(double)(p+q);
  Q = (double)q/(double)(p+q);
  // printf("%d %d %lf %lf\n",p,q,P,Q);
  x = -0.5 * (double)log((1-2*(P-Q))-0.25*(double)(log(1-2*Q)));
  return x;
}
