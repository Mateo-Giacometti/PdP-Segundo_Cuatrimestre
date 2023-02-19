#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

int main(void){
    int i = 3, * pint;
    float f = 10.0;

    pint = &i;
    *pint = 10;
    *pint = f; //mal
    pint = &f; //mal
    pint = 4321; //mal

    return EXIT_SUCCESS;
}