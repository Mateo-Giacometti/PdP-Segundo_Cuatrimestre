#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>

/*Escribir un programa que calcule las 2 raíces de un polinomio de segundo grado. Validar las operaciones a 
realizar (no dividir por cero ni calcular la raíz de un número negativo, o imprimir la raíz compleja).*/

int main(void){
    
    float a, b, c;
    float r1, r2;
    float discriminante;

    /* Ingreso de datos */
    printf("Ingrese a: ");
    scanf("%f", &a);

    printf("Ingrese b: ");
    scanf("%f", &b);

    printf("Ingrese c: ");
    scanf("%f", &c);

    /* Validación de datos */
    if (a == 0) {
        printf("No es una cuadrática\n");
        if (b != 0) {
            printf("By the way, LA raíz es: %f\n", -c / b);
        }
        return EXIT_SUCCESS;
    }

    /* Procesamiento */
    discriminante = b * b - 4  * a * c;
    if (discriminante < 0) {
        printf("Raices complejas\n");
    } else if (discriminante == 0) {
        printf("Raíz real doble\n");
        r1 = r2 = -b / (2 * a);
        printf("r1 = %f\nr2 = %f\n", r1, r2);
    } else {
        printf("Raices reales\n");
        discriminante = sqrt(discriminante);
        r1 = (-b + discriminante) / (2 * a);
        r2 = (-b - discriminante) / (2 * a);
        printf("r1 = %f\nr2 = %f\n", r1, r2);
    }

    return EXIT_SUCCESS;
}
