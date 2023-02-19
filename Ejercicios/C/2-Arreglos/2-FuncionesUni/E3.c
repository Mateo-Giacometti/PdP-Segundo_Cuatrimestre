#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba 2 vectores y sus longitudes, y retorne un valor booleano indicando si los vectores son iguales.*/

bool iguales(int v1[], size_t lv1, int v2[], size_t lv2){
    if(lv1 == lv2){
    for(int i = 0; i < lv1; i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
    }
    else{
        return false;
    }
}
int main(void){
    int orig[10] = {1,2,3,4,5,6,7,8,9,10};
    int dest[10] = {1,2,3,4,5,6,7,8,9,10};
    if(iguales(dest, 10, orig, 10) == true){
        puts("Son iguales");
    }
    return EXIT_SUCCESS;
}