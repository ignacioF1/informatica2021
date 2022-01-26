/* ENUNCIADO Parcial SUBE
Se tienen datos diarios del primer semestre del 2020 del movimiento de pasajeros en colectivos, lancha provistos por la tarjeta SUBE.  Consisten en 182 de datos de cada medio entre el 1 de enero y 30 de junio, recuerde que 2020 fue bisiesto.
Se pide realizar un programa que:
A) Abrir los archivos colectivos.dat y lancha.dat y ponga disponibles los datos en sendos vectores.
B) Mostrar un menu repetitivo tal que sus opciones sean las siguientes:
1.	Promedio de viajes en colectivo prepandemia-pandemia: tener en cuenta que el día 80 empezó la cuarentena, calcule el promedio antes y después del día 80 simétricamente. Guardar los dos datos en un archivo cambioscovid.dat 
2.	Promedio diario colectivo-lancha: ingresar un número de día entre 1 y 29(para descartar la diferencia de los meses) muestre el promedio de ese número de día de cada mes en ese día entre colectivo y lancha.
3.	Días sin viaje en lancha: muestra la cantidad de días sin viajes en lancha y el porcentaje sobre el total de días analizados e indique cuántos son en prepandemia y cuántos en pandemia.
4.	Máxima cantidad de pasajeros: selecciones colectivo o lancha e informa qué día hubo el máximo número de pasajeros y la cantidad, si hay más de uno muestre sólo uno.
5.	Salir.
1) promedio de viajes en colectivo semestre y guardelos en el archivo promcolectivos.dat
2) promedio de viajes en lancha semestre y guardelos en el archivo promlancha.dat
3) promedio de viajes en subte semestrey guardelos en el archivo promsubte.dat
4) promedio de viajes en tren semestrey guardelos en el archivo promtren.dat
5) Promedio de viajes el día 1 de enero
6) promedio de viajes el día 30 de junio
7) el maximo de viajes realizados en colectivo y en que orden se encuentra del vector correspondiente se encuentra
8) maximos de viajes en lancha en enero y febrero imprima la cantidad de días considerados en cada mes 
9) salir
*/

#include <stdio.h>

//Declaro variables
int i, c, c1, vecLancha[182], vecColectivo[182];
FILE *lancha, *colectivo;

int main(){
//Cada archivo contiene la cantidad de personas que viajaron por día para cada día en int. Son 182 días.

//Abro el archivo para leerlo
lancha = fopen ("lancha.dat", "rb");           //Abro el archivo para lectura "read binary"
if(lancha==NULL){                              //Chequea si el archivo es accesible
    perror("Error al abrir el archivo para leer \n"); 
    return(-1);
}

//Abro el archivo para leerlo
colectivo = fopen ("colectivo.dat", "rb");           //Abro el archivo para lectura "read binary"
if(colectivo==NULL){                              //Chequea si el archivo es accesible
    perror("Error al abrir el archivo para leer \n"); 
    return(-1);
}

//Leo el archivo
c1=fread(&vecLancha,sizeof(vecLancha),1,lancha);
if (c1 !=1){
	perror("Error al leer \n"); 
    return (-2); 
}

//Leo el archivo
c1=fread(&vecColectivo,sizeof(vecColectivo),1,colectivo);
if (c1 !=1){
	perror("Error al leer \n"); 
    return (-2); 
}

//Muestro menú
printf("\nIngrese el numero de opcion deseada:\n1-Promedio de viajes en colectivo prepandemia-pandemia\n2-Promedio diario colectivo-lancha\n3-Días sin viaje en lancha\n4-Máxima cantidad de pasajeros\n5-Salir\n");
i=0;
scanf("%i",&i);
switch(i){
    case 1:
        printf("-> Promedio de viajes en colectivo prepandemia-pandemia\n");
        printf("%f\n",0);
        break;
    case 2:
        printf("-> Promedio diario colectivo-lancha\n");
        printf("%f\n",1);
        break;
    case 3:
        printf("-> Días sin viaje en lancha\n");
        printf("%f\n",2);
        break;
    case 4:
        printf("-> Máxima cantidad de pasajeros\n");
        printf("%f\n",3);
        break;
    case 5:
        printf("-> Salir\n");
        break;
    default:
        printf("Ingrese una opcion entre 1 y 5\n");
        break;
    }








return 0;
}