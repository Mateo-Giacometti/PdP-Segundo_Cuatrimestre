#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir un programa que imprima la tabla de conversión de Celsius a Fahrenheit para los valores de 0ºC a 100ºC de 10 en 10 con 2 decimales.*/

int main(void){
    for(int C = 0; C < 101; C = C+10){
        printf("%.2lfºC\n", (1.8)*C + 32);
    }
    return 0;  
}