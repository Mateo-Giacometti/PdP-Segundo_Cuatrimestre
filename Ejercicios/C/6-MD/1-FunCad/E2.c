#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar 2 funciones equivalentes a las 2 funciones del punto anterior, pero en lugar de copiar una cadena, copian un arreglo de números*/

int *copia(int *enteros){
    int n = sizeof(enteros)/sizeof(enteros[0]);
    int *copia = (int *)malloc(n * sizeof(int));
    if(copia == NULL){
        return NULL;
    }
    for(int i = 0; i < 10; i++){
        copia[i] = enteros[i];
    }
    return copia;
}

bool copia2(int *enteros, int **copia){
    int n = sizeof(enteros)/sizeof(enteros[0]);
    int *copia2 = (int *)malloc(sizeof(int)*n);
    if(copia2 == NULL){
        return false;
    }
    for(int i = 0; i < n; i++){
        copia2[i] = enteros[i];
    }
    *copia = copia2;
    return true;
}

int main(void){
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *cop;
    int *copy = copia(i);
    for(int i = 0; i < 10; i++){
        printf("%i\n", copy[i]);
    }

    if(copia2(i, &cop)){
        for(int i = 0; i < 10; i++){
            printf("%i\n", cop[i]);
        }
    }

    free(cop);
    free(copy);
    return EXIT_SUCCESS;
}