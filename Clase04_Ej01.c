#include <stdio.h>
#include <math.h>
//Grupo 3 - Integrantes:
/*
Este programa realiza lo siguiente:
Mostrar los números del 1 al 20.
Mostrar los cuadrados de los números del 1 al 20.
Mostrar los cubos de los números del 1 al 20.
*/
int main(){
    // Declaro la variable de tipo entero op para almacenar la opción ingresada
    int op;
    // Pido ingresar un número de opción entre 1 y 3
    // Mientras que el número no esté entre 1 y 3, lo vuelvo a pedir
    do{
    printf ("1- Muestra los numeros del 1 al 20 \n2- Muestra los cuadrados de los numeros del 1 al 20 \n3- Muestra los cubos de los numeros del 1 al 20 \nIngrese una opcion entre 1 y 3 \n");
    scanf("%i",&op);
    }while(op<1 || op>3);

    printf("Los numeros son:\n");
    // Genero los números del 1 al 20
    for(int i=1 ; i<21 ; i++){
        // Imprimo cada número, o su cuadrado o su cubo, según la elección del usuario
        // Utilizo la función pow() de la librería math.h para elevar un número a una potencia
        // La función pow() no genera un entero, por lo que le hacemos un CAST a int para mostrarlo
        printf("%i ", (int)(pow (i,op)));
    }
    return 0;
}