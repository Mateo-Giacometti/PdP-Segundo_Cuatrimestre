#include <stdio.h>
#include <math.h>

/*Escribir una función que convierta un valor en grados Celsius a grados Fahrenheit.*/

int main(void){
 float C;
 double F; 
 printf("Ingrese los grados en Celsius: ");
 scanf("%f",&C); 
 F = (1.8)*C + 32;
 printf("Los grados en Fahrenheit son: %lf\n", F);
 return 0; 
 
}