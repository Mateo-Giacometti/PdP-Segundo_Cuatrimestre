#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implementar una función que retorne una matriz dinámica, de un tamaño pasado como argumento, siendo la misma inicializada con:
ceros, unos, la identidad, números aleatorios.*/

int **mat(size_t rows, size_t cols){
   
    int **m = (int **) malloc(sizeof(int *) * rows);

    if (NULL == m) {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++){
        m[i] = (int*) malloc(cols * sizeof(int));
        
        if (NULL == m[i]) {
            while (i--) {
                free(m[i]);
            }
            free(m);
            return NULL;
        }
    }

    return m;
}

void ceros(int **mat, size_t rows, size_t cols){
    for( size_t r = 0; r < rows; r++ ){
        for( size_t c = 0; c < cols; c++ ){
            mat[r][c] = 0;
        }
 
    }
}

void unos(int **mat, size_t rows, size_t cols){
     for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++) {
            mat[r][c] = 1;
        }
    }
}

void identidad(int **mat, size_t rows, size_t cols){
    for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++) {
            if(r == c){
                mat[r][c] = 1;
            }
            else{
                mat[r][c] = 0;
            }
        }
    }
}

void randomz(int **mat, size_t rows, size_t cols){
    srand(time(NULL));
    for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++) {
            mat[r][c] = rand() % 5;
        }
    }
}

int main(int argc, char* argv[]){
    size_t rows, cols;
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-r") == 0){
            rows = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-c") == 0){
            cols = atoi(argv[i+1]);
        }
    }

    int **max = mat(rows, cols);
    
    ceros(max, rows, cols);

    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++){
            printf("%d", max[r][c]);
        }
        puts("");
    }
    puts("");
    
    
    unos(max, rows, cols);

    for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++){
            printf("%d", max[r][c]);
        }
        puts("");
    }
    puts("");

    identidad(max, rows, cols);

    for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++){
            printf("%d", max[r][c]);
        }
        puts("");
    }
    puts("");

    randomz(max, rows, cols);

    for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++){
            printf("%d", max[r][c]);
        }
        puts("");
    }
    puts("");

    return EXIT_SUCCESS;
}