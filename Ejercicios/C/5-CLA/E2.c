#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escriba un programa que reciba una cadena de caracteres e imprima su longitud, à la strlen()*/

int main(int argc, char* argv[]){
    for(int i = 1; i < argc; i++){
        int j = 0;
        while(argv[i][j] != '\0'){
            j++;
        }
        printf("%d\n", j);
    }
}