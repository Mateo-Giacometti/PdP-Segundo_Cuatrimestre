#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"
#include "battle_rep.h"
#include "game_maker.h"

status_t create_folder(char *name){
    /*
    Creates a directory to stores the PPM files. 

    Parameters
    ----------
    name : char*
        Name of the directory.

    Returns
    -------
    status_t
    */
    if(name == NULL){
        return ST_ERR_NULL_PTR;
    }

    int status;
    status=mkdir(name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);   

    return ST_OK;
}

status_t ppm_battlefield(struct Pokemon **bat, size_t rows, size_t cols, int turn, char *dic_name){
    /*
    Generates a PPM file with the current state of the Pokemon's combat. 

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.

    rows : size_t
        Number of rows of the matrix to be created.

    cols : size_t
        Number of columns of the matrix to be created.

    seed : int
        Seed to generate random numbers.
    
    turn : int
        Number of the current turn
    
    dic_name : char*
        Name of the directory to store the PPM files.

    Returns
    -------
    status_t
    */

    if((bat == NULL) || (dic_name == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((rows == 0) || (cols == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    char filename[50];
    sprintf(filename, "%s/matrix_in_turn_%d.ppm", dic_name, turn);
    
    FILE* pgmimg;
    pgmimg = fopen(filename, "wb");
    fprintf(pgmimg, "P3\n"); 
    fprintf(pgmimg, "%ld %ld\n", cols, rows); 
    fprintf(pgmimg, "255\n"); 
    
    for(size_t r = 0; r < rows; r++ ){
        for(size_t c = 0; c < cols; c++ ){
            fprintf(pgmimg,"%s",ppm_rep[bat[r][c].type]);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);

    return ST_OK;
}

status_t show_battlefield_in_terminal(struct Pokemon **bat, size_t rows, size_t cols){
    /*
    Generates a PPM file with the current state of the Pokemon's combat. 

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.

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

    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++){
            printf( "%s", tr_rep[bat[r][c].type]);
        }
        puts("");
    }
    puts("");

    return ST_OK;
}

status_t show_ppm_battlefield_in_termina(struct Pokemon **bat, size_t rows, size_t cols){
    /*
    Prints the PPM representation with the current state of the Pokemon's combat.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
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

    printf("P3 %ld %ld 255 ", cols, rows);
    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < cols; c++){
            printf("%s", ppm_rep[bat[r][c].type]);
        }
    }
    puts("\n");
    return ST_OK;
}