#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*
a- Implementar una función que reciba una cadena y retorne una copia de la misma, utilizando memoria dinámica, por el nombre.
Si por algún motivo no se puede, retornar NULL.

b- Implementar una función equivalente, pero en vez de retornar la copia por el nombre, que lo haga por la interfaz, mientras 
que por el nombre retorna un estado, bool, indicando el resultado de la operación.
*/


char *copia(char *cadena){
    char *copia = (char *)malloc((strlen(cadena)+1) * sizeof(char));
    if(copia == NULL){
        return NULL;
    }
    strcpy(copia, cadena);
    return copia;
}

bool copy(char *cadena, char **copia){
    *copia = (char *) malloc((strlen(cadena)+1) * sizeof(char));
    if(copia == NULL){
        return false;
    }
    strcpy(*copia, cadena);
    return true;
}

int main(void){
    char cadena[100];
    char *new_cadena;
    char *cadenita;

    printf("Ingrese una cadena: ");
    fgets(cadena, 100, stdin);
    
    new_cadena = copia(cadena);
    printf("%s", new_cadena);

    if(copy(cadena, &cadenita)){
        printf("%s", cadenita);
    }

    free(new_cadena);
    free(cadenita);
    return EXIT_SUCCESS;
}