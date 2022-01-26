#include <stdio.h>
//Matrices
//m[m][n] (m filas x n columnas)

//Puedo declarar mostrarMatriz(int z[][3], int , int); el primer índice no hace falta
void mostrarMatriz(int z[4][3], int , int);

void cargarMatriz(int z[4][3], int , int);

//Declaro puntero a archivo
FILE *archivo;

int main(){
    //Matriz de 4 por 3 (z[0][0] a z[3][2])
    int z[4][3];
    int valor = 2;

    /*
    //Lleno una matriz con un valor cte.
    for(int m=0; m<4; m++) {
        for (int n=0; n<3; n++){ 
            z[m][n]= valor;
        }
    }
    */

    cargarMatriz(z,4,3);

    mostrarMatriz(z,4,3);

    //Abro el archivo en modo escritura
    archivo = fopen ("datosMat.dat", "wb");        //Abro el archivo para escritura
    if(archivo == NULL){                           //Chequea si el archivo es accesible, de lo contrario sale
        perror("Error al abrir el archivo para escribir \n"); 
        return(-1);
    }

    //Escribo el contenido de la matríz en el archivo
    int c = fwrite(z,sizeof(int),12,archivo);
    if (c!=12){                                    //Si se presenta un error al escribir el archivo, se informa y sale
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}

    //Cierro el archivo
    c = fclose(archivo);
    if (c!=0){                                     //Si hay un error al cerrar, lo informa y sale
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    return 0;
}



//Función que solicita valores para llenar la matriz
void cargarMatriz(int z[4][3] , int fila , int columna){
    for(int m=0; m<fila; m++) {
        for (int n=0; n<columna; n++){
            printf("Ingrese el valor de la posicion (%d,%d)\n",m,n);
            //Solicito valores para llenar la matriz
            scanf("%d",&z[m][n]);
        }
    }
    return;
}


//Función para imprimir la matriz en pantalla
void mostrarMatriz(int z[4][3] , int fila , int columna){
    for(int i=0; i<fila ; i++){
        printf("[");
        for(int j=0; j<columna ; j++){
            printf("%d ",z[i][j]);
        }
        printf("\b]\n");
    }
    printf("\n");
    return;
}