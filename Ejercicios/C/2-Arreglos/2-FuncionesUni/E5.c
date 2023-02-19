#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba un vector, su longitud, un número objetivo a buscar y retorne un valor booleando indicando 
si el mismo se encuentra o no.*/

bool find_the_number(int v[], size_t lv, int number){
    for(int i = 0; i < lv; i++){
        if(v[i] == number){
            return true;
        } 
    }
    return false;
}

int main(void){
    int vector[5] = {1,2,3,4,5};
    
    if(find_the_number(vector,5,10) == false){
        puts("El 10 no esta");
    }
    if(find_the_number(vector,5,3) == true){
        puts("El 3 si esta");
    }

    return EXIT_SUCCESS;
}