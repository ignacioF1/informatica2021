//2do Parcial
//Alumno:

//2021.11.20 Corrección profe
// stdlib no se usa y en promedio, utilizar float

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaro funciones
int Cant_dias_disponible(int Matriz[][31], int dia_inicio, int dia_fin);
int Dia_mas_pasajeros(int Matriz[][31], int dia_inicio, int dia_fin);
int hubo_servicio(int Matriz[][31], int empresa, int dia);
void Mostrar_Pasajeros(int Matriz[][31], int desde, int hasta, int empresa);
void promedio_empresa_dia(int M[][31], int empresa);

//Declaro punteros a los archivos
FILE *lanchas, *prom;

//Declaramos variables
int c, dia_inicio, dia_fin, dias, mayor, empresa, flag;

int main(){
    
    //A. Abra el archivo LanchasMarzo2020.dat y ponga disponibles en una matriz M_lanchas .
    int M_lanchas[6][31];

    //Abro el archivo LanchasMarzo2020.dat en modo lectura
    lanchas = fopen ("LanchasMarzo2020.dat", "rb");     //Abro el archivo para lectura
    if(lanchas == NULL){                                //Chequea si el archivo es accesible, de lo contrario sale
        perror("Error al abrir el archivo para leer \n"); 
        return(-1);
    }
    //Leo el archivo
    c = fread(&M_lanchas,sizeof(M_lanchas),1,lanchas);
    if (c != 1){                                        //Si hay un error de lectura, lo informa y sale
	   perror("Error al leer \n"); 
       return(-2); 
	}
    //Cierro el archivo
    c = fclose(lanchas);
    if (c !=0){                                         //Si hay un error al cerrar, lo informa y sale
        perror("Error al cerrar archivo\n"); 
        return (-3); 	
    }

    //Muestro un menú que se repetirá hasta que el usuario ingrese la opción 6 para salir
    int i = 0;  //Inicializamos i en 0, para utilizarlo para las opciones del menú
    do{
        printf("\nIngrese el numero de opcion deseada:\n1-Cantidad de dias que hubo servicio durante un rango de dias\n2-Dia con mas pasajeros\n3-Hubo Servicio\n4-Mostrar Pasajeros de empresa\n5-Promedio de pasajeros diarios por una empresa\n6-Terminar\n");
        scanf("%i",&i);
        switch(i){
            case 1:
                printf("Indique el primer dia\n"); //
                scanf("%i", &dia_inicio);
                printf("Indique el dia final\n");
                scanf("%i", &dia_fin);
                dias = Cant_dias_disponible(M_lanchas, dia_inicio, dia_fin);   //Llamo a la función
                printf("Dias con servicio: %i\n", dias);
                break;
            case 2:
                printf("Indique el primer dia\n"); //
                scanf("%i", &dia_inicio);
                printf("Indique el dia final\n");
                scanf("%i", &dia_fin);
                dias = Dia_mas_pasajeros(M_lanchas, dia_inicio, dia_fin);
                printf("Dia con mas pasajeros: %i\n", dias+1);
                printf("Cantidad de pasajeros: %i\n", mayor);
                break;
            case 3:
                printf("Indique el numero de empresa (1-6)\n"); //
                scanf("%i", &empresa);
                printf("Indique el dia\n");
                scanf("%i", &dias);
                flag = hubo_servicio(M_lanchas, empresa, dias);
                if(flag == 1){
                    printf("Hubo servicio\n");
                }else{
                    printf("No hubo servicio\n");
                }
                break;
            case 4:
                printf("Indique el numero de empresa (1-6)\n"); //
                scanf("%i", &empresa);
                printf("Indique el primer dia\n");
                scanf("%i", &dia_inicio);
                printf("Indique el dia final\n");
                scanf("%i", &dia_fin);
                Mostrar_Pasajeros(M_lanchas, dia_inicio, dia_fin, empresa);
                break;
            case 5:
                printf("Indique el numero de empresa (1-6)\n"); //
                scanf("%i", &empresa);
                promedio_empresa_dia(M_lanchas, empresa);
                break;
            case 6:
                printf("-> Terminar\n");    //La opción 6 sale
                break;
            default:
                printf("Ingrese una opcion entre 1 y 6\n");
                break;
            }
    }while(i != 6); //Si la opción ingresada es 6 no vuelve a mostrar el menú

    //Devuelvo 0 si la función principal finalizó correctamente
    return 0;
}

//Función para contabilizar los días con servicio
int Cant_dias_disponible(int Matriz[][31], int dia_inicio, int dia_fin){
    int dias = 0;
    for(int i=0; i<6 ; i++){
        for(int j=dia_inicio-1; j<=dia_fin-1 ; j++){
            if(Matriz[i][j] >= 0){
                dias ++;
            }
        };
    }
    return dias;
}

//Función para obtener el día con más pasajeros
int Dia_mas_pasajeros (int Matriz[][31], int dia_inicio, int dia_fin){
    int dia = 0;
    mayor = 0;
    for(int i=0; i<6 ; i++){
        for(int j=dia_inicio-1; j<=dia_fin-1 ; j++){
            if(Matriz[i][j] > mayor){
                mayor = Matriz[i][j];
                dia = j;
            }
        };
    }
    return dia;
}

//Función para obtener el estado del servicio para una empresa un día
int hubo_servicio (int Matriz[][31], int empresa, int dias){
    int flag = 0;
    if(Matriz[empresa-1][dias-1] >= 0){
        flag = 1;
    }
    return flag;
}

//Función para mostrar la cantidad de pasajeros de cada día en una empresa en un rango de días
void Mostrar_Pasajeros (int Matriz[][31], int dia_inicio, int dia_fin, int empresa){
    int aux;
    for(int j=dia_inicio-1; j<=dia_fin-1 ; j++){
        if(Matriz[empresa-1][j] >= 0){
            printf("Dia %i, pasajeros %i.\n", j+1,Matriz[empresa-1][j]);
        }else{
            printf("Dia %i, sin servicio.\n", j+1);
        }
    }
    return;
}

//Función que calcula el promedio de pasajeros de la empresa ingresada
void promedio_empresa_dia(int M[][31], int empresa){
    int promedio = 0;
    int cant = 0;
    for(int j=0; j<31 ; j++)
    if(M[empresa-1][j] > 0){
        promedio += M[empresa-1][j];
        cant++;
    }
    promedio = promedio / cant;                     //Promedio de los días que hubo pasajeros
    printf("Promedio de pasajeros por dia que hubo 1 o mas pasajeros %i.\n",promedio);

    /* genera el nombre/empresa del archivo*/
    char empresa_str[ 10 ];
    char archivo[ 30 ] = "promedioEmpresa" ;
    sprintf(empresa_str, "%d" ,empresa);
    strcat(archivo,empresa_str);
    strcat(archivo, ".dat" );
    printf( "\n %s \n" ,archivo);
    
    //Abro el archivo en modo escritura
    prom = fopen (archivo, "wb");                   //Abro el archivo para escritura
    if(prom == NULL){                               //Chequea si el archivo es accesible, de lo contrario sale
        perror("Error al abrir el archivo para escribir \n"); 
        return;
    }
    //Escribo el contenido del vector en el archivo
    c = fwrite(&promedio,sizeof(promedio),1,prom);
    if (c != 1){                                    //Si se presenta un error al escribir el archivo, se informa y sale
	      	perror("Error al guardar \n"); 
          	return; 	
	}
    //Cierro el archivo
    c = fclose(prom);
    if (c !=0){                                     //Si hay un error al cerrar, lo informa y sale
        perror("Error al cerrar archivo\n"); 
        return; 	
    }

    return;
}