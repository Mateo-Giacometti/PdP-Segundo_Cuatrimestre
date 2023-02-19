#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implemente una función similar de búsqueda, utilizando búsqueda binaria. Un posible prototipo*/

int busqueda_binaria(const int v[], size_t n, int objetivo){
    int izq = 0;
    int der = n - 1;
    int medio;
    
    while (izq <= der) {
        medio = (izq + der) / 2;
        if (v[medio] == objetivo) {
            return medio;
        } 
        else if (v[medio] < objetivo) {
            izq = medio + 1;
        } 
        else {
            der = medio - 1;
        }
    }
    return -1;
}

int main(void){
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(v) / sizeof(v[0]);
    int objetivo;
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &objetivo);
    int resultado = busqueda_binaria(v, n, objetivo);
    if (resultado != -1) {
        printf("El numero %d se encuentra en la posicion %d del arreglo v\n", objetivo, resultado);
    } 
    else {
        printf("El elemento %d no se encuentra en el arreglo v\n", objetivo);
    }
    return 0;
}