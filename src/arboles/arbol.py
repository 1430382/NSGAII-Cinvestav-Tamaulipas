from Bio import Phylo
import pylab
###3
##3 arbol que se manda
print("arbol que se manda")
tree = Phylo.read('/home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/temp.txt', 'newick')
#print (tree)
Phylo.draw_ascii(tree)
##3 arbol en memoria
print("arbol en memoria")
tree1 = Phylo.read('/home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/test.txt', 'newick')
#print (tree)
Phylo.draw_ascii(tree1)
