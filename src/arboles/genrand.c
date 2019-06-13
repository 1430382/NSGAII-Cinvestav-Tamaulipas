#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "genrand.h"


#define	POOLSIZE	1024


static int indice = POOLSIZE;
static unsigned int randpool[POOLSIZE];


/* get a random number */
int get_rand_number(unsigned int *prn)
{
	int fd;

	if(indice < POOLSIZE){
		*prn = randpool[indice++];
		return 0;
	}

	fd = 0;
	if((fd = open("/dev/urandom", O_RDONLY)) == -1){
		perror("open (get_rand_number)");
		return -1;
	}

	if(read(fd, randpool, sizeof(randpool)) != sizeof(randpool)){
		perror("read (get_rand_number)");
		return -1;
	}

	indice = 0;
	*prn = randpool[indice++];
	close(fd);
	return 0;
}

