#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/**/

int main(void){
    int conj[5], list[]={5, 4, 3, 2, 1};
    int *punt;
    int *punt1;

    punt = list;
    punt1 = &list;

    printf("%p\n", punt);
    printf("%p\n", punt1);

    printf("Elemento de puntero a array: %i\nElemento de puntero a entero: %i\n", punt[1], punt1[1]);

    return 0;
    
}