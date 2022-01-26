#include <stdio.h>
// Diseña un programa que lea dos números enteros y muestre por pantalla,
// de estos tres mensajes, el que convenga:
// El segundo es el cuadrado exacto del primero.
// El segundo es menor que el cuadrado del primero.
// El segundo es mayor que el cuadrado del primero.
int main(){
int A;
int B;
printf("Bienvenido, este programa analiza la relacion entre los cuadrados de dos enteros\n");
printf("Ingrese el primer entero: ");
scanf("%i",&A);
printf("Ingrese el segundo entero: ");
scanf("%i",&B);
if (B > A*A)
    printf("El segundo es mayor que el cuadrado del primero.");
else
    if (B == A*A)
        printf("El segundo es el cuadrado exacto del primero.");
    else
        printf("El segundo es menor que el cuadrado del primero.");

return 0;
}