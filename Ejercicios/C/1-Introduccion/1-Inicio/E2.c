#include <stdio.h>
#include <math.h>

/*Escribir una función que convierta un valor en grados Fahrenheit a grados Celsius.*/

int main(void){
 float F;
 double C; 
 printf("Ingrese los grados en Fahrenheit: ");
 scanf("%f",&F); 
 C = ((F - 32)*5)/9;
 printf("Los grados en Celsius son: %lf\n", C);
 return 0; 
}