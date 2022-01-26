/*
1er Parcial
Integrantes: 

Fecha: 02/10/2021
*/

//Incluímos bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaramos variables
int i, j, c, suma, mayor, menor, zona, posicion, aleatorio, temperaturas[35], promedio[8];
//En el vector temperaturas almacenaremos los datos de teminside.dat de 140bytes (35 datos x 4 bytes)

//Declaro punteros a los archivos
FILE *archivo, *prom;

//Función principal
int main(){

//Fijamos el punto de comienzo (semilla) para generar números aleatorios para el punto C.4
srand(time(0));

    //A)
    //Abro el archivo teminside.dat en modo lectura
    archivo = fopen ("teminside.dat", "rb");        //Abro el archivo para lectura
    if(archivo == NULL){                            //Chequea si el archivo es accesible, de lo contrario sale
        perror("Error al abrir el archivo para leer \n"); 
        return(-1);
    }
    //Leo el archivo
    c = fread(&temperaturas,sizeof(temperaturas),1,archivo);
    if (c != 1){                                    //Si hay un error de lectura, lo informa y sale
	   perror("Error al leer \n"); 
       return(-2); 
	}

    //Cierro el archivo
    c = fclose(archivo);
    if (c !=0){                                     //Si hay un error al cerrar, lo informa y sale
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    //B)
    //Calculo el promedio en cada zona y lo guardo en cada posición del vector "promedio"
    //Zona 1
    suma = 0;
    for(i=0;i<9;i++){
        suma += temperaturas[i];
    }
    promedio[0] = suma/9;
    //Zona 2
    promedio[1] = temperaturas[9];
    //Zona 3
    suma = 0;
    for(i=10;i<14;i++){
        suma += temperaturas[i];
    }
    promedio[2] = suma/4;
    //Zona 4
    suma = 0;
    for(i=14;i<17;i++){
        suma += temperaturas[i];
    }
    promedio[3] = suma/3;
    //Zona 5
    suma = 0;
    for(i=17;i<22;i++){
        suma += temperaturas[i];
    }
    promedio[4] = suma/5;
    //Zona 6
    suma = 0;
    for(i=22;i<25;i++){
        suma += temperaturas[i];
    }
    promedio[5] = suma/3;
    //Zona 7
    suma = 0;
    for(i=25;i<31;i++){
        suma += temperaturas[i];
    }
    promedio[6] = suma/6;
    //Zona 8
    suma = 0;
    for(i=31;i<35;i++){
        suma += temperaturas[i];
    }
    promedio[7] = suma/4;

    //Abro el archivo tempProm.dat en modo escritura
    prom = fopen ("tempProm.dat", "wb");        //Abro el archivo para escritura
    if(prom == NULL){                            //Chequea si el archivo es accesible, de lo contrario sale
        perror("Error al abrir el archivo para escribir \n"); 
        return(-1);
    }

    //Escribo el contenido del vector en el archivo
    c = fwrite(&promedio,sizeof(promedio),1,prom);
    if (c != 1){                                    //Si se presenta un error al escribir el archivo, se informa y sale
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}

    //Cierro el archivo
    c = fclose(prom);
    if (c !=0){                                     //Si hay un error al cerrar, lo informa y sale
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    // /* -----------------
    // Agregamos para visualizar ambos vectores
    printf("PROMS: ");
    for(j=0;j<8;j++){
        printf("%i ", promedio[j]);
    }
    printf("TEMPS: ");
    for(j=0;j<35;j++){
        printf("%i ", temperaturas[j]);
    }                   
    printf("\n");
    // ----------------- */

    //C
    //Muestro un menú que se repetirá hasta que el usuario ingrese la opción 5 para salir
    i = 0;  //Inicializamos i en 0, para utilizarlo para las opciones del menú
    do{
        printf("\nIngrese el numero de opcion deseada:\n1-Zona Mayor Temperatura Promedio\n2-Zona Menor Promedio\n3-Menor Temperatura\n4-Temperatura Centigrado\n5-Terminar\n");
        scanf("%i",&i);
        switch(i){
            case 1:
                printf("-> Zona Mayor Temperatura Promedio\n");
                mayor = 0;  //Asumimos que van a existir temeraturas promedio mayores a 0 Farenheit
                for(j=0;j<8;j++){   //Recorremos el vector
                    if(promedio[j] > mayor){    //Si la temperatura promedio es mayor a "mayor"
                        mayor = promedio[j];    //El nuevo "mayor" sera dicha temperatura promedio
                        zona = j+1;             //La zona de dicha temp. prom. será la posición + 1
                    }
                }
                printf("La zona de mayor temperatura promedio es la: %i\n",zona);
                break;
            case 2:
                printf("-> Zona Menor Promedio\n");
                menor = 212;  //Asumimos que van a existir temeraturas promedio menores a 212 Farenheit o 100°C
                for(j=0;j<8;j++){   //Recorremos el vector
                    if(promedio[j] < menor){    //Si la temperatura promedio es menor a "menor"
                        menor = promedio[j];    //El nuevo "menor" sera dicha temperatura promedio
                        zona = j+1;             //La zona de dicha temp. prom. será la posición + 1
                    }
                }
                printf("La zona de menor temperatura promedio es la: %i\n",zona);
                break;
            case 3:
                printf("-> Menor Temperatura\n");
                menor = 212;  //Asumimos que van a existir temeraturas menores a 212 Farenheit o 100°C
                for(j=0;j<35;j++){   //Recorremos el vector
                    if(temperaturas[j] < menor){    //Si la temperatura es menor a "menor"
                        menor = temperaturas[j];    //El nuevo "menor" sera dicha temperatura
                        posicion = j;               //Almacenamos la posición de dicha temperatura
                    }
                }
                if(posicion < 9){           //Una vez obtenida la posición de la menor temperatura,
                    zona = 1;               //analizamos a que zona pertenece
                }else if(posicion == 9){
                    zona = 2;
                }else if(posicion < 14){
                    zona = 3;
                }else if(posicion < 17){
                    zona = 4;
                }else if(posicion < 22){
                    zona = 5;
                }else if(posicion < 25){
                    zona = 6;
                }else if(posicion < 31){
                    zona = 7;
                }else{
                    zona = 8;
                }
                printf("La menor temperatura se encuentra en la zona: %i\n",zona);
                printf("La menor temperatura se encuentra en la posicion: %i (partiendo de 0)\n",posicion);
                break;
            case 4:
                printf("-> Temperatura Centigrado\n");
                aleatorio = (rand()%35);   //Generamos un número aleatorio entre 0 y 34 (posiciones del vector temperaturas)
                printf("%.2f C\n",(temperaturas[aleatorio]-32.f)*(5.f/9.f));   //Tomando la temperatura de la posición aleatoria
                break;                                                      //obtenida, la convertimos a centígrados
            case 5:
                printf("-> Terminar\n");    //La opción 5 sale
                break;
            default:
                printf("Ingrese una opcion entre 1 y 5\n");
                break;
            }
    }while(i != 5); //Si la opción ingresada es 5 no vuelve a mostrar el menú

    //Devuelvo 0 si la función principal finalizó correctamente
    return 0;
}