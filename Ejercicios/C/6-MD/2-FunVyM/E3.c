#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar una función similar a la del ejercicio anterior, pero en lugar de retornar un nuevo vector, modifica 
el primero pegándole el segundo.*/ 

void concatenar(int **copia, int *v1, size_t l1){
    *copia = (int *)malloc(sizeof(int) * l1);
    if(copia != NULL){
        for(int i = 0; i < l1; i++){
        (*copia)[i] = v1[i];
        }
    }
}

int main(void){
    int *copia;
    int v[6] = {1,2,3,4,5,6};
    concatenar(&copia, v, 6);
    for(int i = 0; i < 6; i++){
        printf("%i", copia[i]);
    }
    puts("");

    free(copia);
    
    return EXIT_SUCCESS;
}