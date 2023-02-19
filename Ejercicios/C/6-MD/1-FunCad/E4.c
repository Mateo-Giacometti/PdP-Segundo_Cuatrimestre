#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*
a- Implementar una función que reciba una cadena de caracteres que comienza con espacios y retorna, por 
la interfaz, una copia de la cadena sin los espacios del comienzo. Realizar las validaciones necesarias.

b- Implementar una función similar, pero que retorna una copia de la cadena original, eliminando los espacios al final.

c- Implementar una que borre los espacios a izquierda y a derecha.
*/

void sin_espacios_izq(char *cadena, char **copia){
    int i = 0;
   
    while(cadena[i] == ' '){
        i++;
    }
    *copia = (char *)malloc(sizeof(char) * (strlen(cadena) - i));
    
    strcpy(*copia, cadena + i);
}

void sin_espacios_der(char *cadena, char **copia){
    int i = strlen(cadena) - 1;
    
    while(cadena[i] == ' '){
        i--;
    }
    
    *copia = (char *)malloc(sizeof(char) * (i+1));

    while (i >= 0){
        (*copia)[i] = cadena[i];
        i--;
    }
    
}

void sin_espacios(char *cadena, char **copia){
    int i = 0;
    int j = 0;
    int k = 0;
    int l = strlen(cadena) - 1;
    
    while(cadena[i] == ' '){
        i++;
    }
    while(cadena[l] == ' '){
        l--;
    }
    *copia = (char *)malloc(sizeof(char) * (l - i + 1));
    
    while (i <= l){
        (*copia)[j] = cadena[i];
        i++;
        j++;
    }

}

int main(void){
    char *cadena1 = "   Hola";
    char *cadena2 = "Hola   ";
    char *cadena3 = "   Hola   ";
    char *copia1;
    char *copia2;
    char *copia3;
    sin_espacios_izq(cadena1, &copia1);
    printf("%s", copia1);
    
    sin_espacios_der(cadena2, &copia2);
    printf("%s", copia2);

    sin_espacios(cadena3, &copia3);
    printf("%s", copia3);

    return EXIT_SUCCESS;
}