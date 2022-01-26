#include <stdio.h>
/*Dadas dos variables numéricas A y B, que el usuario debe teclear, se pide realizar un algoritmo que intercambie los valores de ambas variables y muestre cuanto valen al final las dos variables.*/
int main(){
    int A;
    int B;
    int C;
    printf("Bienvenido, este programa intercambia las variables numericas A y B, ingrese la variable A: \n");
    scanf("%i", &A);
    printf("Ingrese la variable B: \n");
    scanf("%i", &B);
    C = A;
    A = B;
    B = C;
    printf("La nueva variable A es: %i y la nueva variable B es: %i", A,B);
    return 0;
}