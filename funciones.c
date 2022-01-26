#include <stdio.h>

//Declaración de la fucnión o función prototipo
int sumo(int , int);
void swap(int *a1 , int *b1);
void function(int arr[]);

int main(){
int a = 3;
int b = 2;
int c = 0;
int arr[4]={0,1,2,3};
//Llamada por valores, paso los valores, que se copian en otras variables locales a la función en cuestión
c = sumo(a,b);  //a , b -> parámetros actuales o reales
printf("a=%d + b=%d = c=%d\n", a,b,c);

swap(&a,&b);    //Llamada por referencia, paso direcciones de a y b
printf("a=%d + b=%d = c=%d\n", a,b,c);

//Los vectores siempre pasan por referencia
printf("Primer valor de arr=%d\n",arr[0]);
function(arr);
printf("Primer valor de arr=%d\n",arr[0]);
return 0;
}

int sumo(int var1 , int var2){
    //suma, var1 y var2 -> variables locales a sumo
    //var1, var2 -> parámetros formales
    int suma = var1 + var2;
    return suma;
}

void swap(int *a1 , int *b1){    //Cambio el contenido de las variables a donde apuntan los punteros
    int tmp;
    tmp = *a1;
    *a1 = *b1;
    *b1 = tmp;
}

void function(int arr[]){
    arr[0] = arr[3];
}