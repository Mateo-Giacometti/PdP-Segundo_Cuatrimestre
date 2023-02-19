#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "status_t.h"

/*
Escribir una función recursiva que calcule el n-ésimo número de la sucesión de Fibonacci.
*/


int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void){
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("El numero de fibonacci es: %d\n", fibonacci(n));
    return EXIT_SUCCESS;
}
