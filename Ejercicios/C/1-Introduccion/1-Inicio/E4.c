#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*Escribir una función que dadas la hora, minutos y segundos devuelva el tiempo en segundos.*/

int main(void){
    double h,m,s,s1,s2,total;
    printf("Ingrese las horas: ");
    scanf("%lf", &h);
    printf("Ingrese las minutos: ");
    scanf("%lf", &m);
    printf("Ingrese las segundos: ");
    scanf("%lf", &s);
    s1 = h * 3600;
    s2 = m * 60;
    total = s1 + s2 + s;
    printf("En segundos totales equivale a: %lf\n", total);
    return 0;
}