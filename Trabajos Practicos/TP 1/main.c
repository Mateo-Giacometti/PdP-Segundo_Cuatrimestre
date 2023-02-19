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

int main(int argc, char *argv[]){
    size_t cols;
    size_t rows;
    int cycles = 1000;
    int ppm_num = 0; 
    int seed;
    bool term_repr = false;
    bool ppm_tr = false;
    
    status_t arg = argparse(argc, argv, &cols, &rows, &ppm_num, &seed, &cycles, &term_repr, &ppm_tr);
        if (arg != ST_OK){
            printf("%s\n", status_msg[arg]);
            return EXIT_FAILURE;
        }
    
    status_t pl = play(rows, cols, ppm_num, seed, cycles, term_repr, ppm_tr);
        if (pl != ST_OK){
            printf("%s\n", status_msg[pl]);
            return EXIT_FAILURE;
        }
    
    return EXIT_SUCCESS;
    
}
