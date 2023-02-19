#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función que reciba 2 vectores y sus longitudes, y copie el contenido de uno en el otro, usando el siguiente prototipo:

bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig)

*/

bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig){
    if (ldest > lorig){
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
    const double orig[10] = {0,0,0,0,0,0,0,0,0,0};
    double dest[10] = {1,2,3,4,5,6,7,8,9,10};
    veccpy(dest, 10, orig, 10);
    return 0;
}
