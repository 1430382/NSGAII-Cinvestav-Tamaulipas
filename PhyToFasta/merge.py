#! /usr/bin/python
import os
import sys
from sys import argv

if len(sys.argv) > 3:
	name=argv[1]
	name2=argv[2]
	name3=argv[3]
	filenames = [name2,name3]
	with open(name, 'w') as outfile:
		for fname in filenames:
			with open(fname) as infile:
				for line in infile:
					line=line.replace(' ','\n ')
					outfile.write(line)
else:
	print("Error in the command line parameter")
	print("To execute the program follow the next sentence:  ")
	print("python3 merge.py nameofthetxt.txt")
