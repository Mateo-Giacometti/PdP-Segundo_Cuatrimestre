#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Escriba un programa que lea una cadena de caracteres e imprima por pantalla, para cada elemento de la cadena: su posición dentro de 
la cadena, el carácter y su código en representación ASCII. */

int main(void){
    char cadena[100];
    printf("Ingrese la cadena de caracteres: ");
    fgets(cadena, 100, stdin);
    for(int i = 0; i < strlen(cadena); i++){
        printf("% i %c %d\n", i, cadena[i], cadena[i]);
    }
    return 0;
}