/* Grupo 3 - Integrantes: Braian Green, Victoria Maurizi, Ignacio Mendizábal, Máximo Pavón */

// El siguiente programa devuelve un array con los primeros 10 números primos

#include <stdio.h>
#include <math.h>

int main(){
// Inicializo un array de 10 números enteros ( 0 al 9 )
int primos[9];
int n,m,r,i,mod;
m=0;
// Itero generando n números a partir del 2 hasta que m de primos[m] llegue a 9
for(n=2;m<10;n++){
    // Obtengo la raíz cuadrada del número generado
    r = sqrt(n);
    // Este algoritmo se basa en analizar el resto del cociente del número generado (n) y los números desde
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
        // El número n es primo, entonces lo guardo en la posición m del array y aumento m en 1. 
        primos[m] = n;
        m++;
    }
}

// Una vez terminado el ciclo for se completó el array con 10 números, entonces lo muestro en pantalla.
printf("Los primeros 10 numeros primos son:\n");
// Voy mostrando de a un número, separándolos por comas. El último número no lleva coma al final.
for(m=0;m<10;m++){
    if(m!=9){
        printf("%i, ", primos[m]);
    }else{
        printf("%i", primos[m]);
    }
}
return 0;
}