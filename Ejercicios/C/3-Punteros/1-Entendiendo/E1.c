#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

int main(void){
    float * pfloat, manzana = 40.0, pera = 35.0;

    printf("&pfloat: %p\n", &pfloat);
    printf("&manzana: %p\n", &manzana);
    printf("&pera: %p\n", &pera);

    printf("pfloat: %p\n", pfloat);

    pfloat = &manzana;
    printf("pfloat: %p\n", pfloat);
    printf("*pfloat: %p\n", *pfloat);

    pfloat = &pera;
    printf("pfloat: %p\n", pfloat);
    printf("*pfloat: %p\n", *pfloat);

    return EXIT_SUCCESS;
}