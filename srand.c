#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
int i;
srand(time(0));
for(i=0;i<10;i++)
    printf("%1.3f\n",(float)(rand()%76)/100); //el resto 76 genera entre 0 y 75, 1.3f fija en 3 digitos decimales
    printf("\b\b\n\n");
return 0;
}