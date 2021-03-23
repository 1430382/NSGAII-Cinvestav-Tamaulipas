# Application of a multi-objective approach to solve the problem of phylogenetic reconstruction
_The objective of this project is to solve the problem of maximum parsimony with a multiobjective perspective_
## Summary 📋
```
Bioinformatics is an interdisciplinary field that encompasses molecular and genetic biology,
computer science, mathematics, and statistics.
Parsimony is the  idea  that, given  a set of possible explanations,  
the  simplest  is  usuallythe correct one. 
The principle of parsimony in the sciences is usually a selection of competitive models
 to describe a phenomenon; in biology this is more commonly used as a study of phylogeny.
Phylogeny is a way of thinking about how organisms are related through time.
It’s like a family tree, which starts with species that exist today and determines 
how close are related in their genetic material, if you have two species that share genes, 
which are expressed as the traits, which can track the genetics through time until you 
find an ancestor in common. Through this you can create a life map of the phylogenetic, 
which shows the relationships between life forms in existence and their ancestors.
There is the phylogenetic reconstruction, the maximum parsimony is classified as
 a problem of complete np since it is highly combinatorial, and based on its 
search space it grows exponentially with respect to the number of species studied. 
The multiobjectivization of the problem presents an alternative to allow 
that an evolutionary algorithm find competitive solutions; 
based on the reformulation of methods modifying fitness, 
thus affecting the Algorithm performance trying to optimize two different approaches.
Subsequently, three proposals were selected, 
which are: the decomposition of the originalfunction of parsimony, 
which deals with; the management of partial evaluations in series ona tree phylogenetic.
Using the function of secondary objectives in order to maximize the information 
evaluated the propagation of the Fitch algorithm for the states of the sets, some functions are:  
This based on Jaccard’s index in the dissimilarity between sample sets, 
defined as the cardinalityof the intersection.  
Based on the dissimilarity of BrayCurtis, the similarity between the geographic sites 
based on tree species found in each site.
```
## Information
_Algorithm: NSGA-II version=0.1_
#
```
In the Initializer Folder it can found the grd of some instances such as: 
* RBCL
* ZILLA
* MTDNA
and more.
In the initializersBin folder it can found the grd from set one and set two (ANGI,CARP,TST01,Etc)

In InstancesBin contains the binary instances of:
* ANGI
* CARP
* TST01
and more.

In the instanciasestadias folder you can found the set one and set two converted to txt because
the algorithm works with txt files.
```

_PhyToFasta folder_
```
PhyToFasta is a Python code that converts format files from phylip to fasta,
this code is still in construction.
if you have reading problems use execute.sh.
```
_General Information_
```
In the sets folder it can found from set one to set four from:
```
* [sets](http://www.info.univ-angers.fr/~richer/recbio_phylo.php#DATA.)

```
in the smallinstances folder it can found 30 allign instances such as:
* drosophyl2
* mtDNA_186
* rbCL_55
* RDPI_218
* ZILLA_500
```

## Execute the code 🚀
_Instructions to run the code_
```
You need to enter to src folder and if you are in a gnu/linux system based of you can use
sh Z.sh to compile and run the code.

If you want to visualize the tree results you can enter in the arboles folder inside src and 
run execute.sh before running the code you need to modify the path of the file arbol.py
and modify the path inside the file arbol.py
```
