#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "status_t.h"

/*
Implementar una función recursiva que retorne la cantidad de dígitos de un número entero.
*/

int dig_r(char* numero){
    if (strlen(numero) == 1){
        return 1;
    }
    else{
        return 1 + dig_r(numero + 1);
    }
}


int main(void){
    char *endptr;
    char numero[100];
    printf("Ingrese un numero: ");
    scanf("%s", numero);
    strtof(numero, &endptr);

    if (*endptr != '\0'){
        printf("No es un numero\n");
        return EXIT_FAILURE;
    }

    printf("La cantidad de digitos es: %d\n", dig_r(numero));

    return EXIT_SUCCESS;
}