#!/opt/anaconda/bin/python

import sys

# www-data PATH: /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

#sys.path.append('/opt/anaconda3/bin')
#sys.path.append('/usr/local/sbin')
#sys.path.append('/usr/local/bin')
#sys.path.append('/usr/sbin')

from sys import argv
import numpy as np
from Bio import SeqIO
import subprocess
from os import system
import shutil
import os
import os.path as path

my_seqlist = []
fileInput = open(argv[1], "r")
archivo = os.path.splitext(argv[1])[0]
arch=archivo+".fasta"
import numpy as np
for seq_record in SeqIO.parse(arch, 'fasta'):
	my_seqlist.append(seq_record)
seqMat = np.array(my_seqlist)
num= len(my_seqlist)
cant=len(seq_record)
cont=0
for i in range(0,num-1):
    for j in range(i+1,num):	
        for k in range(0,cant):
            if (seqMat[i][k]==seqMat[j][k]):
                cont=cont+1
res=cant*(((num-1)*num)/2)
q=(cont/float(res))*100
calculos=""+"\n"+str(num)+"\n"+str(cant)+"\n"
print(calculos)
file = open(archivo+"temp.txt","w")
file.write(str((calculos)))
file.close()
