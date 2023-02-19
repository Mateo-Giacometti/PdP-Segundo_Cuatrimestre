#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*Escribir una función que reciba el capital inicial, una tasa de interés y un número de años y devuelva el monto final a cobrar.
Donde C es el capital inicial, X es la tasa de interés y n es el número de años a calcular.*/

int main (void){ 
    int capital;
    double tasa;
    int year;
    printf("Ingrese un capital, en entero: ");
    scanf("%d",&capital);
    printf("Ingrese una tasa, (con decimal): ");
    scanf("%lf",&tasa);
    printf("Ingrese los años: \n");
    scanf("%d",&year);
    double cuenta,capi_final,cuen;
    double pote = 3;
    double num1 = 2;
    cuenta = capital * (1+tasa / 100);
    capi_final = pow(cuenta,year);
    printf("%lf\n",capi_final);
    cuen = pow(num1,pote);
    printf(" %lf\n",cuen);
    return 0;
}