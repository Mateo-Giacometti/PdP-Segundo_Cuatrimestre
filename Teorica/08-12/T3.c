#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include "my_math.h"

float fsuma(float, float); // Nombre --> Prototipo 

int main(void){
    float a;
    float b;
    float r;
    float s;
    float x1;
    float x2;
    float y1;
    float y2;

    printf("Ingresa (a,b): ");
    scanf("(%f %f)", &a, &b);
    
    r = fsuma(a,b);

    printf("El resultado de fsuma(%f,%f) es %f\n", a, b, r); 

    printf("Ingrese x1, y1, x2, y2: ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    s = distancia(x1, y1, x2, y2);

    printf("El resultado de la funcion distancia es: %f\n",s);

    return EXIT_SUCCESS;
}

// Necesariamente hay que compilarlo asi
/* 
gcc T3.c -o T3.o -c
gcc my_math.c -o my_math.o -c
gcc T3.o my_math.o -o Tfinal
*/