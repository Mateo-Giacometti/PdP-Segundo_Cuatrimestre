#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escribir las definiciones siguientes:

-Un arreglo de 10 elementos de tipo entero.
-Un arreglo de enteros con 15 elementos, todos ellos de valor 0.
-Un arreglo de 7 doubles, todos ellos de valor 3.0.
-Un arreglo de SIZE floats, todos ellos de valor 0.
-Un arreglo de 4 enteros con los valores: 3, 2, 0, 9.
-Un arreglo de 4 caracteres con los valores: 'h', 'o', 'l', 'a'.
-Un arreglo de 4 caracteres con los valores: 104, 111, 108, 97.
-Un arreglo con SIZE elementos de algún tipo (bool, int, float, double, etc) y lo inicialice con valores aleatorios.

Imprimir todos los arreglos creados y la suma de sus elementos.
*/
int main (void){
    int size = rand() % 11;
    int enteros[10] = {1,2,3,4,5,6,7,8,9,10};
    int ceros[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double dobles[7] = {3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
    int valores[4] = {3, 2, 0, 9};
    char caracteres[4] = {'h', 'o', 'l', 'a'};
    int caracteres_int[4] = {104, 111, 108, 97};
    float SIZE[size];
    int SIZE1[size];

    for(int i = 0; i < size; i++){
        SIZE[i] = 0.0;
        SIZE1[i] = rand(); 
    }

    for(int v = 0; v < size; ++v){
        printf("%i\n", SIZE1[v]);
    }

    puts("");

    for(int c = 0; c < size; ++c){
        printf("%f\n", SIZE[c]);
    }

    return EXIT_SUCCESS;
}