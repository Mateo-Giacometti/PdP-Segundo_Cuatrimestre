#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar una función que reciba dos vectores de números y retorne un nuevo vector con los números de ambos vectores concatenados.*/


int *concatenar(int *v1, int *v2, int l1, int l2){
    int c = 0;
    int n = (l1 + l2);
    int *new_vector = (int *)malloc(n * sizeof(int));
    if (NULL == new_vector){
        return NULL;
    }

    for(int i = 0; i < l1; i++){
        new_vector[i] = v1[i];
    }

    for(int v = l1; v < n; v++){
        new_vector[v] = v2[c];
        c++;
    }

    return new_vector;
}
int main(void){
    int v1[10] = {1,2,3,4,5,6,7,8,9,10};
    int v2[10] = {11,12,13,14,15,16,17,18,19,20};

    int *new_v = concatenar(v1, v2, 10, 10);

    for(int i = 0; i < 20; i++){
        printf("%i", new_v[i]);
    }
    puts("");

    free(new_v);

    return EXIT_SUCCESS;
}


/*
-Liberar la memoria tomada 
void(double **v){
    free(*v);
    *v = NUll;
}
*/