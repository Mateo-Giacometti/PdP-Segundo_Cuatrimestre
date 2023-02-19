#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "status_t.h"

/*
-Definir una estructura punto que contenga las coordenadas de un punto en R2.
-Definir un nuevo tipo utilizando la definición de la estructura punto.
-Implementar una función que reciba dos estructuras punto y calcule la distancia euclídea entre ambos puntos.
-Implementar la función del inciso c ¡pero ahora validando!
*/

typedef struct punto{
    double x;
    double y;
}punto_t;

double distancia(punto_t p1, punto_t p2){
    double dist = pow(pow((p2.x - p1.x), 2) + pow(p2.y - p1.y, 2), 0.5);
    return dist;
}

status_t distancia_v2(punto_t *p1, punto_t *p2, double *distance){
    if((p1 == NULL) || (p2 == NULL) || (distance == NULL)){
        return ST_ERR_NULL_PTR;
    }

    *distance = pow(pow((p2->x - p1->x), 2) + pow(p2->y - p1->y, 2), 0.5);

    return ST_OK;
}

int main(void){
    punto_t p1 = {2,2};
    punto_t p2 = {4,4};
    double dist_v2;
    double dist_f = distancia(p1,p2);
    distancia_v2(&p1, &p2,&dist_v2);
    printf("La distancia entre los puntos es de %f\n", dist_f);
     printf("La distancia con validacion entre los puntos es de %f\n", dist_v2);
    return EXIT_SUCCESS;
}