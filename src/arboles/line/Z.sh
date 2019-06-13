 #!/bin/bash
guion=-greed
Archivo=main
rm $Archivo
gcc *.c -o $Archivo -lm -Wall -O3 -w
#echo "Enter the name of the txt example: phy/ANGI, followed by [ENTER]:"
archivo99=zilla
#read archivo99

./$Archivo
#Set_One
echo "Done!"
