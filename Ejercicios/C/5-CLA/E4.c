#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escriba un programa que reciba como argumentos dos números e imprima el resultado de la operación módulo entre ambos*/

int modulo(int a, int b){
    int modul = a + b;
    if(modul < 0){
        return modul * (-1);
    }
    return modul;
}

int main(int argc, char* argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("Modulo: %i\n", modulo(a,b));
    return EXIT_SUCCESS;
}