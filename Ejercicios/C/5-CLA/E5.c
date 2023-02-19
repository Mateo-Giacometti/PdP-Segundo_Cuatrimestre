#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Escriba un programa que imprima de manera ordenada los argumentos recibidos. 
Si el primer parámetro del programa es -r, entonces los ordena al revés.*/

int main(int argc, char* argv[]){
    bool reverse = false;
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-r") == 0){
            reverse = true;
        }
    }
    if(reverse == true){
        for(int i = argc - 1; i > 0; i--){
            if(strcmp(argv[i], "-r") != 0){
                printf("%s\n",argv[i]);
            }
        }
    }
    else{
        for(int i = 1; i < argc; i++){
            printf("%s\n",argv[i]);
        }
    }
}