#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba 2 vectores y sus longitudes, y copie el contenido de uno en el otro, usando el 
siguiente prototipo y notación de punteros en la implementación, la función debe devolver true de poder realizar la 
operación false en caso contrario*/

bool veccpy(double *dest, size_t ldest, const double *orig, size_t lorig){
    if(ldest < lorig){
        return false;
    }
    else{
        for(int i = 0; i < lorig; i++){
            dest[i] = orig[i];
        }
        return true;
    }
}

int main(void){
    double v1[5] = {1,2,3,4,5};
    double v2[5] = {0,0,0,0,0};
    veccpy(v2, 5, v1, 5);
    for(int i = 0; i < 5; i++){
        printf("%lf ", v2[i]);
    }
    puts("");
    return 0;
}