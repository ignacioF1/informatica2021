#include <stdio.h>
#include <math.h>
// Grupo 3 - Integrantes:
// Este programa indica si el número entero mayor a 1 ingresado es primo.
int main(){
int n,r,i,mod;
// Solicito ingresar un número entero y continúo solicitándolo si dicho número es menor a 2
do{
    printf("Ingrese un numero entero mayor a 1 para saber si es un numero primo\n");
    scanf("%i",&n);
}while(n<2);
// Obtengo la raíz cuadrada del número ingresado
r = sqrt(n);
// Este algoritmo se basa en analizar el resto del cociente del número ingresado (n) y los números desde
// 2 hasta la raíz cuadrada del mismo (r). El ciclo do-while finaliza si el resto (mod) es 0 o si se
// analizaron todos los números.
i = 2;
do{
    mod = n % i;
    i++;
}while(mod != 0 && i <= r);
// Si luego de completar el ciclo, no se encontró ningún divisor que deje el resto (mod) en 0
// ó si el número ingresado es 2 ó 3, entonces el número es primo, de lo contrario no lo es.
if(mod != 0 || n < 4){
    printf("El numero ingresado es primo\n");
}else{
    printf("El numero ingresado NO es primo\n");
}
return 0;
}