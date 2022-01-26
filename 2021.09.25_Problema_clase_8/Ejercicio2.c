/*
2- Hacer un programa que dado un vector de 24 datos tipo int(generados al azar) con valores x entre 0 y 50 
los guarde en un archivo enteros.bin.
2.1 Cuantos bytes ocupa enteros.bin?
2.2 Multiplique cada elemento por 2 y guarde los nuevos valores en un archivo doble.bin: 
2.3 Hacer un código que realice lo siguiente:
a) abra el archivo enteros.bin, y sabiendo que son enteros, coloquelos en un vector
b) presente un menú que ofrezca y realice las siguientes opciones :
 b.1 Suma Total: sume todos los elementos del vector 
 b.2 Suma Pares: sume todos los elementos pares
 b.3 Suma M5: sume todos los múltiplos de 5
 b.4 Porcentaje Pares: devuelva el porcentaje de números pares
 b.5 Porcentaje M5: Devuelva el porcentaje de múltiplos de 5.
 (en cada item guarde en un indice de un vector float de 5 posiciones, sería apropiado que el vector se denomine 
 resultados)
 c) Imprima los resultados
 d) Guarde los resultados en un vector float de 5 posiciones
 e) Guarde el vector resultados en un archivo resultado.dat

3- Dado el archivo enteros.bin del ej 2-
3.1 Abrir el archivo y mostrar los indices de los numeros pares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaro variables
int i, j, k, v[24]={}, c1, c2, entero, e[24]={};
float resultados[5]={0};
FILE *ent, *dob, *res;                //Declaro puntero al archivo

int main(){
    srand(time(0));
    for(i=0;i<24;i++){
        v[i]=(rand()%51);       //Genera un número aleatorio entre 0 y 50
        printf("%i ",v[i]);     //Test
    }

    //Abro un nuevo archivo para escribir
    ent=fopen("enteros.bin","wb");          //Abro el arhivo para escritura "write binary"
	if(ent == NULL){                        //Puede ser NULL, chequear
		perror("error al abir el archivo"); //Equivalente a printf pero para errores
		return(-1);
	}

    //Escribo el contenido del vector en el archivo
    c1=fwrite(&v,sizeof(v),1,ent);
    if (c1 != 1){
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}
    
    printf("\nTamano de enteros.bin: %i bytes\n", sizeof(v));

    //Cierro el archivo
    c2=fclose(ent);
    if (c2 !=0){ 
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    //Abro un nuevo archivo para escribir
    dob=fopen("doble.bin","wb");          //Abro el arhivo para escritura "write binary"
	if(dob == NULL){                        //Puede ser NULL, chequear
		perror("error al abir el archivo"); //Equivalente a printf pero para errores
		return(-1);
	}

    //Genero un vector
    for(i=0;i<24;i++){
        v[i]=2 * v[i];          //Multiplica cada componente del vector por 2
        printf("%i ",v[i]);     //Test
    }

    //Escribo el contenido del vector en el archivo
    c1=fwrite(&v,sizeof(v),1,dob);
    if (c1 != 1){
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}

    //Cierro el archivo
    c2=fclose(dob);
    if (c2 !=0){ 
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    //Abro el archivo enteros.bin para leerlo
    ent = fopen ("enteros.bin", "rb");          //Abro el archivo para lectura "read binary"
    if(ent==NULL){                              //Chequea si el archivo es accesible
        perror("Error al abrir el archivo para leer \n"); 
        return(-1);
    }
    //Leo el archivo
    c1=fread(&e,sizeof(e),1,ent);
    if (c1 !=1){
	   perror("Error al leer \n"); 
       return (-2); 
	}

    //guarde en un indice de un vector float "resultados" de 5 posiciones

    j=0;
    k=0;
    for(i=0;i<24;i++){
        resultados[0] += v[i];
        if(v[i]%2 == 0){
            resultados[1] += v[i];
        }
        if(v[i]%5 == 0){
            resultados[2] += v[i];
        }
        if(v[i] != 0 && v[i]%2 == 0){
           j++;
        }
        if(v[i] != 0 && v[i]%5 == 0){
                        k++;
        }
    }
    resultados[3] = (float)j*100/24;
    resultados[4] = (float)k*100/24;
    
    //Imprima los resultados
    printf("\nResultados: ");
    for(i=0;i<5;i++){
        printf("%f ",resultados[i]);
    }

    i=0;
    printf("\nIngrese el numero de opcion deseada:\n1-Suma Total\n2-Suma Pares\n3-Suma M5\n4-Porcentaje Pares\n5-Porcentaje M5\n");
    scanf("%i",&i);
    switch(i){
        case 1: // b.1 Suma Total: sume todos los elementos del vector 
                printf("-> Suma Total\n");
                printf("%f\n",resultados[0]);
                break;
        case 2: // b.2 Suma Pares: sume todos los elementos pares
                printf("-> Suma Pares\n");
                printf("%f\n",resultados[1]);
                break;
        case 3: // b.3 Suma M5: sume todos los múltiplos de 5
                printf("-> Suma M5\n");
                printf("%f\n",resultados[2]);
                break;
        case 4: // b.4 Porcentaje Pares: devuelva el porcentaje de números pares
                printf("-> Porcentaje Pares\n");
                printf("%f\n",resultados[3]);
                break;
        case 5: // b.5 Porcentaje M5: Devuelva el porcentaje de múltiplos de 5.
                printf("-> Porcentaje M5\n");
                printf("%f\n",resultados[4]);
                break;
        default:
                printf("Ingrese una opcion entre 1 y 5\n");
                break;
    }

    //Cierro el archivo
    c2=fclose(ent);
    if (c2 !=0){ 
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    // Guarde el vector resultados en un archivo resultado.dat

    //Abro un nuevo archivo para escribir
    res=fopen("resultado.dat","wb");          //Abro el arhivo para escritura "write binary"
	if(ent == NULL){                        //Puede ser NULL, chequear
		perror("error al abir el archivo"); //Equivalente a printf pero para errores
		return(-1);
	}

    //Escribo el contenido del vector en el archivo
    c1=fwrite(&resultados,sizeof(resultados),1,dob);
    if (c1 != 1){
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}

    //Cierro el archivo
    c2=fclose(res);
    if (c2 !=0){ 
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    return 0;                               //Devuelve 0 si todo es correcto (0 errores)
}