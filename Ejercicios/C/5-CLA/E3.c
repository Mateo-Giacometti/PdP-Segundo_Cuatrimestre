#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>

/*Escriba un programa que reciba dos cadenas de caracteres e imprima el resultado de su comparación lexicográfica, 
como lo haría la función strcmp() o strcasecmp().*/

int len_words(char w[]){
    int j = 0;
    while(w[j] != '\0'){
        j++;
    }
    return j;
}

bool str_comparison(char p1[], char p2[]){
    if(len_words(p1) == len_words(p2)){
        for(int i = 0; i < len_words(p1); i++){
            if(p1[i] != p2[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char* argv[]){
    char word1[20];
    char word2[20];
    int j = 0;
    int k = 0;
   
    while(argv[1][j] != '\0'){
        word1[j] = argv[1][j];
        j++;
    }

    while(argv[2][k] != '\0'){
        word2[k] = argv[2][k];
        k++;
    }

    if(str_comparison(word1, word2) == false){
        puts("No son la misma palabra");
    }

    if(str_comparison(word1, word2) == true){
        puts("Son la misma palabra");
    }
    return EXIT_SUCCESS;
}