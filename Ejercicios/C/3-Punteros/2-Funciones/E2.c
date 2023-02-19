#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

void suma(int a, int b, long int *suma){
    long int sum = a + b;
    suma = &sum;
    printf("Suma: %li\n", *suma);
    printf("Direccion de memoria de la suma: %p\n", suma);
}

void resta(int a, int b, long int *resta){
    long int res = a - b;
    resta = &res;
    printf("Resta: %li\n", *resta);
    printf("Direccion de memoria de la operacion: %p\n", resta);
}

void producto(int multiplicando, int multiplicador, float *producto){
    float produc = multiplicando * multiplicador;
    producto = &produc;
    printf("Multiplicacion: %f\n", *producto);
    printf("Direccion de memoria de la operacion: %p\n", producto);
}

void division(int dividendo, int divisor, double *resultado){
    double result = dividendo / divisor;
    resultado = &result;
    printf("Division: %lf\n", *resultado);
    printf("Direccion de memoria de la operacion: %p\n", resultado);
}

void mod(int a, int b, int *resto){
    int res = a % b;
    resto = &res;
    printf("Resto: %i\n", *resto);
    printf("Direccion de memoria de la operacion: %p\n", resto);
}

int main(void){
    long int *sum;
    long int *res;
    float *product;
    double *result;
    int *resto;
    int a,b;
    long int c;
    printf("Ingrese 2 numeros: ");
    scanf("%d%d",&a,&b);
    //Llamamaos a las funciones
    suma(a, b, sum);
    resta(a, b, res);
    producto(a, b, product);
    division(a, b, result);
    mod(a, b, resto);
    
    return EXIT_SUCCESS;
}