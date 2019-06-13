 #!/bin/bash
guion=-greed
Archivo=newick
rm $Archivo
gcc *.c -o $Archivo -lm -Wall -O3 -w
#echo "Enter the name of the txt example: phy/ANGI, followed by [ENTER]:"
#archivo99=zilla
#read archivo99

#./$Archivo /home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/instancias/zilla.txt /home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/instancias/zilla.grd /home/asura/Documents/Estadias/VALIDACION/fusion/ExperimentalSetup/src/arboles/instancias/temp/temp.txt
./$Archivo instancias/zilla.txt instancias/zilla.grd instancias/temp/temp.txt iteraciones/iteracion1.txt
#Set_One
echo "Done!"
