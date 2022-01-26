#include <stdio.h>
//Grupo 3 - Integrantes:
/*Realice un programa utilizando switch que ingrese un número entre uno y
tres simulando los lados de un dado. Según sea el número de lado muestre
su opuesto.*/
int main(){
    int n; // Declaro la variable de tipo entero n para almacenar el número ingresado
    int op; // Declaro la variable de tipo entero op para almacenar el número de cara opuesta
    // Pido ingresar un número entre 1 y 3
    // Mientras que el número no esté entre 1 y 3, lo vuelvo a pedir
    do{
    printf("Ingrese un numero entre 1 y 3\n");
    scanf("%i",&n);
    }while(n<1 || n>3);
    // Analizo el número ingresado y modifico el valor de la variable op para cada caso
    switch(n){
        case 1: op=6; break;
        case 2: op=5; break;
        case 3: op=4; break;
        default: break;
    }
    // Muestro en pantalla el número de la cara opuesta
    printf("El lado opuesto de la cara del dado es: %d", op);

    return 0;
}