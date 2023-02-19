#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Escribir una función que reciba un número entero y devuelva 1 si el número es positivo y 0 si el número es negativo.*/

int mom(int a){
    if(a >= 0){
        printf("%i\n",1);
        return 1;
    }
    else{
        printf("%i\n",0);
        return 0;
    }
}

int main(void){
    int a1;
    printf("Ingrese un numero: ");
    scanf("%i",&a1);
    mom(a1);
    return 0;
}