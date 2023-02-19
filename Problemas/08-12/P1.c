#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>

/*Escribir una función que dados dos números x e y imprima:
-x es mayor que y, si x es mayor que y,
-x y y son iguales, si los números son iguales.*/

void comparar(float x, float y){
    if (x > y){
        printf("x es mayor que y\n");
    }else if (x == y){
        printf("x e y son iguales\n");
    }
}

int main(void){
    comparar(1.1, 0.2);
    comparar(1.1, 2.2);
    comparar(1.1, 1.1);
    return EXIT_SUCCESS;
}