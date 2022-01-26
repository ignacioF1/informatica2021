#include <stdio.h>
int main(){
int a = 23;
int b = 3;
float c = 0;
c = (float) a/b;
printf("Resultado float: %f\n", c);
printf("Resultado float con 4 enteros y 3 decimales: %4.3f", c);
}