 #!/bin/bash
guion=-
Archivo=nsgaII
rm $Archivo
gcc *.c -o $Archivo -lm -Wall -O3 -w #-fopenmp
echo "Enter the name of the txt example: phy/ANGI, followed by [ENTER]:"
archivo99=ANGI
#read archivo99
mkdir ../Results/libro/$archivo99
./$Archivo -Input ../instanciasestadias/$archivo99.txt -Output ../Results/libro/$archivo99/$archivo99$guion -OBJ 0
objetivocero=obj0
objetivouno=obj1
objetivodos=obj2
objetivotres=obj3
objetivocuatro=obj4
objetivocinco=obj5
objetivoseis=obj6
objetivosiete=obj7
objetivoocho=obj8
objetivonueve=obj9
objetivodiez=obj10
###33
ANGI=ANGI
CARP=CARP
ETHE=ETHE
GOLO=GOLO
GRIS=GRIS
ROPA=ROPA
SCHU=SCHU
TENU=TENU
tst01=tst01
tst02=tst02
tst03=tst03
tst04=tst04
tst05=tst05
tst06=tst06
tst07=tst07
tst08=tst08
tst09=tst09
tst10=tst10
tst11=tst11
tst12=tst12
tst13=tst13
tst14=tst14
tst15=tst15
tst16=tst16
tst17=tst17
tst18=tst18
tst19=tst19
tst20=tst20
echo "Phase One"
#for counter in $(seq 1 10);
#do
#echo "ANGI"
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo0/$ANGI$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo1/$ANGI$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo2/$ANGI$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo3/$ANGI$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo4/$ANGI$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo5/$ANGI$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo6/$ANGI$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo7/$ANGI$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo8/$ANGI$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo9/$ANGI$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$ANGI.txt -Output ../Results/$ANGI/objetivo10/$ANGI$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "CARP"
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo0/$CARP$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo1/$CARP$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo2/$CARP$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo3/$CARP$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo4/$CARP$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo5/$CARP$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo6/$CARP$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo7/$CARP$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo8/$CARP$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo9/$CARP$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$CARP.txt -Output ../Results/$CARP/objetivo10/$CARP$guion$objetivodiez$guion$counter -OBJ 10
#echo "ETHE"
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo0/$ETHE$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo1/$ETHE$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo2/$ETHE$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo3/$ETHE$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo4/$ETHE$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo5/$ETHE$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo6/$ETHE$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo7/$ETHE$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo8/$ETHE$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo9/$ETHE$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$ETHE.txt -Output ../Results/$ETHE/objetivo10/$ETHE$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "GOLO"
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo0/$GOLO$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo1/$GOLO$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo2/$GOLO$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo3/$GOLO$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo4/$GOLO$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo5/$GOLO$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo6/$GOLO$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo7/$GOLO$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo8/$GOLO$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo9/$GOLO$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$GOLO.txt -Output ../Results/$GOLO/objetivo10/$GOLO$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "GRIS"
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo0/$GRIS$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo1/$GRIS$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo2/$GRIS$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo3/$GRIS$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo4/$GRIS$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo5/$GRIS$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo6/$GRIS$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo7/$GRIS$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo8/$GRIS$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo9/$GRIS$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$GRIS.txt -Output ../Results/$GRIS/objetivo10/$GRIS$guion$objetivodiez$guion$counter -OBJ 10
###3
#echo "ROPA"
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo0/$ROPA$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo1/$ROPA$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo2/$ROPA$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo3/$ROPA$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo4/$ROPA$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo5/$ROPA$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo6/$ROPA$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo7/$ROPA$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo8/$ROPA$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo9/$ROPA$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$ROPA.txt -Output ../Results/$ROPA/objetivo10/$ROPA$guion$objetivodiez$guion$counter -OBJ 10
####3
#echo "SCHU"
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo0/$SCHU$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo1/$SCHU$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo2/$SCHU$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo3/$SCHU$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo4/$SCHU$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo5/$SCHU$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo6/$SCHU$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo7/$SCHU$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo8/$SCHU$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo9/$SCHU$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$SCHU.txt -Output ../Results/$SCHU/objetivo10/$SCHU$guion$objetivodiez$guion$counter -OBJ 10
###3
#echo "TENU"
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo0/$TENU$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo1/$TENU$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo2/$TENU$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo3/$TENU$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo4/$TENU$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo5/$TENU$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo6/$TENU$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo7/$TENU$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo8/$TENU$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo9/$TENU$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$TENU.txt -Output ../Results/$TENU/objetivo10/$TENU$guion$objetivodiez$guion$counter -OBJ 10
##33
#echo "tst01"
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo0/$tst01$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo1/$tst01$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo2/$tst01$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo3/$tst01$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo4/$tst01$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo5/$tst01$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo6/$tst01$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo7/$tst01$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo8/$tst01$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo9/$tst01$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst01.txt -Output ../Results/$tst01/objetivo10/$tst01$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst01"
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo0/$tst02$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo1/$tst02$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo2/$tst02$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo3/$tst02$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo4/$tst02$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo5/$tst02$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo6/$tst02$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo7/$tst02$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo8/$tst02$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo9/$tst02$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst02.txt -Output ../Results/$tst02/objetivo10/$tst02$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst03"
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo0/$tst03$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo1/$tst03$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo2/$tst03$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo3/$tst03$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo4/$tst03$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo5/$tst03$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo6/$tst03$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo7/$tst03$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo8/$tst03$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo9/$tst03$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst03.txt -Output ../Results/$tst03/objetivo10/$tst03$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst04"
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo0/$tst04$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo1/$tst04$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo2/$tst04$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo3/$tst04$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo4/$tst04$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo5/$tst04$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo6/$tst04$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo7/$tst04$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo8/$tst04$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo9/$tst04$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst04.txt -Output ../Results/$tst04/objetivo10/$tst04$guion$objetivodiez$guion$counter -OBJ 10
##33
#echo "tst05"
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo0/$tst05$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo1/$tst05$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo2/$tst05$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo3/$tst05$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo4/$tst05$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo5/$tst05$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo6/$tst05$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo7/$tst05$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo8/$tst05$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo9/$tst05$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst05.txt -Output ../Results/$tst05/objetivo10/$tst05$guion$objetivodiez$guion$counter -OBJ 10
##333
#echo "tst06"
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo0/$tst06$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo1/$tst06$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo2/$tst06$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo3/$tst06$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo4/$tst06$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo5/$tst06$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo6/$tst06$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo7/$tst06$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo8/$tst06$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo9/$tst06$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst06.txt -Output ../Results/$tst06/objetivo10/$tst06$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst07"
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo0/$tst07$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo1/$tst07$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo2/$tst07$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo3/$tst07$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo4/$tst07$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo5/$tst07$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo6/$tst07$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo7/$tst07$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo8/$tst07$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo9/$tst07$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst07.txt -Output ../Results/$tst07/objetivo10/$tst07$guion$objetivodiez$guion$counter -OBJ 10
##333
#echo "tst08"
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo0/$tst08$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo1/$tst08$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo2/$tst08$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo3/$tst08$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo4/$tst08$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo5/$tst08$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo6/$tst08$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo7/$tst08$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo8/$tst08$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo9/$tst08$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst08.txt -Output ../Results/$tst08/objetivo10/$tst08$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst09"
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo0/$tst09$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo1/$tst09$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo2/$tst09$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo3/$tst09$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo4/$tst09$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo5/$tst09$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo6/$tst09$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo7/$tst09$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo8/$tst09$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo9/$tst09$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst09.txt -Output ../Results/$tst09/objetivo10/$tst09$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst10"
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo0/$tst10$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo1/$tst10$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo2/$tst10$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo3/$tst10$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo4/$tst10$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo5/$tst10$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo6/$tst10$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo7/$tst10$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo8/$tst10$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo9/$tst10$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst10.txt -Output ../Results/$tst10/objetivo10/$tst10$guion$objetivodiez$guion$counter -OBJ 10
##3
#echo "tst11"
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo0/$tst11$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo1/$tst11$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo2/$tst11$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo3/$tst11$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo4/$tst11$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo5/$tst11$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo6/$tst11$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo7/$tst11$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo8/$tst11$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo9/$tst11$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst11.txt -Output ../Results/$tst11/objetivo10/$tst11$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst12"
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo0/$tst12$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo1/$tst12$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo2/$tst12$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo3/$tst12$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo4/$tst12$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo5/$tst12$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo6/$tst12$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo7/$tst12$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo8/$tst12$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo9/$tst12$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst12.txt -Output ../Results/$tst12/objetivo10/$tst12$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst13"
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo0/$tst13$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo1/$tst13$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo2/$tst13$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo3/$tst13$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo4/$tst13$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo5/$tst13$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo6/$tst13$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo7/$tst13$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo8/$tst13$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo9/$tst13$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst13.txt -Output ../Results/$tst13/objetivo10/$tst13$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst14"
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo0/$tst14$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo1/$tst14$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo2/$tst14$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo3/$tst14$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo4/$tst14$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo5/$tst14$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo6/$tst14$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo7/$tst14$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo8/$tst14$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo9/$tst14$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst14.txt -Output ../Results/$tst14/objetivo10/$tst14$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst15"
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo0/$tst15$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo1/$tst15$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo2/$tst15$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo3/$tst15$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo4/$tst15$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo5/$tst15$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo6/$tst15$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo7/$tst15$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo8/$tst15$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo9/$tst15$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst15.txt -Output ../Results/$tst15/objetivo10/$tst15$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst16"
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo0/$tst16$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo1/$tst16$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo2/$tst16$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo3/$tst16$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo4/$tst16$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo5/$tst16$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo6/$tst16$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo7/$tst16$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo8/$tst16$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo9/$tst16$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst16.txt -Output ../Results/$tst16/objetivo10/$tst16$guion$objetivodiez$guion$counter -OBJ 10
##33
#echo "tst17"
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo0/$tst17$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo1/$tst17$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo2/$tst17$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo3/$tst17$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo4/$tst17$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo5/$tst17$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo6/$tst17$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo7/$tst17$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo8/$tst17$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo9/$tst17$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst17.txt -Output ../Results/$tst17/objetivo10/$tst17$guion$objetivodiez$guion$counter -OBJ 10
##333
#echo "tst18"
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo0/$tst18$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo1/$tst18$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo2/$tst18$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo3/$tst18$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo4/$tst18$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo5/$tst18$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo6/$tst18$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo7/$tst18$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo8/$tst18$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo9/$tst18$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst18.txt -Output ../Results/$tst18/objetivo10/$tst18$guion$objetivodiez$guion$counter -OBJ 10
##333
#echo "tst19"
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo0/$tst19$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo1/$tst19$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo2/$tst19$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo3/$tst19$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo4/$tst19$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo5/$tst19$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo6/$tst19$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo7/$tst19$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo8/$tst19$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo9/$tst19$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst19.txt -Output ../Results/$tst19/objetivo10/$tst19$guion$objetivodiez$guion$counter -OBJ 10
###33
#echo "tst20"
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo0/$tst20$guion$objetivocero$guion$counter -OBJ 0
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo1/$tst20$guion$objetivouno$guion$counter -OBJ 1
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo2/$tst20$guion$objetivodos$guion$counter -OBJ 2
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo3/$tst20$guion$objetivotres$guion$counter -OBJ 3
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo4/$tst20$guion$objetivocuatro$guion$counter -OBJ 4
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo5/$tst20$guion$objetivocinco$guion$counter -OBJ 5
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo6/$tst20$guion$objetivoseis$guion$counter -OBJ 6
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo7/$tst20$guion$objetivosiete$guion$counter -OBJ 7
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo8/$tst20$guion$objetivoocho$guion$counter -OBJ 8
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo9/$tst20$guion$objetivonueve$guion$counter -OBJ 9
#./$Archivo -Input ../instanciasestadias/$tst20.txt -Output ../Results/$tst20/objetivo10/$tst20$guion$objetivodiez$guion$counter -OBJ 10

##33
#done
echo "Nice!"
