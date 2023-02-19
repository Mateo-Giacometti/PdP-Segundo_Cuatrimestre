#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Escribir una función que dado un número devuelva el primer número múltiplo de 10 inferior a él. Por ejemplo, para 153 debe devolver 150.*/

int main(){
    int num;
    printf("Ingrese un numero: ");
    scanf("%i",&num);
    for(int i = 0; num % 10 != 0; i++) {
        num--;
    }
    printf("%i\n", num);
    return num;
}