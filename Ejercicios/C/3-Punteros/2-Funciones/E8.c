#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implemente una función similar de búsqueda, utilizando búsqueda binaria.*/

const int * busqueda_binaria(const int *v, size_t n, int objetivo, size_t izq, size_t der){
    
    if(izq > der){
        return NULL;
    }
    
    size_t medio = (izq + der) / 2;
    
    if(v[medio] == objetivo){
        return &v[medio];
    }
    
    if(v[medio] < objetivo){  
        return busqueda_binaria(v, n, objetivo, medio + 1, der);
    }

    if(v[medio] > objetivo){
        return busqueda_binaria(v, n, objetivo, izq, medio - 1);
    }
}

int main(){
    
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(v) / sizeof(v[0]); 
    int objetivo;

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &objetivo);
    
    const int *resultado = busqueda_binaria(v, n, objetivo, 0, n - 1);
    
    if(resultado == NULL){
        printf("No se encontro el elemento %d en el vector\n", objetivo); 
    }else{
        printf("Se encontro el elemento %d en el vector en la posicion %ld\n", objetivo, resultado - v); 
    }

    return EXIT_SUCCESS;
}