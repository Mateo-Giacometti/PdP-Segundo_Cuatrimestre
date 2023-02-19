#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>

/*Escribir una función que convierta un valor en grados Fahrenheit a grados Celsius.
Escribir una función que convierta un valor en grados Celsius a grados Fahrenheit.*/

float FaC(float c_temp){
    return (9.0f/5.0f) * c_temp + 32;
}

float CaF(float f_temp){
    return(f_temp - 32) * (9.0/5.0);
}

int main(void){

    float c_temp;

    printf("5 grados Celsius son %.2f\n", FaC(5));
    printf("10 grados Celsius son %.2f\n", FaC(10));
    printf("15 grados F son %.2f\n\n", CaF(15));

    printf("| ** C ** | ** F ** |\n");
    printf("| ------: | ------: |\n");
    for (c_temp = 0; c_temp <= 100; c_temp += 10.0f){
        printf("| %7.2f | %7.2f |\n", c_temp, FaC(c_temp));
    }
    return EXIT_SUCCESS;
}