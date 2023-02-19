#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "status_t.h"

/*
Cargue una matriz y modifique dicha matriz cambiándola por su transpuesta o lea otra matriz con las dimensiones adecuadas y la cargue con 
la transpuesta.
*/

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

void matFree(int ***mat, size_t rows, size_t cols) {
    int **_m;

    if (mat) {
        _m = *mat;
        while (rows--) {
            free(_m[rows]);
        }
        free(_m);
        *mat = NULL;
    }
}

void randomz(int **mat, size_t rows, size_t cols, int seed){
    srand(seed);
    for(size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++) {
            mat[r][c] = rand() % 5;
        }
    }
}

status_t transpuesta(int ***matrix, size_t r, size_t c){
    int **t =  mat(r, c);

    if(t == NULL){
        return ST_ERR_NULL_PTR;
    }

    for(size_t r1 = 0; r1 < c; r1++){
        for(size_t c1 = 0; c1 < r; c1++){
            t[r1][c1] = (*matrix)[c1][r1];
        }
    }

    *matrix = t;

    return ST_OK;
}

status_t mul_mat(int **mat1, size_t r1, size_t c1, int **mat2, size_t r2, size_t c2, int ***mat3, size_t r3, size_t c3){
    if(mat1 == NULL || mat2 == NULL || mat3 == NULL){
        return ST_ERR_NULL_PTR;
    }

    int counter = 0;

    for(size_t r = 0; r < r1; r++){
        for(size_t c = 0; c < c2; c++){
            for(size_t i = 0; i < c1; i++){
                counter += mat1[r][i] * mat2[i][c];
            }
            (*mat3)[r][c] = counter;
            counter = 0;
        }
    }

}

int main(void){
    size_t rows = 5;
    size_t cols = 3;

    int **matriz = mat(rows, cols);
    int **m1 = mat(rows, cols);
    int **m2 = mat(rows, cols);
    int **m3 = mat(rows, cols);

    randomz(matriz, rows, cols,1);
    randomz(m1, rows, cols,2);
    randomz(m2, rows, cols,3);

    for(size_t i = 0; i < rows; i++){
        for(size_t v = 0; v < cols; v++){
            printf("%i ",matriz[i][v]);
        }
        puts("");
    }

    transpuesta(&matriz, rows, cols);
    puts("");

    for(size_t i = 0; i < cols; i++){
        for(size_t v = 0; v < rows; v++){
            printf("%i ",matriz[i][v]);
        }
        puts("");
    }

    mul_mat(m1, rows, cols, m2, rows, cols, &m3, rows, cols);
    puts("");

    for(size_t i = 0; i < rows; i++){
        for(size_t v = 0; v < cols; v++){
            printf("%i ",m3[i][v]);
        }
        puts("");
    }

    puts("");

    for(size_t i = 0; i < rows; i++){
        for(size_t v = 0; v < cols; v++){
            printf("%i ",m1[i][v]);
        }
        puts("");
    }

    puts("");
     for(size_t i = 0; i < rows; i++){
        for(size_t v = 0; v < cols; v++){
            printf("%i ",m2[i][v]);
        }
        puts("");
    }

    return EXIT_SUCCESS;
}