#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir un programa que imprima la tabla de multiplicar para los números del 1 al 10.*/

int main(void){
    for(int i=1; i<11; i++){
        for(int v=1; v<11; v++){
            printf("%i\n", i*v);
        }
    }
    return 0;
}