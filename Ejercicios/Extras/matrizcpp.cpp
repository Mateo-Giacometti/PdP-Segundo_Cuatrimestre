#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include "status_t.h"

int **mat(size_t f, size_t c){
    int **mat = new int*[f];

    for(size_t i = 0; i < f; i++){
        mat[i] = new int[c]; 
    }
    return mat;
}

void full_mat(int ***mat, size_t f, size_t c){
    srand(time(NULL));
    for (size_t i = 0; i < f; i++){
        for (size_t j = 0; j < c; j++){
            (*mat)[i][j] = rand() % 5;
        }
    }
}

void print_mat(int **mat, size_t f, size_t c){
    for (size_t i = 0; i < f; i++){
        for (size_t j = 0; j < c; j++){
            std::cout<< mat[i][j];
        }
    std::cout<< std::endl;
    }
}

void free_mat(int ***mat, size_t f, size_t c){
    if(mat == NULL || f <= 0 || c <= 0){
        return;
    }
    for (int i = 0; i < f; i++){
        delete[] (*mat)[i];
    }
    delete[] *mat;

}

int main(void){

    int **matriz = mat(3, 3);
    full_mat(&matriz, 3, 3);
    print_mat(matriz, 3, 3);
    free_mat(&matriz, 3, 3);

    return EXIT_SUCCESS;
}
