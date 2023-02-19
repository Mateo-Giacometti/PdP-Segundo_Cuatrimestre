#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba un vector, su longitud y retorne true si el mismo se encuentra ordenado, false en caso contrario. 
De las múltiples maneras que existen para retornar un valor booleano, elija una y justifique la respuesta.*/

bool orden(int v[], size_t longitud){
    for(int i = 0; i < longitud; i++){
        if(v[i+1] < v[i]){
            return false;
        }
    }
    return true;
}

int main(void){
    int v1[5] = {1,4,5,3,9};
    int v2[5] = {1,2,3,4,5};
    if(orden(v1,5) == false){
        puts("Desordenado");
    }
    if(orden(v2,5) == true){
      puts("Ordenado");  
    }
    return EXIT_SUCCESS;
}