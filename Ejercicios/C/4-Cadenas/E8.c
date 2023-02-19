#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implemente una función que reciba una cadena y retorne un booleano indicando si la misma es palíndroma o no.*/

bool es_palindromo(char *c){
    int i = 0;
    int j = strlen(c) - 1;
    while(i < j){
        if(c[i] != c[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(void){
    char c[100];
    printf("Ingrese una cadena: ");
    scanf("%s", c);
    if(es_palindromo(c)){
        printf("La cadena es palindromo :)\n");
    }
    else{
        printf("La cadena no es palindromo :(\n");
    }
    return EXIT_SUCCESS;
}