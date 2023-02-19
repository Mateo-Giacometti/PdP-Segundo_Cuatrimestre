#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Escribir una función que dado un número entero devuelva 1 si el mismo es impar y 0 si fuera par.*/

int main(){
    int num;
    printf("Ingrese un numero: ");
    scanf("%i", &num);
    if (num % 2 != 0){
        puts("Cero");
        return 0;
    }
    else{
        puts("Uno");
        return 1;
    }
}