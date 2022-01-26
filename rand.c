#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
int i;
srand(2); // si la semilla es la misma, los números generados son los mismos, por eso se utiliza time dentro de srand
// para generar una semilla respecto de un número que va creciendo con el tiempo.
for(i=0;i<4;i++)
    printf("%d\n",(rand()%11));
printf("\n");
return 0;
}