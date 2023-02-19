#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implemente una función que reciba una cadena y la invierta*/

char * invertir(char *c){
    int i = 0;
    int j = strlen(c) - 1;
    while(i < j){
        char aux = c[i];
        c[i] = c[j];
        c[j] = aux;
        i++;
        j--;
    }
    return c;
}

int main(void){
    char c[100];
    printf("Ingrese una cadena: ");
    scanf("%s", c);
    printf("La cadena invertida es: %s\n", invertir(c));
    return EXIT_SUCCESS;
}