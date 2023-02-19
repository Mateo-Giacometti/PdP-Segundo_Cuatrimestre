#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Implementar funciones que reciban un arreglo de números y su longitud y realicen las operaciones detalladas abajo. 
Utilice notación de punteros exclusivamente.

a- Completar el vector con ceros
b- Completar el vector con unos
c- Calcular y retornar la media por la interfaz
d- Calcular y retornar la media por la interfaz
e- Calcular y retornar la varianza por la interfaz
f- Retornar el valor máximo del arreglo por la interfaz
g- Retornar el valor mínimo del arreglo por la interfaz
h- Modificar los elementos del vector reemplazándolos por sus valores al cuadrado
j- Modificar los elementos del arreglo reemplazándolos por las diferencias finitas de primer orden*/

void completar_con_ceros(int *vector, int *longitud){
    for (int i = 0; i < *longitud; i++){
        *(vector + i) = 0;
    }
}

void completar_con_unos(int *vector, int *longitud){
    for (int i = 0; i < *longitud; i++){
        *(vector + i) = 1;
    }
}

int sum_elementos(int *vector, int *longitud){
    int suma = 0;
    for (int i = 0; i < *longitud; i++){
        suma += *(vector + i);
    }
    return suma;
}

float calcular_media(int *vector, int *longitud){
    float media;
    media = (float)sum_elementos(vector, longitud) / *longitud;
    return media;
}

int max_element(int *vector, int *longitud){
    int max = vector[0];
    for (int i = 0; i < *longitud; i++){
        if (*(vector + i) > max){
            max = *(vector + i);
        }
    }
    return max;
}

int min_element(int *vector, int *longitud){
    int min = vector[0];
    for (int i = 0; i < *longitud; i++){
        if (*(vector + i) < min){
            min = *(vector + i);
        }
    }
    return min;
}

void value_x_value(int *vector, int *longitud){
    for (int i = 0; i < *longitud; i++){
        *(vector + i) *= *(vector + i);
    }
}

void change_of_sign(int *vector, int *longitud){
    for (int i = 0; i < *longitud; i++){
        if(*(vector + i) >= 0){
            *(vector + i) = 1;
        }
        else{
            *(vector + i) = -1;
        }
    }
}

void finit_dif(int *vector, int *longitud){
    for (int i = 0; i < *longitud - 1; i++){
        *(vector + i) = *(vector + (i + 1)) - *(vector + i);
    }
}

int main(){
    int *vector;
    int longitud = 10;
    completar_con_ceros(vector, &longitud);
    for (int i = 0; i < longitud; i++){
        printf("%i ", *(vector + i));
    }
    puts("");
    completar_con_unos(vector, &longitud);
    for (int i = 0; i < longitud; i++){
        printf("%i ", *(vector + i));
    }
    puts("");
    printf("Suma de elementos de vector: %d\n", sum_elementos(vector, &longitud));
    printf("Media de elementos de vector: %f\n", calcular_media(vector, &longitud));
    *(vector + 5) = 10;
    printf("El elemento mas grande del vector es: %i\n", max_element(vector, &longitud));
    *(vector + 4) = 0;
    printf("El elemento mas chico del vector es: %i\n", min_element(vector, &longitud));
    for (int i = 0; i < longitud; i++){
        *(vector + i) += 1;
    }
    value_x_value(vector, &longitud);
    for (int i = 0; i < longitud; i++){
        printf("%i ", *(vector + i));
    }
    puts("");
    change_of_sign(vector, &longitud);
    for (int i = 0; i < longitud; i++){
        printf("%i ", *(vector + i));
    }
    puts("");
    finit_dif(vector, &longitud);
    for (int i = 0; i < longitud; i++){
        printf("%i ", *(vector + i));
    }
    puts("");
    return EXIT_SUCCESS;
} 