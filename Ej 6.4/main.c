#include <stdio.h>
#include <stdlib.h>

//6.4. Escribir un programa que realice las siguientes tareas:

//Declaro la función suma
int suma (int vec[],int n);

//Declaro puntero al archivo
FILE *archivo;

//Función principal
int main(){		
  //declaro mis variables
	int n,c,suma1;
	int vec[5]={};

  //a) Leer el archivo enteros.dat
  //Abro el archivo enteros.dat en modo lectura
  archivo = fopen ("enteros.dat","rb");        //Abro el archivo para lectura
  if(archivo == NULL){                         //Chequea si el archivo es accesible, de lo contrario sale
    perror("Error al abrir el archivo para leer \n"); 
    return(-1);
  }

  //Leo el archivo
  c = fread(&vec,sizeof(int),5,archivo);
  if (c != 5){                                    //Si hay un error de lectura, lo informa y sale
	  perror("Error al leer \n"); 
    return(-2); 
	}

  //Cierro el archivo
  c = fclose(archivo);
  if (c !=0){                                     //Si hay un error al cerrar, lo informa y sale
    perror("Error al cerrar archivo\n"); 
    return (-3); 	
  }

  //b) Llamar a la función int suma (int vec[ ], int n)
  suma1=suma(vec,5);
  //c) Informar el resultado de la suma de todos los números.
	printf("\nLa suma total es %i.",suma1);
	return 0;
}


//Función suma
int suma(int vec[],int n){
	int i,suma=0;
	for(i=0;i<n;i++){
    //Imprimo los numeros del vector
    printf("%i ",vec[i]);
		suma+=vec[i];
	}
	return suma;
}