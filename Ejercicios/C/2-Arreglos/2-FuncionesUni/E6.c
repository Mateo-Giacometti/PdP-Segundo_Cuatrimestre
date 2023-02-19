#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar una función que reciba un vector, su longitud, un número objetivo a buscar y retorne la posición en la que se encuentra.*/

int busqueda_lineal(const int v[], size_t n, int objetivo){
    for (size_t i = 0; i < n; i++){
        if (v[i] == objetivo){
            return i;
        }
    }
    return -1;
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int objetivo = 5;
    int posicion = busqueda_lineal(v, 10, objetivo);
    printf("El objetivo %d se encuentra en la posicion %d\n", objetivo, posicion);
    return EXIT_SUCCESS;
}