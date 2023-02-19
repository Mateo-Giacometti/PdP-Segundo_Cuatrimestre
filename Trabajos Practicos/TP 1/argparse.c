#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "pokemons_and_damage.h"
#include "attack_and_defense.h"
#include "battle_rep.h"
#include "fight.h"
#include "game_maker.h"
#include "generate_battlefield.h"
#include "args_and_errors.h"
#include "argparse.h"

status_t argparse(int argc, char *argv[], size_t *cols, size_t *rows, int *ppm_num, int *seed, int *cycles, bool *term_repr, bool *ppm_tr){
    
    char *pend = NULL;
    int arg;
    bool cols_processed = false;
    bool rows_processed = false;
    bool _term_repr = false;
    bool _ppm_tr = false;
    bool h = false;
    int _cols = 0, _rows = 0;
    int _ppm_num = 0, _seed, _cycles = 1000;

    if((argc < 4) && (strcmp(argv[1], "-h") != 0) && (strcmp(argv[1], "--help") != 0)){
        return ST_ERR_INSUFFICIENT_ARGUMENTS;
    }

    if(argc > 20){
        return ST_ERR_TOO_MANY_ARGUMENTS;
    }

    if ((NULL == argv) || (NULL == cols) || (NULL == rows) || (NULL == ppm_num) || (NULL == seed) || (NULL == cycles) || (NULL == term_repr) || (ppm_tr == NULL)){
        return ST_ERR_NULL_PTR;
    }

    for (int i = 1; i < argc; ++i) {
        for (arg = 0; arg < sizeof(valid_args) / sizeof(valid_args[0]); ++arg) {
            if (!strcmp(argv[i], valid_args[arg])) {
                break;
            }
        }
        switch(arg){
            case ARG_COLS_SHORT: 
            case ARG_COLS_LONG:
                i++;
                _cols = strtof(argv[i], &pend);
                if ('\0' != *pend || _cols < 1) {
                    return ST_ERR_INVALID_NUMBER;
                }
                cols_processed = true;
                break;
            case ARG_ROWS_SHORT:
            case ARG_ROWS_LONG:
                i++;
                _rows = strtof(argv[i], &pend);
                if ('\0' != *pend || _rows < 1){
                    return ST_ERR_INVALID_NUMBER;
                }
                rows_processed = true;
                break;
            case ARG_SEED_SHORT:
            case ARG_SEED_LONG:
                i++;
                _seed = strtof(argv[i], &pend);
                if ('\0' != *pend) {
                    return ST_ERR_INVALID_NUMBER;
                }
                break;
            case ARG_CYCLES:
                i++;
                _cycles = strtof(argv[i], &pend);
                if ('\0' != *pend || _cycles < 1) {
                    return ST_ERR_INVALID_NUMBER;
                }
                break;
            case ARG_PPM:
                i++;
                _ppm_num = strtof(argv[i], &pend);
                if ('\0' != *pend || _ppm_num < -1) {
                    return ST_ERR_INVALID_NUMBER;
                }
                break;
            case ARG_TER_REP:
                _term_repr = true;
                break;
            case ARG_HELP_SHORT:
            case ARG_HELP_LONG:
                h = true;
                break;
            case ARG_PPM_TER:
                _ppm_tr = true;
                break;
            default:
                return ST_ERR_UNKNOWN_ARGUMENT;
        }
    }

    if(h == true){
        puts("--help, -h:   Prints a help and ends the execution of the program.");
        puts("--width, -w:  Sets the number of rows of the matrix.");
        puts("--height, -H: Sets the number of columns of the matrix.");
        puts("--seed, -s:   Sets the seed for the random number generator.");
        puts("--cycles, -c: Sets the number of cycles to be simulated.");
        puts("-n:           Sets the number of cycles between each PPM image.");
        puts("-tr:          Prints the Pokemon's matrix in the terminal.");
        puts("-pt:          Prints the Pokemon's matrix in the terminal as PPM format.");
        return ST_HELP;
    }

    if ((cols_processed == false) || (rows_processed  == false)) {
        return ST_ERR_INSUFFICIENT_ARGUMENTS;
    }

    *cols = _cols;
    *rows = _rows;
    *seed = _seed;
    *cycles = _cycles;
    *ppm_num = _ppm_num;
    *term_repr = _term_repr;
    *ppm_tr = _ppm_tr;

    return ST_OK;
}