#! /usr/bin/python
import sys
from sys import argv

if len(sys.argv) > 1:
	while True:
				try:
					name=argv[1]
					fileInput = open(name, "r")
					import os
					archivo = os.path.splitext(argv[1])[0]
					arch=archivo+".fasta"
					import re 
					i=0
					for strLine in fileInput:
						if re.match("[0-9]", strLine[0]):
							fileOutput = open(arch, "w")
							os.chmod(arch, 0o777)
							for strLine in fileInput:
								if re.match("[A-Z-a-z]", strLine[0]):
									strLine=strLine.split(' ')
									while '' in strLine:
												strLine.remove('')
									strLine=' '.join(strLine)
									strLine = strLine.replace(' ', '\n')	    			
									fileOutput.write(">"+strLine)
							fileOutput.close()
						else:
							break
			
					break
				except IOError:

					break
else:
	print("Error in the command line parameter")
	print("To execute the program follow the next sentence:  ")
	print("python3 test.py phy/nameofthetxt.txt")
