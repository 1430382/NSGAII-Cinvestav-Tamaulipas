OBJS = phylip.o genrand.o
OBJSP = $(OBJS) phylo.o nni.o spr.o

phylo : newick.o $(OBJSP)
	gcc -O3 -march=opteron -lm -o phylo $(OBJSP)
	gcc -O3 -march=opteron -o newick newick.o $(OBJS)

phylo.o : phylo.c phylip.h nni.h spr.h
	gcc -Wextra -Wall -O3 -march=opteron -c phylo.c

phylip.o : phylip.c phylip.h genrand.h
	gcc -Wextra -Wall -O3 -march=opteron -c phylip.c

genrand.o : genrand.c genrand.h
	gcc -Wextra -Wall -O3 -march=opteron -c genrand.c

nni.o : nni.c nni.h phylip.h
	gcc -Wextra -Wall -O3 -march=opteron -c nni.c

spr.o : spr.c spr.h phylip.h
	gcc -Wextra -Wall -O3 -march=opteron -c spr.c

newick.o : newick.c phylip.h
	gcc -Wextra -Wall -O3 -march=opteron -c newick.c

