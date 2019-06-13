#!/bin/bash
echo "Enter the name of the txt example: phy/ANGI, followed by [ENTER]:"
read archivo
#echo $archivo
python3 phytofasta.py $archivo.txt $archivo.fasta &
#wait
#python3 test4.py $archivo1.txt &
#wait
#echo "Enter the name of the output, the first txt and the second txt"
#echo "example: phy/calculos followed by [ENTER]:"
#temp2="temp"
#archivo3=$archivo$temp2
#python3 merge.py $archivo.txt $archivo3.txt $archivo.fasta &
#wait
#file=$archivo.txt
#while IFS= read line
#do
        
#	echo "$line"
#done <"$file"