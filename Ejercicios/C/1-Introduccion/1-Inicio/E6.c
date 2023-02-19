#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Teniendo el radio de un cilindro y su altura escribir funciones que calculen:
-El diámetro del cilindro.
-La circunferencia.
-El área de la base.
-El volumen del cilindro.
-El área del cilindro.
(Notar que algunas funciones pueden resolverse llamando a las ya programadas.)*/

int main(void){
    double PI = 3.14159265358979323846;
    float r,a;
    double d,c,v,ar,ar1;
    printf("Ingrese el valor del radio y la altura del cilindro: ");
    scanf("%f%f", &r,&a);
    d = r*2;
    printf("El diametro del cilindro es de: %lf\n", d);
    c = d*PI;
    printf("La circunferencia es de %lf\n", c);
    ar = r*r*PI;
    printf("El area de la base es de: %lf\n", ar);
    v = r*r*PI*a;
    printf("El volumen del cilindro es: %lf\n", v);
    ar1 = 2*PI*r*(r + a);
    printf("El area del cilindro es de: %lf\n", ar1);
    return 0;
}