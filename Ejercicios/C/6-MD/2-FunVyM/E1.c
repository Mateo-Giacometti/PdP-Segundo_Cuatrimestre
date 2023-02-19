#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <time.h>
#include <string.h>

/*Implementar una función que reciba el inicio de un intervalo, el final y la cantidad de puntos y 
retorne un arreglo de números linealmente espaciados entre el inicio y el final.*/

double * linspace(double inicio, double fin, size_t nelems){
    double * arreglo = malloc(nelems * sizeof(double));
    double paso = (fin - inicio) / (nelems - 1);
    for (size_t i = 0; i < nelems; i++){
        arreglo[i] = inicio + paso * i;
    }
    return arreglo;
}

bool linspace2(double inicio, double fin, size_t nelemes, double **valores){
    *valores = (double *)malloc(nelemes * sizeof(double));
    if(valores == NULL){
        return false;
    }
    double paso = (fin - inicio) / (nelemes - 1);
    for (size_t i = 0; i < nelemes; i++){
        (*valores)[i] = inicio + paso * i;
    }
    return true;
}

int main(void){
    double * arreglo = linspace(0, 5, 5);
    double *arreglito; 
    for (size_t i = 0; i < 5; i++){
        printf("%f ", arreglo[i]);
    }
    puts("");

    linspace2(0, 5, 5, &arreglito);

    for (size_t i = 0; i < 5; i++){
        printf("%f ", arreglito[i]);
    }
    puts("");
    
    free(arreglito);
    free(arreglo);
    return 0;
}