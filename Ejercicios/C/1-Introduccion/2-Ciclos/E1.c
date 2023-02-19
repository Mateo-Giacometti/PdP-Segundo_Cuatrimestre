#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir un programa que imprima la tabla de multiplicar del número 7.*/

int main(void){
    for(int i = 0; i<11; i++){
        printf("%i\n", i*7);
    }
    return 0;
}
