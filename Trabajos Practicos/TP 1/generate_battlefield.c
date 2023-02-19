#include <stdio.h>
#include <stdlib.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"
#include "game_maker.h"

status_t battlefield(struct Pokemon ***bat, size_t rows, size_t cols){
    /*
    Reserve memory spaces to store a matrix of a certain number of columns and rows, whose content will be structs Pokemon.

    Parameters
    ----------
    rows : size_t
        Number of rows of the matrix to be created.

    cols : size_t
        Number of columns of the matrix to be created.

    Returns
    -------
    status_t
    */

    if((bat == NULL)){
        return ST_ERR_NULL_PTR;
    
    }

    if((rows == 0) || (cols == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    struct Pokemon **new_bat = malloc(sizeof(struct Pokemon*) * rows);
    
    if (NULL == new_bat) {
        return ST_ERR_MEM_ALLOC;
    }

    for (size_t i = 0; i < rows; i++) {
        (new_bat)[i] = malloc(cols * sizeof(struct Pokemon));
        if (NULL == new_bat[i]) {
            while (i--) {
                free((new_bat)[i]);
            }
            free(new_bat);
            return ST_ERR_MEM_ALLOC;
        }
    }

    *bat = new_bat;

    return ST_OK;
}

status_t full_battlefield(struct Pokemon **bat, size_t rows, size_t cols, int seed){
    /*
    Place a random struct Pokemon in each coordinate of the matrix.

    Parameters
    ----------
    bat : struct Pokemon ***
        A matrix of struct Pokemon with the specified number of rows and columns.

    rows : size_t
        Number of rows of the matrix to be created.

    cols : size_t
        Number of columns of the matrix to be created.

    seed : int
        Seed to generate random numbers.

    Returns
    -------
    status_t
    */

    if((bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((rows == 0) || (cols == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    srand(seed);

    for ( size_t r = 0; r < rows; r++ ) {
        for ( size_t c = 0; c < cols; c++ ) {
            (bat)[r][c].type = rand() % Pokemons;
            
            if ((bat)[r][c].type == No_type){
                (bat)[r][c].life = 0.0;
            }
            else{
                (bat)[r][c].life = 10.0;
            }
        }
    }

    return ST_OK;
}