#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escribir ciclos que realicen cada una de las siguientes operaciones:

-Inicializar un vector de 15 elementos con ceros.
-Sumar 1 a cada uno de los 15 elementos del arreglo vector.
-Leer del teclado y almacenar 12 valores de punto flotante en el arreglo temp_mensuales.
-Imprimir los 5 primeros valores del vector de enteros puntajes en forma de columna.
-Sumar un 30% a cada uno de los 20 elementos del arreglo de números salarios.
*/

int main(void){
    int vec[15];
    float temp_mensual[12];
    int enteros[10] = {1,2,3,4,5,6};
    float salarios[20] = {34,5567,8787,9989,567,234,436,543,7345,73457,863,24,652,234,543,765,8576,234,98765,344455};
    
    //Inicializar un vector de 15 elementos con ceros.
    for(int i = 0; i < 15; i++){
        vec[i] = 0;
     }
    //Sumar 1 a cada uno de los 15 elementos del arreglo vector.
    for(int v = 0; v < 15; v++){
        vec[v] += 1;
    }

    for(int c = 0; c < 15; c++){
        printf("%d ", vec[c]);
    }
    
    //Leer del teclado y almacenar 12 valores de punto flotante en el arreglo temp_mensuales.
    
    puts("\nIngrese 12 valores numericos");
    
    for(int q = 0; q < 12; q++){
        scanf("%f",&temp_mensual[q]);
    }

    puts("");

    for(int c = 0; c < 12; c++){
        printf("%f ", temp_mensual[c]);
    }
   
    puts("\n");

    //Imprimir los 5 primeros valores del vector de enteros puntajes en forma de columna.
    printf("| N |\n");
    for(int q = 0; q < 5; q++){
        printf("| %d |\n",enteros[q]);
    }

    //Sumar un 30% a cada uno de los 20 elementos del arreglo de números salarios.

    for(int q = 0; q < 20; q++){
        salarios[q] = salarios[q] + (salarios[q])*(0.3);
    }

    for(int q = 0; q < 20; q++){
        printf("%f ", salarios[q]);
    }

    puts("\n");

    return EXIT_SUCCESS;
}