#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Escriba un programa que lea una cadena de caracteres y verifique si la misma se encuentra vacía.*/

bool full_or_empty(char *c){
    if (c[0] == '\0'){
        return true;
    }
    else{
        return false;
    }
}
int main(void){
    char r[4];
    if (full_or_empty(r) == true){
        printf("La cadena esta vacia\n");
    }
    else{
        printf("La cadena no esta vacia\n");
    }
    return EXIT_SUCCESS;
}