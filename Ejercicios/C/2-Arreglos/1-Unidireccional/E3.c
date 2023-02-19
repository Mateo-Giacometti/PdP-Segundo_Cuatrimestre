#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escribir un programa que permita ingresar una cantidad fija de números, los almacene en un arreglo y luego 
imprima la media y la varianza del mismo.*/

int main(void){
    int n;
    printf("Ingrese la cantidad de numeros a ingresar: ");
    scanf("%d", &n);
    int numeros[n];
    int suma = 0;
    for (int i = 0; i < n; i++){
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
    }
    float media = (float)suma/n;
    float varianza = 0;
    for (int i = 0; i < n; i++){
        varianza += pow(numeros[i] - media, 2);
    }
    varianza /= n;
    printf("La media es: %f\n", media);
    printf("La varianza es: %f\n", varianza);
    
    return 0;
}