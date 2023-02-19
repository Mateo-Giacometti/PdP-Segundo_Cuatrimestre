#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar una función que reciba una cadena de caracteres y un carácter. 
La función retorna una copia de la cadena, pero elimina todo lo que esté después del carácter recibido. Utilizar memoria dinámica.*/

char *delete_caracter(char *cadena, char caracter){
    int final = 0;
    char *copy = (char *)(malloc((strlen(cadena)+1) * sizeof(char)));
    while(cadena[final] != caracter){
        copy[final] = cadena[final];
        final++;
    }
    copy[final] = '\0';
    return copy;
}

int main(void){
    char cadena[100];
    char caracter = 'a';
    char *new_cadena;

    printf("Ingrese una cadena: ");
    fgets(cadena, 100, stdin);
    
    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);
    
    new_cadena = delete_caracter(cadena, caracter);
    printf("%s\n", new_cadena);

    return EXIT_SUCCESS;
}