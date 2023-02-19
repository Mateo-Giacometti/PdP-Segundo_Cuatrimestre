#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escribir un programa que pida al usuario una cantidad n de valores a generar. Luego genere n valores enteros en el intervalo [0, 10] y
cuente la cantidad de 0s, de 1s, de 2s, etc. Al finalizar, imprima las cantidades calculadas en forma absolutas y relativas. 
Realice las validaciones necesarias.*/

int main(void){
    //function that generates a random number between 0 and 10
    int randomNumber(){
        int randomNumber = (rand() % 10) +1;
        return randomNumber;
    }

    void generator(int n){
        int contador[10] = {0,0,0,0,0,0,0,0,0,0};
        int random_array[n];
        srand(time(NULL));
        
        //fill array with random ints between 0 and 10
        for (int i = 0; i < n; i++){
            random_array[i] = randomNumber();
        }

        for(int i = 0; i < n ; i++){
            for(int index=0;index < 10;index++){
                if (random_array[i] == index+1){
                    contador[index] += 1;
                }
            }
        }

        //print contador array
        printf("elemento  valor histograma\n");
        for(int i = 0; i<10;i++){
            printf("%2d: %10d ", i+1, contador[i]);
            for(int t=0;t<contador[i]* 100/n;t++){
                printf("*");
            }
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}