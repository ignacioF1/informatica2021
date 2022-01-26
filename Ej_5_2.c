//5.2. Ingresar 10 números reales de doble precisión y almacenarlos en el archivo reales.dat. Verificar que el
//archivo contiene 80 bytes.

#include<stdio.h>
#include<stdlib.h>

int main(void){  
int c,i;
double vector[10], lector[10];
FILE* archivo; //Creo puntero al archivo

//Creo un archivo para escribir
archivo=fopen("reales.dat","w");
if(archivo==NULL){
    perror("Error al abrir el archivo");
    return(-1);
}

//Solicito 10 num reales
//Al mismo tiempo voy guardando de a uno en el archivo
printf("Ingrese 10 numeros reales\n");
for(i=0;i<10;i++){
  scanf("%lf",&vector[i]);
  c=fwrite(&vector[i],sizeof(double),1,archivo);
  if(c!=1){
    perror("Error al guardar el archivo");
    return(-2);
  }
}

//Cierro el archivo
c=fclose(archivo);
if (c!=0){ 
  perror("Error al cerrar archivo\n"); 
  return (-3); 	
}

//Abro el archivo en modo lectura
archivo=fopen("reales.dat","r");
if(archivo == NULL){
  perror("Error al abrir el archivo");
  return(-1);
}

//Leo el archivo
c=fread(&lector,sizeof(lector),1,archivo);
if (c!=1){ 
    perror("Error al leer archivo\n"); 
    return (-3); 	
}

//Imprimo el vector leído
printf("Numeros leidos: ");
for(i=0;i<10;i++){
  printf("%lf ", lector[i]);
}

//Cierro el archivo
c=fclose(archivo);
if (c!=0){ 
  perror("Error al cerrar archivo\n"); 
  return (-3); 	
}

return 0;  
}