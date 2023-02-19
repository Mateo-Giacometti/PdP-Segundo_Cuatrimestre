#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> //Nueva libreria. Ver sus funciones 
#include <stdbool.h> //Nueva libreria. Ver sus funciones 

int main(void){
    unsigned int n;
    float nota;
    float suma = 0;
    float promedio = 0; 
    int aux;
    bool valid;

    do {
        valid = false;
        printf("Ingrese la cantidad de notas: ");
        aux = scanf("%u",&n);
       
        if(aux != 1){
            puts("No ingresaste una cantidad de notas validas");
            valid = true; 
        }

        while (getchar() != '\n'){
            puts("Ingresaste algo que no es un numero");
            valid = true;
        }
        
        if (n == 0 && valid){
            printf("Ingresaste un 0\n");
            return EXIT_SUCCESS;
        }
    }while(valid == false);

    printf("Vas a ingresar %i\n",n);
   
    for(size_t i = 0; i < n; ++i){
        aux = scanf("%f", &nota);
        if(aux != 1){
            puts("No ingresaste una notas valida");
            return EXIT_FAILURE; 
        }
        while (getchar() != '\n'){
        }
        suma += nota;
    }
    promedio = suma / n;
    printf("El promedio de %i notas es %.2f\n", n, promedio);
    return EXIT_SUCCESS;
}