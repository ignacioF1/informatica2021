#include <stdio.h>

int main() { 
    int n, e, op, edadC=0,edadA=0,res,caba=0,amba=0; 
    char sexo[1];
    n = 0; 

    do {
        n = n + 1; 
        printf("Edad del conductor\n"); 
        scanf("%d", &e); 
        printf("Sexo de conductor F= femenino, M= masculino\n"); 
        scanf("%s", sexo); // sin & porque es string
        printf("1- CABA\n2- AMBA\n3- Salir\n"); 
        scanf("%d", &op);
        switch(op){
        case 1: caba++; 
				edadC += e;
				break;
        case 2: amba++; 
				edadA += e;
				break;
        default: break;
           
        }
        printf("Desea ingresar otro usuario? 1 si o 0 No?\n");
        scanf("%d", &res);
    } while (res != 0);
    // Mostrar el promedio de edades para cada region
    // Antes de hacer el promedio consultamos si las cantidades de conductores son mayores a 0
    // CABA
    if(caba>0){
        printf("El promedio de edades para CABA es de: %i\n",(edadC/caba));
    }else{
        printf("No se han ingresado conductores de CABA\n");
    }

    // AMBA
    if(amba>0){
        printf("El promedio de edades para AMBA es de: %i\n",(edadA/amba));
    }else{
        printf("No se han ingresado conductores de AMBA\n");
    }

    return 0;
}