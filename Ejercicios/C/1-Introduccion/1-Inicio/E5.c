#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Escribir una función que dadas las coordenadas de un vector en R3 y devuelva la norma del mismo.*/

int main(void){
    int x,y,z;
    double total;
    printf("Ingrese las coordenadas de su vector en R3: ");
    scanf("%i%i%i",&x,&y,&z);
    total = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    printf("La norma del vector ingresado es de %lf\n", total);
    return 0;
}