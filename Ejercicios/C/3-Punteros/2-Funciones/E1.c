#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar una función swap que reciba 2 datos a y b por puntero y los intercambie, de forma tal que b sea a y viceversa.*/

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int a, b;
    printf("Ingrese 2 numeros: ");
    scanf("%d%d", &a, &b);

    printf("Tu primer numero es %d\n", a);
    printf("Tu segundo numero es %d\n", b);

    swap(&a, &b);

    printf("Tu nuevo primer numero es %d\n", a);
    printf("Tu nuevo segundo numero es %d\n", b);

    return EXIT_SUCCESS;
}