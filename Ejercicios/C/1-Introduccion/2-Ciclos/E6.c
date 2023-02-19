#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir funciones que calculen:
1-Factorial
2-Número de Euler
3-Exponencial
4-Tetración*/

int factorial(int a){
    int factorial = 1;
    for(int i = 1; i <= a; i++){
        factorial *= i;
    }
    return factorial;
}

float euler(int b){
    
}

int main(void){
    int a1;
    printf("Ingrese su numero a convertir en factorial: ");
    scanf("%i",&a1);
    printf("%i\n",factorial(a1));
    return 0;
}