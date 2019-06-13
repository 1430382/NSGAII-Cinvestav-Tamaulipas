#!/usr/bin/env python

import sys

from Bio import AlignIO
from sys import argv
name=argv[1]
name2=argv[2]
input_handle = open(name, "rU")
output_handle = open(name2, "w")

alignments = AlignIO.parse(input_handle, "phylip")
AlignIO.write(alignments, output_handle, "fasta")

output_handle.close()
input_handle.close()

