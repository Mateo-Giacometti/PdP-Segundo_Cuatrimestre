#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar una función que reciba una cadena de caracteres, un carácter y una longitud. 
La misma retorna una copia dinámica de la cadena original, centrada en la longitud especificada y rellenando con el carácter pedido.
                          _________
                         |         |
(" cadena ", '*', 12) -->| centrar |--> "** cadena **"
                         |_________|

*/


char *centrar(char *cadena, char caracter, size_t longitud){
    int re_der, re_izq;

    if(strlen(cadena) == longitud){
        char *copia = (char *)malloc(longitud * sizeof(char));
        strcpy(copia, cadena);
        return copia;
    }
    else if(longitud > strlen(cadena)){

        char *copia = (char *)malloc(longitud * sizeof(char));
        
        int exceso = longitud - strlen(cadena);
        int c_count = 0;

        if(exceso % 2 == 0){
            re_der = exceso / 2;
            re_izq = exceso / 2;
        }
        else{
            re_der = (exceso / 2) + 1;
            re_izq = exceso / 2;
        }

        for(int i = 0; i < re_izq; i++){
            copia[i] = caracter;
        }

        for(int i = re_izq; i < (strlen(cadena) + re_izq); i++){
            copia[i] = cadena[c_count];
            c_count++;
        }

        for(int i = (strlen(cadena) + re_izq); i < longitud; i++){
            copia[i] = caracter;
        }

        return copia;
    }
    else{
        return NULL;
    }
    
}

int main(void){
    char cadena[20] = " Pepe ";
    char caracter = '*';
    size_t longitud = 12;

    char *copy = centrar(cadena, caracter, longitud);

    printf("%s\n", copy);

    return EXIT_SUCCESS;
}