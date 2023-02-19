#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>

/*Escribir una función que dada una dimensión imprima la matriz identidad de esa dimensión.*/

void identidad(size_t n){// size_t es un entero para almacenar tamaños 
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            if (i == j){
                putchar('1');
            }
            else {
                putchar('0');
            }
        }
        putchar('\n');
    }
}

int main(void){
    puts("id 3x3");
    identidad(3);
    puts("\nid 2x2");
    identidad(2);
    puts("\nid 1x1");
    identidad(1);
    puts("\nid 0x0");
    identidad(0);
    return EXIT_SUCCESS;
}