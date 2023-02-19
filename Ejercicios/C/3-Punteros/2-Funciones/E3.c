#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escribir una función que convierta un número que representa una cantidad de segundos, a su equivalente en horas, minutos y segundos, 
retornando las partes por la interfaz, bool por el nombre, indicando el resultado de la operación, true de ser posible false si no. 
Realizar las validaciones pertinentes.*/

bool convertirSegundos(int segundos, int *horas, int *minutos, int *segundosRestantes){
    if(segundos < 0){
        return false;
    }
    else{
        *horas = segundos / 3600;
        *minutos = (segundos % 3600) / 60;
        *segundosRestantes = (segundos % 3600) % 60;
        return true;
    }
}

int main(){
    int segundos, horas, minutos, segundosRestantes;
    printf("Ingrese la cantidad de segundos: ");
    scanf("%d", &segundos);
    if(convertirSegundos(segundos, &horas, &minutos, &segundosRestantes) == true){
        printf("%d segundos equivalen a %d horas, %d minutos y %d segundos\n", segundos, horas, minutos, segundosRestantes);
    }
    else{
        printf("La cantidad de segundos ingresada es invalida\n");
    }
    return 0;
}