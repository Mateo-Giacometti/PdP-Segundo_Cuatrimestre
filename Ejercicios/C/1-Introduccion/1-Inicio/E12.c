#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir un programa que imprima, en 3 líneas separadas, su nombre, apellido y legajo.*/

int main(void){
    char nom[20];
    char ap[20];
    int legajo;
    printf("Ingrese su nombre: ");
    scanf("%s",nom);
    printf("Ingrese su apellido: ");
    scanf("%s",ap);
    printf("Ingrese su numero de legajo: ");
    scanf("%i",&legajo);
    printf("Nombre: %s\nApellido: %s\nLegajo: %i\n",nom, ap, legajo);
    return 0;
}