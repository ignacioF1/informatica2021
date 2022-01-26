#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Crear un archivo con 9 numeros distintos entre 1 y 9 no consecutivos,
con ese archivo crear una matriz que tenga los valores.
Ingrese un numero por pantalla, entre 1 y 9 y diga en que fila y
columna esta.
*/

void vectorAmatriz(int z[3][3], int , int, int vector[]);
void mostrarMatriz(int z[][3], int , int);
void consultaFilaCol(int z[][3], int , int, int);

//Declaro puntero a archivo
FILE *archivo;

int main(){
    int i=0,aleatorio,flag=0,num=0;
    int ma[3][3];    //Matriz de 3x3
    int numeros[9]={};
    //Fijamos el punto de comienzo (semilla) para generar números aleatorios para el punto C.4
    srand(time(0));

    while(i<9){
        //Generamos un número aleatorio entre 0 y 8 y le sumamos 1 para obtener un numero del 1 al 9
        aleatorio = (rand()%9)+1;
        //Si es el primero, lo ingresa
        if(i==0){
            numeros[i] = aleatorio;
            i++;
        //Evalúo que no sea consecutivo
        }else if(numeros[i-1] < aleatorio-1 || numeros[i-1] > aleatorio+1){
            //Evalúo que ya no esté en el vector
            for(int j=0;j<i;j++){
               if(numeros[j]==aleatorio){
                flag = 1;
                break;
               } 
            }
            if(flag==0){
                numeros[i] = aleatorio;
                i++;
            }
            flag = 0;
        }
    }

    /*TEST Imprimo el vector*/
    for(i=0;i<9;i++){
        printf("%i ",numeros[i]);
    }
    printf("\n");

    //Abro el archivo matriz.dat en modo escritura
    archivo = fopen ("matriz.dat", "wb");        //Abro el archivo para escritura
    if(archivo == NULL){                            //Chequea si el archivo es accesible, de lo contrario sale
        perror("Error al abrir el archivo para escribir \n"); 
        return(-1);
    }

    //Escribo el contenido del vector en el archivo
    int c = fwrite(&numeros,sizeof(numeros),1,archivo);
    if (c != 1){                                    //Si se presenta un error al escribir el archivo, se informa y sale
	      	perror("Error al guardar \n"); 
          	return (-2); 	
	}

    //Cierro el archivo
    c = fclose(archivo);
    if (c !=0){                                     //Si hay un error al cerrar, lo informa y sale
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    //Convierto el vector en matriz
    vectorAmatriz(ma,3,3,numeros);

    //TEST muestro la matriz
    mostrarMatriz(ma,3,3);

    //Solicito un numero entre 1 y 9
    while(num<1 || num>9){
        printf("Ingrese un numero entre 1 y 9\n");
        scanf("%i",&num);
    }

    //Consulto en que fila y columna está el número
    consultaFilaCol(ma,3,3,num);

    return 0;
}

//Función que convierte de vector a matriz
//0->(0,0) 1->(0,1) 2->(0,2) 3->(1,0) 4->(1,1) 5->(1,2) 6->(2,0) 7->(2,1) 8->(2,2)
void vectorAmatriz(int z[3][3] , int fila , int columna, int vector[]){
    for(int m=0; m<fila; m++) {
        for (int n=0; n<columna; n++){
            z[m][n] = vector[(m*columna)+n];
        }
    }
    return;
}

//Función para imprimir la matriz en pantalla
void mostrarMatriz(int z[][3] , int fila , int columna){
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

//Función que indica en que fila y columna está un número
void consultaFilaCol(int z[][3] , int fila , int columna, int num){
    for(int i=0; i<fila ; i++){
        for(int j=0; j<columna ; j++){
            if(z[i][j]==num){
                printf("El numero se encuentra en la fila %d y columna %d.",i,j);
            }
        }
    }
    printf("\n");
    return;
}