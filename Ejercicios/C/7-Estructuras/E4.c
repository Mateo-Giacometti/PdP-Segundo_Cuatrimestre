#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "status_t.h"

/*
Volvamos sobre nuestros pasos y rehagamos los menúes.

Definir una estructura que contenga un valor que el usuario tenga que ingresar (puede ser entero, enum, char, cadena) y una cadena 
con lo que se debe mostrar como mensaje para la opción.

Implementar una función que reciba un vector con estructuras e imprima un menú.

Como variante del inciso anterior, la función puede imprimir el menú, leer lo que se ingresa y retornar la opción seleccionada.

¿Cómo se debe definir la estructura para poder utilizarla de la siguiente manera?

*/


typedef struct{
    char *mensaje;
    int valor;
}menu_t;

status_t imprimir_menu(menu_t *menu, size_t n){
    if(menu == NULL){
        return ST_ERR_NULL_PTR;
    } 
    for(size_t i = 0; i < n; i++){
        printf("%d) %s \n", menu[i].valor, menu[i].mensaje);
    }   
    return ST_OK;
}

status_t leer_opcion(menu_t *menu, size_t n, int *opcion){
    if((menu == NULL) || (opcion == NULL)){
        return ST_ERR_NULL_PTR;
    }
    int op;
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
    for(size_t i = 0; i < n; i++){
        if(op == menu[i].valor){
            *opcion = op;
            return ST_OK;
        }
    }
    return ST_ERR_INVALID_ARG;
}       

int main(void){
    menu_t menu[] = {
        {"Opcion 1", 1},
        {"Opcion 2", 2},
        {"Opcion 3", 3},
        {"Opcion 4", 4},
        {"Opcion 5", 5},
        {"Opcion 6", 6},
        {"Opcion 7", 7},
        {"Opcion 8", 8},
        {"Opcion 9", 9},
        {"Opcion 10", 10},
    };
    int opcion;
    imprimir_menu(menu, 10);
    leer_opcion(menu, 10, &opcion);
    printf("La opcion seleccionada es: %d\n", opcion);
    return EXIT_SUCCESS;
}
