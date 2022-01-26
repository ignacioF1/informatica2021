#include <stdio.h>
/*Dado un número de dos cifras, dise ne un algoritmo que permita obtener el número invertido. Ejemplo, si se introduce 23 que muestre 32.*/
int main(){
    int num;
    int dec;
    int uni;
    printf("Bienvenido, ingrese un numero de dos cifras \n");
    scanf("%i", &num);
    uni = num/10;
    dec = num-(uni*10);
    num = uni + (dec*10);
    printf("El numero es: %d", num);
    return 0;
}