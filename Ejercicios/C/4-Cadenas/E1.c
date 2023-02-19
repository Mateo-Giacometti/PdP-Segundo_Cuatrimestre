#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Escriba un programa que lea una cadena de caracteres ingresada por el flujo de entrada estándar y la imprima por pantalla.
Almacena la cadena en un arreglo de no más de 100 caracteres. Utilice los siguientes métodos:
- Itere hasta leer el carácter '\n' inclusive,
- Lea utilizando fgets().
*/

int main(void){
    char m[30];
    printf("Mensaje: ");
    fgets(m, 30, stdin);
    printf("%s", m);
    return 0;
}