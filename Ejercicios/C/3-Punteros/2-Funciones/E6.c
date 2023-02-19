#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba 2 vectores y sus longitudes, y retorne un valor booleano, por la interfaz, si los vectores son iguales*/

bool same_vector(int *v1, size_t n1, int *v2, size_t n2){
    if(n1 != n2){
        return false;
    }
    else{
        for(int i = 0; i < n1; i++){
            if(*(v1 + i) != *(v2 + i)){
                return false;
            }  
        }
        return true;
    }
}

int main(void){
    int v1[5] = {1,2,3,4,5};
    int v2[5] = {5,4,3,2,1};
    int v3[5] = {1,2,3,4,5};
    if(same_vector(v3, 5, v1, 5)){
        puts("Iguales");
    }

}