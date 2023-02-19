#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba un vector, su longitud, un número objetivo a buscar y retorne un puntero a la posición en la que 
se encuentra. ¿Qué ocurre en caso que el objetivo no se encuentre y qué se retorna?*/

const int * busqueda_lineal(const int *v, size_t n, int objetivo){
    for (size_t i = 0; i < n; i++){
        if (v[i] == objetivo){
            return &v[i];
        }
    }
    return NULL;
}

bool busqueda_lineal2(int *v, size_t n, int objetivo, int **resultado){
    for(size_t i = 0; i < n; i++){
        if (v[i] == objetivo){
            *resultado = &v[i];
            return true;
        }
    }
    return false;
}

int main(void){

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int objetivo = 5;
    int *resultado;
    const int *p = busqueda_lineal(v, 10, objetivo);
    if (p == NULL){
        printf("No se encontro el objetivo %d en el vector v \n", objetivo);
    }
    else{
        printf("Se encontro el objetivo %d en el vector v en la posicion %ld\n", objetivo, p - v);
    }
    if(busqueda_lineal2(v, 10, objetivo, &resultado)){
        printf("Se encontro el objetivo %d en el vector v en la posicion %ld\n", objetivo, resultado - v);
    }

    return EXIT_SUCCESS;
}