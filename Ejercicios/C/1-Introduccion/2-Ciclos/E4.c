#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir un programa que imprima por pantalla todas las fichas del dominó, sin repetir.*/

int main(void){
    for(int a = 0; a < 7; a++){
        for(int b = 0; b < 7; b++){
            printf("Ficha (%i - %i)\n", a,b);
        }
    }
    return 0;
}