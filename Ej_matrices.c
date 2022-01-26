#include <stdio.h>
#include <stdlib.h>

void mostrarMatriz(int z[][4], int , int);
void traspuesta(int z[][4] , int , int);

int main(){
    int i=0,aleatorio,flag=0,num=0;
    int ma[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};    //Matriz de 3x4

    //Muestro la matriz
    mostrarMatriz(ma,3,4);

    //Convierto a la traspuesta
    traspuesta(ma,3,4);

    //Muestro la matriz
    mostrarMatriz(ma,4,3);

    return 0;
}


//Función para imprimir la matriz en pantalla
void mostrarMatriz(int z[][4] , int fila , int columna){
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

//Función que hace la traspuesta de una matriz
void traspuesta(int z[][4] , int fila , int columna){
    int x[fila][columna];
    for(int i=0; i<fila ; i++){
        for(int j=0; j<columna ; j++){
            //Copio la matriz
            x[i][j]=z[i][j];
        }
    }
    //Hago la traspuesta
    for(int i=0; i<fila ; i++){
        for(int j=0; j<columna ; j++){
            z[j][i]=x[i][j];
        }
    }
    return;
}