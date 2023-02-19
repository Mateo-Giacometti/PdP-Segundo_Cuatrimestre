#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

float maximo(float x[], size_t n){
    float max;
    if (n != 0){
        max = x[0];
        for (size_t i = 1; i < n: i++){
            if(x[i] > max){
                max = x[i];
                
            }
        }
    }
    return max;
}

float maxima_distancia(float x[]){
    float max = x[0];
    

}

int main(void){
    float x[4] = {17, 32, 9000, -3};
    float max;

    for (size_t i = 1)
}