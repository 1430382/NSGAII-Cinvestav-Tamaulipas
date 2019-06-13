#!/bin/bash
Archivo=nsgaII
guion=-
backup=backup1
#cd $Carpeta
rm $Archivo
gcc *.c -o $Archivo -lm -Wall -O3
echo "Enter the name of the txt example: phy/ANGI, followed by [ENTER]:"
#read archivo99
archivo99=ANGI
./$Archivo -Input ../../InstancesBin/$archivo99.txt  -Output ../../Results/libro/$archivo99/$archivo99$guion$backup -OBJ 0 -Greed ../../InitializersBin/ANGI.grd
######33
archivo0=ANGI
archivo1=CARP
archivo2=ETHE
archivo3=GOLO
archivo4=GRIS
archivo5=ROPA
archivo6=SCHU
archivo7=TENU
#Set_Two
archivo8=TST01
archivo9=TST02
archivo10=TST03
archivo11=TST04
archivo12=TST05
archivo13=TST06
archivo14=TST07
archivo15=TST08
archivo16=TST09
archivo17=TST10
archivo18=TST11
archivo19=TST12
archivo20=TST13
archivo21=TST14
archivo22=TST15
archivo23=TST16
archivo24=TST17
archivo25=TST18
archivo26=TST19
archivo27=TST20
#echo "Phase One"
#for counter in $(seq 1 30); 
#do 
#Set_One
#echo "ANGI"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo0.txt  -Output ../../Results/old/$archivo0/$archivo0$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "CARP"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo1.txt  -Output ../../Results/old/$archivo1/$archivo1$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "ETHE"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo2.txt  -Output ../../Results/old/$archivo2/$archivo2$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1 
#
#echo "GOLO"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo3.txt  -Output ../../Results/old/$archivo3/$archivo3$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1 
#
#echo "GRIS"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo4.txt  -Output ../../Results/old/$archivo4/$archivo4$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1 
#
#echo "ROPA"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo5.txt  -Output ../../Results/old/$archivo5/$archivo5$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1 
#
#echo "SCHU"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo6.txt  -Output ../../Results/old/$archivo6/$archivo6$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1 
#
#echo "TENU"
#./$Archivo -Input ../../PhyToFasta/set1/$archivo7.txt  -Output ../../Results/old/$archivo7/$archivo7$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1 
#Set_Two

#echo "TST01"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo8.txt  -Output ../../Results/old/$archivo8/$archivo8$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST02"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo9.txt  -Output ../../Results/old/$archivo9/$archivo9$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST03"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo10.txt  -Output ../../Results/old/$archivo10/$archivo10$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST04"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo11.txt  -Output ../../Results/old/$archivo11/$archivo11$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST05"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo12.txt  -Output ../../Results/old/$archivo12/$archivo12$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST06"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo13.txt  -Output ../../Results/old/$archivo13/$archivo13$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST07"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo14.txt  -Output ../../Results/old/$archivo14/$archivo14$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST08"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo15.txt  -Output ../../Results/old/$archivo15/$archivo15$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
echo "TST09"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo16.txt  -Output ../../Results/old/$archivo16/$archivo16$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
echo "TST10"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo17.txt  -Output ../../Results/old/$archivo17/$archivo17$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST11"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo18.txt  -Output ../../Results/old/$archivo18/$archivo18$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST12"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo19.txt  -Output ../../Results/old/$archivo19/$archivo19$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST13"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo20.txt  -Output ../../Results/old/$archivo20/$archivo20$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST14"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo21.txt  -Output ../../Results/old/$archivo21/$archivo21$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST15"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo22.txt  -Output ../../Results/old/$archivo22/$archivo22$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST16"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo23.txt  -Output ../../Results/old/$archivo23/$archivo23$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST17"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo24.txt  -Output ../../Results/old/$archivo24/$archivo24$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#echo "TST18"
#
#./$Archivo -Input ../../PhyToFasta/set2/$archivo25.txt  -Output ../../Results/old/$archivo25/$archivo25$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST19"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo26.txt  -Output ../../Results/old/$archivo26/$archivo26$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#
#echo "TST20"
#./$Archivo -Input ../../PhyToFasta/set2/$archivo27.txt  -Output ../../Results/old/$archivo27/$archivo27$counter -SIZEP 500 -GEN 100 -PC 0.818 -PM 0.270 -NNI 0.255 -SPR 0.337 -TBR 0.079 -LFS 0.295 -STP 0.135 -LS 0.137 -OBJ 1
#done
echo "Nice!"


######3

