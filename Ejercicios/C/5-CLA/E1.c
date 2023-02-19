#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escriba un programa que imprima por pantalla todos los argumentos recibidos, uno por línea.*/

int main(int argc, char* argv[]){
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    return EXIT_SUCCESS;
}