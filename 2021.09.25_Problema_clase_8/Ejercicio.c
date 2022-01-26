#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *dat, *prom;					                //Declaro puntero al archivo
	int num, size, c1, c2;                //variables enteras
    float f, vecf[100]={}, promedio;
    int i, j;
    double d;
    char c;
    int fs = sizeof(f);
    printf("%i bytes ocupa un float \n", fs);
    int is = sizeof(i);
    printf("%i bytes ocupa un int \n", is);
    int ds = sizeof(d);
    printf("%i bytes ocupa un double \n", ds);
    int cs = sizeof(c);
    printf("%i byte ocupa un char \n", cs);

    dat = fopen ("datos.dat", "rb");        //Abro el archivo para lectura "read binary"
    if(dat==NULL){                         //Chequea si el archivo es accesible
        perror("Error al abrir el archivo para leer \n"); 
        return(-1);
    }

    /*
    Una forma de leer el tamaño (fuente StackOverflow)
    fseek(dat, 0L, SEEK_END);   //Recorro los datos del archivo leído hasta el final
    size = ftell(dat);        //Almaceno en una variable el tamaño del archivo
    */
    
    size=0;   //Inicializo el tamaño en 0
    do {
        i=fread(&num, 1,1,dat); //Leo el archivo de a un byte
        if (i != 0){
            size++;   //Leyó un byte, auento el tamaño en uno
        }
    }while(i != 0);  //Cuando se lea el último dato, la función fread arrojará 0

    printf("El archivo pesa %i bytes \n", size);

    printf("Si el archivo almacena datos del tipo float contiene %i datos.\n", size/fs);
    printf("Si el archivo almacena datos del tipo int contiene %i datos.\n", size/is);
    printf("Si el archivo almacena datos del tipo double contiene %i datos.\n", size/ds);
    printf("Si el archivo almacena datos del tipo char contiene %i datos.\n", size/cs);

    //1.3 Haga un programa que lea el archivo y muestre los datos
    //Abro el archivo nuevamente para regenerar el puntero dat
    dat = fopen ("datos.dat", "rb");        //Abro el archivo para lectura "read binary"
    if(dat==NULL){                         //Chequea si el archivo es accesible
        perror("Error al abrir el archivo para leer \n"); 
        return(-1);
    }
    printf("Datos leidos:\n");
    do {
        i=fread(&num,sizeof(num),1,dat); //Leo el archivo de a un entero
        if (i != 0){
            printf("%i ", num);   //Leo e imprimo en pantalla
        }
    }while(i != 0);  //Cuando se lea el último dato, la función fread arrojará 0

    //1.4 Haga un programa que lea el archivo, los cargue en un vector float, calcule el promedio y lo guarde
    //en un archivo promedio.dat(deberá tener 4 bytes)
    //Abro el archivo nuevamente para regenerar el puntero dat
    dat = fopen ("datos.dat", "rb");        //Abro el archivo para lectura "read binary"
    if(dat==NULL){                         //Chequea si el archivo es accesible
        perror("Error al abrir el archivo para leer \n"); 
        return(-1);
    }

    j=0;
    do {
        i=fread(&num,sizeof(num),1,dat); //Leo el archivo de a un entero
        if (i != 0){
            vecf[j]=num;
            j++;
            promedio+=num;
        }
    }while(i != 0);        //Cuando se lea el último dato, la función fread arrojará 0
    promedio = promedio/j;
    printf("\nPromedio %f\n", promedio);   //Leo e imprimo en pantalla

    //Cierro el archivo leído
    c1=fclose(dat);     //Devuelve 0 si cerró correctamente
	if (c1 !=0){ 
		perror("Error al cerrar archivo\n"); 
        return (-3); 	
	}

    //Abro un nuevo archivo
    prom=fopen("promedio.dat","wb");        //Abro el arhivo para escritura "write binary"
	if(prom == NULL){                       //Puede ser NULL, chequear
		perror("error al abir el archivo"); //Equivalente a printf pero para errores
		return(-1);
	}

    //Escribo el promedio en el archivo
    c2=fwrite(&promedio,sizeof(promedio),1,prom);
    if (c2 != 1){
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}

    c1=fclose(prom); 
    if (c1 !=0){ 
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }                             //cierra archivo

    return 0;   //Devuelve 0 si todo es correcto (0 errores)
}